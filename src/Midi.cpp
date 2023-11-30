#include "Midi.h"

#include <cmath>

MIDI::MIDI()
{
    midiout.open_virtual_port();
}

MIDI::~MIDI()
{
    for (const Note item : notes)
    {
        // Note Off: 128, 64, 40
        midiout.send_message(128, item.pitch, 40);
    }
}

int MIDI::time_to_beat(double t)
{
    const int beat = std::floor(t);
    return beat;
}

// TODO: push notes into a queue and pop them off as they are played
// play each note for a constant duration.
void MIDI::play_next_note(double t)
{
    // Note On: 144, 64, 90
    midiout.send_message(144, notes[current_note].pitch, 90);
    notes[current_note].triggered_on = t;
    current_note = (current_note + 1) % notes.size();
}

void MIDI::update(const double t)
{
    for (const auto [pitch, triggered_on] : notes)
    {
        if (t >= triggered_on + 0.5)
        {
            // Note Off: 128, 64, 40
            midiout.send_message(128, pitch, 40);
        }
    }
}
