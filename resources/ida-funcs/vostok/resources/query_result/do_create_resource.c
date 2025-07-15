void __userpurge vostok::resources::query_result::do_create_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>,
        bool *out_finished_create)
{
  bool *v3; // ebx
  volatile signed __int32 *v5; // edi
  vostok::resources::query_result *v6; // ecx
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  vostok::resources::resources_manager *m_variable; // edi
  int v9; // eax
  vostok::resources::query_result *v10; // ecx
  unsigned int v11; // eax
  bool *v12; // [esp+0h] [ebp-10h]

  v3 = out_finished_create;
  v5 = (volatile signed __int32 *)(a2 + 684);
  vostok::resources::query_result::do_create_resource_impl(
    (vostok::resources::query_result *)_InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 1u),
    a2);
  if ( v3 )
    *v3 = *(_DWORD *)(a2 + 256) == 0;
  if ( *(_DWORD *)(a2 + 224) )
  {
    vostok::threading::interlocked_and((volatile int *)(a2 + 688), 0xFFDFFFFF);
    v7 = (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)_InterlockedExchangeAdd(v5, 0xFFFFFFFF);
    m_variable = vostok::resources::g_resources_manager.m_variable;
    vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      (char *)&loc_2044D + (unsigned int)vostok::resources::g_resources_manager.m_variable + 3,
      (vostok::resources::query_result *)a2,
      v12);
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)m_variable));
  }
  else
  {
    v9 = *(_DWORD *)(a2 + 260);
    if ( v9 == 2 || v9 == 5 )
    {
      if ( !_InterlockedExchangeAdd(v5, 0xFFFFFFFF) )
        vostok::resources::query_result::end_query_might_destroy_this_impl(v6);
    }
    else
    {
      vostok::resources::query_result::do_create_resource_end_part(v6, a2);
      if ( _InterlockedExchangeAdd(v5, 0xFFFFFFFF)
        || (vostok::resources::query_result::end_query_might_destroy_this_impl(v10), debug_macro_helper_ignore_always_20) )
      {
        vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v10);
      }
      else
      {
        v11 = occurances_left_20;
        if ( occurances_left_20 == -1 )
          v11 = 10;
        occurances_left_20 = v11 - 1;
        if ( v11 )
        {
          LOBYTE(out_finished_create) = 0;
          vostok::debug::on_error(
            (unsigned int)v3,
            (bool *)&out_finished_create,
            process_error_false,
            &debug_macro_helper_ignore_always_20,
            assert_untyped,
            "assertion_failed",
            (const char *)&stru_95AF78.m_key_bindings[6],
            ".\\resources_query_result_cook.cpp",
            "vostok::resources::query_result::do_create_resource",
            0xF5u);
          if ( vostok::debug::is_debugger_present() || (_BYTE)out_finished_create )
            __debugbreak();
        }
      }
    }
  }
}
