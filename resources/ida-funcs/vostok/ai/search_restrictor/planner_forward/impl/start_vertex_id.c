vostok::ai::planning::world_state *__thiscall vostok::ai::search_restrictor::planner_forward::impl::start_vertex_id(
        vostok::ai::search_restrictor::planner_forward::impl *this,
        vostok::ai::planning::world_state *result,
        unsigned int index)
{
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> __a; // [esp+BAh] [ebp-1Ah] BYREF
  char v6; // [esp+BBh] [ebp-19h]
  vostok::ai::planning::world_state resulta; // [esp+BCh] [ebp-18h] BYREF
  const vostok::ai::planning::world_state_property *it_end; // [esp+CCh] [ebp-8h]
  const vostok::ai::planning::world_state_property *it_property; // [esp+D0h] [ebp-4h]

  v6 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
    (stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *)&resulta,
    &__a);
  resulta.m_hash = 0;
  it_property = this->m_start_vertex_id->m_properties._M_impl._M_start;
  it_end = this->m_start_vertex_id->m_properties._M_impl._M_finish;
  while ( it_property != it_end )
    vostok::ai::planning::world_state::add(&resulta, it_property++);
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(
    &result->m_properties._M_impl,
    &resulta.m_properties._M_impl);
  result->m_hash = resulta.m_hash;
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::~_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>(&resulta.m_properties._M_impl);
  return result;
}
