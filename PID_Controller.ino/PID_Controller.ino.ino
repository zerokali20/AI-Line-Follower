// PID Line Follower Robot - Arduino Code

// Define motor pins
#define LEFT_MOTOR_FORWARD  5
#define LEFT_MOTOR_BACKWARD 6
#define RIGHT_MOTOR_FORWARD 9
#define RIGHT_MOTOR_BACKWARD 10

// Define IR sensor pins
#define SENSOR_COUNT 5
const int sensorPins[SENSOR_COUNT] = {A0, A1, A2, A3, A4};

// PID Constants (Tune these values)
float Kp = 2.5;  // Proportional Gain
float Ki = 0.0;  // Integral Gain (set to 0 initially)
float Kd = 1.2;  // Derivative Gain

// PID Variables
float lastError = 0, integral = 0;
int baseSpeed = 100;  // Adjust motor speed

void setup() {
    Serial.begin(9600);  // Debugging output
    pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
    pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
    pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
    pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
    
    for (int i = 0; i < SENSOR_COUNT; i++) {
        pinMode(sensorPins[i], INPUT);
    }
}

void loop() {
    int position = readSensors();  // Get position from IR sensors
    float error = position - 2;    // Centered around middle sensor
    integral += error;              // Sum of past errors
    float derivative = error - lastError;  // Change in error
    lastError = error;              // Store last error

    // PID calculation
    float correction = (Kp * error) + (Ki * integral) + (Kd * derivative);

    // Adjust motor speeds
    int leftSpeed = baseSpeed - correction;
    int rightSpeed = baseSpeed + correction;

    // Debugging: Print motor speed values
    Serial.print("Left Speed: ");
    Serial.print(leftSpeed);
    Serial.print("\tRight Speed: ");
    Serial.println(rightSpeed);

    moveMotors(leftSpeed, rightSpeed);
}

// Function to read IR sensors and determine position
int readSensors() {
    int weightedSum = 0, total = 0;
    for (int i = 0; i < SENSOR_COUNT; i++) {
        int sensorValue = digitalRead(sensorPins[i]) ? 1 : 0;
        weightedSum += sensorValue * i;
        total += sensorValue;
    }
    int position = (total > 0) ? (weightedSum / total) : 2;  // Default to center
    Serial.print("Sensor Position: ");
    Serial.println(position);  // Debugging: Print sensor position
    return position;
}

// Function to move motors
void moveMotors(int leftSpeed, int rightSpeed) {
    leftSpeed = constrain(leftSpeed, 0, 255);
    rightSpeed = constrain(rightSpeed, 0, 255);

    analogWrite(LEFT_MOTOR_FORWARD, leftSpeed);
    analogWrite(RIGHT_MOTOR_FORWARD, rightSpeed);
}
