// #include <AccelStepper.h>

#define potPin 1  // P2
#define ledPin 1
#define buttonPin 3
#define stepPin 4  // One in
#define dirPin 5   // Corner
#define motorInterfaceType 1
#define stepsPerRevolution 200

int val = 200;
bool override = true;
bool bdown = false;

// AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);

    // stepper.setMaxSpeed(1000);

    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void loop() {
    if (digitalRead(buttonPin) == LOW) {
        if (!bdown) {
            override = !override;
            bdown = true;
        }
    } else {
        bdown = false;
    }

    digitalWrite(ledPin, override);
    // val = map(analogRead(potPin), 0, 1023, -5, 5);
    // val *= 100;
    // val += (val >= 0) ? 100 : -100;

    // stepper.setSpeed(override ? 200 : val);
    // stepper.runSpeed();

    // Set the spinning direction clockwise:
    digitalWrite(dirPin, HIGH);

    // Spin the stepper motor 1 revolution slowly:
    for (int i = 0; i < stepsPerRevolution; i++) {
        // These four lines result in 1 step:
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2000);
    }

    delay(1000);

    // // Set the spinning direction counterclockwise:
    // digitalWrite(dirPin, LOW);

    // // Spin the stepper motor 1 revolution quickly:
    // for (int i = 0; i < stepsPerRevolution; i++) {
    //     // These four lines result in 1 step:
    //     digitalWrite(stepPin, HIGH);
    //     delayMicroseconds(1000);
    //     digitalWrite(stepPin, LOW);
    //     delayMicroseconds(1000);
    // }

    // delay(1000);

    // // Set the spinning direction clockwise:
    // digitalWrite(dirPin, HIGH);

    // // Spin the stepper motor 5 revolutions fast:
    // for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    //     // These four lines result in 1 step:
    //     digitalWrite(stepPin, HIGH);
    //     delayMicroseconds(500);
    //     digitalWrite(stepPin, LOW);
    //     delayMicroseconds(500);
    // }

    // delay(1000);

    // // Set the spinning direction counterclockwise:
    // digitalWrite(dirPin, LOW);

    // // Spin the stepper motor 5 revolutions fast:
    // for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    //     // These four lines result in 1 step:
    //     digitalWrite(stepPin, HIGH);
    //     delayMicroseconds(500);
    //     digitalWrite(stepPin, LOW);
    //     delayMicroseconds(500);
    // }

    // delay(1000);
}