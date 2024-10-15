#pragma once
#include "event.h"
#include <memory>

class EventFactory 
{
public:
    virtual std::unique_ptr<Event> createEvent() = 0;
    virtual ~EventFactory() = default;
};

class WorkshopFactory : public EventFactory 
{
public:
    std::unique_ptr<Event> createEvent() override;// Implementation to create a Workshop event
};

class ConcertFactory : public EventFactory 
{
public:
    std::unique_ptr<Event> createEvent() override;// Implementation to create a Concert event
};

class ConferenceFactory : public EventFactory 
{
public:
    std::unique_ptr<Event> createEvent() override;// Implementation to create a Conference event
};