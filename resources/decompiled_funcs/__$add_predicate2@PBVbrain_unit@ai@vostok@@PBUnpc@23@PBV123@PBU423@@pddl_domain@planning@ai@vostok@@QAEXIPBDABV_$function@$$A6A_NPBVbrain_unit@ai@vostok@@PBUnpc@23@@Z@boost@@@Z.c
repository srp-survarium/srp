void __thiscall vostok::ai::planning::pddl_domain::add_predicate2<vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::brain_unit const *,vostok::ai::npc const *>(
        vostok::ai::planning::pddl_domain *this,
        unsigned int required_type,
        const char *name,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *predicate)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v6; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // [esp+8h] [ebp-B4h]
  void *_Where; // [esp+A4h] [ebp-18h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v10; // [esp+ACh] [ebp-10h]
  char *v11; // [esp+B0h] [ebp-Ch]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v4);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x48u);
  v11 = (char *)operator new(0x48u, _Where);
  if ( v11 )
  {
    *(_DWORD *)v11 = required_type;
    vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
      (vostok::buffer_vector<unsigned int> *)(v11 + 4),
      (unsigned int *)v11 + 3,
      4u,
      0);
    *((_DWORD *)v11 + 7) = name;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v11 + 1,
      (_DWORD *)v11 + 8);
    v7 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v11;
  }
  else
  {
    v7 = 0;
  }
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v7 + 1,
    (int *)&v7[1]);
  v10 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)operator new(0x20u, &v7[1]);
  if ( v10 )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v6, v10);
    boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
      v10,
      predicate);
  }
  v7[2].vtable = (boost::detail::function::vtable_base *)vostok::ai::planning::predicate_binder<vostok::ai::brain_unit const *,vostok::ai::animation_item const *,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>;
  vostok::ai::planning::pddl_domain::deduce_parameter_type<vostok::ai::brain_unit const *>(
    this,
    (vostok::ai::planning::pddl_predicate *)v7);
  vostok::ai::planning::pddl_domain::deduce_parameter_type<vostok::ai::npc const *>(
    this,
    (vostok::ai::planning::pddl_predicate *)v7);
  *stlp_std::map<unsigned int,vostok::ai::planning::pddl_predicate *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::pddl_predicate *>>>::operator[]<unsigned int>(
     &this->m_predicates,
     &required_type) = (stlp_std::priv::_Rb_tree_node_base *)v7;
}
