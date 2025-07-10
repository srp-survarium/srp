void __thiscall survarium::collision_geometry::collision_geometry(survarium::collision_geometry *this)
{
  vostok::collision::game_object *v1; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_physics_world);
  vostok::collision::game_object::game_object(v1, this);
  this->__vftable = (survarium::collision_geometry_vtbl *)&survarium::collision_geometry::`vftable';
  this->m_physics_world = 0;
  this->m_subscribers._M_impl._M_start = 0;
  this->m_subscribers._M_impl._M_finish = 0;
  this->m_subscribers._M_impl._M_end_of_storage._M_data = 0;
  vostok::fixed_string<260>::fixed_string<260>(&this->m_name);
  this->m_ghost_object = 0;
  this->m_group = 0;
  this->m_mask = 0;
}
