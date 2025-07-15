void __thiscall survarium::base_project::~base_project(survarium::base_project *this)
{
  survarium::game_camera *v1; // ecx

  this->__vftable = (survarium::base_project_vtbl *)&survarium::base_project::`vftable';
  if ( this->m_static_collision_objects )
    vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,survarium::static_collision,vostok::memory::detail::call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
      &this->m_static_collision_objects);
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::~_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>(&this->m_objects_to_resolve._M_impl);
  stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260>>,stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::clear(&this->m_objects_registry._M_t);
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_objects_registry);
}
