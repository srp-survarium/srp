int __usercall vostok::render::compare@<eax>(const vostok::render::res_declaration *right@<eax>, unsigned int left)
{
  unsigned int v2; // ebx
  bool v5; // cf
  int *p_left; // eax
  int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = left;
  if ( (*(_DWORD *)(left + 1044) - *(_DWORD *)(left + 1040)) / 28 < (unsigned int)(right->dcl_code.m_end
                                                                                 - right->dcl_code.m_begin) )
    return -1;
  if ( (*(_DWORD *)(left + 1044) - *(_DWORD *)(left + 1040)) / 28 > (unsigned int)(right->dcl_code.m_end
                                                                                 - right->dcl_code.m_begin) )
    return 1;
  left = right->dcl_code.m_end - right->dcl_code.m_begin;
  v5 = left < (*(_DWORD *)(v2 + 1044) - *(_DWORD *)(v2 + 1040)) / 28;
  v7 = (*(_DWORD *)(v2 + 1044) - *(_DWORD *)(v2 + 1040)) / 28;
  p_left = (int *)&left;
  if ( !v5 )
    p_left = &v7;
  return memcmp(*(const char **)(v2 + 1040), (const char *)right->dcl_code.m_begin, 28 * *p_left);
}


int __fastcall vostok::render::compare(const vostok::render::res_pass *right, const vostok::render::res_pass *left)
{
  vostok::render::res_state *m_object; // eax
  vostok::render::res_state *v3; // esi
  int result; // eax
  vostok::render::res_xs<vostok::render::ps_data> *v5; // eax
  vostok::render::res_xs<vostok::render::ps_data> *v6; // esi
  vostok::render::res_xs<vostok::render::vs_data> *v7; // eax
  vostok::render::res_xs<vostok::render::vs_data> *v8; // esi
  vostok::render::res_xs<vostok::render::gs_data> *v9; // eax
  vostok::render::res_xs<vostok::render::gs_data> *v10; // esi
  vostok::render::res_input_layout *v11; // edx
  vostok::render::res_input_layout *v12; // ecx

  m_object = left->m_state.m_object;
  v3 = right->m_state.m_object;
  if ( v3 > m_object )
    return -1;
  result = v3 < m_object;
  if ( !result )
  {
    v5 = left->m_ps.m_object;
    v6 = right->m_ps.m_object;
    if ( v6 > v5 )
      return -1;
    result = v6 < v5;
    if ( result )
      return result;
    v7 = left->m_vs.m_object;
    v8 = right->m_vs.m_object;
    if ( v8 > v7 )
      return -1;
    result = v8 < v7;
    if ( result )
      return result;
    v9 = left->m_gs.m_object;
    v10 = right->m_gs.m_object;
    if ( v10 > v9 )
      return -1;
    result = v10 < v9;
    if ( result )
      return result;
    v11 = left->m_input_layout.m_object;
    v12 = right->m_input_layout.m_object;
    if ( v12 > v11 )
      return -1;
    result = v12 < v11;
    if ( v12 >= v11 )
      return 0;
  }
  return result;
}


int __usercall vostok::render::compare@<eax>(
        const vostok::render::res_shader_technique *left@<ecx>,
        const vostok::render::res_shader_technique *right@<eax>)
{
  vostok::render::res_shader_technique::sflags m_flags; // edx
  vostok::render::res_shader_technique::sflags v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int result; // eax
  unsigned int v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // ecx
  int v18; // eax
  int v19; // ecx
  bool v20; // cf
  int *v21; // eax
  unsigned int v22; // ebx
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_begin; // edi
  char *v24; // esi
  int v25; // [esp+Ch] [ebp-Ch] BYREF
  int v26; // [esp+10h] [ebp-8h] BYREF
  unsigned int v27; // [esp+14h] [ebp-4h]

  m_flags = right->m_flags;
  v5 = left->m_flags;
  v6 = *(_BYTE *)&v5 & 3;
  v7 = *(_BYTE *)&m_flags & 3;
  if ( v7 > v6 )
    return -1;
  result = v7 < v6;
  if ( !result )
  {
    v9 = (*(unsigned int *)&v5 >> 2) & 1;
    v10 = (*(unsigned int *)&m_flags >> 2) & 1;
    if ( v10 > v9 )
      return -1;
    result = v10 < v9;
    if ( result )
      return result;
    v11 = (*(unsigned int *)&v5 >> 3) & 1;
    v12 = (*(unsigned int *)&m_flags >> 3) & 1;
    if ( v12 > v11 )
      return -1;
    result = v12 < v11;
    if ( result )
      return result;
    v13 = (*(unsigned int *)&v5 >> 5) & 1;
    v14 = (*(unsigned int *)&m_flags >> 5) & 1;
    if ( v14 > v13 )
      return -1;
    result = v14 < v13;
    if ( result )
      return result;
    v15 = (*(unsigned int *)&v5 >> 4) & 1;
    v16 = (*(unsigned int *)&m_flags >> 4) & 1;
    if ( v16 > v15 )
      return -1;
    result = v16 < v15;
    if ( v16 < v15 )
      return result;
    if ( left->m_passes.m_end - left->m_passes.m_begin < (unsigned int)(right->m_passes.m_end - right->m_passes.m_begin) )
      return -1;
    v17 = left->m_passes.m_end - left->m_passes.m_begin;
    result = right->m_passes.m_end - right->m_passes.m_begin < v17;
    if ( right->m_passes.m_end - right->m_passes.m_begin >= v17 )
    {
      v18 = (char *)right->m_passes.m_end - (char *)right->m_passes.m_begin;
      v19 = (char *)left->m_passes.m_end - (char *)left->m_passes.m_begin;
      v27 = 0;
      v19 >>= 2;
      v26 = v18 >> 2;
      v20 = v18 >> 2 < (unsigned int)v19;
      v25 = v19;
      v21 = &v26;
      if ( !v20 )
        v21 = &v25;
      v22 = *v21;
      if ( *v21 )
      {
        m_begin = left->m_passes.m_begin;
        v24 = (char *)((char *)right->m_passes.m_begin - (char *)m_begin);
        while ( 1 )
        {
          result = vostok::render::compare(
                     *(const vostok::render::res_pass **)((char *)&m_begin->m_object + (_DWORD)v24),
                     m_begin->m_object);
          if ( result )
            break;
          ++v27;
          ++m_begin;
          if ( v27 >= v22 )
            return 0;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}


int __usercall vostok::render::compare@<eax>(
        const vostok::render::shader_constant *left@<ecx>,
        const vostok::render::shader_constant *right@<eax>)
{
  vostok::shared_string *p_m_name; // ebx
  vostok::strings::shared::profile *v6; // ebx
  void *m_pointer; // eax
  void *v8; // ecx
  unsigned int m_size; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int m_value_high; // edi
  unsigned int v14; // esi
  vostok::shared_string *v15; // [esp+Ch] [ebp-Ch]
  vostok::shared_string *v16; // [esp+10h] [ebp-8h]
  vostok::strings::shared::profile *v17; // [esp+14h] [ebp-4h]

  p_m_name = &left->m_host->m_name;
  v15 = p_m_name;
  v16 = &right->m_host->m_name;
  v17 = vostok::shared_string::c_str(v16);
  if ( vostok::shared_string::c_str(p_m_name) < v17 )
    return -1;
  v6 = vostok::shared_string::c_str(v16);
  if ( vostok::shared_string::c_str(v15) > v6 )
    return 1;
  m_pointer = left->m_source.m_pointer;
  v8 = right->m_source.m_pointer;
  if ( m_pointer < v8 )
    return -1;
  if ( m_pointer > v8 )
    return 1;
  m_size = left->m_source.m_size;
  v10 = right->m_source.m_size;
  if ( m_size < v10 )
    return -1;
  if ( m_size > v10 )
    return 1;
  v11 = *(_DWORD *)&left->m_slot.m_class_id;
  v12 = *(_DWORD *)&right->m_slot.m_class_id;
  m_value_high = HIDWORD(left->m_slot.m_value);
  v14 = HIDWORD(right->m_slot.m_value);
  if ( m_value_high > v14 )
    return 1;
  if ( m_value_high < v14 || v11 < v12 )
    return -1;
  return __PAIR64__(m_value_high, v11) > __PAIR64__(v14, v12);
}
