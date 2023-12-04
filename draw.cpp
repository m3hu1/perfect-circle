#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

#include <ApplicationServices/ApplicationServices.h>

using namespace std;

void thSleep(long millis) {
    this_thread::sleep_for(chrono::milliseconds(millis));
}

void mouseMove(double x, double y) {
    CGEventRef event = CGEventCreateMouseEvent(
            nullptr, kCGEventMouseMoved,
            CGPointMake(x, y),
            kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, event);
    CFRelease(event);
}

void mouseClickDown(double x, double y) {
    CGEventRef event = CGEventCreateMouseEvent(
            nullptr, kCGEventLeftMouseDown,
            CGPointMake(x, y),
            kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, event);
    CFRelease(event);
}

void mouseClickUp(double x, double y) {
    CGEventRef event = CGEventCreateMouseEvent(
            nullptr, kCGEventLeftMouseUp,
            CGPointMake(x, y),
            kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, event);
    CFRelease(event);
}

int main(int argc, char** argv) {
    int steps = 1000;
    int sleepTime = 5;
    int waitTime = 5000;
    int radius = 400;

    if (argc > 1) {
        for (int i = 1; i < argc; i += 2) {
            if (strcmp(argv[i], "-steps") == 0) {
                steps = atoi(argv[i + 1]);
            } else if (strcmp(argv[i], "-sleep") == 0) {
                sleepTime = atoi(argv[i + 1]);
            } else if (strcmp(argv[i], "-wait") == 0) {
                waitTime = atoi(argv[i + 1]);
            } else if (strcmp(argv[i], "-r") == 0) {
                radius = atoi(argv[i + 1]);
            }
        }
    }

    thSleep(waitTime);
    CGEventRef event = CGEventCreate(nullptr);
    CGPoint cursor = CGEventGetLocation(event);
    CFRelease(event);
    double x, y, xc = cursor.x, yc = cursor.y;
    mouseMove(xc + radius, yc);
    mouseClickDown(xc + radius, yc);
    for (double angle = 0; angle < M_PI * 2; angle += (M_PI * 2) / steps) {
        x = cos(angle) * radius;
        y = sin(angle) * radius;
        mouseMove(xc + x, yc + y);
        thSleep(sleepTime);
    }
    mouseClickUp(xc + x, yc + y);

    return 0;
}
