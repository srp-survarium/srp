survarium::collision_geometry_subscriber *__thiscall survarium::collision_geometry_subscriber::`scalar deleting destructor'(
        survarium::collision_geometry_subscriber *this,
        char a2)
{
  this->__vftable = (survarium::collision_geometry_subscriber_vtbl *)&survarium::collision_geometry_subscriber::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
