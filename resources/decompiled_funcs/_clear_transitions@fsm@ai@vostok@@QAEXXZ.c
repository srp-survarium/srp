void __thiscall vostok::ai::fsm::clear_transitions(vostok::ai::fsm *this)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::ai::fsm_state_transition *i; // [esp+28h] [ebp-8h] BYREF
  vostok::ai::fsm_state *j; // [esp+2Ch] [ebp-4h]

  for ( j = (vostok::ai::fsm_state *)boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
                                       (boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *)this,
                                       (int)this);
        j;
        j = (vostok::ai::fsm_state *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                       v1,
                                       (int)j) )
  {
    while ( 1 )
    {
      i = vostok::intrusive_list<vostok::ai::fsm_state_transition,vostok::ai::fsm_state_transition *,36,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(&j->transitions);
      if ( !i )
        break;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v1);
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,vostok::ai::fsm_state_transition,vostok::memory::detail::call_destructor_predicate>(
        v2,
        &i);
    }
  }
}
