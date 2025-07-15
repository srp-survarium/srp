vostok::physics::bullet_physics_world::object_query::__l2::object_query_callback *__thiscall `btCollisionWorld::objectQuerySingle'::`46'::LocalInfoAdder::`vector deleting destructor'(
        vostok::physics::bullet_physics_world::object_query::__l2::object_query_callback *this,
        char a2)
{
  this->__vftable = (vostok::physics::bullet_physics_world::object_query::__l2::object_query_callback_vtbl *)&btCollisionWorld::ConvexResultCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
