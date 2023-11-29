#ifndef MIDI_HPP
#define MIDI_HPP
#include "libremidi/libremidi.hpp"

struct Note
{
    int pitch;
    double triggered_on;
};


class MIDI
{
private:
    libremidi::midi_out midiout;
    std::vector<Note> notes = {
        {60, 0.0},
        {64, 0.0},
        {67, 0.0},
        {68, 0.0},
        {72, 0.0},
    };
    unsigned long current_note = 0;
    int current_beat = 0;
    static int time_to_beat(double t);

public:
    void play_next_note(double t);
    MIDI();
    ~MIDI();
};


#endif //MIDI_HPP
