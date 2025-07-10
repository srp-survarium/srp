vostok::physics::bt_collision_shape *__thiscall vostok::physics::bt_collision_shape::`scalar deleting destructor'(
        vostok::physics::bt_collision_shape *this,
        char a2)
{
  vostok::physics::bt_collision_shape::~bt_collision_shape(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
