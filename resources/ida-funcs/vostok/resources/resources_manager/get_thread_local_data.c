vostok::resources::thread_local_data *__thiscall vostok::resources::resources_manager::get_thread_local_data(
        vostok::resources::resources_manager *this,
        unsigned int thread_id,
        unsigned int create_if_not_exist,
        char a4)
{
  vostok::threading::reader_writer_lock *v5; // ecx
  unsigned int v6; // edi
  vostok::buffer_string *v7; // esi
  vostok::threading::reader_writer_lock *v8; // ecx
  char *v9; // edi
  volatile signed __int64 *v10; // ebx
  vostok::threading::reader_writer_lock *v11; // ecx
  char *m_begin; // eax
  char *v13; // ecx
  char *v14; // eax
  char *v15; // edx
  char *v16; // eax
  vostok::memory::doug_lea_allocator *v17; // esi
  vostok::memory::doug_lea_allocator *v18; // ecx
  char *v19; // eax
  vostok::resources::thread_local_data *v20; // ecx
  char *v21; // eax
  vostok::memory::pthreads3_allocator *v22; // ecx
  char *v23; // eax
  vostok::threading::reader_writer_lock *v24; // ecx
  vostok::threading::reader_writer_lock *v26; // [esp-4h] [ebp-28h]
  const char *v27; // [esp+0h] [ebp-24h]
  const char *v28; // [esp+4h] [ebp-20h]
  unsigned int v29; // [esp+8h] [ebp-1Ch]
  char v30; // [esp+10h] [ebp-14h] BYREF
  volatile signed __int64 *v31; // [esp+18h] [ebp-Ch]
  vostok::threading::lock_type_enum v32; // [esp+1Ch] [ebp-8h]
  char *Value; // [esp+2Ch] [ebp+8h]

  Value = 0;
  v6 = create_if_not_exist;
  if ( GetCurrentThreadId() == create_if_not_exist
    && (Value = (char *)TlsGetValue(*(_DWORD *)((char *)&loc_203D0 + thread_id))) != 0 )
  {
    v7 = (vostok::buffer_string *)(Value + 560);
    v9 = (char *)vostok::threading::current_thread_logging_name();
    if ( *((_DWORD *)Value + 141) == *((_DWORD *)Value + 140) && strlen(v9) )
    {
      v10 = (volatile signed __int64 *)((char *)&loc_203B8 + thread_id);
      vostok::threading::reader_writer_lock::lock_write_impl(v8, v10);
      m_begin = v7->m_begin;
      if ( v7->m_begin != v9 )
      {
        *((_DWORD *)Value + 141) = m_begin;
        *m_begin = 0;
        vostok::buffer_string::operator+=(v7, v9);
      }
      vostok::threading::reader_writer_lock::unlock(v11, v10, lock_type_write);
    }
  }
  else
  {
    v32 = (a4 != 0) + 1;
    v31 = (volatile signed __int64 *)((char *)&loc_203B8 + thread_id);
    vostok::threading::reader_writer_lock::lock(v5, (volatile signed __int64 *)((char *)&loc_203B8 + thread_id), v32);
    v13 = (char *)&loc_203C0 + thread_id;
    v14 = *(char **)((char *)&loc_203C0 + thread_id);
    v15 = (char *)&loc_203C0 + thread_id;
    if ( !v14 )
      goto LABEL_15;
    do
    {
      if ( *((_DWORD *)v14 - 1) >= create_if_not_exist )
      {
        v15 = v14;
        v14 = (char *)*((_DWORD *)v14 + 1);
      }
      else
      {
        v14 = (char *)*((_DWORD *)v14 + 2);
      }
    }
    while ( v14 );
    v13 = (char *)&loc_203C0 + thread_id;
    if ( v15 == (char *)&loc_203C0 + thread_id || create_if_not_exist < *((_DWORD *)v15 - 1) )
LABEL_15:
      v15 = v13;
    if ( v15 == v13 )
    {
      if ( a4 )
      {
        if ( GetCurrentThreadId() == *(_DWORD *)((char *)&loc_203D3 + thread_id + 1) )
        {
          v16 = type_info::raw_name(&vostok::resources::thread_local_data `RTTI Type Descriptor');
          v17 = &vostok::memory::g_resources_helper_allocator;
          v19 = vostok::memory::doug_lea_allocator::malloc_impl(
                  v18,
                  (int)&vostok::memory::g_resources_helper_allocator,
                  0x278u,
                  v16,
                  v27,
                  v28,
                  v29);
        }
        else
        {
          v21 = type_info::raw_name(&vostok::resources::thread_local_data `RTTI Type Descriptor');
          v17 = (vostok::memory::doug_lea_allocator *)&vostok::memory::g_mt_allocator;
          v19 = vostok::memory::pthreads3_allocator::malloc_impl(
                  v22,
                  (int)&vostok::memory::g_mt_allocator,
                  (const char *const)0x278,
                  v21,
                  v27,
                  (const unsigned int)v28);
        }
        if ( v19 )
        {
          vostok::resources::thread_local_data::thread_local_data(v20, (int)v19, create_if_not_exist, v17);
          v6 = create_if_not_exist;
          Value = v23;
        }
        else
        {
          Value = 0;
        }
        boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0>>::insert_unique(
          (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *)v20,
          (boost::intrusive::rbtree_node<void *> *)((char *)&loc_203C0 + thread_id),
          (vostok::resources::thread_local_data *)&v30,
          (int)Value);
      }
    }
    else
    {
      Value = v15 - 612;
    }
    if ( GetCurrentThreadId() == v6 && Value )
    {
      vostok::threading::tls_set_value(*(_DWORD *)((char *)&loc_203D0 + thread_id), Value);
      v24 = v26;
    }
    vostok::threading::reader_writer_lock::unlock(v24, v31, v32);
  }
  return (vostok::resources::thread_local_data *)Value;
}
