void __userpurge vostok::render::static_render_surface::load(
        vostok::render::static_render_surface *this@<ecx>,
        vostok::render::hw_buffer_pool *a2@<xmm0>,
        const vostok::configs::binary_config_value *properties,
        vostok::memory::chunk_reader *chunk)
{
  vostok::memory::chunk_reader *v5; // ecx
  vostok::render::resource_manager *v6; // ecx
  vostok::render::res_declaration *declaration; // eax
  float y; // esi
  int v9; // eax
  unsigned int v10; // edi
  vostok::render::untyped_buffer *v11; // eax
  vostok::memory::chunk_reader *v12; // ecx
  vostok::memory::reader *v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // edi
  vostok::render::untyped_buffer *v16; // eax
  vostok::render::resource_manager *v17; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::memory::chunk_reader *v19; // ecx
  vostok::memory::reader *v20; // eax
  vostok::render::static_render_surface *v21; // ecx
  vostok::memory::chunk_reader *v22; // ecx
  vostok::memory::reader *v23; // eax
  vostok::memory::chunk_reader *v24; // ecx
  vostok::memory::reader *v25; // eax
  vostok::math::half_pod *v26; // ecx
  unsigned int v27; // edi
  void *v28; // esp
  int v29; // esi
  vostok::math::half_pod *v30; // ecx
  vostok::buffer_vector<`vostok::render::static_render_surface::load'::`2'::prepared_vertex_data> *v31; // ecx
  int v32; // xmm0_4
  unsigned int v33; // edi
  vostok::render::resource_manager *v34; // esi
  bool v35; // zf
  int v36; // eax
  vostok::render::untyped_buffer *v37; // edi
  unsigned int v38; // eax
  vostok::render::resource_manager *v39; // [esp-18h] [ebp-70h]
  float v40; // [esp-10h] [ebp-68h]
  unsigned int vertex_count; // [esp-8h] [ebp-60h]
  vostok::render::hw_buffer_pool *v42[3]; // [esp+0h] [ebp-58h] BYREF
  float v43[5]; // [esp+Ch] [ebp-4Ch] BYREF
  vostok::render::static_render_surface::load::__l2::prepared_vertex_data value; // [esp+20h] [ebp-38h] BYREF
  unsigned int m_size; // [esp+34h] [ebp-24h]
  vostok::render::hw_buffer_pool *v46; // [esp+38h] [ebp-20h]
  vostok::render::hw_buffer_pool *v47; // [esp+40h] [ebp-18h]
  vostok::render::hw_buffer_pool *v48; // [esp+44h] [ebp-14h]
  unsigned int vertex_stride; // [esp+48h] [ebp-10h] BYREF
  vostok::render::untyped_buffer *ib; // [esp+4Ch] [ebp-Ch]
  unsigned int v51; // [esp+50h] [ebp-8h]
  int v52; // [esp+54h] [ebp-4h]
  unsigned int propertiesb; // [esp+60h] [ebp+8h]
  vostok::render::untyped_buffer *propertiesa; // [esp+60h] [ebp+8h]
  vostok::memory::chunk_reader *chunka; // [esp+64h] [ebp+Ch]

  vostok::render::render_surface::load(this, properties, chunk);
  vostok::memory::chunk_reader::open_reader(
    v5,
    chunk,
    (const unsigned __int8 **)&value.uv,
    (vostok::memory::chunk_reader::chunk_type *)3,
    (unsigned int)v42[0]);
  if ( this->m_vertex_input_type == static_mesh_vertex_colored_input_type )
    declaration = vostok::render::resource_manager::create_declaration(
                    v6,
                    (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    colored_static_vertex_input_layout,
                    6u);
  else
    declaration = vostok::render::resource_manager::create_declaration(
                    v6,
                    (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    static_vertex_input_layout_0,
                    5u);
  vertex_stride = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    vertex_stride = (unsigned int)declaration;
  }
  y = value.uv.y;
  LODWORD(value.uv.y) += 4;
  propertiesb = *(_DWORD *)LODWORD(y);
  v9 = 4 * (this->m_vertex_input_type == static_mesh_vertex_colored_input_type) + 28;
  this->m_render_geometry.vertex_count = *(_DWORD *)LODWORD(y);
  v10 = v9 * propertiesb;
  propertiesa = (vostok::render::untyped_buffer *)v9;
  vostok::render::resource_manager::create_buffer(
    v10,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)v9,
    SLODWORD(value.uv.y),
    0,
    0,
    0);
  ib = 0;
  if ( v11 )
  {
    ++v11->m_reference_count;
    ib = v11;
  }
  v13 = vostok::memory::chunk_reader::open_reader(
          v12,
          chunk,
          (const unsigned __int8 **)&value,
          (vostok::memory::chunk_reader::chunk_type *)4,
          (unsigned int)v42[0]);
  value.uv = *(vostok::math::float2 *)&v13->m_data;
  m_size = v13->m_size;
  v51 = *(_DWORD *)LODWORD(value.uv.y);
  v14 = v51 / 3;
  LODWORD(value.uv.y) += 4;
  v40 = value.uv.y;
  v15 = 2 * v51;
  v39 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  this->m_render_geometry.index_count = v51;
  this->m_render_geometry.primitive_count = v14;
  vostok::render::resource_manager::create_buffer(v15, v39, (void *)2, SLODWORD(v40), 1, 0, 0);
  v51 = 0;
  if ( v16 )
  {
    ++v16->m_reference_count;
    v51 = (unsigned int)v16;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               v17,
               (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
               (vostok::render::res_declaration *)vertex_stride,
               propertiesa,
               ib,
               (vostok::render::untyped_buffer *)v51);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_render_geometry.geom,
    geometry);
  v20 = vostok::memory::chunk_reader::open_reader(
          v19,
          chunk,
          (const unsigned __int8 **)&value,
          (vostok::memory::chunk_reader::chunk_type *)3,
          (unsigned int)v42[0]);
  vertex_count = this->m_render_geometry.vertex_count;
  value.uv = *(vostok::math::float2 *)&v20->m_data;
  m_size = v20->m_size;
  vostok::render::static_render_surface::create_shadow_pass_geometry(
    v21,
    (const unsigned __int8 *)this,
    (unsigned __int8 *)(LODWORD(value.uv.y) + 4),
    vertex_count,
    (int)propertiesa);
  v23 = vostok::memory::chunk_reader::open_reader(
          v22,
          chunk,
          (const unsigned __int8 **)&value,
          (vostok::memory::chunk_reader::chunk_type *)3,
          (unsigned int)v42[0]);
  value.uv = *(vostok::math::float2 *)&v23->m_data;
  m_size = v23->m_size;
  v52 = LODWORD(value.uv.y) + 4;
  v25 = vostok::memory::chunk_reader::open_reader(
          v24,
          chunk,
          (const unsigned __int8 **)&value,
          (vostok::memory::chunk_reader::chunk_type *)4,
          (unsigned int)v42[0]);
  value.uv = *(vostok::math::float2 *)&v25->m_data;
  m_size = v25->m_size;
  v27 = this->m_render_geometry.vertex_count;
  LODWORD(value.uv.y) += 4;
  v28 = alloca(20 * v27);
  chunka = 0;
  LODWORD(value.position.x) = v42;
  LODWORD(value.position.y) = v42;
  LODWORD(value.position.z) = &v42[5 * v27];
  if ( v27 )
  {
    do
    {
      v43[0] = *(float *)v52;
      v43[1] = *(float *)(v52 + 4);
      v43[2] = *(float *)(v52 + 8);
      vostok::math::half_pod::operator float(v26, (unsigned __int16 *)(v52 + 24));
      v29 = v52;
      v46 = a2;
      vostok::math::half_pod::operator float(v30, (unsigned __int16 *)(v52 + 26));
      v47 = v46;
      LODWORD(v43[3]) = v46;
      v48 = a2;
      LODWORD(v43[4]) = a2;
      v52 = (int)propertiesa + v29;
      _push_back___buffer_vector_Uprepared_vertex_data__1__load_static_render_surface_render_vostok__UAEXABVbinary_config_value_configs_5_AAVchunk_reader_memory_5__Z__vostok__QAEXABUprepared_vertex_data__1__load_static_render_surface_render_2_UAEXABVbinary_config_value_configs_2_AAVchunk_reader_memory_2__Z__Z(
        v31,
        &value,
        v43);
      chunka = (vostok::memory::chunk_reader *)((char *)chunka + 1);
    }
    while ( (unsigned int)chunka < this->m_render_geometry.vertex_count );
  }
  v32 = vostok::render::calculate_streaming_texture_factor(
          this->m_render_geometry.index_count,
          (const vostok::math::float3 *)LODWORD(value.position.x),
          (const vostok::math::float2 *)(LODWORD(value.position.x) + 12),
          0x14u,
          LODWORD(value.uv.y));
  v33 = v51;
  v34 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  LODWORD(this->m_streaming_texture_factor) = v32;
  if ( v33 )
  {
    v35 = (*(_DWORD *)v33)-- == 1;
    if ( v35 )
    {
      if ( *(_DWORD *)(v33 + 4) )
      {
        if ( *(_DWORD *)(v33 + 28) == 1 && v34->m_indices_pool )
          vostok::render::hw_buffer_pool::deallocate((const vostok::render::hw_buffer_pool_range *)(v33 + 4), v42[0]);
        if ( !*(_DWORD *)(v33 + 28) && v34->m_vertices_pool )
          vostok::render::hw_buffer_pool::deallocate((const vostok::render::hw_buffer_pool_range *)(v33 + 4), v42[0]);
      }
      else
      {
        v36 = *(_DWORD *)(v33 + 20);
        if ( *(_DWORD *)(v33 + 28) == 1 )
          v34->m_total_index_buffers_size -= v36;
        else
          v34->m_total_vertex_buffers_size -= v36;
      }
    }
  }
  v37 = ib;
  if ( ib )
  {
    v35 = ib->m_reference_count-- == 1;
    if ( v35 )
    {
      if ( v37->pool_range.owner )
      {
        if ( v37->m_type == enum_buffer_type_index && v34->m_indices_pool )
          vostok::render::hw_buffer_pool::deallocate(&v37->pool_range, v42[0]);
        if ( v37->m_type == enum_buffer_type_vertex && v34->m_vertices_pool )
          vostok::render::hw_buffer_pool::deallocate(&v37->pool_range, v42[0]);
      }
      else
      {
        v38 = v37->m_size;
        if ( v37->m_type == enum_buffer_type_index )
          v34->m_total_index_buffers_size -= v38;
        else
          v34->m_total_vertex_buffers_size -= v38;
      }
    }
  }
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&vertex_stride);
}
