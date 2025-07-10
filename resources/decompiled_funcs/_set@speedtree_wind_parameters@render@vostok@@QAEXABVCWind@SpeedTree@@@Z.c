void __userpurge vostok::render::speedtree_wind_parameters::set(
        const SpeedTree::CWind *wind@<eax>,
        vostok::render::speedtree_wind_parameters *this)
{
  const char *m_conflicted_key_name; // esi
  vostok::render::shader_constant_host *m_wind_dir_parameter; // eax
  unsigned int v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm2_4
  int m_buffer_index; // ecx
  vostok::render::shader_constant_host *m_wind_times_parameter; // eax
  unsigned int v10; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  int v14; // ecx
  vostok::render::shader_constant_host *m_wind_distances_parameter; // eax
  unsigned int v16; // edx
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  int v20; // ecx
  vostok::render::shader_constant_host *m_wind_leaves_parameter; // eax
  unsigned int v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  int v25; // ecx
  vostok::render::shader_constant_host *m_wind_gust_parameter; // eax
  unsigned int v27; // edx
  float v28; // xmm1_4
  float v29; // xmm2_4
  int v30; // ecx
  vostok::render::shader_constant_host *m_wind_gust_hints_parameter; // eax
  unsigned int v32; // edx
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // ecx
  vostok::render::shader_constant_host *m_wind_frond_ripple_parameter; // eax
  unsigned int v37; // edx
  float v38; // xmm1_4
  float v39; // xmm2_4
  int v40; // ecx
  vostok::render::shader_constant_host *m_wind_rolling_branches_parameter; // eax
  unsigned int v42; // edx
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  int v46; // ecx
  vostok::render::shader_constant_host *m_wind_rolling_leaves_parameter; // eax
  unsigned int v48; // edx
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  int v52; // ecx
  vostok::render::shader_constant_host *m_wind_twitching_leaves_parameter; // eax
  unsigned int v54; // edx
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  int v58; // ecx
  vostok::render::shader_constant_host *m_wind_tumbling_leaves_parameter; // eax
  unsigned int v60; // edx
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  int v64; // ecx
  char src_ptr[4]; // [esp+10h] [ebp-10h] BYREF
  float v66; // [esp+14h] [ebp-Ch]
  float v67; // [esp+18h] [ebp-8h]
  float v68; // [esp+1Ch] [ebp-4h]

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_wind_dir_parameter = this->m_wind_dir_parameter;
  v5 = this->m_wind_dir_parameter->m_update_markers[0];
  v6 = wind->m_afShaderValues[1];
  v7 = wind->m_afShaderValues[2];
  *(float *)src_ptr = wind->m_afShaderValues[0];
  v66 = v6;
  v67 = v7;
  if ( v5 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    m_buffer_index = m_wind_dir_parameter->m_shader_slots[0].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_dir_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_dir_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_times_parameter = this->m_wind_times_parameter;
  v10 = m_wind_times_parameter->m_update_markers[0];
  v11 = wind->m_afShaderValues[4];
  v12 = wind->m_afShaderValues[5];
  v13 = wind->m_afShaderValues[6];
  *(float *)src_ptr = wind->m_afShaderValues[3];
  v66 = v11;
  v67 = v12;
  v68 = v13;
  if ( v10 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v14 = m_wind_times_parameter->m_shader_slots[0].m_buffer_index;
    if ( v14 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_times_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_times_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v14),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_distances_parameter = this->m_wind_distances_parameter;
  v16 = m_wind_distances_parameter->m_update_markers[0];
  v17 = wind->m_afShaderValues[8];
  v18 = wind->m_afShaderValues[9];
  v19 = wind->m_afShaderValues[10];
  *(float *)src_ptr = wind->m_afShaderValues[7];
  v66 = v17;
  v67 = v18;
  v68 = v19;
  if ( v16 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v20 = m_wind_distances_parameter->m_shader_slots[0].m_buffer_index;
    if ( v20 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_distances_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_distances_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v20),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_leaves_parameter = this->m_wind_leaves_parameter;
  v22 = m_wind_leaves_parameter->m_update_markers[0];
  v23 = wind->m_afShaderValues[12];
  v24 = wind->m_afShaderValues[13];
  *(float *)src_ptr = wind->m_afShaderValues[11];
  v66 = v23;
  v67 = v24;
  if ( v22 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v25 = m_wind_leaves_parameter->m_shader_slots[0].m_buffer_index;
    if ( v25 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_leaves_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_leaves_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v25),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_gust_parameter = this->m_wind_gust_parameter;
  v27 = m_wind_gust_parameter->m_update_markers[0];
  v28 = wind->m_afShaderValues[18];
  v29 = wind->m_afShaderValues[19];
  *(float *)src_ptr = wind->m_afShaderValues[17];
  v66 = v28;
  v67 = v29;
  if ( v27 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v30 = m_wind_gust_parameter->m_shader_slots[0].m_buffer_index;
    if ( v30 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_gust_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_gust_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v30),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_gust_hints_parameter = this->m_wind_gust_hints_parameter;
  v32 = m_wind_gust_hints_parameter->m_update_markers[0];
  v33 = wind->m_afShaderValues[21];
  v34 = wind->m_afShaderValues[22];
  *(float *)src_ptr = wind->m_afShaderValues[20];
  v66 = v33;
  v67 = v34;
  if ( v32 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v35 = m_wind_gust_hints_parameter->m_shader_slots[0].m_buffer_index;
    if ( v35 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_gust_hints_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_gust_hints_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v35),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_frond_ripple_parameter = this->m_wind_frond_ripple_parameter;
  v37 = m_wind_frond_ripple_parameter->m_update_markers[0];
  v38 = wind->m_afShaderValues[15];
  v39 = wind->m_afShaderValues[16];
  *(float *)src_ptr = wind->m_afShaderValues[14];
  v66 = v38;
  v67 = v39;
  if ( v37 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v40 = m_wind_frond_ripple_parameter->m_shader_slots[0].m_buffer_index;
    if ( v40 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_frond_ripple_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_frond_ripple_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v40),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_rolling_branches_parameter = this->m_wind_rolling_branches_parameter;
  v42 = m_wind_rolling_branches_parameter->m_update_markers[0];
  v43 = wind->m_afShaderValues[24];
  v44 = wind->m_afShaderValues[25];
  v45 = wind->m_afShaderValues[26];
  *(float *)src_ptr = wind->m_afShaderValues[23];
  v66 = v43;
  v67 = v44;
  v68 = v45;
  if ( v42 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v46 = m_wind_rolling_branches_parameter->m_shader_slots[0].m_buffer_index;
    if ( v46 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_rolling_branches_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_rolling_branches_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v46),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_rolling_leaves_parameter = this->m_wind_rolling_leaves_parameter;
  v48 = m_wind_rolling_leaves_parameter->m_update_markers[0];
  v49 = wind->m_afShaderValues[28];
  v50 = wind->m_afShaderValues[29];
  v51 = wind->m_afShaderValues[30];
  *(float *)src_ptr = wind->m_afShaderValues[27];
  v66 = v49;
  v67 = v50;
  v68 = v51;
  if ( v48 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v52 = m_wind_rolling_leaves_parameter->m_shader_slots[0].m_buffer_index;
    if ( v52 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_rolling_leaves_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_rolling_leaves_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v52),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_twitching_leaves_parameter = this->m_wind_twitching_leaves_parameter;
  v54 = m_wind_twitching_leaves_parameter->m_update_markers[0];
  v55 = wind->m_afShaderValues[32];
  v56 = wind->m_afShaderValues[33];
  v57 = wind->m_afShaderValues[34];
  *(float *)src_ptr = wind->m_afShaderValues[31];
  v66 = v55;
  v67 = v56;
  v68 = v57;
  if ( v54 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v58 = m_wind_twitching_leaves_parameter->m_shader_slots[0].m_buffer_index;
    if ( v58 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_twitching_leaves_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_twitching_leaves_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v58),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  m_wind_tumbling_leaves_parameter = this->m_wind_tumbling_leaves_parameter;
  v60 = m_wind_tumbling_leaves_parameter->m_update_markers[0];
  v61 = wind->m_afShaderValues[36];
  v62 = wind->m_afShaderValues[37];
  v63 = wind->m_afShaderValues[38];
  *(float *)src_ptr = wind->m_afShaderValues[35];
  v66 = v61;
  v67 = v62;
  v68 = v63;
  if ( v60 == *((_DWORD *)m_conflicted_key_name + 572) )
  {
    v64 = m_wind_tumbling_leaves_parameter->m_shader_slots[0].m_buffer_index;
    if ( v64 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_wind_tumbling_leaves_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_wind_tumbling_leaves_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v64),
        src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
