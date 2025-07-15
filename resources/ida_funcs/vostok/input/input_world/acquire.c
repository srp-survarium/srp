void __thiscall vostok::input::input_world::acquire(vostok::input::input_world *this)
{
  void (*on_activate)(void); // edx

  if ( !this->m_acquired )
  {
    on_activate = (void (*)(void))this->on_activate;
    this->m_acquired = 1;
    on_activate();
  }
}
