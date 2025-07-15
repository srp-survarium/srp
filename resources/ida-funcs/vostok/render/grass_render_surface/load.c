void __thiscall vostok::render::grass_render_surface::load(
        vostok::render::grass_render_surface *this,
        const vostok::configs::binary_config_value *properties,
        vostok::memory::chunk_reader *chunk)
{
  vostok::memory::chunk_reader *v4; // ecx
  vostok::render::resource_manager *v5; // ecx
  vostok::render::res_declaration *declaration; // eax
  unsigned int *v7; // esi
  vostok::render::untyped_buffer *v8; // eax
  vostok::memory::chunk_reader *v9; // ecx
  vostok::memory::reader *v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  vostok::render::untyped_buffer *v13; // eax
  vostok::render::resource_manager *v14; // ecx
  vostok::render::untyped_buffer *v15; // edi
  vostok::render::res_geometry *geometry; // eax
  bool v17; // zf
  vostok::render::resource_manager *v18; // [esp-18h] [ebp-40h]
  void *v19; // [esp-10h] [ebp-38h]
  unsigned int v20; // [esp+0h] [ebp-28h]
  unsigned int v21; // [esp+0h] [ebp-28h]
  vostok::render::hw_buffer_pool *v22; // [esp+0h] [ebp-28h]
  const unsigned __int8 *v23; // [esp+Ch] [ebp-1Ch] BYREF
  const unsigned __int8 *m_data; // [esp+18h] [ebp-10h] BYREF
  void *data; // [esp+1Ch] [ebp-Ch]
  unsigned int m_size; // [esp+20h] [ebp-8h]
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v27; // [esp+24h] [ebp-4h] BYREF
  unsigned int propertiesb; // [esp+30h] [ebp+8h]
  vostok::render::untyped_buffer *propertiesa; // [esp+30h] [ebp+8h]

  vostok::render::render_surface::load(this, properties, chunk);
  this->m_vertex_input_type = grassmesh_vertex_input_type;
  vostok::memory::chunk_reader::open_reader(v4, chunk, &m_data, (vostok::memory::chunk_reader::chunk_type *)3, v20);
  declaration = vostok::render::resource_manager::create_declaration(
                  v5,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  static_vertex_input_layout,
                  5u);
  v27.m_object = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v27.m_object = declaration;
  }
  v7 = (unsigned int *)data;
  data = (char *)data + 4;
  propertiesb = *v7;
  this->m_render_geometry.vertex_count = *v7;
  vostok::render::resource_manager::create_buffer(
    28 * propertiesb,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0x1C,
    (vostok::render::enum_buffer_type)data,
    0,
    0,
    0);
  propertiesa = 0;
  if ( v8 )
  {
    ++v8->m_reference_count;
    propertiesa = v8;
  }
  v10 = vostok::memory::chunk_reader::open_reader(v9, chunk, &v23, (vostok::memory::chunk_reader::chunk_type *)4, v21);
  m_data = v10->m_data;
  data = (void *)v10->m_pointer;
  m_size = v10->m_size;
  v11 = *(_DWORD *)data;
  v12 = *(_DWORD *)data / 3u;
  data = (char *)data + 4;
  v19 = data;
  v18 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  this->m_render_geometry.index_count = v11;
  this->m_render_geometry.primitive_count = v12;
  vostok::render::resource_manager::create_buffer(
    2 * v11,
    v18,
    (void *)2,
    (vostok::render::enum_buffer_type)v19,
    1,
    0,
    0);
  v15 = 0;
  if ( v13 )
  {
    ++v13->m_reference_count;
    v15 = v13;
  }
  geometry = vostok::render::resource_manager::create_geometry(
               v14,
               (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
               0,
               (vostok::render::untyped_buffer *)0x1C,
               propertiesa,
               v15);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_render_geometry.geom,
    geometry);
  if ( v15 )
  {
    v17 = v15->m_reference_count-- == 1;
    if ( v17 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v15, v22);
  }
  if ( propertiesa )
  {
    v17 = propertiesa->m_reference_count-- == 1;
    if ( v17 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(propertiesa, v22);
  }
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&v27);
}
