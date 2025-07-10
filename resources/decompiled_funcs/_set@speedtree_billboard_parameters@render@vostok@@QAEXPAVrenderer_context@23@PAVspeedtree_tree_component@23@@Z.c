void __userpurge vostok::render::speedtree_billboard_parameters::set(
        vostok::render::speedtree_billboard_parameters *this@<ecx>,
        unsigned int a2@<esi>,
        vostok::render::constants_handler<0> **context,
        vostok::render::renderer_context *tree_component,
        int sine)
{
  vostok::render::speedtree_billboard_parameters *m_scene; // ecx
  vostok::render::constants_handler<0> **v6; // ebx
  int v7; // edi
  float v8; // xmm0_4
  char *v9; // eax
  const char *m_conflicted_key_name; // esi
  int v11; // ecx
  int *v12; // edi
  float v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // ecx
  float v16; // xmm0_4
  vostok::render::constants_handler<0> *v17; // eax
  unsigned int m_diff_range_start; // ecx
  int m_diff_range_start_low; // ecx
  vostok::render::speedtree_forest *m_speedtree_forest; // eax
  float m_fCameraPitch; // xmm0_4
  vostok::render::constants_handler<0> *v22; // eax
  unsigned int v23; // ecx
  int v24; // ecx
  void *v25; // esp
  unsigned int v26; // edx
  int v27; // ecx
  int v28; // eax
  int v29; // xmm0_4
  int v30; // eax
  vostok::render::constants_handler<0> *v31; // eax
  int v32; // ecx
  char *v33; // eax
  int v34; // ecx
  int v35; // ecx
  vostok::render::constants_handler<0> *v36; // eax
  int v37; // ecx
  float _X; // [esp+0h] [ebp-30h]
  char v39[4]; // [esp+4h] [ebp-2Ch] BYREF
  unsigned int v40; // [esp+8h] [ebp-28h]
  char src_ptr[8]; // [esp+14h] [ebp-1Ch] BYREF
  __int64 v42; // [esp+1Ch] [ebp-14h]
  char v43[4]; // [esp+24h] [ebp-Ch] BYREF
  float azimuth; // [esp+28h] [ebp-8h]
  float sinea; // [esp+40h] [ebp+10h]

  m_scene = (vostok::render::speedtree_billboard_parameters *)tree_component->m_scene;
  v6 = context;
  azimuth = *((float *)&m_scene[34].m_billboard_tangents_parameter[11].m_shader_slots[0].m_value + 1);
  v40 = a2;
  vostok::render::speedtree_billboard_parameters::set_billboard_tangents(m_scene, a2, context, azimuth);
  v7 = *(_DWORD *)(sine + 4);
  v8 = *(float *)(v7 + 608);
  v9 = (char *)context[1];
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v11 = *((_DWORD *)v9 + 9);
  v12 = (int *)(v7 + 600);
  v13 = v8 * 0.5;
  *(float *)&src_ptr[4] = v8 * -0.5;
  LODWORD(v42) = v12[3];
  v14 = v12[4];
  *(float *)src_ptr = v13;
  HIDWORD(v42) = v14;
  if ( v11 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    v15 = *((unsigned __int16 *)v9 + 6);
    if ( v15 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *((unsigned __int16 *)v9 + 7),
        (unsigned __int8)*((_WORD *)v9 + 4),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * v15),
        src_ptr);
  }
  v16 = azimuth;
  ++*((_DWORD *)m_conflicted_key_name + 23);
  sinea = sinf(-v16);
  v17 = context[4];
  m_diff_range_start = v17[3].m_diff_range_start;
  *(float *)v43 = (float)v12[1];
  if ( m_diff_range_start == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    m_diff_range_start_low = LOWORD(v17[1].m_diff_range_start);
    if ( m_diff_range_start_low != 0xFFFF )
    {
      vostok::render::shader_constant_buffer::set_memory(
        HIWORD(v17[1].m_diff_range_start),
        (unsigned __int8)LOWORD(v17->m_current.m_object),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16)
                                                   + 4 * m_diff_range_start_low),
        v43);
      v6 = context;
    }
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_speedtree_forest = tree_component->m_scene->m_speedtree_forest;
  *(float *)src_ptr = m_speedtree_forest->m_view.m_fCameraAzimuth;
  m_fCameraPitch = m_speedtree_forest->m_view.m_fCameraPitch;
  v22 = v6[3];
  v23 = v22[3].m_diff_range_start;
  *(float *)&src_ptr[4] = m_fCameraPitch;
  v42 = 0;
  if ( v23 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v24 = LOWORD(v22[1].m_diff_range_start);
    if ( v24 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        HIWORD(v22[1].m_diff_range_start),
        (unsigned __int8)LOWORD(v22->m_current.m_object),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v24),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v25 = alloca(16 * v12[1]);
  v26 = 0;
  if ( v12[1] )
  {
    v27 = 0;
    do
    {
      v28 = v12[5];
      v29 = *(_DWORD *)(v28 + v27);
      v30 = v27 + v28;
      *(_DWORD *)src_ptr = v29;
      *(_DWORD *)&src_ptr[4] = *(_DWORD *)(v30 + 4);
      v42 = *(_QWORD *)(v30 + 8);
      *(_QWORD *)&v39[v27] = *(_QWORD *)src_ptr;
      *(_QWORD *)&v39[v27 + 8] = v42;
      ++v26;
      v27 += 16;
    }
    while ( v26 < v12[1] );
  }
  v31 = context[5];
  if ( v31[3].m_diff_range_start == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v32 = LOWORD(v31[1].m_diff_range_start);
    if ( v32 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        HIWORD(v31[1].m_diff_range_start),
        (unsigned __int8)LOWORD(v31->m_current.m_object) * HIWORD(v31->m_current.m_object),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v32),
        v39);
  }
  _X = azimuth;
  ++*((_DWORD *)m_conflicted_key_name + 23);
  *(float *)src_ptr = sinea;
  *(float *)&src_ptr[4] = cosf(_X);
  v33 = (char *)context[2];
  v34 = *((_DWORD *)v33 + 9);
  *(float *)&v42 = -sinea;
  HIDWORD(v42) = 0;
  if ( v34 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v35 = *((unsigned __int16 *)v33 + 6);
    if ( v35 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        *((unsigned __int16 *)v33 + 7),
        (unsigned __int8)*((_WORD *)v33 + 4),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v35),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  v36 = context[6];
  if ( v36[3].m_diff_range_start == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v37 = LOWORD(v36[1].m_diff_range_start);
    if ( v37 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        HIWORD(v36[1].m_diff_range_start),
        (unsigned __int8)LOWORD(v36->m_current.m_object),
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v37),
        (const char *)&tree_component->m_view_pos);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
