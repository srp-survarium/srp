void __thiscall vostok::ai::planning::pddl_domain::~pddl_domain(vostok::ai::planning::pddl_domain *this)
{
  survarium::game_camera *v1; // ecx
  boost::_bi::list1<vostok::network_core::packet_reader &> *v2; // eax
  stlp_std::priv::_Rb_tree_node_base *v3; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > v4; // [esp-4h] [ebp-40h] BYREF
  vostok::ai::planning::pddl_domain *thisa; // [esp+0h] [ebp-3Ch]
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *p_m_predicates; // [esp+4h] [ebp-38h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v7[8]; // [esp+8h] [ebp-34h] BYREF
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+2Bh] [ebp-11h] BYREF
  stlp_std::priv::_Rb_tree_node_base *v9; // [esp+2Ch] [ebp-10h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_left; // [esp+30h] [ebp-Ch]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::ai::planning::pddl_predicate *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::ai::planning::pddl_predicate *> > > iter; // [esp+38h] [ebp-4h] BYREF

  for ( thisa = this;
        thisa->m_predicates._M_t._M_node_count;
        stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::erase(
          (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&thisa->m_predicates,
          v4) )
  {
    M_left = (boost::_bi::list1<vostok::network_core::packet_reader &> *)thisa->m_predicates._M_t._M_header._M_data._M_left;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      M_left,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&iter);
    v9 = iter._M_node + 1;
    survarium::weapon_user_dead_state::finalize(v1);
    v7[4] = v2;
    call_destructor_predicate = 0;
    v4._M_node = (stlp_std::priv::_Rb_tree_node_base *)&call_destructor_predicate;
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::planning::pddl_predicate,vostok::memory::detail::call_destructor_predicate>(
      (vostok::memory::doug_lea_allocator *)v2,
      (vostok::ai::planning::pddl_predicate **)&v9->_M_parent);
    v7[3] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v7;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)iter._M_node,
      v7);
    v4._M_node = v3;
    v7[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&v4;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v7[0],
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v4);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(thisa->m_predicates._M_t._M_node_count == 0));
  p_m_predicates = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&thisa->m_predicates;
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::oracle *>>>::clear((stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&thisa->m_predicates);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&p_m_predicates->_M_key_compare);
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::ai::planning::oracle *>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::oracle *>>>::clear((stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)thisa);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)thisa);
}
