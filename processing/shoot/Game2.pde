import java.util.ArrayList;

class Bullet{
    String imgPath;
    int SIZE = 30;
    int offset = 5;
    int damage = 20;
    PImage img;
    float px,py;
    float offsetX,offsetY;
    boolean exist;
    Bullet(int x,int y,int targetX,int targetY) {
        px = x + 10;
        py = y + 10;
        imgPath = "bullet.png";
        img = loadImage(imgPath);
        exist = true;
        
        float d = dist(px,py,targetX,targetY);
        offsetX = -(px - targetX) / d * offset;
        offsetY = -(py - targetY) / d * offset;
        
        
    }
    
    void display() {
        image(img,px,py);
    }
    void move() {
        px += offsetX;
        py += offsetY;
    }
};

class Creature{
    int px,py;
    int health;
    int walkSpeed;
    PImage[] imgs;
    int imgIndex;
    
    Creature() {}
    
    void setImagePath(String[] paths) {
        imgs = new PImage[3];
        for (int i = 0;i < 3;i++) {
            imgs[i] = loadImage(paths[i]);
        }
        imgIndex = 0;
    }
    
    void setPos(int x,int y) {
        px = x;
        py = y;
        health = 100;
        walkSpeed = 5;
    }
    
    void display() {
        if (health > 0) {
            image(imgs[imgIndex],px,py);
            int width = health / 2;
            noStroke();
            fill(255,0,0);
            rect(px, py - 8, width, 10);
        }
    }
    
    void debug() {
        System.out.println(px + " " + py + " ");
    }
    void move() {
        
    }
};

class Monster extends Creature{
    int damage = 10;
    Monster() {
        walkSpeed = 5;
    }
    void move(int x,int y) {
        // println(frameCount + " " + frameRate + " " + frameCount % frameRate);
        if (frameCount % (int)(frameRate / 10) ==  0) {
            int xD = px - x;
            int yD = py - y;
            //X distanceY >distance
            if (abs(xD)>abs(yD)) {
                if (xD > 0) {
                    px -= walkSpeed;
                } else{
                    px += walkSpeed;
                }
            } else{
                if (yD > 0) {
                    py -= walkSpeed;
                } else{
                    py += walkSpeed;
                }
            }
            if (imgIndex > 1) {
                imgIndex = 0;
            } else{
                imgIndex++;
            }
        }
        
    }
}

class Humen extends Creature{
    boolean lastState;
    boolean currentState;
    Humen() {
        lastState = false;
        currentState = false;
    }
    
    void display() {
        if (health > 0) {
            image(imgs[imgIndex],px,py);
            int width = health / 2;
            noStroke();
            fill(0,255,0);
            rect(px - 2, py - 8, width, 10);
        }
    }
    
    void setImagePath(String[] paths) {
        imgs = new PImage[5];
        for (int i = 0;i < 5;i++) {
            imgs[i] = loadImage(paths[i]);
        }
        imgIndex = 0;
    }
    
    void move() {
        if (keyPressed) {
            //X Coords
            if (key ==  'w' ||  key ==  'W' ||  key ==  's' ||  key ==  'S') {
                if (key ==  'w' ||  key ==  'W') {
                    h.py -= h.walkSpeed;
                }
                if (key ==  's' ||  key ==  'S') {
                    h.py += h.walkSpeed;
                }
                //Use walk image
                if (frameCount % (int)(frameRate / 10) ==  0) {
                    if (imgIndex ==  0 ||  imgIndex ==  2) {
                        imgIndex = 1;
                    } else {
                        imgIndex = 2;
                    }
                }
                
            }
            if (key ==  'a' ||  key ==  'A' ||  key ==  'd' ||  key ==  'D') {
                if (key ==  'a' ||  key ==  'A') {
                    h.px -= h.walkSpeed;
                }
                if (key ==  'd' ||  key ==  'D') {
                    h.px += h.walkSpeed;
                } 
                if (frameCount % (int)(frameRate / 10) ==  0) {
                    //Use walk image
                    if (imgIndex == 0  ||  imgIndex ==  3) {
                        imgIndex = 4;
                    } else {
                        imgIndex = 3;
                    }
                } 
            }
            
            //Movement control:In the map
            if (px < 0) {
                px = 0;
            } else if (px > 600 - 50) {
                px = 600 - 50;
            }
            if (py < 0) {
                py = 0;
            } else if (py > 800 - 50) {
                py = 800 - 50;
            }
        } else{ //Not moving
            //Use standing image
            imgIndex = 0;
        }
    }
    void move(int d) {
        if (d!= 0) {
            //X Coords
            if (d!= 7 &&  d!= 3) {
                if (d ==  8 ||  d ==  1 ||  d ==  2) {
                    h.py -= h.walkSpeed;
                }
                if (d ==  6 ||  d ==  5 ||  d ==  4) {
                    h.py += h.walkSpeed;
                }
                //Use walk image
                if (frameCount % (int)(frameRate / 10) ==  0) {
                    if (imgIndex ==  0 ||  imgIndex ==  2) {
                        imgIndex = 1;
                    } else {
                        imgIndex = 2;
                    }
                }
                
            }
            if (d!= 1 &&  d!= 5) {
                if (d ==  8 ||  d ==  7 ||  d ==  6) {
                    h.px -= h.walkSpeed;
                }
                if (d ==  2 ||  d ==  3 ||  d ==  4) {
                    h.px += h.walkSpeed;
                } 
                if (frameCount % (int)(frameRate / 10) ==  0) {
                    //Use walk image
                    if (imgIndex == 0  ||  imgIndex ==  3) {
                        imgIndex = 4;
                    } else {
                        imgIndex = 3;
                    }
                } 
            }
            
            //Movement control:In the map
            if (px < 0) {
                px = 0;
            } else if (px > 600 - 50) {
                px = 600 - 50;
            }
            if (py < 0) {
                py = 0;
            } else if (py > 800 - 50) {
                py = 800 - 50;
            }
        } else{ //Not moving
            //Use standing image
            imgIndex = 0;
        }
    }
    void debug() {
        System.out.println(h.health);
    }
    
    boolean isFire() {
        
        boolean result;
        if (mousePressed && (mouseButton == LEFT)) {
            currentState = true;
        } else{
            currentState = false;
        }
        if (!lastState &&  currentState) {
            result = true;
        } else{
            result = false;
        }
        lastState = currentState;
        return result ||  frameCount % (int)(frameRate / 5) ==  0;
    }
}  

int getGameState() {
    if (keyPressed&&key==' ') {
      if (h.health > 0) {
          level++;
          return 1;
      } else{ //Humen dead go back to first level
          level = 1;
          return - 1;
      }   
    }
    return gameState;
}

// GlobalVar
ArrayList<Monster> monsters = new ArrayList<Monster>();
ArrayList<Bullet> bullets = new ArrayList<Bullet>();
String[][] monsterPaths = new String[2][3];
PImage menu,press,win,lose;
Humen h;
Monster m;
Monster closest;
Bullet b;
float closestDistance;
int gameState; // -1 Reset 0 Not decide 1 NextRound
int level;
static int X = 600;
static int Y = 800;
int monsterNumber; //How many monsters in current round
int checkHealthIndex; //check monster in monster list isdead or not
int checkBulletIndex;
int t;

Monster addMonster() {
    m = new Monster();
    int choice = (int)random(0,2); //Which monster
    m.setImagePath(monsterPaths[choice]);
    int px = (int)random(0, X - 50);
    int py = (int)random(Y - 50);
    //Prevent distance to give the change which humen run or fire
    while(dist(h.px,h.py,px,py)<150) {
        px = (int)random(0, X - 50);
        py = (int)random(Y - 50);
    }
    m.setPos(px,py);
    return m;
}

void init() {
    gameState = 1;
    monsters.clear();
    bullets.clear();
    for (int i = 0;i < monsterNumber;i++) {
        monsters.add(addMonster());
    }
    //Heal Humen
    h.health = 100;
}

void setup() {
    frameRate(60);
    size(600,800);
    background(255);
    
    
    h = new Humen();
    String[] humenPath = {"human_stand.png","human_walk1.png","human_walk2.png","human_walk1_l.png","human_walk2_l.png"};
    h.setImagePath(humenPath);
    h.setPos((int)random(0, 600 - 50),(int)random(800 - 50));    
    
    //Set the monsters image path
    monsterPaths[0][0] = "monster_1_stand.png";
    monsterPaths[0][1] = "monster_1_walk1.png";
    monsterPaths[0][2] = "monster_1_walk2.png";
    monsterPaths[1][0] = "monster_2_stand.png";
    monsterPaths[1][1] = "monster_2_walk1.png";
    monsterPaths[1][2] = "monster_2_walk2.png";
    
    menu = loadImage("menu.jpg");
    press = loadImage("press.png");
    lose = loadImage("lose.jpg");
    win = loadImage("win.jpg");
    
    //Initial the game
    monsterNumber = 1;
    init();
    gameState =-  2;//Show menu
    t = 0;
    level = 1;
}

void draw() {
    // Still have monster(Battle is not finished)
    if (gameState ==  1) {
        tint(255, 255);
        background(255);
        fill(0);
        textSize(20);
        text("Level: " + level + "  Monster left: " + monsters.size(),2,20);
        h.display();
        
        // Check the monsterlist for removing dead monster
        checkHealthIndex = 0;
        while(checkHealthIndex <  monsters.size()) {
            m = monsters.get(checkHealthIndex);
            if (m.health <=  0) {
                monsters.remove(checkHealthIndex);
                continue;
            } else{
                checkHealthIndex++;
            }
        }
        
        //Draw monster
        for (int i = 0;i < monsters.size();i++) {
            m = monsters.get(i);
            m.display();
            //Detect if monster hit humen or not
            if (dist(h.px,h.py,m.px,m.py)<50.0) {
                m.health = 0;
                h.health -= m.damage;
            } else{ //Move monster more close to the humen
                m.move(h.px,h.py);
            }
        }
        
        //Step2:Move Humen
        h.move();
        
        // Step3: Fire 
        if (h.isFire()) {
            try {
                if (monsters.size()>0) {
                    //Find first not dead monster
                    checkHealthIndex = 0;
                    while(checkHealthIndex!= monsters.size()) {
                        m = monsters.get(checkHealthIndex);
                        if (m.health > 0) {
                            break;
                        }
                        checkHealthIndex++;
                    }
                    
                    closest = monsters.get(checkHealthIndex);
                    closestDistance = dist(h.px,h.py,closest.px,closest.py);
                    //Find cloesest Monster
                    for (int i = checkHealthIndex;i < monsters.size();i++) {
                        m = monsters.get(i);
                        if (m.health > 0) {
                            float d = dist(h.px + 10,h.py + 10,m.px + 10,m.py + 10);
                            if (d < closestDistance) {
                                closest = m;
                                closestDistance = d;
                            }
                        }
                    }
                    bullets.add(new Bullet(h.px,h.py,closest.px,closest.py));
                }   
            } catch(Exception e) {
                
            }
        }
        
        //Draw bullet
        for (int i = 0;i < bullets.size();i++) {
            b = bullets.get(i);
            b.display();
            b.move();
        }
        
        // Check bullet is hit any monster or not
        checkBulletIndex = 0;
        while(checkBulletIndex!= bullets.size()) {
            b = bullets.get(checkBulletIndex);
            //Check hit monster or not
            for (int i = 0;i < monsters.size();i++) {
                m = monsters.get(i);
                if (dist(b.px,b.py,m.px,m.py)<50) {
                    m.health -= b.damage;
                    b.exist = false;
                    break;
                }
            }
            //Check bullet is out the map or not
            if (b.exist) {
                //Check upper bound
                if (b.px < 0 ||  b.py < 0) {
                    b.exist = false;
                } else if (b.px > X - b.SIZE ||  b.py > Y - b.SIZE) {//Lower bound
                    b.exist = false;
                }
            }
            
            if (!b.exist) {
                bullets.remove(checkBulletIndex);
                continue;
            }
            checkBulletIndex++;
        }
        
        //Detect round is finished or not
        if (monsters.size() ==  0 ||  h.health<= 0) {
            gameState = 0;
        }
    } else if (gameState == -2) {
        background(menu);
        gameState = getGameState();
        image(menu, 0, 0);
        if (t < 200) {
            tint(255, t);
            image(press, 50, 600);
        }
        t += 3;
        if (t > 255)  t = 100;
    } else{
        if (h.health <=  0 &&  monsters.size()!= 0) { //Humen Dead
            background(lose);
        } else{
            background(win);
        }
        
        
        
        //Get new gameState
        gameState = getGameState();
        if (gameState == -1) {  //Reset
            monsterNumber = 1;
            init();
        } else if (gameState ==  1) {//Next Round
            monsterNumber += 3;
            init();
        }
        
    }
}

/*
Step1 : MoveHuman(IF need)
Step2 : MoveMonster(x and y both move)
Steop3 : Fire Bullet(Aim to closest Monster)
*/
