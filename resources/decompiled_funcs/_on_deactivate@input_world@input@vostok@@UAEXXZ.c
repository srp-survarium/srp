void __thiscall vostok::input::input_world::on_deactivate(vostok::input::input_world *this)
{
  _InterlockedExchange(&this->m_target_state, 1);
}
