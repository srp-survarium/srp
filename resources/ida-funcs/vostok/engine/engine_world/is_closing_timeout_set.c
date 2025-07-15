bool __thiscall vostok::engine::engine_world::is_closing_timeout_set(vostok::engine::engine_world *this)
{
  return vostok::command_line::key::is_set((vostok::command_line::key *)this);
}
