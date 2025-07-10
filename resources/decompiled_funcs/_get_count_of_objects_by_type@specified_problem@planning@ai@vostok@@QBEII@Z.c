int __thiscall vostok::ai::planning::specified_problem::get_count_of_objects_by_type(
        vostok::ai::planning::specified_problem *this,
        unsigned int type)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v5; // [esp+10h] [ebp-14h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+1Ch] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> > > > iter; // [esp+20h] [ebp-4h] BYREF

  v5 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::_M_find<unsigned int>(
                                                                     (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&this->m_objects,
                                                                     &type);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v5,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->m_objects,
    &v6);
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node == v6 )
    return 0;
  else
    return ((char *)iter._M_node[1]._M_left - (char *)iter._M_node[1]._M_parent) / 276;
}
