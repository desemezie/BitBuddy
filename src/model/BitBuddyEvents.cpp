//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/BitBuddyEvents.h"

#include "model/SingleAttributeEvent.h"

const std::vector<SingleAttributeEvent> PREDEFINED_EVENTS = {
    SingleAttributeEvent(-1, BitBuddyAttribute::HUNGER, 0.7, "BitBuddy's stomach rumbles loudly."),
    SingleAttributeEvent(-1, BitBuddyAttribute::HAPPINESS, 0.4, "BitBuddy seems a bit withdrawn."),
    SingleAttributeEvent(-1, BitBuddyAttribute::THIRST, 0.6, "BitBuddy looks desperately thirsty."),
    SingleAttributeEvent(-1, BitBuddyAttribute::HEALTH, 0.2, "BitBuddy doesn't seem to be feeling well."),
    SingleAttributeEvent(-1, BitBuddyAttribute::TIREDNESS, 0.5, "BitBuddy's eyelids are drooping."),
    SingleAttributeEvent(-1, BitBuddyAttribute::BOREDOM, 0.5, "BitBuddy lets out a big yawn."),
    SingleAttributeEvent(-1, BitBuddyAttribute::HYGIENE, 0.3, "BitBuddy could use a bath.")
};
