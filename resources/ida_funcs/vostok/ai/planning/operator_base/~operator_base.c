void __thiscall vostok::ai::planning::operator_base::~operator_base(vostok::ai::planning::operator_base *this)
{
  this->__vftable = (vostok::ai::planning::operator_base_vtbl *)&vostok::ai::planning::operator_base::`vftable';
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&this->m_effects.m_properties._M_impl);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&this->m_preconditions.m_properties._M_impl);
}
