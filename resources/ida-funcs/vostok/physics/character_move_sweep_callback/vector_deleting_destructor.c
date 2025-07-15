vostok::physics::character_move_sweep_callback *__thiscall vostok::physics::character_move_sweep_callback::`vector deleting destructor'(
        vostok::physics::character_move_sweep_callback *this,
        char a2)
{
  this->__vftable = (vostok::physics::character_move_sweep_callback_vtbl *)&btCollisionWorld::ConvexResultCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
