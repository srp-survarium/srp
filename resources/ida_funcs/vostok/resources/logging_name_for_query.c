vostok::fixed_string<512> *__usercall vostok::resources::logging_name_for_query@<eax>(
        vostok::resources::query_result *query@<ecx>,
        int a2@<esi>)
{
  bool v2; // zf
  const char *v3; // ebx
  vostok::resources::class_id_enum m_class_id; // eax
  const char *v5; // edx
  char *m_requery_path; // eax
  char *m_begin; // [esp-4h] [ebp-218h]
  vostok::fixed_string<512> out_result; // [esp+8h] [ebp-20Ch] BYREF
  _UNKNOWN *retaddr; // [esp+214h] [ebp+0h] BYREF

  v2 = query->m_quality_levels_count == 1;
  out_result.m_begin = out_result.m_buffer;
  out_result.m_end = out_result.m_buffer;
  out_result.m_max_end = (char *)&retaddr;
  out_result.m_buffer[0] = 0;
  v3 = "Q";
  if ( v2 )
    v3 = (const char *)&buf;
  m_class_id = query->m_class_id;
  if ( m_class_id == test_resource_class1 )
  {
    v5 = "A";
  }
  else if ( m_class_id == test_resource_class2 )
  {
    v5 = "B";
  }
  else
  {
    v5 = "C";
    if ( m_class_id != test_resource_class3 )
      v5 = (const char *)&buf;
  }
  m_requery_path = query->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = query->m_request_path;
  vostok::buffer_string::assignf(&out_result, "'%s%s %s' [quid %d]", m_requery_path, v5, v3, query->m_uid);
  m_begin = out_result.m_begin;
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 524;
  *(_BYTE *)(a2 + 12) = 0;
  vostok::buffer_string::operator+=((vostok::buffer_string *)a2, m_begin);
  return (vostok::fixed_string<512> *)a2;
}
