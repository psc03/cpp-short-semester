#ifndef COMMON_H
#define COMMON_H

/* Tank */
#define TANK_MOVE_SPEED 2.5
#define TANK_ROTATE_SPEED 2.5

/* red_tank */
#define RED_TANK_INIT_X 0
#define RED_TANK_INIT_Y 0
#define RED_TANK_INIT_ANGLE 0

/* green_tank */
#define GREEN_TANK_INIT_X 3
#define GREEN_TANK_INIT_Y 300
#define GREEN_TANK_INIT_ANGLE 0

/* mapscene */
#define SCENE_WIDTH 491
#define SCENE_HEIGHT 491

/* notification */
enum {
    TANK_MOVE_FORWARD = 2,
    TANK_MOVE_BACKWARD,
    TANK_ROTATE_LEFT,
    TANK_ROTATE_RIGHT
};

/* catogory */
enum {
    RED_TANK = 10,
    GREEN_TANK
};

#endif // COMMON_H
