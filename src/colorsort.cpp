#include "colorsort.hpp"

disk_color_types allowed_color = red_disk;

disk_color get_disk_color(){
    c::optical_rgb_s_t cur_color = optical.get_rgb();
    bool is_red = cur_color.red > cur_color.blue && cur_color.red > COLOR_SORT_THRESHOLD && cur_color.blue < COLOR_SORT_THRESHOLD;
    if (is_red){
        return red_disk; //return that it is red
    } else if (cur_color.blue > COLOR_SORT_THRESHOLD){
        return blue_disk; //return that it is blue
    } else {
        return allowed_color; //default it being allowed color so that is wont try descoring if it is not red or blue detected
    }
}

void color_sort_update(){
    if (get_disk_color() != allowed_color){
        arm_pid.target_set(arm_scoring);
    }
}

void color_sort_loop_task_fn(){
    while (true){
        color_sort_update();
        delay(20);
    }
}

//Task color_sort_task(color_sort_loop_task_fn, "Color Sort Task");