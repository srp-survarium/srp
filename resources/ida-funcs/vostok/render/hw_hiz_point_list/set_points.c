void __thiscall vostok::render::hw_hiz_point_list::set_points(
        vostok::render::hw_hiz_point_list *this,
        const vostok::math::float4 *in_data,
        unsigned int *culling_results_buffer_width,
        unsigned int a4)
{
  vostok::render::untyped_buffer *v5; // eax
  vostok::render::untyped_buffer *v6; // ecx
  ID3D11Buffer *v7; // [esp+Ch] [ebp-Ch]
  unsigned int v8; // [esp+10h] [ebp-8h]
  unsigned int v9; // [esp+20h] [ebp+8h]

  v5 = (vostok::render::untyped_buffer *)vostok::render::untyped_buffer::map(
                                           (vostok::render::untyped_buffer *)this,
                                           SLODWORD(in_data->y),
                                           D3D11_MAP_WRITE_DISCARD);
  v9 = 0;
  if ( LODWORD(in_data->z) )
  {
    v6 = v5;
    do
    {
      v6->m_reference_count = *culling_results_buffer_width;
      v6->pool_range.owner = (vostok::render::hw_buffer_pool_chunk *)culling_results_buffer_width[1];
      v6->pool_range.begin_offset = culling_results_buffer_width[2];
      v6->pool_range.end_offset = culling_results_buffer_width[3];
      *(float *)&v7 = (float)(v9 % a4);
      *(float *)&v8 = (float)(v9 / a4);
      ++v9;
      culling_results_buffer_width += 4;
      v6->m_hardware_buffer = v7;
      v6->m_size = v8;
      v6 = (vostok::render::untyped_buffer *)((char *)v6 + 24);
    }
    while ( v9 < LODWORD(in_data->z) );
  }
  vostok::render::untyped_buffer::unmap(v6, LODWORD(in_data->y));
}
