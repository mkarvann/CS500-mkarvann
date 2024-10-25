#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) 
{
    if (start == nullptr) return false;
    
    bool hasSpellbook = false, hasPotion = false, hasWand = false;
    MazeCell* current = start;
    
    // Check initial cell for an item
    if (current->whatsHere == Item::SPELLBOOK) 
    {
        hasSpellbook = true;
    }
    if (current->whatsHere == Item::POTION) 
    {
        hasPotion = true;
    }
    if (current->whatsHere == Item::WAND)
    {
        hasWand = true;
    }
    // Process the move string
    for (char move : moves) 
    {
        if (move == 'N' && current->north != nullptr) 
        {
            current = current->north;
        } 
        else if (move == 'S' && current->south != nullptr) 
        {
            current = current->south;
        } 
        else if (move == 'E' && current->east != nullptr) 
        {
            current = current->east;
        } 
        else if (move == 'W' && current->west != nullptr) 
        {
            current = current->west;
        } 
        else 
        {            
            return false;
        }
        
        // Check for items in the new cell
        if (current->whatsHere == Item::SPELLBOOK) hasSpellbook = true;
        if (current->whatsHere == Item::POTION) hasPotion = true;
        if (current->whatsHere == Item::WAND) hasWand = true;
    }

    // Check if all items were collected
    return hasSpellbook && hasPotion && hasWand;
}
