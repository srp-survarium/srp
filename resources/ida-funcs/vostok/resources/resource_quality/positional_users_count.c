unsigned int __thiscall vostok::resources::resource_quality::positional_users_count(
        vostok::resources::resource_quality *this,
        vostok::threading::simple_lock *resource_user)
{
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *p_m_thread_id; // esi
  const vostok::threading::simple_lock *v5; // eax
  vostok::resources::resource_link *no_dying; // eax
  int v7; // edi
  vostok::resources::resource_link *v8; // esi
  vostok::threading::simple_lock::mutex_raii v9; // [esp+8h] [ebp-8h] BYREF

  if ( resource_user )
  {
    if ( ((unsigned __int8)((resource_user[1].m_lock & 8) - 8) == 0 ? (unsigned int)resource_user : 0) != 0 )
      return 1;
    p_m_thread_id = (vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)&resource_user[7].m_thread_id;
  }
  else
  {
    p_m_thread_id = &this->m_parent_resources;
  }
  if ( p_m_thread_id )
    v5 = &p_m_thread_id->vostok::threading::simple_lock;
  else
    v5 = 0;
  v9.lock = v5;
  vostok::threading::simple_lock::lock(resource_user, (int)v5);
  v9.locked = 1;
  no_dying = vostok::resources::resource_link_list_front_no_dying(p_m_thread_id);
  v7 = 0;
  while ( 1 )
  {
    v8 = no_dying;
    if ( !no_dying )
      break;
    v7 += vostok::resources::resource_quality::positional_users_count(
            this,
            (vostok::threading::simple_lock *)no_dying->resource);
    no_dying = vostok::resources::resource_link_list_next_no_dying(v8);
  }
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v9);
  return v7;
}
