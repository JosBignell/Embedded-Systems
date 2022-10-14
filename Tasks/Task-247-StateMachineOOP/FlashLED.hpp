#include "mbed.h"
#include <chrono>
using namespace std::chrono;

class FlashLED {
private:
    enum {off, on} _state;
    Timer _tmr;
    DigitalOut _led;
    microseconds _duration = 0ms;
    microseconds _currenttime = 0ms;

public:
    FlashLED(PinName pin, microseconds duration) : _led(pin), _duration(duration) {
        _tmr.start();
        _led = 0;
    }

    void start() {
        _tmr.start();
    }

    void stop() {
        _tmr.stop();
    }

    void readInputs() {
        _currenttime = _tmr.elapsed_time();
    }

    void updateState() {
        if (_currenttime >= _duration) {
            _led = !_led;
            _tmr.reset();
            _currenttime = 0ms;
        }
    }


};
