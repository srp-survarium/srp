int __usercall vostok::render::compare@<eax>(
        const vostok::render::res_declaration *left@<ecx>,
        const vostok::render::res_declaration *right@<eax>)
{
  unsigned int v5; // ecx
  unsigned int *v6; // eax
  D3D11_INPUT_ELEMENT_DESC *M_start; // esi
  D3D11_INPUT_ELEMENT_DESC *v8; // edi
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  if ( left->dcl_code._M_impl._M_finish - left->dcl_code._M_impl._M_start < (unsigned int)(right->dcl_code._M_impl._M_finish
                                                                                         - right->dcl_code._M_impl._M_start) )
    return -1;
  if ( left->dcl_code._M_impl._M_finish - left->dcl_code._M_impl._M_start > (unsigned int)(right->dcl_code._M_impl._M_finish
                                                                                         - right->dcl_code._M_impl._M_start) )
    return 1;
  v5 = right->dcl_code._M_impl._M_finish - right->dcl_code._M_impl._M_start;
  v12 = left->dcl_code._M_impl._M_finish - left->dcl_code._M_impl._M_start;
  v11 = v5;
  v6 = &v11;
  if ( v5 >= v12 )
    v6 = &v12;
  M_start = right->dcl_code._M_impl._M_start;
  v8 = left->dcl_code._M_impl._M_start;
  v9 = 28 * *v6;
  if ( v9 < 4 )
  {
LABEL_10:
    if ( !v9 )
      return 0;
  }
  else
  {
    while ( v8->SemanticName == M_start->SemanticName )
    {
      v9 -= 4;
      M_start = (D3D11_INPUT_ELEMENT_DESC *)((char *)M_start + 4);
      v8 = (D3D11_INPUT_ELEMENT_DESC *)((char *)v8 + 4);
      if ( v9 < 4 )
        goto LABEL_10;
    }
  }
  v10 = LOBYTE(v8->SemanticName) - LOBYTE(M_start->SemanticName);
  if ( v10 )
    return (v10 >> 31) | 1;
  if ( v9 <= 1 )
    return 0;
  v10 = BYTE1(v8->SemanticName) - BYTE1(M_start->SemanticName);
  if ( v10 )
    return (v10 >> 31) | 1;
  if ( v9 <= 2 )
    return 0;
  v10 = BYTE2(v8->SemanticName) - BYTE2(M_start->SemanticName);
  if ( v10 )
    return (v10 >> 31) | 1;
  if ( v9 > 3 )
  {
    v10 = HIBYTE(v8->SemanticName) - HIBYTE(M_start->SemanticName);
    return (v10 >> 31) | 1;
  }
  return 0;
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


int __cdecl vostok::render::compare(
        const vostok::render::res_shader_technique *left,
        const vostok::render::res_shader_technique *right)
{
  const vostok::render::res_shader_technique *v2; // ebx
  vostok::render::res_shader_technique::sflags m_flags; // edx
  const vostok::render::res_shader_technique *v4; // ebp
  vostok::render::res_shader_technique::sflags v5; // ecx
  int result; // eax
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edx
  const vostok::render::res_shader_technique *v16; // ecx
  unsigned int v17; // edi
  const vostok::render::res_shader_technique **p_right; // eax
  const vostok::render::res_pass **p_m_object; // esi
  int v20; // ebx

  v2 = right;
  m_flags = right->m_flags;
  v4 = left;
  v5 = left->m_flags;
  if ( (*(_BYTE *)&m_flags & 3u) > (*(_BYTE *)&v5 & 3u) )
    return -1;
  result = (*(_BYTE *)&m_flags & 3u) < (*(_BYTE *)&v5 & 3u);
  if ( (*(_BYTE *)&m_flags & 3u) >= (*(_BYTE *)&v5 & 3u) )
  {
    v7 = (*(unsigned int *)&v5 >> 2) & 1;
    v8 = (*(unsigned int *)&m_flags >> 2) & 1;
    if ( v8 > v7 )
      return -1;
    result = v8 < v7;
    if ( result )
      return result;
    v9 = (*(unsigned int *)&v5 >> 3) & 1;
    v10 = (*(unsigned int *)&m_flags >> 3) & 1;
    if ( v10 > v9 )
      return -1;
    result = v10 < v9;
    if ( result )
      return result;
    v11 = (*(unsigned int *)&v5 >> 5) & 1;
    v12 = (*(unsigned int *)&m_flags >> 5) & 1;
    if ( v12 > v11 )
      return -1;
    result = v12 < v11;
    if ( result )
      return result;
    v13 = (*(unsigned int *)&v5 >> 4) & 1;
    v14 = (*(unsigned int *)&m_flags >> 4) & 1;
    if ( v14 > v13 )
      return -1;
    result = v14 < v13;
    if ( v14 < v13 )
      return result;
    if ( left->m_passes._M_impl._M_finish - left->m_passes._M_impl._M_start < (unsigned int)(right->m_passes._M_impl._M_finish
                                                                                           - right->m_passes._M_impl._M_start) )
      return -1;
    v15 = right->m_passes._M_impl._M_finish - right->m_passes._M_impl._M_start;
    result = v15 < left->m_passes._M_impl._M_finish - left->m_passes._M_impl._M_start;
    if ( v15 >= left->m_passes._M_impl._M_finish - left->m_passes._M_impl._M_start )
    {
      v16 = (const vostok::render::res_shader_technique *)(left->m_passes._M_impl._M_finish
                                                         - left->m_passes._M_impl._M_start);
      v17 = 0;
      right = (const vostok::render::res_shader_technique *)(right->m_passes._M_impl._M_finish
                                                           - right->m_passes._M_impl._M_start);
      left = v16;
      p_right = &right;
      if ( right >= v16 )
        p_right = &left;
      right = *p_right;
      if ( right )
      {
        p_m_object = (const vostok::render::res_pass **)&v4->m_passes._M_impl._M_start->m_object;
        v20 = (char *)v2->m_passes._M_impl._M_start - (char *)p_m_object;
        while ( 1 )
        {
          result = vostok::render::compare(*(const vostok::render::res_pass **)((char *)p_m_object + v20), *p_m_object);
          if ( result )
            break;
          ++v17;
          ++p_m_object;
          if ( v17 >= (unsigned int)right )
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
        const vostok::render::shader_constant *right@<eax>,
        const vostok::render::shader_constant *left)
{
  int result; // eax
  void *m_pointer; // eax
  void *v5; // ecx
  unsigned int m_size; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned int m_value_high; // ebx
  unsigned int v11; // edi

  result = vostok::render::compare(left->m_host, right->m_host);
  if ( !result )
  {
    m_pointer = left->m_source.m_pointer;
    v5 = right->m_source.m_pointer;
    if ( m_pointer < v5 )
      return -1;
    if ( m_pointer > v5 )
      return 1;
    m_size = left->m_source.m_size;
    v7 = right->m_source.m_size;
    if ( m_size < v7 )
      return -1;
    if ( m_size > v7 )
      return 1;
    v8 = *(_DWORD *)&left->m_slot.m_class_id;
    v9 = *(_DWORD *)&right->m_slot.m_class_id;
    m_value_high = HIDWORD(left->m_slot.m_value);
    v11 = HIDWORD(right->m_slot.m_value);
    if ( m_value_high > v11 )
      return 1;
    if ( m_value_high < v11 || v8 < v9 )
      return -1;
    return __PAIR64__(m_value_high, v8) > __PAIR64__(v11, v9);
  }
  return result;
}


int __usercall vostok::render::compare@<eax>(
        const vostok::render::shader_constant_host *left@<edx>,
        const vostok::render::shader_constant_host *right@<esi>)
{
  vostok::strings::shared::profile *m_object; // eax
  unsigned int v3; // ecx
  vostok::strings::shared::profile *v4; // eax
  vostok::strings::shared::profile *v6; // eax
  unsigned int v7; // ecx
  vostok::strings::shared::profile *v8; // eax

  m_object = left->m_name.m_pointer.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v3 = (unsigned int)&m_object[1];
  }
  else
  {
    v3 = 0;
  }
  v4 = right->m_name.m_pointer.m_object;
  if ( v4
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && v3 < (unsigned int)&v4[1] )
  {
    return -1;
  }
  v6 = left->m_name.m_pointer.m_object;
  if ( v6
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v7 = (unsigned int)&v6[1];
  }
  else
  {
    v7 = 0;
  }
  v8 = right->m_name.m_pointer.m_object;
  if ( v8
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    return (unsigned int)&v8[1] < v7;
  }
  else
  {
    return v7 != 0;
  }
}


int __cdecl vostok::render::compare(
        const vostok::render::res_xs<vostok::render::vs_data> *left,
        const vostok::render::res_xs<vostok::render::vs_data> *right)
{
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // ecx
  vostok::render::res_xs_hw<vostok::render::vs_data> *v3; // eax
  int result; // eax

  m_object = right->m_hardware_shader.m_object;
  v3 = left->m_hardware_shader.m_object;
  if ( m_object > v3 )
    return -1;
  result = m_object < v3;
  if ( !result )
  {
    result = vostok::render::shader_constant_table::compare(left->m_constants.m_object, right->m_constants.m_object);
    if ( !result )
    {
      result = vostok::render::res_texture_list::compare(left->m_textures.m_object, right->m_textures.m_object);
      if ( !result )
        return vostok::render::res_sampler_list::compare(left->m_samplers.m_object, right->m_samplers.m_object);
    }
  }
  return result;
}
