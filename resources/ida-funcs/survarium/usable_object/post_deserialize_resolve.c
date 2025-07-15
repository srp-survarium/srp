void __userpurge survarium::usable_object::post_deserialize_resolve(
        survarium::usable_object *this@<ecx>,
        survarium::usable_object *a2@<esi>,
        survarium::game_world_core *game_world_core)
{
  unsigned __int8 *m_end; // ebx
  unsigned __int8 *i; // edi
  survarium::usable_object_user_data *p_m_usable_object_user_data; // eax

  m_end = a2->m_deserialized_users.m_end;
  for ( i = a2->m_deserialized_users.m_begin; i != m_end; ++i )
  {
    p_m_usable_object_user_data = &survarium::game_world_core::player(game_world_core, *i)->m_usable_object_user_data;
    p_m_usable_object_user_data->current_object = a2;
    vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<survarium::usable_object_user_data,survarium::usable_object_user_data *,20,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)p_m_usable_object_user_data,
      &a2->m_usable_object_users.m_size);
  }
  a2->m_deserialized_users.m_end = a2->m_deserialized_users.m_begin;
}
