char __thiscall survarium::messaging_client::read_friend_status(
        survarium::messaging_client *this,
        survarium::messaging_client *reader,
        vostok::network_core::packet_reader *readera)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int16 v5; // cx
  unsigned int *v6; // eax
  unsigned int v7; // ecx
  char v8; // bl
  survarium::account_list_item *M_finish; // esi
  survarium::account_list_item *v10; // eax
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  int v14; // [esp+10h] [ebp-2Ch]
  unsigned int account_id; // [esp+14h] [ebp-28h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-24h] BYREF
  unsigned int readerb; // [esp+44h] [ebp+8h]

  m_pointer = readera->m_pointer;
  v5 = *(_WORD *)m_pointer;
  readera->m_pointer = m_pointer + 2;
  readerb = 0;
  if ( v5 )
  {
    v14 = v5;
    do
    {
      v6 = (unsigned int *)readera->m_pointer;
      v7 = *v6++;
      readera->m_pointer = (const unsigned __int8 *)v6;
      v8 = *(_BYTE *)v6;
      readera->m_pointer = (const unsigned __int8 *)v6 + 1;
      M_finish = reader->m_friend_list._M_impl._M_finish;
      account_id = v7;
      v10 = stlp_std::priv::__find<survarium::account_list_item *,unsigned int>(
              reader->m_friend_list._M_impl._M_start,
              M_finish,
              &account_id);
      if ( v10 == M_finish )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
        {
          v11 = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
          if ( v11 )
          {
            log_callback.functor.obj_ptr = v11;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          readerb |= 1u;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\messaging_client.cpp",
            0x7Cu,
            "bool __thiscall survarium::messaging_client::read_friend_status(class vostok::network_core::packet_reader &)",
            "game:",
            error,
            "Friend list out of sync.");
        }
        if ( (readerb & 1) != 0 )
        {
          readerb &= ~1u;
          if ( log_callback.vtable )
          {
            if ( ((int)log_callback.vtable & 1) == 0 )
            {
              v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
              if ( v12 )
                v12(&log_callback.functor, &log_callback.functor, 2);
            }
          }
        }
      }
      else
      {
        v10->online = v8;
      }
      --v14;
    }
    while ( v14 );
  }
  return 1;
}
