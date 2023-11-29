#ifndef MIDI_HPP
#define MIDI_HPP
#include "libremidi/libremidi.hpp"


class MIDI
{
private:
    libremidi::midi_out midiout;
    std::vector<uint8_t> notes = {64, 66, 68, 70, 72, 74, 76, 78};
    unsigned long current_note = 0;
    int current_beat = 0;
    static int time_to_beat(double t);

public:
    void play_next_note(double t);
    MIDI();
    ~MIDI();
};


#endif //MIDI_HPP
