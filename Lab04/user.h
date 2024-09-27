#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User 
{
    // Stores the user's name, email address, friends
private:
    std::string userName;
    std::string email;
    std::vector<User*> friendList;


public:
    // Constructor Initializes User object with a username and email
    User(const std::string& cUserName, const std::string& cEmail);
    // Setters: Methods to set the username and email
    void setUserName(const std::string& cUserName);
    void setEmail(const std::string& cEmail);

    // Getters: Methods to retrieve the username and email
    std::string getUserName() const;
    std::string getEmail() const;

    // Add a friend to the vector
    void addFriend(User* friendUser);

    // Remove a friend by username
    void removeFriend(const std::string& friendUserName);

    // Number of friends
    int numFriends() const;

    // Returns a pointer to a friend at a specific index in the friend list
    User* getFriendAt(int index) const;
};

#endif 
