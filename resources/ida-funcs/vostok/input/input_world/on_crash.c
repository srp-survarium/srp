void __thiscall vostok::input::input_world::on_crash(vostok::input::input_world *this)
{
  if ( this->m_keyboard )
    this->m_keyboard->on_activate(this->m_keyboard);
}
