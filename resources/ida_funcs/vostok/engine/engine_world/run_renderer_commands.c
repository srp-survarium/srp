void __thiscall vostok::engine::engine_world::run_renderer_commands(vostok::engine::engine_world *this)
{
  vostok::render::one_way_render_channel::render_process_commands((vostok::render::one_way_render_channel *)this, 0);
}
