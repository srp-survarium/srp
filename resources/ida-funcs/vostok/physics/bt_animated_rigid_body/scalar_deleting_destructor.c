vostok::physics::bt_animated_rigid_body *__thiscall vostok::physics::bt_animated_rigid_body::`scalar deleting destructor'(
        vostok::physics::bt_animated_rigid_body *this,
        char a2)
{
  vostok::physics::bt_animated_rigid_body::~bt_animated_rigid_body(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
