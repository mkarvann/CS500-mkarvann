#pragma once
#include <string>
#include <vector>
#include <set>
#include <memory>

class Event
{
    public:
        Event (const std::string &name, const std::string &date, const std::string &location, const std::set<std::string> &attendee) 
            : eventName(name), eventDate(date), eventLocation(location), attendees(attendee){}
        virtual std::string getDetails() const = 0; // Pure virtual function, must be implemented in derived classes
        bool isUpcoming() const;
        std::string getName() const;
        std::string getDate() const;
        std::string getLocation() const;
        void addAttendee(const std::string &attendee);
        void removeAttendee(const std::string &attendee);
        bool isAttending(const std::string &attendee) const;
        size_t getAttendeeCount() const ;
        const std::set<std::string>& getAttendees() const { return attendees; }

    
    protected:
        std::string eventName;// Name of the event
        std::string eventDate;// Date of the event
        std::string eventLocation;// Location of the event
        std::set<std::string> attendees;// Set of attendees
};

class Workshop : public Event
{
    public:
        Workshop(const std::string &name, const std::string &date, const std::string &location, int duration, const std::string &instructor)
            : Event(name, date, location,std::set<std::string>()), duration(duration), instructor(instructor) {}
        
        std::string getDetails() const override; // Implementation specific to Workshop

    private:
        int duration;
        std::string instructor;
};

class Concert : public Event 
{
    public:
        Concert(const std::string &name, const std::string &date, const std::string &location, const std::string &bandName, const std::string &genre)
            : Event(name, date, location, std::set<std::string>()), bandName(bandName), genre(genre) {}
        
        std::string getDetails() const override;

    private:
        std::string bandName;
        std::string genre;
};

class Conference : public Event 
{
    public:
        Conference(const std::string &name, const std::string &date, const std::string &location, const std::vector<std::string> &speakers, const std::vector<std::string> &topics)
            : Event(name, date, location, std::set<std::string>()), speakers(speakers), topics(topics) {}
        
        std::string getDetails() const override;

    private:
        std::vector<std::string> speakers;
        std::vector<std::string> topics;
};