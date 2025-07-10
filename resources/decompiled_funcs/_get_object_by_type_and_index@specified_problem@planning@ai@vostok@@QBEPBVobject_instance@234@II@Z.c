const vostok::ai::planning::object_instance *__thiscall vostok::ai::planning::specified_problem::get_object_by_type_and_index(
        vostok::ai::planning::specified_problem *this,
        unsigned int type,
        unsigned int index)
{
  survarium::game_camera *v3; // ecx
  stlp_std::priv::_Rb_tree_node_base *v6; // [esp+8h] [ebp-1Ch]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v7; // [esp+Ch] [ebp-18h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v8; // [esp+1Ch] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> > > > iter; // [esp+20h] [ebp-4h] BYREF

  v7 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::_M_find<unsigned int>(
                                                                     (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&this->m_objects,
                                                                     &type);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v7,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->m_objects,
    &v8);
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node == v8 )
    return 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)iter._M_node);
  v6 = iter._M_node + 1;
  survarium::weapon_user_dead_state::finalize(v3);
  return (const vostok::ai::planning::object_instance *)((char *)v6->_M_parent + 276 * index);
}
