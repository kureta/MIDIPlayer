#include "Midi.h"

#include <cmath>

MIDI::MIDI()
{
    midiout.open_virtual_port();
}

MIDI::~MIDI()
{
    // Note Off: 128, 64, 40
    midiout.send_message(128, notes[current_note], 40);
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
    using namespace std::literals;

    const int beat = time_to_beat(t);

    if (beat != current_beat)
    {
        const int next_note = (current_note + 1) % notes.size();
        // Note Off: 128, 64, 40
        midiout.send_message(128, notes[current_note], 40);

        // Note On: 144, 64, 90
        midiout.send_message(144, notes[next_note], 90);
        current_note = next_note;
        current_beat += 1;
    }
}
