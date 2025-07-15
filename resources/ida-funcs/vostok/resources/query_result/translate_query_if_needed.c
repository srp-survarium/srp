bool __usercall vostok::resources::query_result::translate_query_if_needed@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::translate_query_cook *translate_query_cook; // ebx
  vostok::resources::query_result *v5; // ecx
  int v6; // eax
  vostok::resources::query_result *v7; // ecx
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v9; // ecx
  unsigned int *p_in_translate_query_counter; // edi
  int v11; // edi
  vostok::resources::query_result *v12; // [esp-4h] [ebp-14h]
  unsigned int thread_id; // [esp+Ch] [ebp-4h]

  if ( !vostok::resources::query_result::is_translate_query(this, a2) )
    return 0;
  translate_query_cook = vostok::resources::cook_base::find_translate_query_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  thread_id = vostok::resources::query_result::allocate_thread_id(v12, a2);
  if ( thread_id != GetCurrentThreadId() )
    return 0;
  if ( translate_query_cook->m_reuse_type != reuse_true || !strlen(*(const char **)(a2 + 248)) )
    goto LABEL_11;
  v6 = vostok::resources::query_result::consider_with_name_registry(v5, (char *)a2, 0);
  if ( v6 == 4 || !v6 )
  {
    vostok::resources::query_result::end_query_might_destroy_this(v7, a2);
    return 1;
  }
  if ( v6 == 2 )
    return 1;
LABEL_11:
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 728), 1u);
  CurrentThreadId = GetCurrentThreadId();
  p_in_translate_query_counter = &vostok::resources::resources_manager::get_thread_local_data(
                                    v9,
                                    (unsigned int)&s_resources_manager_buffer,
                                    CurrentThreadId,
                                    1)->in_translate_query_counter;
  ++*p_in_translate_query_counter;
  translate_query_cook->translate_query(translate_query_cook, (vostok::resources::query_result_for_cook *)a2);
  --*p_in_translate_query_counter;
  v11 = *(_DWORD *)(a2 + 256);
  _InterlockedOr((volatile signed __int32 *)(a2 + 704), 0x4000u);
  vostok::resources::query_result::try_push_created_resource_to_manager_might_destroy_this(
    (vostok::resources::query_result *)(a2 + 704),
    a2);
  return v11 != 7;
}
