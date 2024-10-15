#include "event_factory.h"
#include <iostream>

std::unique_ptr<Event> WorkshopFactory::createEvent() {
    std::string name, date, location, instructor;
    int duration;

    std::cout << "Enter workshop name: ";
    std::getline(std::cin, name);
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "Enter location: ";
    std::getline(std::cin, location);
    std::cout << "Enter duration (hours): ";
    std::cin >> duration;
    std::cin.ignore();
    std::cout << "Enter instructor name: ";
    std::getline(std::cin, instructor);

    return std::make_unique<Workshop>(name, date, location, duration, instructor);
}

std::unique_ptr<Event> ConcertFactory::createEvent() {
    std::string name, date, location, bandName, genre;

    std::cout << "Enter concert name: ";
    std::getline(std::cin, name);
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "Enter location: ";
    std::getline(std::cin, location);
    std::cout << "Enter band name: ";
    std::getline(std::cin, bandName);
    std::cout << "Enter genre: ";
    std::getline(std::cin, genre);

    return std::make_unique<Concert>(name, date, location, bandName, genre);
}

std::unique_ptr<Event> ConferenceFactory::createEvent() {
    std::string name, date, location, speaker, topic;
    std::vector<std::string> speakers, topics;

    std::cout << "Enter conference name: ";
    std::getline(std::cin, name);
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "Enter location: ";
    std::getline(std::cin, location);

    std::cout << "Enter speakers (enter 'done' when finished):\n";
    while (true) {
        std::getline(std::cin, speaker);
        if (speaker == "done") break;
        speakers.push_back(speaker);
    }

    std::cout << "Enter topics (enter 'done' when finished):\n";
    while (true) {
        std::getline(std::cin, topic);
        if (topic == "done") break;
        topics.push_back(topic);
    }

    return std::make_unique<Conference>(name, date, location, speakers, topics);
}