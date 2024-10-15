#include "search_strategy.h"
#include <cctype>
#include <algorithm>

bool iequals(const std::string& a, const std::string& b) {
    return std::equal(a.begin(), a.end(), b.begin(), b.end(),
                      [](char a, char b) {
                          return std::tolower(a) == std::tolower(b);
                      });
}

bool DateSearchStrategy::match(const std::shared_ptr<Event>& event, const std::string& criteria) const {
    return event->getDate() == criteria;
}

bool LocationSearchStrategy::match(const std::shared_ptr<Event>& event, const std::string& criteria) const {
    return iequals(event->getLocation(), criteria);
}

bool TypeSearchStrategy::match(const std::shared_ptr<Event>& event, const std::string& criteria) const {
    if (iequals(criteria, "workshop")) {
        return dynamic_cast<Workshop*>(event.get()) != nullptr;
    } else if (iequals(criteria, "concert")) {
        return dynamic_cast<Concert*>(event.get()) != nullptr;
    } else if (iequals(criteria, "conference")) {
        return dynamic_cast<Conference*>(event.get()) != nullptr;
    }
    return false;
}