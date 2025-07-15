int __thiscall vostok::engine::engine_world::get_exit_code(vostok::engine::engine_world *this)
{
  return this->m_exit_code;
}


int __thiscall vostok::engine::engine_world::get_exit_code(char *this)
{
  return vostok::engine::engine_world::get_exit_code((vostok::engine::engine_world *)(this - 8));
}
