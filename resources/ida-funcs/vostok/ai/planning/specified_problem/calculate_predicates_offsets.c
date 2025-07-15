void __thiscall vostok::ai::planning::specified_problem::calculate_predicates_offsets(
        vostok::ai::planning::specified_problem *this)
{
  survarium::game_camera *v1; // ecx
  stlp_std::priv::_Rb_tree_node_base *v2; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > v3; // [esp-4h] [ebp-8Ch] BYREF
  bool v4; // [esp+2h] [ebp-86h]
  bool v5; // [esp+3h] [ebp-85h]
  vostok::ai::planning::specified_problem *thisa; // [esp+4h] [ebp-84h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v7[5]; // [esp+8h] [ebp-80h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> **v8; // [esp+1Ch] [ebp-6Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v9; // [esp+20h] [ebp-68h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v10[2]; // [esp+30h] [ebp-58h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v11; // [esp+38h] [ebp-50h]
  unsigned int type; // [esp+3Ch] [ebp-4Ch]
  char v13; // [esp+43h] [ebp-45h]
  vostok::fixed_vector<unsigned int,4> *p_m_parameters; // [esp+44h] [ebp-44h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v15[2]; // [esp+48h] [ebp-40h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_left; // [esp+50h] [ebp-38h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v17; // [esp+58h] [ebp-30h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v18; // [esp+60h] [ebp-28h] BYREF
  unsigned int objects_count; // [esp+68h] [ebp-20h]
  unsigned int j; // [esp+6Ch] [ebp-1Ch]
  unsigned int combinations_count; // [esp+70h] [ebp-18h]
  bool exclude_from_world_state; // [esp+77h] [ebp-11h]
  const vostok::ai::planning::pddl_predicate *current_predicate; // [esp+78h] [ebp-10h]
  stlp_std::priv::_Rb_tree_node_base *_M_node; // [esp+7Ch] [ebp-Ch] BYREF
  unsigned int offset; // [esp+80h] [ebp-8h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > iter; // [esp+84h] [ebp-4h] BYREF

  thisa = this;
  vostok::ai::planning::specified_problem::restore_predicates(this);
  offset = 0;
  M_left = (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa->m_predicates._M_t._M_header._M_data._M_left;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_left,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&_M_node);
  while ( 1 )
  {
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa,
      &v18);
    v15[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v15;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v18,
      v15);
    v5 = _M_node != (stlp_std::priv::_Rb_tree_node_base *)v15[0];
    if ( _M_node == (stlp_std::priv::_Rb_tree_node_base *)v15[0] )
      break;
    current_predicate = (const vostok::ai::planning::pddl_predicate *)_M_node[1]._M_parent;
    combinations_count = 1;
    exclude_from_world_state = 0;
    for ( j = 0; ; ++j )
    {
      p_m_parameters = &current_predicate->m_parameters;
      v1 = (survarium::game_camera *)(current_predicate->m_parameters.m_end - current_predicate->m_parameters.m_begin);
      if ( j >= (unsigned int)v1 )
        break;
      v13 = 0;
      survarium::weapon_user_dead_state::finalize(v1);
      type = current_predicate->m_parameters.m_begin[j];
      objects_count = vostok::ai::planning::specified_problem::get_count_of_objects_by_type(thisa, type);
      if ( !objects_count )
      {
        exclude_from_world_state = 1;
        break;
      }
      combinations_count *= objects_count;
    }
    if ( exclude_from_world_state )
    {
      _M_node[1]._M_left = (stlp_std::priv::_Rb_tree_node_base *)-1;
    }
    else
    {
      _M_node[1]._M_left = (stlp_std::priv::_Rb_tree_node_base *)offset;
      offset += combinations_count;
    }
    _M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(_M_node);
  }
  v11 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa->m_predicates._M_t._M_header._M_data._M_left;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v11,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  while ( 1 )
  {
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa,
      &v17);
    v10[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v10;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v17,
      v10);
    v4 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node != v10[0];
    if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node == v10[0] )
      break;
    if ( iter._M_node[1]._M_left == (stlp_std::priv::_Rb_tree_node_base *)-1 )
    {
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
        (vostok::buffer_vector<void const *> *)&thisa->m_excluded_predicates,
        (const void **)&iter._M_node[1]._M_parent);
      v8 = v7;
      stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
        (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node,
        &v9);
      iter._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(iter._M_node);
      stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
        v9,
        v8);
      v3._M_node = v2;
      v7[3] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&v3;
      stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
        v7[0],
        (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v3);
      stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::erase(
        &thisa->m_predicates._M_t,
        v3);
    }
    else
    {
      iter._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(iter._M_node);
    }
  }
}
