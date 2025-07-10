void __thiscall vostok::engine::engine_world::exit(vostok::engine::engine_world *this, int exit_code)
{
  this->set_exit_code(this, exit_code);
  _InterlockedExchange(&this->m_destruction_started, 1);
}
