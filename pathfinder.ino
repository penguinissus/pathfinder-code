int BUT1 = 26;
int BUT2 = 27;
int BUT3 = 28;
int BUT4 = 1;
int LED1 = 29;
int LED2 = 6;
int LED3 = 7;
int LED4 = 0;

bool light1 = false;
bool light2 = false;
bool light3 = false;
bool light4 = false;
    
void setup() {
    pinMode(BUT1, INPUT_PULLUP);
    pinMode(BUT2, INPUT_PULLUP);
    pinMode(BUT3, INPUT_PULLUP);
    pinMode(BUT4, INPUT_PULLUP);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);

    long startTime = millis();
    int prevTime = millis();
    int currentTime = millis();
}

void loop() {
    if(){
        //if all buttons pressed at the same time, start game
    }
    flickerLight();
    game();
    flickerLight();
}

void game(){
    //game
}

int flickerInterval = 100;
void flickerLight() {
    prevTime = millis();
    for(int i = 0; i < 12; i++){
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        switch((i%4)+1){
            case 1:
                digitalWrite(LED1, HIGH);
                break;
            case 2:
                digitalWrite(LED2, HIGH);
                break;
            case 3:
                digitalWrite(LED3, HIGH);
                break;
            case 4:
                digitalWrite(LED4, HIGH);
                break;            
        }
        currentTime = millis();
        while((currentTime-prevTime)<flickerInterval){
            currentTime = millis();
        }
        prevTime = millis();
    }
}