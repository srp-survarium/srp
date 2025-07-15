void __thiscall survarium::victory_item_core::use_initialize(
        survarium::victory_item_core *this,
        vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *user)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)user->m_size + 20))(user->m_size);
  (*(void (__thiscall **)(int, survarium::player_params_modifier *))(*(_DWORD *)(v3 + 264) + 4))(
    v3 + 264,
    &this[-1].m_move_speed_modifier);
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    user,
    this->m_deserialized_users.m_buffer[0].m_store);
  user[1].m_size = -1;
  *(_DWORD *)&user->gap4 = this != (survarium::victory_item_core *)20 ? this : 0;
}
