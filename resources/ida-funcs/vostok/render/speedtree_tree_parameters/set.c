void __userpurge vostok::render::speedtree_tree_parameters::set(
        const SpeedTree::CInstance *instance@<eax>,
        vostok::render::speedtree_tree_parameters *this,
        vostok::render::speedtree_tree_component *tree_component,
        const SpeedTree::SInstanceLod *instance_lod)
{
  vostok::render::shader_constant_host *m_tree_position_and_scale_parameter; // eax
  unsigned int v6; // ecx
  float y; // xmm1_4
  float z; // xmm2_4
  float m_fScale; // xmm3_4
  const char *m_conflicted_key_name; // edi
  int m_buffer_index; // ecx
  SpeedTree::EGeometryType (__thiscall *get_geometry_type)(vostok::render::speedtree_tree_component *); // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  vostok::render::shader_constant_host *m_tree_rotation_parameter; // eax
  unsigned int v16; // edx
  const char *v17; // esi
  int v18; // ecx
  vostok::math::float4 tree_pos; // [esp+Ch] [ebp-10h] BYREF

  m_tree_position_and_scale_parameter = this->m_tree_position_and_scale_parameter;
  v6 = this->m_tree_position_and_scale_parameter->m_update_markers[0];
  y = instance->m_vPos.y;
  z = instance->m_vPos.z;
  m_fScale = instance->m_fScale;
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  tree_pos.x = instance->m_vPos.x;
  *(_QWORD *)&tree_pos.elements[1] = __PAIR64__(LODWORD(z), LODWORD(y));
  tree_pos.w = m_fScale;
  if ( v6 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    m_buffer_index = m_tree_position_and_scale_parameter->m_shader_slots[0].m_buffer_index;
    if ( m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_tree_position_and_scale_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_tree_position_and_scale_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * m_buffer_index),
        (const char *)&tree_pos);
  }
  ++*((_DWORD *)m_conflicted_key_name + 23);
  get_geometry_type = tree_component->get_geometry_type;
  v13 = (float)instance->m_anRotationVector[1] * 0.0078740157;
  tree_pos.x = (float)instance->m_anRotationVector[0] * 0.0078740157;
  tree_pos.y = v13;
  v14 = instance_lod->m_afShaderLerps[get_geometry_type(tree_component)];
  m_tree_rotation_parameter = this->m_tree_rotation_parameter;
  v16 = m_tree_rotation_parameter->m_update_markers[0];
  v17 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  tree_pos.z = v14;
  tree_pos.w = instance_lod->m_fLod;
  if ( v16 == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 572) )
  {
    v18 = m_tree_rotation_parameter->m_shader_slots[0].m_buffer_index;
    if ( v18 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_tree_rotation_parameter->m_shader_slots[0].m_slot_index,
        (unsigned __int8)m_tree_rotation_parameter->m_shader_slots[0].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 51)
                                                               + 16)
                                                   + 4 * v18),
        (const char *)&tree_pos);
  }
  ++*((_DWORD *)v17 + 23);
}
