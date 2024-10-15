#include "event.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

bool Event::isUpcoming() const 
{
    std::tm tm = {};
    std::istringstream ss(eventDate);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    
    auto eventTime = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    auto now = std::chrono::system_clock::now();
    
    return eventTime > now;
}

std::string Workshop::getDetails() const 
{
    std::stringstream ss;
    ss << "Workshop: " << eventName << "\n"
       << "Date: " << eventDate << "\n"
       << "Location: " << eventLocation << "\n"
       << "Duration: " << duration << " hours\n"
       << "Instructor: " << instructor << "\n"
       << "Attendees: " << attendees.size();
    return ss.str();
}

std::string Concert::getDetails() const 
{
    std::stringstream ss;
    ss << "Concert: " << eventName << "\n"
       << "Date: " << eventDate << "\n"
       << "Location: " << eventLocation << "\n"
       << "Band: " << bandName << "\n"
       << "Genre: " << genre << "\n"
       << "Attendees: " << attendees.size();
    return ss.str();
}

std::string Conference::getDetails() const 
{
    std::stringstream ss;
    ss << "Conference: " << eventName << "\n"
       << "Date: " << eventDate << "\n"
       << "Location: " << eventLocation << "\n"
       << "Speakers: ";
    
    for (const auto& speaker : speakers) 
    {
        ss << speaker << ", ";
    }

    ss << "\nTopics: ";
    for (const auto& topic : topics) 
    {
        ss << topic << ", ";
    }
    
    ss << "\nAttendees: " << attendees.size();
    return ss.str();
}

void Event::addAttendee(const std::string &attendee) 
{
    attendees.insert(attendee);
}

void Event::removeAttendee(const std::string &attendee) 
{
    attendees.erase(attendee);
}

bool Event::isAttending(const std::string &attendee) const 
{
    return attendees.find(attendee) != attendees.end();
}

size_t Event::getAttendeeCount() const 
{
    return attendees.size();
}
std::string Event::getName() const 
{
    return eventName;
}

std::string Event::getDate() const 
{
    return eventDate;
}

std::string Event::getLocation() const 
{
    return eventLocation;
}