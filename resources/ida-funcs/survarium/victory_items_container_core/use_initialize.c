void __thiscall survarium::victory_items_container_core::use_initialize(
        survarium::victory_items_container_core *this,
        vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *user)
{
  int v3; // eax
  survarium::inventory *v4; // ecx
  survarium::carryable_object *m_carried_item; // ebx

  v3 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)user->m_size + 20))(user->m_size);
  v4 = *(survarium::inventory **)(v3 + 268);
  m_carried_item = v4->m_carried_item;
  if ( this->m_owner_team == *(_DWORD *)(*(_DWORD *)((char *)&loc_11066 + v3 + 2) + 440) )
  {
    survarium::inventory::drop_carried_item(v4, (int)v4);
    m_carried_item[5].survarium::interactive_object::__vftable = (survarium::carryable_object_vtbl *)this;
  }
  else
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)(v3 + 264) + 4))(
      v3 + 264,
      *((_DWORD *)this->m_victory_items._M_impl._M_finish - 1));
  }
  vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    user,
    &this->m_usable_object_users.m_size);
  user[1].m_size = -1;
  *(_DWORD *)&user->gap4 = this;
}
