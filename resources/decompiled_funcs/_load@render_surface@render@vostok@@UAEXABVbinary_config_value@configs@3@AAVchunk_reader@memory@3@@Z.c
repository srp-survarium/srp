void __thiscall vostok::render::render_surface::load(
        vostok::render::render_surface *this,
        vostok::configs::binary_config_value *properties,
        vostok::memory::chunk_reader *chunk)
{
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  __int64 v6; // xmm0_8
  float v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  __int64 v10; // xmm0_8
  float v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  int max_storage_low; // eax
  __int64 sphere_origin; // [esp+10h] [ebp-20h]
  float v16[3]; // [esp+24h] [ebp-Ch]

  v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 properties,
                                                 (const char *)&stru_962594.m_v_shaders._M_t._M_header._M_data._M_color);
  v5 = vostok::configs::binary_config_value::operator[](v4, (const char *)&stru_962594.m_v_shaders._M_t._M_node_count);
  v6 = *(_QWORD *)v5->data.pointer;
  v7 = *((float *)v5->data.pointer + 2);
  *(_QWORD *)&this->m_aabbox.max.x = v6;
  this->m_aabbox.max.z = v7;
  v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 properties,
                                                 (const char *)&stru_962594.m_v_shaders._M_t._M_header._M_data._M_color);
  v9 = vostok::configs::binary_config_value::operator[](v8, (const char *)&stru_962594.m_v_shaders._M_t._M_key_compare);
  v10 = *(_QWORD *)v9->data.pointer;
  v11 = *((float *)v9->data.pointer + 2);
  *(_QWORD *)&this->m_aabbox.min.x = v10;
  this->m_aabbox.min.z = v11;
  v12 = (float)(this->m_aabbox.max.y - this->m_aabbox.min.y) * 0.5;
  *(float *)&v10 = (float)(this->m_aabbox.max.x - this->m_aabbox.min.x) * 0.5;
  v13 = (float)(this->m_aabbox.max.z - this->m_aabbox.min.z) * 0.5;
  *(float *)&sphere_origin = (float)(this->m_aabbox.min.x + this->m_aabbox.max.x) * 0.5;
  *((float *)&sphere_origin + 1) = (float)(this->m_aabbox.max.y + this->m_aabbox.min.y) * 0.5;
  v16[0] = (float)(this->m_aabbox.max.z + this->m_aabbox.min.z) * 0.5;
  v16[1] = sqrtf((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(*(float *)&v10 * *(float *)&v10));
  *(_QWORD *)&this->m_bounding_sphere.vector.x = sphere_origin;
  *(_QWORD *)&this->m_bounding_sphere.center.elements[2] = *(_QWORD *)v16;
  max_storage_low = LOWORD(vostok::configs::binary_config_value::operator[](properties, "type")->data.max_storage);
  this->m_vertex_input_type = null_vertex_input_type;
  switch ( max_storage_low )
  {
    case 0:
    case 1:
      this->m_vertex_input_type = static_mesh_vertex_input_type;
      break;
    case 2:
      this->m_vertex_input_type = static_mesh_vertex_colored_input_type;
      break;
    case 44:
      this->m_vertex_input_type = skeletal_1_bones_mesh_vertex_input_type;
      break;
    case 45:
      this->m_vertex_input_type = skeletal_2_bones_mesh_vertex_input_type;
      break;
    case 46:
      this->m_vertex_input_type = skeletal_3_bones_mesh_vertex_input_type;
      break;
    case 47:
      this->m_vertex_input_type = skeletal_4_bones_mesh_vertex_input_type;
      break;
    default:
      return;
  }
}
