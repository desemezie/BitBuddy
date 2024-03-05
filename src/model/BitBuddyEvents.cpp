//
// Created by Ryan Hecht  on 2024-03-04.
//

#include "model/BitBuddyEvents.h"

#include "model/SingleAttributeEvent.h"

const std::vector<SingleAttributeEvent> PREDEFINED_EVENTS = {
    SingleAttributeEvent(-1, BitBuddyAttributeName::HUNGER, 0.7, "BitBuddyWidget's stomach rumbles loudly."),
    SingleAttributeEvent(-1, BitBuddyAttributeName::HAPPINESS, 0.4, "BitBuddyWidget seems a bit withdrawn."),
    SingleAttributeEvent(-1, BitBuddyAttributeName::THIRST, 0.6, "BitBuddyWidget looks desperately thirsty."),
    SingleAttributeEvent(-1, BitBuddyAttributeName::HEALTH, 0.2, "BitBuddyWidget doesn't seem to be feeling well."),
    SingleAttributeEvent(-1, BitBuddyAttributeName::TIREDNESS, 0.5, "BitBuddyWidget's eyelids are drooping."),
    SingleAttributeEvent(-1, BitBuddyAttributeName::BOREDOM, 0.5, "BitBuddyWidget lets out a big yawn."),
    SingleAttributeEvent(-1, BitBuddyAttributeName::HYGIENE, 0.3, "BitBuddyWidget could use a bath.")
};
