void __thiscall vostok::input::input_world::acquire(vostok::input::input_world *this)
{
  vostok::input::input_world_vtbl *v1; // eax

  if ( !this->m_acquired )
  {
    v1 = this->vostok::input::world::__vftable;
    this->m_acquired = 1;
    ((void (*)(void))v1->on_activate)();
  }
}
