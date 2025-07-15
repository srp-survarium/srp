vostok::render::world *__thiscall vostok::engine::engine_world::get_renderer_world(vostok::engine::engine_world *this)
{
  vostok::render::world *result; // eax

  result = (vostok::render::world *)this->m_on_before_render_window_showed.functor.bound_memfunc_ptr.obj_ptr;
  if ( !result )
  {
    do
      vostok::threading::yield(0xAu, (vostok::tasks *)this);
    while ( !this->m_on_before_render_window_showed.functor.bound_memfunc_ptr.obj_ptr );
    return (vostok::render::world *)this->m_on_before_render_window_showed.functor.bound_memfunc_ptr.obj_ptr;
  }
  return result;
}
