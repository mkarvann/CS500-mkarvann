#include "user.h"
#include <iostream>
#include <vector>
#include <string>

// Set the user's name and email

User::User(const std::string &cUserName, const std::string &cEmail)
{ 
    userName= cUserName; 
    email= cEmail;
}

void User::setUserName(const std::string &cUserName) 
{
    this->userName = cUserName;
}

void User::setEmail(const std::string &cEmail) 
{
    this->email = cEmail;
}

std::string User::getUserName() const 
{
    return userName;
}

std::string User::getEmail() const 
{
    return email;
}

void User::addFriend(User* friendUser) 
{
    if (friendList.size() < 100 && friendUser != nullptr) 
    {
        for (User* user : friendList) 
        {
            if (user == friendUser) 
            {
                return; 
            }
        }
        friendList.push_back(friendUser);
    }
}


void User::removeFriend(const std::string& friendUserName) 
{
    for (size_t i = 0; i < friendList.size(); ++i) 
    {
        if (friendList[i]->getUserName() == friendUserName) 
        {
            friendList.erase(friendList.begin() + i);
            return;
        }
    }
}


int User::numFriends() const 
{
    return friendList.size();
}


User* User::getFriendAt(int index) const {
    if (index >= 0 && index < numFriends()) {
        return friendList[index];
    }
    return nullptr; 
}
