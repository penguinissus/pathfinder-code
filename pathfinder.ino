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
    //starts game when all 4 buttons pressed
    if(button1state && button2state && button3state && button4state){
        flickerLight();
        delay(1000);
        game();
        delay(1000);
        flickerLight();
        delay(1000);
        showScore();
        score = 0;
        delay(1000);
        flickerLight();
    }
}

void showScore(){
    if(score>9999){
        for(int i = 0; i<3, i++){
            digitalWrite(LED1, HIGH);
            digitalWrite(LED2, HIGH);
            digitalWrite(LED3, HIGH);
            digitalWrite(LED4, HIGH);
            delay(500);
        lightsOff();
        delay(150);
        }
    } else {
        while(score!=0){
            while((score%10)!=0){
                digitalWrite(LED4, HIGH);
                delay(200);
                digitalWrite(LED4, LOW);
                delay(200);
                score--;
            }
            score/=10;
        }
    }
}

int gameDuration = 60000;
int lightOnDuration = 500;
unsigned long prevLight = 0;
unsigned long gameStartTime = 0;
void game(){
    gameStartTime = millis();
    prevLight = -500;
    lightOn = 0;
    score = 0;
    lightOnDuration = 1000;
    bool stage1passed = false;
    bool stage2passed = false;
    bool stage3passed = false;
    while((currentTime-gameStartTime)<gameDuration){
        currentTime = millis();
        button1state = digitalRead(BUT1);
        button2state = digitalRead(BUT2);
        button3state = digitalRead(BUT3);
        button4state = digitalRead(BUT4);

        if((currentTime-prevLight)>lightOnDuration){
            randomLight();
            prevLight = millis();
        }
        if((currentTime-prevLight)>(lightOnDuration*2)){
            lightsOff();
            lightOn = 0;
        }

        //increasingly fast light speed
        if((currentTime-gameStartTime>15000) && !stage1passed){
            lightOnDuration/=2;
            stage1passed = true;
        }
        if((currentTime-gameStartTime>30000) && !stage2passed){
            lightOnDuration/=2;
            stage2passed = true;
        }
        if((currentTime-gameStartTime>45000) && !stage3passed){
            lightOnDuration/=2;
            stage3passed = true;
        }

        //check buttons pressed
        if ((button1state && !(button2state || button3state || button4state) && lightOn==1) || (button2state && !(button1state || button3state || button4state) && lightOn = 2) || (button3state && !(button1state || button2state || button4state) && lightOn==3) || (button4state && !(button1state || button2state || button3state) && lightOn==4)){
            score++;
        }
    }
}

void randomLight(){
    lightsOff();
    lightOn = randInt(1,5);
    switch(lightOn) {
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
}

int flickerInterval = 100;
void flickerLight() {
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
        delay(100);
    }
}

void lightsOff(){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
}