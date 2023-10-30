//
// Created by Arkan Yota on 19/10/2023.
//

#include "raylib.h"
#include "sdf.h"
#include "math.h"
#include "vec3.h"
#include <math.h>
#include <printf.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 450

#define YAWFOV 3.
#define PITCHFOV ((YAWFOV*450.)/800.)

#define MAX_STEPS 100
#define MAX_DIST 255.0
#define MIN_DIST 0.0001

int cpt = 0;
vec3 sun_dir = {0.5, 0.5, 0.5};


double throw_ray(vec3 pos, double yaw, double pitch, double dist);

Color get_ray_color(double dist, double angle);


double throw_ray(vec3 pos, double yaw, double pitch, double dist) {
    if (dist > MAX_DIST) {
        return INFINITY;
    }
    float near_dist = abs_f(scene(pos));
    if (near_dist < MIN_DIST) {
        return dist;
    }
    vec3 new_pos = vec3_new_pos(pos, near_dist, yaw, pitch);
    double new_dist = dist + near_dist;
    return throw_ray(new_pos, yaw, pitch, new_dist);
}

Color get_ray_color(double dist, double angle) {
    if (dist == INFINITY) {
        return (Color) {255, 255, 255, 255};
    } else{
        return (Color) {(int) (70*angle), 0, 0, 255};
    }
    int near_dist = (int) (dist);
    int near_color = min_i(max_i(near_dist, 0), 255);
    return (Color) {near_color, near_color, near_color, 255};
}


int main(void) {
    InitWindow(WIDTH, HEIGHT, "RayMarching");
    double yaw = 0.8;
    double pitch = -1.08;
    double new_yaw;
    double new_pitch;
    double ray_dist;
    Color ray_color;
    vec3 pos_after_ray;
    int key;
    vec3 player_pos = {25, 25, -14};
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RED);


        key = GetKeyPressed();
        switch (key) {
            case KEY_ESCAPE:
                CloseWindow();
                break;
            case KEY_A:
                player_pos.x++;
                break;
            case KEY_Q:
                player_pos.x--;
                break;
            case KEY_W:
                player_pos.y++;
                break;
            case KEY_S:
                player_pos.y--;
                break;
            case KEY_E:
                player_pos.z++;
                break;
            case KEY_D:
                player_pos.z--;
                break;
            case KEY_RIGHT:
                yaw += 0.1;
                break;
            case KEY_LEFT:
                yaw -= 0.1;
                break;
            case KEY_UP:
                pitch -= 0.1;
                break;
            case KEY_DOWN:
                pitch += 0.1;
                break;
            default:
                break;

        }
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            yaw = yaw + (YAWFOV * ((double) GetMouseX() / WIDTH)) - (YAWFOV / 2.);
            pitch = pitch + (PITCHFOV * ((double) GetMouseY() / HEIGHT)) - (PITCHFOV / 2.);
        }
       //  if (IsKeyPressed(KEY_A))     player_pos.x++;
       //  if (IsKeyPressed(KEY_Q))     player_pos.x--;
       //  if (IsKeyPressed(KEY_Z))     player_pos.y++;
       //  if (IsKeyPressed(KEY_S))     player_pos.y--;
       //  if (IsKeyPressed(KEY_E))     player_pos.z++;
       //  if (IsKeyPressed(KEY_D))     player_pos.z--;
       //  if (IsKeyPressed(KEY_RIGHT)) yaw += 0.1;
       //  if (IsKeyPressed(KEY_LEFT))  yaw -= 0.1;
       //  if (IsKeyPressed(KEY_UP))    pitch += 0.1;
       //  if (IsKeyPressed(KEY_DOWN))  pitch -= 0.1;

        // Draw pixel
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                new_yaw = yaw + (YAWFOV * ((double) i / WIDTH)) - (YAWFOV / 2.);
                new_pitch = pitch + (PITCHFOV * ((double) j / HEIGHT)) - (PITCHFOV / 2.);

                ray_dist = throw_ray(player_pos, new_yaw, new_pitch, 0.);

                vec3 pos_after_ray = vec3_new_pos(player_pos, ray_dist, new_yaw, new_pitch);
                vec3 normal_after_ray = normal(pos_after_ray);

                double angle = angle_between(normal_after_ray, sun_dir);
                ray_color = get_ray_color(ray_dist, angle);

                DrawPixel(i, j, ray_color);
            }
        }
        char print_text[100];
        sprintf(print_text, "X: %.2f, Y: %.2f, Z: %.2f, Yaw: %.2f, Pitch: %.2f, cpt: %d", player_pos.x, player_pos.y, player_pos.z, yaw, pitch, cpt++);


        DrawRectangle(0, 0, 800, 30, WHITE);
        DrawText(print_text, 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

