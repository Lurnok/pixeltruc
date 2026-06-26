#include "nuklear_gui.h"
#include "../../../structs/App/app.h"

#include "../../../../external/Nuklear/nuklear.h"
#include "../../../../external/Nuklear/demo/sdl_renderer/nuklear_sdl_renderer.h"

void nuklear_draw(App *app){
    struct nk_color bar_color = nk_rgba(BG_DARK_R, BG_DARK_G, BG_DARK_B, 255); 
    nk_style_push_color(app->engine->nk_ctx, &app->engine->nk_ctx->style.window.background, bar_color);

    if (nk_begin(app->engine->nk_ctx, "MainWindow", nk_rect(0, 0, 1920, 1080), NK_WINDOW_BACKGROUND | NK_WINDOW_NO_SCROLLBAR)) {
        nuklear_menubar(app);
        
        struct nk_color main_app_bg = nk_rgba(BG_MEDIUM_R, BG_MEDIUM_G, BG_MEDIUM_B, 255);
        struct nk_style_item group_bg = nk_style_item_color(main_app_bg);
        nk_style_push_style_item(app->engine->nk_ctx, &app->engine->nk_ctx->style.window.fixed_background, group_bg);

        struct nk_vec2 remaining_space = nk_window_get_content_region_size(app->engine->nk_ctx);
        nk_layout_row_dynamic(app->engine->nk_ctx, remaining_space.y, 1);

        nk_style_push_vec2(app->engine->nk_ctx, &app->engine->nk_ctx->style.window.group_padding, nk_vec2(10, 10));
        nk_style_push_vec2(app->engine->nk_ctx, &app->engine->nk_ctx->style.window.padding, nk_vec2(0, 0));

        
    
        if (nk_group_begin(app->engine->nk_ctx, "MainContent", NK_WINDOW_NO_SCROLLBAR)) {
            nk_layout_row_dynamic(app->engine->nk_ctx, 30, 1);
            nk_label(app->engine->nk_ctx, "caca", NK_TEXT_LEFT);
            
            nk_group_end(app->engine->nk_ctx);
        }
        nk_style_pop_style_item(app->engine->nk_ctx);
        nk_style_pop_vec2(app->engine->nk_ctx);
        nk_style_pop_vec2(app->engine->nk_ctx);

    }
    nk_end(app->engine->nk_ctx);

    nk_style_pop_color(app->engine->nk_ctx);

    nk_sdl_render(NK_ANTI_ALIASING_ON);
    nk_clear(app->engine->nk_ctx);
}

void nuklear_menubar(App * app){
    struct nk_color bar_color = nk_rgba(BG_DARK_R, BG_DARK_G, BG_DARK_B, 255); 
    struct nk_color button_border_color = nk_rgba(BG_DARK_R - 10, BG_DARK_G - 10, BG_DARK_B - 10, 255);
    struct nk_color hover_bg_color = nk_rgba(BG_DARK_R + 10, BG_DARK_G + 10, BG_DARK_B + 10, 255);
    struct nk_color text_color = nk_rgba(255, 255, 255, 255);

    nk_style_push_color(app->engine->nk_ctx, &app->engine->nk_ctx->style.menu_button.normal.data.color, bar_color);
    nk_style_push_color(app->engine->nk_ctx, &app->engine->nk_ctx->style.menu_button.border_color, bar_color);
    nk_style_push_color(app->engine->nk_ctx, &app->engine->nk_ctx->style.menu_button.hover.data.color, hover_bg_color);
    nk_style_push_color(app->engine->nk_ctx, &app->engine->nk_ctx->style.menu_button.text_normal, text_color);
    nk_style_push_color(app->engine->nk_ctx, &app->engine->nk_ctx->style.menu_button.text_hover, text_color);

    nk_menubar_begin(app->engine->nk_ctx);

    nk_layout_row_static(app->engine->nk_ctx, 0, 50, 5);
    if(nk_menu_begin_label(app->engine->nk_ctx, "File", NK_TEXT_CENTERED, nk_vec2(120, 200))){
        nk_layout_row_dynamic(app->engine->nk_ctx, 25, 1);
        if (nk_menu_item_label(app->engine->nk_ctx, "New", NK_TEXT_LEFT)) { /* ... */ }
        if (nk_menu_item_label(app->engine->nk_ctx, "Exit", NK_TEXT_LEFT)) { /* ... */ }
            
        nk_menu_end(app->engine->nk_ctx);
    }

    if(nk_menu_begin_label(app->engine->nk_ctx, "Edit", NK_TEXT_CENTERED, nk_vec2(120, 200))){
        nk_layout_row_dynamic(app->engine->nk_ctx, 25, 1);
        if (nk_menu_item_label(app->engine->nk_ctx, "New", NK_TEXT_LEFT)) { /* ... */ }
        if (nk_menu_item_label(app->engine->nk_ctx, "Exit", NK_TEXT_LEFT)) { /* ... */ }
            
        nk_menu_end(app->engine->nk_ctx);
    }


    nk_menubar_end(app->engine->nk_ctx);

    nk_style_pop_color(app->engine->nk_ctx);
    nk_style_pop_color(app->engine->nk_ctx);
    nk_style_pop_color(app->engine->nk_ctx);
    nk_style_pop_color(app->engine->nk_ctx);
    nk_style_pop_color(app->engine->nk_ctx);
}
