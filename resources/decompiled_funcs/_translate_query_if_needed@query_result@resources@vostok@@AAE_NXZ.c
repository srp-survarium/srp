bool __usercall vostok::resources::query_result::translate_query_if_needed@<al>(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::query_result::only_try_to_get_associated_resource_bool a2@<eax>)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::cook_base *v5; // eax
  vostok::resources::query_result *v6; // ecx
  _DWORD *v7; // ebp
  unsigned int v8; // edi
  vostok::resources::query_result *v9; // ecx
  vostok::resources::query_result::consider_with_name_registry_result_enum v10; // eax
  vostok::resources::query_result *v11; // ecx
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v13; // ecx
  vostok::resources::thread_local_data *thread_local_data; // edi
  int v15; // edi
  vostok::resources::query_result *v16; // ecx

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( !cook || (cook->m_flags.m_flags & 8) == 0 )
    return 0;
  v5 = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( v5 )
  {
    LOBYTE(v6) = v5->m_flags.m_flags & 8;
    v7 = (_BYTE)v6 != 8 ? 0 : (_DWORD *)v5;
  }
  else
  {
    v7 = 0;
  }
  v8 = vostok::resources::query_result::translate_thread_id(v6, a2);
  if ( v8 != GetCurrentThreadId() )
    return 0;
  if ( v7[3] != 1 || !strlen(*(const char **)(a2 + 248)) )
    goto LABEL_15;
  v10 = vostok::resources::query_result::consider_with_name_registry(v9, a2);
  if ( v10 == consider_with_name_registry_result_got_associated_resource
    || v10 == consider_with_name_registry_result_error )
  {
    vostok::resources::query_result::end_query_might_destroy_this(v11);
    return 1;
  }
  if ( v10 == consider_with_name_registry_result_added_as_referer )
    return 1;
LABEL_15:
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 712), 1u);
  CurrentThreadId = GetCurrentThreadId();
  thread_local_data = vostok::resources::resources_manager::get_thread_local_data(
                        v13,
                        vostok::resources::g_resources_manager.m_variable,
                        CurrentThreadId,
                        1);
  ++thread_local_data->in_translate_query_counter;
  (*(void (__thiscall **)(_DWORD *, vostok::resources::query_result::only_try_to_get_associated_resource_bool))(*v7 + 28))(
    v7,
    a2);
  --thread_local_data->in_translate_query_counter;
  v15 = *(_DWORD *)(a2 + 256);
  vostok::threading::interlocked_or((volatile int *)(a2 + 688), 0x4000u);
  vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(v16);
  return v15 != 7;
}
