void __thiscall vostok::render::skeleton_mesh_gpu_skinning_4weights::load(
        vostok::render::skeleton_mesh_gpu_skinning_4weights *this,
        const vostok::configs::binary_config_value *properties,
        unsigned int r)
{
  vostok::memory::chunk_reader *v4; // edi
  vostok::memory::chunk_reader *v6; // ecx
  unsigned int *v7; // esi
  vostok::memory::chunk_reader *v8; // edi
  vostok::memory::chunk_reader *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // edi
  vostok::render::untyped_buffer *v12; // eax
  vostok::render::resource_manager *v13; // ecx
  vostok::render::res_declaration *declaration; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v15; // eax
  vostok::render::resource_manager *v16; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::render::resource_manager *v19; // [esp-18h] [ebp-3Ch]
  void *v20; // [esp-10h] [ebp-34h]
  unsigned int v21; // [esp+0h] [ebp-24h]
  unsigned int v22; // [esp+0h] [ebp-24h]
  vostok::render::hw_buffer_pool *v23; // [esp+0h] [ebp-24h]
  const unsigned __int8 *v24; // [esp+Ch] [ebp-18h] BYREF
  vostok::math::float3 *positions; // [esp+10h] [ebp-14h]
  const unsigned __int8 *v26; // [esp+18h] [ebp-Ch] BYREF
  void *data; // [esp+1Ch] [ebp-8h]
  vostok::render::untyped_buffer *propertiesa; // [esp+2Ch] [ebp+8h]

  v4 = (vostok::memory::chunk_reader *)r;
  vostok::render::render_surface::load(this, properties, (vostok::memory::chunk_reader *)r);
  vostok::memory::chunk_reader::open_reader(v6, v4, &v24, (vostok::memory::chunk_reader::chunk_type *)3, v21);
  v7 = (unsigned int *)positions;
  positions = (vostok::math::float3 *)((char *)positions + 4);
  v8 = (vostok::memory::chunk_reader *)r;
  this->m_render_geometry.vertex_count = *v7;
  vostok::memory::chunk_reader::open_reader(v9, v8, &v26, (vostok::memory::chunk_reader::chunk_type *)4, v22);
  r = *(_DWORD *)data;
  v10 = r / 3;
  data = (char *)data + 4;
  v20 = data;
  v11 = 2 * r;
  v19 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  this->m_render_geometry.index_count = r;
  this->m_render_geometry.primitive_count = v10;
  vostok::render::resource_manager::create_buffer(v11, v19, (void *)2, (vostok::render::enum_buffer_type)v20, 1, 0, 0);
  propertiesa = 0;
  if ( v12 )
  {
    ++v12->m_reference_count;
    propertiesa = v12;
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  v13,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  hardware_4weights_skinning_vertex_layout,
                  7u);
  r = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    r = (unsigned int)declaration;
  }
  vostok::render::resource_manager::create_buffer(
    48 * this->m_render_geometry.vertex_count,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0x30,
    (vostok::render::enum_buffer_type)positions,
    0,
    1,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v15,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&this->m_vertex_buffer,
    (vostok::render::hw_buffer_pool *)&this->m_vertex_buffer);
  geometry = vostok::render::resource_manager::create_geometry(
               v16,
               (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
               (vostok::render::res_declaration *)r,
               (vostok::render::untyped_buffer *)0x30,
               this->m_vertex_buffer.m_object,
               propertiesa);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_render_geometry.geom,
    geometry);
  LODWORD(this->m_streaming_texture_factor) = vostok::render::calculate_streaming_texture_factor(
                                                this->m_render_geometry.index_count,
                                                positions,
                                                (const vostok::math::float2 *)&positions[3].elements[1],
                                                0x30u,
                                                (const unsigned int)data);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&r);
  if ( propertiesa )
  {
    if ( propertiesa->m_reference_count-- == 1 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(propertiesa, v23);
  }
}
