void __thiscall survarium::respawn_point_core::respawn_point_core(survarium::respawn_point_core *this)
{
  this->__vftable = (survarium::respawn_point_core_vtbl *)&survarium::respawn_point_core::`vftable';
  this->point_id = -1;
  vostok::math::float3::float3(&this->position, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  this->orientation = *(float *)&FLOAT_0_0;
  this->point_priority = 0;
  this->team_owner = team_1;
  this->selected_for_respawn = 0;
}
