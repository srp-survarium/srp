void __thiscall vostok::input::input_world::on_activate(vostok::input::input_world *this)
{
  _InterlockedExchange(&this->m_target_state, 0);
}
