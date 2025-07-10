void __thiscall vostok::ai::planning::specified_problem::~specified_problem(
        vostok::ai::planning::specified_problem *this)
{
  vostok::buffer_vector<vostok::resources::request> *v1; // ecx
  const vostok::ai::planning::pddl_predicate **i; // [esp+8h] [ebp-38h]

  vostok::ai::planning::specified_problem::restore_predicates(this);
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>>::clear(&this->m_objects._M_t);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_objects._M_t._M_key_compare);
  vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v1, &this->m_target_offsets.m_begin);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>::~_Impl_vector<vostok::ai::planning::pddl_world_state_property_impl,vostok::ai::std_allocator<vostok::ai::planning::pddl_world_state_property_impl>>(&this->m_target_world_state._M_impl);
  for ( i = this->m_excluded_predicates.m_begin; i != this->m_excluded_predicates.m_end; ++i )
    ;
  this->m_excluded_predicates.m_end = this->m_excluded_predicates.m_begin;
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::oracle *>>>::clear(&this->m_predicates._M_t);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_predicates._M_t._M_key_compare);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
