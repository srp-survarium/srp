void __thiscall survarium::artefact_container_core::use_initialize(
        survarium::artefact_container_core *this,
        vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *user)
{
  survarium::usable_object_user_data *m_last; // eax

  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    user,
    &this->m_usable_object_users.m_size);
  m_last = user->m_last;
  user[1].m_size = 0;
  *(_DWORD *)&user->gap4 = this;
  user->m_first = m_last;
}
