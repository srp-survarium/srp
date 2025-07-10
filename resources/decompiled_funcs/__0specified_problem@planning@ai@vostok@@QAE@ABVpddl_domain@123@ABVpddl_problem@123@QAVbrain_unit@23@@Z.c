void __thiscall vostok::ai::planning::specified_problem::specified_problem(
        vostok::ai::planning::specified_problem *this,
        const vostok::ai::planning::pddl_domain *domain,
        const vostok::ai::planning::pddl_problem *problem,
        vostok::ai::brain_unit *const owner)
{
  const vostok::ai::planning::pddl_predicate *v4; // esi
  stlp_std::priv::_Rb_tree_node_base **v5; // eax
  stlp_std::less<unsigned int> v7; // [esp+7Ah] [ebp-36h] BYREF
  vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > v8; // [esp+7Bh] [ebp-35h] BYREF
  vostok::buffer_vector<unsigned int> *p_m_target_offsets; // [esp+7Ch] [ebp-34h]
  void *buffer; // [esp+84h] [ebp-2Ch]
  stlp_std::priv::_STLP_alloc_proxy<vostok::sound::search::vertex_id_type *,vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *p_m_target_world_state; // [esp+88h] [ebp-28h]
  vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> v12; // [esp+8Eh] [ebp-22h] BYREF
  stlp_std::less<unsigned int> __comp; // [esp+96h] [ebp-1Ah] BYREF
  vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > __a; // [esp+97h] [ebp-19h] BYREF
  const vostok::ai::planning::pddl_predicate *v15; // [esp+98h] [ebp-18h]
  int v16; // [esp+9Ch] [ebp-14h]
  unsigned int __k; // [esp+A0h] [ebp-10h] BYREF
  const vostok::ai::planning::pddl_predicate *current; // [esp+A4h] [ebp-Ch]
  unsigned int i; // [esp+A8h] [ebp-8h]
  unsigned int predicates_count; // [esp+ACh] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>>::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>>(
    &this->m_predicates._M_t,
    &__comp,
    &__a);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&__comp);
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_excluded_predicates);
  p_m_target_world_state = (stlp_std::priv::_STLP_alloc_proxy<vostok::sound::search::vertex_id_type *,vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)&this->m_target_world_state;
  this->m_target_world_state._M_impl._M_start = 0;
  p_m_target_world_state[1]._M_data = 0;
  boost::intrusive::detail::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>::key_nodeptr_comp<vostok::logging::compare_nodes,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::logging::node_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::logging::compare_nodes,unsigned int,0>>>(
    p_m_target_world_state + 2,
    &v12,
    0);
  p_m_target_offsets = &this->m_target_offsets;
  buffer = this->m_target_offsets.m_buffer;
  vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
    &this->m_target_offsets,
    (unsigned int *)this->m_target_offsets.m_buffer,
    0x10u,
    0);
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>>::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>>>(
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> >,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > >,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int> > > > *)&this->m_objects,
    &v7,
    &v8);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v7);
  this->m_domain = domain;
  this->m_problem = problem;
  this->m_owner = owner;
  predicates_count = this->m_domain->m_predicates._M_t._M_node_count;
  for ( i = 0; i < predicates_count; ++i )
  {
    current = vostok::ai::planning::pddl_domain::get_predicate(this->m_domain, i);
    __k = current->m_type;
    v15 = current;
    v16 = -1;
    v4 = current;
    v5 = stlp_std::map<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,stlp_std::pair<vostok::ai::planning::pddl_predicate const *,unsigned int>>>>::operator[]<unsigned int>(
           &this->m_predicates,
           &__k);
    *v5 = (stlp_std::priv::_Rb_tree_node_base *)v4;
    v5[1] = (stlp_std::priv::_Rb_tree_node_base *)-1;
  }
}
