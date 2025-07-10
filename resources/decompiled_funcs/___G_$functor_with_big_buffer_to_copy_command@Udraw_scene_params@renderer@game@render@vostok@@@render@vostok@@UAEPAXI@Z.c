vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params> *__thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>::`scalar deleting destructor'(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params> *this,
        char a2)
{
  vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>::~functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
