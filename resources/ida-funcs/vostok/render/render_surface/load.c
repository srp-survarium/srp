void __thiscall vostok::render::render_surface::load(
        vostok::render::render_surface *this,
        const vostok::configs::binary_config_value *properties,
        vostok::memory::chunk_reader *chunk)
{
  vostok::configs::binary_config_value *v4; // eax
  float **v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  float **v7; // eax
  float v8; // xmm1_4
  float v9; // xmm5_4
  int max_storage_low; // eax
  int v11; // eax
  int v12; // eax
  float v13; // [esp+10h] [ebp-18h]
  float v14; // [esp+14h] [ebp-14h]
  float v15; // [esp+18h] [ebp-10h]
  float v16; // [esp+20h] [ebp-8h]
  float v17; // [esp+20h] [ebp-8h]
  float v18; // [esp+24h] [ebp-4h]
  float v19; // [esp+24h] [ebp-4h]

  v4 = vostok::configs::binary_config_value::operator[](properties, "bounding_box");
  v5 = (float **)vostok::configs::binary_config_value::operator[](v4, "max");
  v16 = (*v5)[1];
  v18 = (*v5)[2];
  this->m_aabbox.max.x = **v5;
  this->m_aabbox.max.y = v16;
  this->m_aabbox.max.z = v18;
  v6 = vostok::configs::binary_config_value::operator[](properties, "bounding_box");
  v7 = (float **)vostok::configs::binary_config_value::operator[](v6, "min");
  v17 = (*v7)[1];
  v19 = (*v7)[2];
  this->m_aabbox.min.x = **v7;
  this->m_aabbox.min.y = v17;
  this->m_aabbox.min.z = v19;
  v8 = (float)(this->m_aabbox.max.x - this->m_aabbox.min.x) * 0.5;
  v9 = (float)(this->m_aabbox.max.y - this->m_aabbox.min.y) * 0.5;
  v13 = (float)(this->m_aabbox.max.y + this->m_aabbox.min.y) * 0.5;
  v14 = (float)(this->m_aabbox.max.z + this->m_aabbox.min.z) * 0.5;
  v15 = fsqrt(
          (float)((float)((float)((float)(this->m_aabbox.max.z - this->m_aabbox.min.z) * 0.5)
                        * (float)((float)(this->m_aabbox.max.z - this->m_aabbox.min.z) * 0.5))
                + (float)(v9 * v9))
        + (float)(v8 * v8));
  this->m_bounding_sphere.vector.x = (float)(this->m_aabbox.min.x + this->m_aabbox.max.x) * 0.5;
  this->m_bounding_sphere.vector.y = v13;
  this->m_bounding_sphere.vector.z = v14;
  this->m_bounding_sphere.vector.w = v15;
  max_storage_low = LOWORD(vostok::configs::binary_config_value::operator[](properties, "type")->data.max_storage);
  this->m_vertex_input_type = null_vertex_input_type;
  if ( max_storage_low > 45 )
  {
    v11 = max_storage_low - 46;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 153 )
          this->m_vertex_input_type = grassmesh_vertex_input_type;
      }
      else
      {
        this->m_vertex_input_type = skeletal_4_bones_mesh_vertex_input_type;
      }
    }
    else
    {
      this->m_vertex_input_type = skeletal_3_bones_mesh_vertex_input_type;
    }
  }
  else if ( max_storage_low == 45 )
  {
    this->m_vertex_input_type = skeletal_2_bones_mesh_vertex_input_type;
  }
  else if ( max_storage_low <= 1 )
  {
    this->m_vertex_input_type = static_mesh_vertex_input_type;
  }
  else if ( max_storage_low == 2 )
  {
    this->m_vertex_input_type = static_mesh_vertex_colored_input_type;
  }
  else if ( max_storage_low == 44 )
  {
    this->m_vertex_input_type = skeletal_1_bones_mesh_vertex_input_type;
  }
}
