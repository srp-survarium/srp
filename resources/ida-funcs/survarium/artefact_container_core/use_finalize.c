void __thiscall survarium::artefact_container_core::use_finalize(
        survarium::artefact_container_core *this,
        survarium::usable_object_user_data *user)
{
  user->current_object = 0;
  user->current_progress = -1;
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
    &this->m_usable_object_users,
    user);
}
