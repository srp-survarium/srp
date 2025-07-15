void __cdecl vostok::render::fill_source_vertices_impl__vostok::render::fill_source_vertices_::_2_::static_vertex_(
        vostok::render::render_geometry *in_render_geometry,
        vostok::fixed_vector<vostok::render::batched_vertex_source,65536> *out_vertices,
        vostok::fixed_vector<unsigned short,65536> *out_indices)
{
  vostok::render::untyped_buffer *m_object; // eax
  vostok::render::untyped_buffer *v5; // edi
  _DWORD *v6; // eax
  vostok::render::untyped_buffer *v7; // ecx
  vostok::render::untyped_buffer *v8; // ecx
  vostok::render::batched_vertex_source *m_begin; // edx
  const void *v10; // esi
  bool v11; // zf
  vostok::memory::doug_lea_allocator *v12; // ecx
  _DWORD *v13; // eax
  D3D11_MAP v14; // edi
  vostok::render::untyped_buffer *v15; // ecx
  unsigned __int8 *v16; // eax
  vostok::render::untyped_buffer *v17; // ecx
  vostok::memory::doug_lea_allocator *v18; // ecx
  vostok::render::resource_manager *v19; // esi
  int v20; // eax
  int v21; // eax
  unsigned int m_size; // eax
  const char *v23; // [esp+0h] [ebp-20h]
  vostok::render::untyped_buffer *v24; // [esp+0h] [ebp-20h]
  const char *v25; // [esp+0h] [ebp-20h]
  vostok::render::untyped_buffer *v26; // [esp+0h] [ebp-20h]
  char *v27; // [esp+0h] [ebp-20h]
  const char *v28; // [esp+4h] [ebp-1Ch]
  const char *v29; // [esp+4h] [ebp-1Ch]
  const char *v30; // [esp+4h] [ebp-1Ch]
  unsigned int v31; // [esp+8h] [ebp-18h]
  unsigned int v32; // [esp+8h] [ebp-18h]
  unsigned int v33; // [esp+8h] [ebp-18h]
  char *count; // [esp+Ch] [ebp-14h]
  unsigned int counta; // [esp+Ch] [ebp-14h]
  vostok::buffer_vector<vostok::render::batched_vertex_source> *v36; // [esp+10h] [ebp-10h]
  char *data; // [esp+14h] [ebp-Ch]
  char *v38; // [esp+18h] [ebp-8h]
  vostok::render::untyped_buffer *source; // [esp+1Ch] [ebp-4h]
  void *stridea; // [esp+28h] [ebp+8h]
  D3D11_MAP stride; // [esp+28h] [ebp+8h]
  char *v42; // [esp+2Ch] [ebp+Ch]
  char *v43; // [esp+2Ch] [ebp+Ch]

  m_object = in_render_geometry->geom.m_object->m_vb.m_object;
  v5 = 0;
  source = 0;
  if ( m_object )
  {
    ++m_object->m_reference_count;
    source = m_object;
    v5 = m_object;
  }
  stridea = (void *)in_render_geometry->geom.m_object->m_vb_stride;
  v36 = (vostok::buffer_vector<vostok::render::batched_vertex_source> *)(v5->m_size
                                                                       / in_render_geometry->geom.m_object->m_vb_stride);
  data = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)v5->m_size,
           (int)vostok::render::g_allocator,
           v5->m_size,
           "base_vb",
           v23,
           v28,
           v31);
  count = data;
  vostok::buffer_vector<vostok::render::batched_vertex_source>::resize(v36, (int *)out_vertices);
  vostok::render::resource_manager::create_buffer(
    v5->m_size,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    stridea,
    (vostok::render::enum_buffer_type)data,
    0,
    0,
    1);
  stride = 0;
  if ( v6 )
  {
    ++*v6;
    stride = (D3D11_MAP)v6;
  }
  vostok::render::resource_manager::copy(source, (vostok::render::resource_manager *)stride, v24);
  v38 = (char *)vostok::render::untyped_buffer::map(v7, stride, D3D11_MAP_READ);
  m_begin = out_vertices->m_begin;
  if ( v36 )
  {
    v42 = (char *)v36;
    do
    {
      v10 = v38;
      v38 += 32;
      qmemcpy(count, v10, 0x20u);
      m_begin->clr.m_value = 0;
      m_begin->position.x = *(float *)count;
      m_begin->position.y = *((float *)count + 1);
      m_begin->position.z = *((float *)count + 2);
      m_begin->normal.m_value = *((_DWORD *)count + 3);
      m_begin->tangent.m_value = 0;
      m_begin->binormal.m_value = 0;
      m_begin->uv.x = *((float *)count + 6);
      v8 = (vostok::render::untyped_buffer *)*((_DWORD *)count + 7);
      LODWORD(m_begin->uv.y) = v8;
      ++m_begin;
      v11 = v42-- == (char *)1;
      count += 32;
    }
    while ( !v11 );
  }
  vostok::render::untyped_buffer::unmap(v8, stride);
  counta = in_render_geometry->geom.m_object->m_ib.m_object->m_size;
  v43 = vostok::memory::doug_lea_allocator::malloc_impl(
          v12,
          (int)vostok::render::g_allocator,
          counta,
          "base_ib",
          v25,
          v29,
          v32);
  vostok::buffer_vector<unsigned short>::resize(
    (vostok::buffer_vector<unsigned short> *)(counta >> 1),
    (int *)out_indices);
  vostok::render::resource_manager::create_buffer(
    counta,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)v43,
    1,
    0,
    1);
  v14 = 0;
  if ( v13 )
  {
    ++*v13;
    v14 = (D3D11_MAP)v13;
  }
  vostok::render::resource_manager::copy(
    in_render_geometry->geom.m_object->m_ib.m_object,
    (vostok::render::resource_manager *)v14,
    v26);
  v16 = (unsigned __int8 *)vostok::render::untyped_buffer::map(v15, v14, D3D11_MAP_READ);
  memcpy((unsigned __int8 *)out_indices->m_begin, v16, counta);
  vostok::render::untyped_buffer::unmap(v17, v14);
  if ( data )
    vostok::memory::doug_lea_allocator::free_impl(v18, (int)vostok::render::g_allocator, data, v27, v30, v33);
  if ( v43 )
    vostok::memory::doug_lea_allocator::free_impl(v18, (int)vostok::render::g_allocator, v43, v27, v30, v33);
  v19 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  if ( v14 )
  {
    v11 = (*(_DWORD *)v14)-- == 1;
    if ( v11 )
    {
      if ( *(_DWORD *)(v14 + 4) )
      {
        if ( *(_DWORD *)(v14 + 28) == 1 && v19->m_indices_pool )
          vostok::render::hw_buffer_pool::deallocate(
            (const vostok::render::hw_buffer_pool_range *)(v14 + 4),
            (vostok::render::hw_buffer_pool *)v27);
        if ( !*(_DWORD *)(v14 + 28) && v19->m_vertices_pool )
          vostok::render::hw_buffer_pool::deallocate(
            (const vostok::render::hw_buffer_pool_range *)(v14 + 4),
            (vostok::render::hw_buffer_pool *)v27);
      }
      else
      {
        v20 = *(_DWORD *)(v14 + 20);
        if ( *(_DWORD *)(v14 + 28) == 1 )
          v19->m_total_index_buffers_size -= v20;
        else
          v19->m_total_vertex_buffers_size -= v20;
      }
    }
  }
  if ( stride )
  {
    v11 = (*(_DWORD *)stride)-- == 1;
    if ( v11 )
    {
      if ( *(_DWORD *)(stride + 4) )
      {
        if ( *(_DWORD *)(stride + 28) == 1 && v19->m_indices_pool )
          vostok::render::hw_buffer_pool::deallocate(
            (const vostok::render::hw_buffer_pool_range *)(stride + 4),
            (vostok::render::hw_buffer_pool *)v27);
        if ( !*(_DWORD *)(stride + 28) && v19->m_vertices_pool )
          vostok::render::hw_buffer_pool::deallocate(
            (const vostok::render::hw_buffer_pool_range *)(stride + 4),
            (vostok::render::hw_buffer_pool *)v27);
      }
      else
      {
        v21 = *(_DWORD *)(stride + 20);
        if ( *(_DWORD *)(stride + 28) == 1 )
          v19->m_total_index_buffers_size -= v21;
        else
          v19->m_total_vertex_buffers_size -= v21;
      }
    }
  }
  v11 = source->m_reference_count-- == 1;
  if ( v11 )
  {
    if ( source->pool_range.owner )
    {
      if ( source->m_type == enum_buffer_type_index && v19->m_indices_pool )
        vostok::render::hw_buffer_pool::deallocate(&source->pool_range, (vostok::render::hw_buffer_pool *)v27);
      if ( source->m_type == enum_buffer_type_vertex )
      {
        if ( v19->m_vertices_pool )
          vostok::render::hw_buffer_pool::deallocate(&source->pool_range, (vostok::render::hw_buffer_pool *)v27);
      }
    }
    else
    {
      m_size = source->m_size;
      if ( source->m_type == enum_buffer_type_index )
        v19->m_total_index_buffers_size -= m_size;
      else
        v19->m_total_vertex_buffers_size -= m_size;
    }
  }
}
