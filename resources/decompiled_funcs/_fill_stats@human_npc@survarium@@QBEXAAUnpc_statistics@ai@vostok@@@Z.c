void __userpurge survarium::human_npc::fill_stats(
        survarium::human_npc *this@<ecx>,
        int a2@<eax>,
        vostok::ai::npc_statistics *stats)
{
  char *m_begin; // eax
  char *m_buffer; // eax
  const char *v6; // esi
  bool v7; // zf
  char *v8; // ebp
  unsigned int v9; // esi
  vostok::fixed_string<64> *m_end; // esi
  char *v11; // edx
  int v12; // ecx
  int v13; // ebp
  char *v14; // eax
  float v15; // ecx
  vostok::fixed_string<64> *v16; // esi
  char *v17; // edx
  int v18; // ecx
  int v19; // ebp
  char *v20; // eax
  float *v21; // esi
  int v22; // eax
  int v23; // eax
  vostok::fixed_string<64> *v24; // esi
  char *v25; // edx
  int v26; // ecx
  int v27; // ebp
  unsigned __int64 v28; // [esp+1Ch] [ebp-90h] BYREF
  int v29; // [esp+24h] [ebp-88h]
  __int64 v30; // [esp+38h] [ebp-74h] BYREF
  float v31; // [esp+40h] [ebp-6Ch]
  __int64 v32; // [esp+44h] [ebp-68h] BYREF
  float v33; // [esp+4Ch] [ebp-60h]
  __int64 v34; // [esp+50h] [ebp-5Ch] BYREF
  float v35; // [esp+58h] [ebp-54h]
  vostok::fixed_string<64> new_item_content; // [esp+5Ch] [ebp-50h] BYREF
  char v37; // [esp+A8h] [ebp-4h] BYREF

  m_begin = stats->general_state.caption.m_begin;
  if ( m_begin != "general properties:" )
  {
    stats->general_state.caption.m_end = m_begin;
    HIDWORD(v28) = "general properties:";
    *m_begin = 0;
    vostok::buffer_string::operator+=(&stats->general_state.caption, (const char *)HIDWORD(v28));
  }
  m_buffer = new_item_content.m_buffer;
  new_item_content.m_begin = new_item_content.m_buffer;
  new_item_content.m_end = new_item_content.m_buffer;
  new_item_content.m_max_end = &v37;
  new_item_content.m_buffer[0] = 0;
  v6 = "name: ";
  do
  {
    if ( m_buffer >= new_item_content.m_max_end )
      break;
    *m_buffer = *v6;
    m_buffer = new_item_content.m_end + 1;
    v7 = *++v6 == 0;
    ++new_item_content.m_end;
  }
  while ( !v7 );
  *m_buffer = 0;
  v8 = (char *)(**(int (__thiscall ***)(int))(a2 + 4))(a2 + 4);
  v9 = strlen(v8);
  memcpy((unsigned __int8 *)new_item_content.m_end, (unsigned __int8 *)v8, v9);
  new_item_content.m_end += v9;
  *new_item_content.m_end = 0;
  m_end = stats->general_state.content.m_end;
  if ( m_end )
  {
    v11 = new_item_content.m_begin;
    v12 = new_item_content.m_end - new_item_content.m_begin;
    m_end->m_max_end = (char *)&m_end[1];
    v13 = v12;
    v28 = __PAIR64__(v12, (unsigned int)v11);
    m_end->m_begin = m_end->m_buffer;
    m_end->m_end = m_end->m_buffer;
    memcpy((unsigned __int8 *)m_end->m_buffer, (unsigned __int8 *)v28, HIDWORD(v28));
    m_end->m_end += v13;
    *m_end->m_end = 0;
  }
  v14 = new_item_content.m_begin;
  ++stats->general_state.content.m_end;
  new_item_content.m_end = v14;
  *v14 = 0;
  v15 = *(float *)(a2 + 616);
  v30 = *(_QWORD *)(a2 + 608);
  v32 = v30;
  v34 = v30;
  v31 = v15;
  v33 = v15;
  v35 = v15;
  vostok::buffer_string::appendf(
    (vostok::buffer_string *)&stru_972F7C,
    (const char *)COERCE_UNSIGNED_INT64(*(float *)&v30),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&v30)),
    *((float *)&v30 + 1),
    v15);
  v16 = stats->general_state.content.m_end;
  if ( v16 )
  {
    v17 = new_item_content.m_begin;
    v18 = new_item_content.m_end - new_item_content.m_begin;
    v16->m_max_end = (char *)&v16[1];
    v19 = v18;
    v28 = __PAIR64__(v18, (unsigned int)v17);
    v16->m_begin = v16->m_buffer;
    v16->m_end = v16->m_buffer;
    memcpy((unsigned __int8 *)v16->m_buffer, (unsigned __int8 *)v28, HIDWORD(v28));
    v16->m_end += v19;
    *v16->m_end = 0;
  }
  v20 = new_item_content.m_begin;
  ++stats->general_state.content.m_end;
  new_item_content.m_end = v20;
  *v20 = 0;
  v21 = (float *)(*(int (__thiscall **)(int, __int64 *, int))(*(_DWORD *)a2 + 16))(a2, &v34, v29);
  v22 = (*(int (__thiscall **)(int, char *))(*(_DWORD *)a2 + 16))(a2, (char *)&v32 + 4);
  v23 = (*(int (__thiscall **)(int, char *, _DWORD, _DWORD))(*(_DWORD *)a2 + 16))(
          a2,
          (char *)&v30 + 4,
          COERCE_UNSIGNED_INT64(*(float *)(v22 + 8)),
          HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(v22 + 8))));
  vostok::buffer_string::appendf(
    (vostok::buffer_string *)&stru_972F94,
    (const char *)COERCE_UNSIGNED_INT64(*v21),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(*v21)),
    *(float *)(v23 + 4));
  v24 = stats->general_state.content.m_end;
  if ( v24 )
  {
    v25 = new_item_content.m_begin;
    v26 = new_item_content.m_end - new_item_content.m_begin;
    v24->m_max_end = (char *)&v24[1];
    v27 = v26;
    v28 = __PAIR64__(v26, (unsigned int)v25);
    v24->m_begin = v24->m_buffer;
    v24->m_end = v24->m_buffer;
    memcpy((unsigned __int8 *)v24->m_buffer, (unsigned __int8 *)v28, HIDWORD(v28));
    v24->m_end += v27;
    *v24->m_end = 0;
  }
  ++stats->general_state.content.m_end;
  survarium::damage_model::fill_stats(
    *(survarium::damage_model **)(*(_DWORD *)(a2 + 348) + 272),
    stats,
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 336) + 168) + 1012));
  v28 = (unsigned int)(a2 + 340);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28
  + 1,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v28);
  (*(void (__thiscall **)(_DWORD, vostok::ai::npc_statistics *, _DWORD))(**(_DWORD **)(a2 + 324) + 76))(
    *(_DWORD *)(a2 + 324),
    stats,
    HIDWORD(v28));
}
