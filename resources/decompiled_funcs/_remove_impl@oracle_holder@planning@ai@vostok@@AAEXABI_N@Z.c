void __thiscall vostok::ai::planning::oracle_holder::remove_impl(
        vostok::ai::planning::oracle_holder *this,
        const unsigned int *oracle_id,
        bool notify_holder)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  stlp_std::priv::_Rb_tree_node_base *v6; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > v7; // [esp-4h] [ebp-44h] BYREF
  vostok::ai::planning::oracle_holder *thisa; // [esp+0h] [ebp-40h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v9[10]; // [esp+8h] [ebp-38h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v10; // [esp+30h] [ebp-10h]
  char v11; // [esp+3Bh] [ebp-5h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::ai::planning::oracle *> > > iter; // [esp+3Ch] [ebp-4h] BYREF

  thisa = this;
  v10 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::_M_find<unsigned int>(
                                                                      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)this,
                                                                      oracle_id);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v10,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
  v11 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  v9[9] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&iter._M_node[1];
  v7._M_node = (stlp_std::priv::_Rb_tree_node_base *)((char *)iter._M_node + 20);
  survarium::weapon_user_dead_state::finalize(v4);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::oracle>(
    v5,
    (vostok::ai::planning::oracle **)v7._M_node);
  v9[5] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v9;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node,
    v9);
  v7._M_node = v6;
  v9[3] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&v7;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v9[0],
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v7);
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::erase(
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)thisa,
    v7);
  if ( notify_holder )
    thisa->m_planner->m_actual = 0;
}
