void __thiscall vostok::render::sliced_cube_geometry::sliced_cube_geometry(
        vostok::render::sliced_cube_geometry *this,
        vostok::render::sliced_cube_geometry *in_num_cells,
        unsigned int in_num_cellsa)
{
  vostok::render::sliced_cube_geometry *v3; // ebx
  void *v4; // esp
  _QWORD *v5; // esi
  void *v6; // esp
  unsigned int v7; // edi
  _WORD *v8; // eax
  const vostok::math::float4x4 *v9; // xmm0_4
  __int64 v10; // xmm4_8
  __int64 v11; // xmm5_8
  __int64 v12; // xmm6_8
  char *v13; // ecx
  double v14; // st7
  double v15; // st6
  __int64 v16; // xmm7_8
  _QWORD *v17; // esi
  _QWORD *v18; // ecx
  float v19; // xmm2_4
  __int64 v20; // xmm2_8
  __int64 v21; // xmm2_8
  _WORD *v22; // eax
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v24; // ecx
  vostok::render::res_declaration *m_object; // eax
  bool v26; // zf
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v28; // ecx
  vostok::render::res_state *v29; // edi
  ID3D11RasterizerState *m_rasterizer_state; // eax
  vostok::render::grass_render_model *v31; // esi
  vostok::render::untyped_buffer *v32; // eax
  vostok::render::untyped_buffer *v33; // ecx
  vostok::render::res_state *v34; // edi
  ID3D11RasterizerState *v35; // eax
  vostok::render::grass_render_model *v36; // esi
  _BYTE v37[12]; // [esp+0h] [ebp-A0h] BYREF
  __int64 v38; // [esp+Ch] [ebp-94h] BYREF
  __int64 v39; // [esp+14h] [ebp-8Ch]
  __int64 v40; // [esp+1Ch] [ebp-84h]
  __int64 v41; // [esp+24h] [ebp-7Ch]
  __int64 v42; // [esp+2Ch] [ebp-74h]
  __int64 v43; // [esp+34h] [ebp-6Ch]
  __int64 v44; // [esp+3Ch] [ebp-64h]
  __int64 v45; // [esp+44h] [ebp-5Ch]
  __int64 v46; // [esp+4Ch] [ebp-54h]
  __int64 v47; // [esp+54h] [ebp-4Ch]
  __int64 v48; // [esp+5Ch] [ebp-44h]
  __int64 v49; // [esp+64h] [ebp-3Ch]
  __int64 v50; // [esp+6Ch] [ebp-34h]
  __int64 v51; // [esp+74h] [ebp-2Ch]
  __int64 v52; // [esp+7Ch] [ebp-24h]
  __int64 v53; // [esp+84h] [ebp-1Ch]
  unsigned int size; // [esp+8Ch] [ebp-14h]
  _BYTE *v55; // [esp+90h] [ebp-10h]
  void *data; // [esp+94h] [ebp-Ch]
  unsigned int num_vertices; // [esp+98h] [ebp-8h]
  float slice_z; // [esp+9Ch] [ebp-4h]
  float in_num_cellsd; // [esp+ACh] [ebp+Ch]
  survarium::options_tab *in_num_cellsb; // [esp+ACh] [ebp+Ch]
  survarium::options_tab *in_num_cellsc; // [esp+ACh] [ebp+Ch]

  v3 = in_num_cells;
  in_num_cells->m_vertext_declaration.m_object = 0;
  in_num_cells->m_vertex_buffer.m_object = 0;
  in_num_cells->m_index_buffer.m_object = 0;
  in_num_cells->m_slices = in_num_cellsa;
  num_vertices = 4 * in_num_cellsa;
  in_num_cells->m_stride = 32;
  v4 = alloca(in_num_cellsa << 7);
  v5 = v37;
  v55 = v37;
  size = 12 * in_num_cellsa;
  v6 = alloca(12 * in_num_cellsa);
  v7 = 0;
  v8 = v37;
  data = v37;
  if ( in_num_cellsa )
  {
    v9 = clear_value;
    v48 = 0;
    LODWORD(v53) = 0;
    LODWORD(v45) = 0;
    HIDWORD(v53) = clear_value;
    v10 = v53;
    v40 = (unsigned int)clear_value;
    v11 = (unsigned int)clear_value;
    HIDWORD(v45) = clear_value;
    v12 = v45;
    LODWORD(v47) = 0;
    LODWORD(v42) = 0;
    LODWORD(v39) = 0;
    LODWORD(v50) = clear_value;
    HIDWORD(v50) = clear_value;
    HIDWORD(v47) = clear_value;
    HIDWORD(v42) = clear_value;
    HIDWORD(v39) = clear_value;
    v13 = (char *)&v38 + 4;
    do
    {
      v14 = (double)v7;
      v15 = v14 / (double)v3->m_slices;
      *v5 = 0;
      v16 = v50;
      v17 = v5 + 12;
      v18 = v13 + 96;
      slice_z = v15;
      *(float *)&v49 = v15;
      *((float *)&v49 + 1) = v14;
      *(float *)&v41 = v15;
      *(v17 - 11) = v49;
      v19 = *((float *)v17 - 24);
      *((float *)&v41 + 1) = v14;
      *(float *)&v52 = (float)(v19 * 2.0) - *(float *)&v9;
      *(float *)&v51 = v15;
      *((float *)&v52 + 1) = (float)((float)(*(float *)&v9 - *((float *)v17 - 23)) * 2.0) - *(float *)&v9;
      *(v18 - 12) = v52;
      v20 = v41;
      *(v18 - 11) = v10;
      *(v17 - 8) = v11;
      *(v17 - 7) = v20;
      *(float *)&v44 = (float)(*((float *)v17 - 16) * 2.0) - *(float *)&v9;
      *((float *)&v44 + 1) = (float)((float)(*(float *)&v9 - *((float *)v17 - 15)) * 2.0) - *(float *)&v9;
      *(v18 - 8) = v44;
      *(v18 - 7) = v12;
      *(v17 - 4) = v16;
      *((float *)&v51 + 1) = v14;
      *(v17 - 3) = v51;
      *(float *)&v46 = (float)(*((float *)v17 - 8) * 2.0) - *(float *)&v9;
      *(float *)&v16 = (float)((float)(*(float *)&v9 - *((float *)v17 - 7)) * 2.0) - *(float *)&v9;
      in_num_cellsd = v14;
      *((float *)&v43 + 1) = in_num_cellsd;
      v21 = v42;
      HIDWORD(v46) = v16;
      *(v18 - 4) = v46;
      *(v18 - 3) = v47;
      *(float *)&v16 = slice_z;
      *v17 = v21;
      LODWORD(v43) = v16;
      v17[1] = v43;
      *(float *)&v38 = (float)(*(float *)v17 * 2.0) - *(float *)&v9;
      *((float *)&v38 + 1) = (float)((float)(*(float *)&v9 - *((float *)v17 + 1)) * 2.0) - *(float *)&v9;
      *v18 = v38;
      v18[1] = v39;
      *v8 = 4 * v7;
      v22 = v8 + 1;
      *v22++ = 4 * v7 + 1;
      *v22++ = 4 * v7 + 2;
      *v22++ = 4 * v7;
      *v22 = 4 * v7 + 2;
      v3 = in_num_cells;
      *++v22 = 4 * v7++ + 3;
      v5 = v17 + 4;
      v13 = (char *)(v18 + 4);
      v8 = v22 + 1;
    }
    while ( v7 < in_num_cells->m_slices );
    v5 = v55;
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  2u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)sliced_cube_vertex_layout);
  v24 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v24 = declaration;
  }
  m_object = v3->m_vertext_declaration.m_object;
  v3->m_vertext_declaration.m_object = v24;
  if ( m_object )
  {
    v26 = m_object->m_reference_count-- == 1;
    if ( v26 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  buffer = vostok::render::resource_manager::create_buffer(
             num_vertices * v3->m_stride,
             v7,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             v5,
             enum_buffer_type_vertex,
             0,
             0);
  v28 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v28 = buffer;
  }
  v29 = (vostok::render::res_state *)v3->m_vertex_buffer.m_object;
  v3->m_vertex_buffer.m_object = v28;
  if ( v29 )
  {
    v26 = v29->m_reference_count-- == 1;
    if ( v26 )
    {
      in_num_cellsb = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v29) )
      {
        in_num_cellsb[2].m_options = (survarium::options_item_base **)((char *)in_num_cellsb[2].m_options
                                                                     - (unsigned int)v29->m_depth_stencil_state);
        m_rasterizer_state = v29->m_rasterizer_state;
        v31 = vostok::render::g_allocator.m_object;
        if ( m_rasterizer_state )
        {
          m_rasterizer_state->Release(v29->m_rasterizer_state);
          v29->m_rasterizer_state = 0;
        }
        BYTE2(v31->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v31->m_reconstruction_info_actuality_tick), v29);
      }
    }
  }
  v32 = vostok::render::resource_manager::create_buffer(
          size,
          (bool)v29,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          data,
          enum_buffer_type_index,
          0,
          0);
  v33 = 0;
  if ( v32 )
  {
    ++v32->m_reference_count;
    v33 = v32;
  }
  v34 = (vostok::render::res_state *)v3->m_index_buffer.m_object;
  v3->m_index_buffer.m_object = v33;
  if ( v34 )
  {
    v26 = v34->m_reference_count-- == 1;
    if ( v26 )
    {
      in_num_cellsc = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v34) )
      {
        in_num_cellsc[2].m_options = (survarium::options_item_base **)((char *)in_num_cellsc[2].m_options
                                                                     - (unsigned int)v34->m_depth_stencil_state);
        v35 = v34->m_rasterizer_state;
        v36 = vostok::render::g_allocator.m_object;
        if ( v35 )
        {
          v35->Release(v34->m_rasterizer_state);
          v34->m_rasterizer_state = 0;
        }
        BYTE2(v36->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v36->m_reconstruction_info_actuality_tick), v34);
      }
    }
  }
}
