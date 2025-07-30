int BUT1 = 1;
int BUT2 = 2;
int BUT3 = 3;
int BUT4 = 8;
int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
int LED4 = 7;

bool button1state = false;
bool button2state = false;
bool button3state = false;
bool button4state = false;

int lightOn = 0;
int score = 0;
    
void setup() {
    pinMode(BUT1, INPUT_PULLUP);
    pinMode(BUT2, INPUT_PULLUP);
    pinMode(BUT3, INPUT_PULLUP);
    pinMode(BUT4, INPUT_PULLUP);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);

    //idk if functions like this would work in setup(), research on that
    lightsOff();

    long startTime = millis();
    int prevTime = millis();
    int currentTime = millis();
}

void loop() {
    button1state = digitalRead(BUT1);
    button2state = digitalRead(BUT2);
    button3state = digitalRead(BUT3);
    button4state = digitalRead(BUT4);
    if(button1state && button2state && button3state && button4state){
        flickerLight();
        delay(100);
        game();
        delay(100);
        flickerLight();
        delay(100);
        showScore();
        delay(100);
    }
}

void lightsOff(){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
}

void showScore(){
    //mabye show score in binary?
}

//check int vs long storage
long gameDuration = 60000;
long lightDuration = 500; //duration tbd
void game(){
    long gameStartTime = millis();
    long prevLight = millis();
    //ideally random light on 500, lights off 500? how to do that
    while((currentTime-gameStartTime)<gameDuration){
        button1state = digitalRead(BUT1);
        button2state = digitalRead(BUT2);
        button3state = digitalRead(BUT3);
        button4state = digitalRead(BUT4);
        //game code
        //use the randomLight function
        currentTime=millis();
    }
}

void randomLight(){
    //random light on?
    //and change the lightOn variable
    lightOn = randInt(1,5);
    switch case
}

int flickerInterval = 100;
void flickerLight() {
    prevTime = millis();
    for(int i = 0; i < 12; i++){
        lightsOff();
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