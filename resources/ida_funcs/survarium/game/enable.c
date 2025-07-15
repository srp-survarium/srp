void __thiscall survarium::game::enable(survarium::game *this, bool value)
{
  bool v2; // zf
  vostok::input::world_vtbl *v3; // eax

  v2 = this->m_render_output_window.m_object == 0;
  this->m_enabled = value;
  if ( !v2 )
  {
    v3 = this->m_input_world->__vftable;
    if ( value )
      ((void (*)(void))v3->acquire)();
    else
      ((void (*)(void))v3->unacquire)();
  }
}
