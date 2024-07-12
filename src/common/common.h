#ifndef COMMON_H
#define COMMON_H

/* Tank */
#define TANK_MOVE_SPEED 2.5
#define TANK_ROTATE_SPEED 2.5
#define TANK_HEIGHT 25
#define TANK_WIDTH 40

/* red_tank */
#define RED_TANK_INIT_X 50
#define RED_TANK_INIT_Y 50
#define RED_TANK_INIT_ANGLE 0

/* green_tank */
#define GREEN_TANK_INIT_X 3
#define GREEN_TANK_INIT_Y 300
#define GREEN_TANK_INIT_ANGLE 0

/* bullet */
#define BULLET_MOVE_SPEED 2.5
// TODO:
#define BULLET_HEIGHT 11
#define BULLET_WIDTH 11

/* mapscene */
#define SCENE_WIDTH 491
#define SCENE_HEIGHT 491

/* notification */
enum Notification{
    TANK_MOVE_FORWARD = 2,
    TANK_MOVE_BACKWARD,
    TANK_ROTATE_LEFT,
    TANK_ROTATE_RIGHT,
    BULLET_MOVE
};

using Command = Notification;

/* catogory */
enum Item{
    RED_TANK = 10,
    GREEN_TANK,
    BULLET
};

#endif // COMMON_H
