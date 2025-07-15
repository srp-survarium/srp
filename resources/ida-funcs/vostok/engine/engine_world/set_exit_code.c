void __thiscall vostok::engine::engine_world::set_exit_code(vostok::engine::engine_world *this, int exit_code)
{
  this->m_exit_code = exit_code;
}


void __thiscall vostok::engine::engine_world::set_exit_code(char *this, int a2)
{
  vostok::engine::engine_world::set_exit_code((vostok::engine::engine_world *)(this - 8), a2);
}
