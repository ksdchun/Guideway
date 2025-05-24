// Define motor control pins
const int ENA = 10;  // PWM pin for speed control
const int IN1 = 8;   // Direction control pin 1
const int IN2 = 9;   // Direction control pin 2

char command = '0';  // Default state: motor stopped
int motorSpeed = 0;  // Default speed: stopped

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    Serial.begin(9600);
    Serial.println("Arduino ready!");
}

void loop() {
    // Check if data is available from Python
    if (Serial.available() > 0) {
        // Read the incoming string until newline
        String data = Serial.readStringUntil('\n');
        
        // Parse command and speed (format: "command:speed")
        int colonIndex = data.indexOf(':');
        if (colonIndex != -1) {
            String cmdStr = data.substring(0, colonIndex);
            String speedStr = data.substring(colonIndex + 1);
            
            command = cmdStr.charAt(0);
            motorSpeed = speedStr.toInt();
            
            Serial.print("Received command: ");
            Serial.print(command);
            Serial.print(", speed: ");
            Serial.println(motorSpeed);
        }
        else {
            // Handle old format (just command, no speed)
            command = data.charAt(0);
            Serial.print("Received legacy command: ");
            Serial.println(command);
            
            // Use default speeds for legacy commands
            if (command == '1') {
                motorSpeed = 255;  // Full speed for ON command
            } 
            else if (command == '0') {
                motorSpeed = 0;    // Zero speed for OFF command
            }
        }
    }

    // Run motor at specified speed when "1", stop when "0"
    if (command == '1') {
        driveMotor(motorSpeed, 1);  // Forward at specified speed
    } 
    else if (command == '0') {
        driveMotor(0, 0);           // Stop motor
    }
}

void driveMotor(int speed, bool direction) {
    // Ensure speed is in the valid range
    speed = constrain(speed, 0, 255);
    
    analogWrite(ENA, speed);
    if (direction) {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
    } 
    else {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
    }
}
