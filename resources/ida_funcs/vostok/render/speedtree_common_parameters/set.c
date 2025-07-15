void __userpurge vostok::render::speedtree_common_parameters::set(
        const vostok::math::float3 *lod_reference_position@<eax>,
        vostok::render::speedtree_common_parameters *this,
        vostok::render::renderer_context *context,
        vostok::render::speedtree_tree_component *tree_component)
{
  const char *m_conflicted_key_name; // ebx
  float z; // xmm0_4
  vostok::render::shader_constant_host *m_lod_reference_position_parameter; // eax
  unsigned int v7; // ecx
  int m_buffer_index; // ecx
  const vostok::math::float3 *v9; // eax
  SpeedTree::SLodProfile *p_m_sLodProfile; // eax
  int m_fBillboardFinalDistance_low; // xmm0_4
  vostok::render::shader_constant_host *m_lod_profile_parameter; // eax
  bool v13; // zf
  int v14; // ecx
  __int64 src_ptr; // [esp+0h] [ebp-D0h] BYREF
  int m_fBillboardStartDistance_low; // [esp+8h] [ebp-C8h]
  const vostok::math::float4x4 *v17; // [esp+Ch] [ebp-C4h]
  unsigned __int8 src[64]; // [esp+10h] [ebp-C0h] BYREF
  vostok::math::float4x4 dst; // [esp+50h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+90h] [ebp-40h] BYREF

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  src_ptr = *(_QWORD *)&lod_reference_position->x;
  z = lod_reference_position->z;
  m_lod_reference_position_parameter = this->m_lod_reference_position_parameter;
  v7 = m_lod_reference_position_parameter->m_update_markers[0];
  m_fBillboardStartDistance_low = LODWORD(z);
  v17 = clear_value;
  if ( v7 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    m_buffer_index = m_lod_reference_position_parameter->m_shader_slots[0].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_lod_reference_position_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_lod_reference_position_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  qmemcpy(src, &context->m_scene->m_speedtree_forest->m_view.m_mCameraFacingMatrix, sizeof(src));
  memcpy((unsigned __int8 *)&dst, src, sizeof(dst));
  v9 = (const vostok::math::float3 *)vostok::math::transpose(&result, &dst);
  vostok::render::constants_handler<0>::set_constant<vostok::math::float3>(
    this->m_camera_facing_matrix_parameter,
    (vostok::render::constants_handler<0> *)(m_conflicted_key_name + 196),
    v9);
  ++*((_DWORD *)m_conflicted_key_name + 23);
  p_m_sLodProfile = &tree_component->m_parent->m_sLodProfile;
  if ( tree_component->m_parent->m_sLodProfile.m_bLodIsPresent )
  {
    src_ptr = *(_QWORD *)&p_m_sLodProfile->m_fHighDetail3dDistance;
    m_fBillboardStartDistance_low = LODWORD(p_m_sLodProfile->m_fBillboardStartDistance);
    m_fBillboardFinalDistance_low = LODWORD(p_m_sLodProfile->m_fBillboardFinalDistance);
    m_lod_profile_parameter = this->m_lod_profile_parameter;
    v13 = m_lod_profile_parameter->m_update_markers[0] == *((_DWORD *)m_conflicted_key_name + 572);
  }
  else
  {
    m_lod_profile_parameter = this->m_lod_profile_parameter;
    v13 = m_lod_profile_parameter->m_update_markers[0] == *((_DWORD *)m_conflicted_key_name + 572);
    src_ptr = 0x497423F000000000LL;
    m_fBillboardStartDistance_low = 1240736752;
    m_fBillboardFinalDistance_low = 1245125364;
  }
  v17 = (const vostok::math::float4x4 *)m_fBillboardFinalDistance_low;
  if ( v13 )
  {
    v14 = m_lod_profile_parameter->m_shader_slots[0].m_buffer_index;
    if ( v14 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_lod_profile_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_lod_profile_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)m_conflicted_key_name + 51) + 16) + 4 * v14),
        (const char *)&src_ptr);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
}
