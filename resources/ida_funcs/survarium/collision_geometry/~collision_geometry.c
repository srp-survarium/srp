void __thiscall survarium::collision_geometry::~collision_geometry(survarium::collision_geometry *this)
{
  survarium::game_camera *v1; // ecx

  this->__vftable = (survarium::collision_geometry_vtbl *)&survarium::collision_geometry::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::collision_geometry::destroy_ghost_object(this);
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::~_Impl_vector<void *,stlp_std::allocator<void *>>(&this->m_subscribers._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_physics_world);
}
