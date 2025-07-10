survarium::collision_geometry_subscriber *__thiscall survarium::collision_geometry_subscriber::`scalar deleting destructor'(
        survarium::collision_geometry_subscriber *this,
        char a2)
{
  this->__vftable = (survarium::collision_geometry_subscriber_vtbl *)&survarium::collision_geometry_subscriber::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this[1]);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
