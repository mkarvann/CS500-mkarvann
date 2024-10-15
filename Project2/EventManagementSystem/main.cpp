#include "event_manager.h"
#include "event_factory.h"
#include <iostream>
#include <memory>

void displayMenu() 
{
    std::cout << "\nEvent Management System\n";
    std::cout << "1. Create new event\n";
    std::cout << "2. Create new user\n";
    std::cout << "3. Display all events\n";
    std::cout << "4. Search for events\n";
    std::cout << "5. Display event details\n";
    std::cout << "6. RSVP for an event\n";
    std::cout << "7. Cancel RSVP\n";
    std::cout << "8. Display event attendees\n";
    std::cout << "9. Display user RSVPs\n";
    std::cout << "10. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() 
{
    EventManager manager;
    std::unique_ptr<EventFactory> factory;

    while (true) 
    {
        displayMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) 
        {
            case 1: 
            {
                std::cout << "Select event type:\n";
                std::cout << "1. Workshop\n2. Concert\n3. Conference\n";
                int eventType;
                std::cin >> eventType;
                std::cin.ignore();

                switch (eventType) 
                {
                    case 1:
                        factory = std::make_unique<WorkshopFactory>();
                        break;
                    case 2:
                        factory = std::make_unique<ConcertFactory>();
                        break;
                    case 3:
                        factory = std::make_unique<ConferenceFactory>();
                        break;
                    default:
                        std::cout << "Invalid event type.\n";
                        continue;
                }

                auto newEvent = factory->createEvent();
                manager.addEvent(std::move(newEvent));
                std::cout << "Event created successfully.\n";
                break;
            }
            
            case 2: 
            {
                std::cout << "Enter username: ";
                std::string username;
                std::getline(std::cin, username);

                std::cout << "Choose notification frequency (1 for Daily, 2 for Weekly): ";
                int freqChoice;
                std::cin >> freqChoice;
                std::cin.ignore();  

                NotificationFrequency freq;
                if (freqChoice == 1) 
                {
                    freq = NotificationFrequency::Daily;
                } 
                else if (freqChoice == 2) 
                {
                    freq = NotificationFrequency::Weekly;
                } else 
                {
                    std::cout << "Invalid choice. Defaulting to Daily notifications.\n";
                    freq = NotificationFrequency::Daily;
                }

                auto user = std::make_shared<User>(username, freq);  
                manager.addUser(user);  
                std::cout << "User " << username << " created successfully.\n";
                break;
            }
            case 3:
                manager.displayAllEvents();
                break;
            case 4: 
            {
                int searchOption;
                std::cout << "Choose search option:\n";
                std::cout << "1. Search by Date\n";
                std::cout << "2. Search by Location\n";
                std::cout << "3. Search by Type\n";
                std::cout << "Enter option (1/2/3): ";
                std::cin >> searchOption;
                std::cin.ignore(); 

                std::string criteria;
                switch (searchOption) 
                {
                    case 1: {
                        std::cout << "Enter date criteria (YYYY-MM-DD): ";
                        std::getline(std::cin, criteria);
                        
                        DateSearchStrategy dateStrategy;
                        auto dateResults = manager.searchEvents(dateStrategy, criteria);
                        
                        if (dateResults.empty()) 
                        {
                            std::cout << "No events found on the specified date.\n";
                        } 
                        else 
                        {
                            std::cout << "Events on " << criteria << ":\n";
                            for (const auto& event : dateResults) {
                                std::cout << event->getDetails() << "\n";
                            }
                        }
                        break;
                    }
                    case 2: 
                    {
                        std::cout << "Enter location criteria: ";
                        std::getline(std::cin, criteria);
                        
                        LocationSearchStrategy locationStrategy;
                        auto locationResults = manager.searchEvents(locationStrategy, criteria);
                        
                        if (locationResults.empty()) 
                        {
                            std::cout << "No events found at the specified location.\n";
                        } 
                        else 
                        {
                            std::cout << "Events at " << criteria << ":\n";
                            for (const auto& event : locationResults) {
                                std::cout << event->getDetails() << "\n";
                            }
                        }
                        break;
                    }
                    case 3: 
                    {
                        std::cout << "Enter type criteria (e.g., 'workshop', 'concert', 'conference'): ";
                        std::getline(std::cin, criteria);
                        
                        TypeSearchStrategy typeStrategy;
                        auto typeResults = manager.searchEvents(typeStrategy, criteria);
                        
                        if (typeResults.empty()) 
                        {
                            std::cout << "No events found for the specified type.\n";
                        } 
                        else 
                        {
                            std::cout << "Events of type " << criteria << ":\n";
                            for (const auto& event : typeResults) 
                            {
                                std::cout << event->getDetails() << "\n";
                            }
                        }
                        break;
                    }
                    default: 
                    {
                        std::cout << "Invalid option. Please select 1, 2, or 3.\n";
                        break;
                    }
                }
                break;
            }

            case 5: 
            {
                std::cout << "Enter event name: ";
                std::string eventName;
                std::getline(std::cin, eventName);
                manager.displayEventDetails(eventName);
                break;
            }
            case 6: 
            {
                std::string username, eventName;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter event name: ";
                std::getline(std::cin, eventName);
                manager.rsvpForEvent(username, eventName);
                break;
            }
            case 7: 
            {
                std::string username, eventName;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter event name: ";
                std::getline(std::cin, eventName);
                manager.cancelRSVP(username, eventName);
                break;
            }
            case 8: 
            {
                std::string eventName;
                std::cout << "Enter event name: ";
                std::getline(std::cin, eventName);
                manager.displayEventAttendees(eventName);
                break;
            }
            case 9: 
            {
                std::string username;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                manager.displayUserRSVPs(username);
                break;
            }
            case 10:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
