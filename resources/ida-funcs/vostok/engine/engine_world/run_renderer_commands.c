void __thiscall vostok::engine::engine_world::run_renderer_commands(vostok::engine::engine_world *this)
{
  vostok::render::one_way_render_channel::render_process_commands(
    (vostok::render::one_way_render_channel *)this,
    (int)this->m_on_before_render_window_showed.functor.bound_memfunc_ptr.obj_ptr,
    0);
}
