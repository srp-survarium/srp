void __thiscall vostok::input::input_world::unacquire(vostok::input::input_world *this)
{
  if ( this->m_acquired )
  {
    this->m_acquired = 0;
    vostok::input::input_world::process_on_deactivate(this, this);
  }
}
