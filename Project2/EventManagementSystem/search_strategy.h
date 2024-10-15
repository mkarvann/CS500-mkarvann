#pragma once
#include "event.h"
#include <memory>
#include <string>

class SearchStrategy {
public:
    virtual ~SearchStrategy() = default;
    virtual bool match(const std::shared_ptr<Event>& event, const std::string& criteria) const = 0;
};

class DateSearchStrategy : public SearchStrategy {
public:
    bool match(const std::shared_ptr<Event>& event, const std::string& criteria) const override;
};

class LocationSearchStrategy : public SearchStrategy {
public:
    bool match(const std::shared_ptr<Event>& event, const std::string& criteria) const override;
};

class TypeSearchStrategy : public SearchStrategy {
public:
    bool match(const std::shared_ptr<Event>& event, const std::string& criteria) const override;
};