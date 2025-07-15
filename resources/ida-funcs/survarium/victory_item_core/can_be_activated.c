char __thiscall survarium::victory_item_core::can_be_activated(
        survarium::victory_item_core *this,
        survarium::base_player *user)
{
  survarium::victory_items_container_core *m_container; // eax

  if ( this->m_user )
    return 0;
  m_container = this->m_container;
  if ( m_container )
    return vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::contains_object(
             (vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&user->m_usable_object_user_data,
             (int)&m_container->m_usable_object_users,
             &user->m_usable_object_user_data);
  else
    return vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::contains_object(
             (vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)this,
             (int)&this->m_usable_object_users,
             &user->m_usable_object_user_data);
}
