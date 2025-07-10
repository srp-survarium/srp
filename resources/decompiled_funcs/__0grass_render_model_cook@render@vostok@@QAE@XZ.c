void __thiscall vostok::render::grass_render_model_cook::grass_render_model_cook(
        vostok::render::grass_render_model_cook *this)
{
  vostok::render::render_model_cook::render_model_cook(&grass_render_model_class_cooker, grass_render_model_class);
  grass_render_model_class_cooker.__vftable = (vostok::render::grass_render_model_cook_vtbl *)&vostok::render::grass_render_model_cook::`vftable';
}
