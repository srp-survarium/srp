void __thiscall survarium::victory_items_container_core::use_finalize(
        survarium::victory_item_core *this,
        survarium::usable_object_user_data *user)
{
  user->current_object = 0;
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)this->m_deserialized_users.m_buffer,
    user);
}
