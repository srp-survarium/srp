bool __thiscall vostok::engine::game_console::get_active(vostok::engine::game_console *this)
{
  return (bool)this[-1].m_input_world;
}
