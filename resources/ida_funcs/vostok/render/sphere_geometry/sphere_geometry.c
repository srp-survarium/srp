void __thiscall vostok::render::sphere_geometry::sphere_geometry(
        vostok::render::sphere_geometry *this,
        vostok::render::sphere_geometry *num_sides,
        float num_rings,
        unsigned int num_ringsa)
{
  vostok::render::sphere_geometry *v4; // esi
  unsigned int v5; // ebx
  void *v6; // esp
  void *v7; // esp
  void *v8; // esp
  _WORD *v9; // edi
  float v10; // xmm0_4
  unsigned int v11; // edx
  vostok::render::sphere_geometry::vertex_type *v12; // eax
  float *v13; // esi
  double v14; // st7
  long double v15; // st7
  unsigned int v16; // eax
  const vostok::math::float4x4 *v17; // xmm1_4
  float v18; // eax
  double v19; // st7
  double v20; // st6
  vostok::render::sphere_geometry::vertex_type *v21; // eax
  float z; // xmm6_4
  float y; // xmm7_4
  float *v24; // ecx
  unsigned int v25; // edx
  float v26; // xmm3_4
  float v27; // xmm5_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm2_4
  vostok::render::sphere_geometry::vertex_type *v31; // edx
  unsigned int v32; // ecx
  _WORD *v33; // edi
  __int16 v34; // dx
  bool v35; // zf
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v37; // ecx
  vostok::render::res_declaration *m_object; // eax
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v40; // ecx
  vostok::render::untyped_buffer *v41; // edi
  vostok::render::resource_manager *v42; // edx
  survarium::game *m_game; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *m_movie; // ecx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **p_m_movie; // ebx
  ID3D11Buffer *m_hardware_buffer; // eax
  vostok::render::grass_render_model *v47; // esi
  vostok::render::untyped_buffer *v48; // eax
  vostok::render::untyped_buffer *v49; // ecx
  vostok::render::untyped_buffer *v50; // edi
  survarium::game *v51; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *v52; // ecx
  survarium::options_tab *v53; // edx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **v54; // ebx
  ID3D11Buffer *v55; // eax
  vostok::render::grass_render_model *v56; // esi
  float _X; // [esp+0h] [ebp-90h]
  _BYTE v58[16]; // [esp+4h] [ebp-8Ch] BYREF
  vostok::math::float4x4 rotation_matrix; // [esp+14h] [ebp-7Ch] BYREF
  __int64 v60; // [esp+54h] [ebp-3Ch]
  __int64 v61; // [esp+5Ch] [ebp-34h]
  void *v62; // [esp+64h] [ebp-2Ch]
  unsigned int num_vertices; // [esp+68h] [ebp-28h]
  int v64; // [esp+6Ch] [ebp-24h]
  float texcoord_u; // [esp+70h] [ebp-20h]
  float angle; // [esp+74h] [ebp-1Ch]
  unsigned int num_indices; // [esp+78h] [ebp-18h]
  float v68; // [esp+7Ch] [ebp-14h]
  void *data; // [esp+80h] [ebp-10h]
  vostok::render::sphere_geometry::vertex_type *vertices_it; // [esp+84h] [ebp-Ch]
  unsigned int s; // [esp+88h] [ebp-8h]
  __int16 num_sidesa; // [esp+9Ch] [ebp+Ch]
  survarium::options_tab *num_ringsb; // [esp+A0h] [ebp+10h]
  survarium::options_tab *num_ringsc; // [esp+A0h] [ebp+10h]

  v4 = num_sides;
  num_sides->m_vertext_declaration.m_object = 0;
  num_sides->m_vertex_buffer.m_object = 0;
  num_sides->m_index_buffer.m_object = 0;
  v5 = num_ringsa + 1;
  num_sides->m_stride = 24;
  num_vertices = (LODWORD(num_rings) + 1) * (num_ringsa + 1);
  num_indices = 6 * num_ringsa * LODWORD(num_rings);
  v6 = alloca(24 * num_vertices);
  data = v58;
  v64 = 24 * (num_ringsa + 1);
  v7 = alloca(v64);
  *(float *)&vertices_it = COERCE_FLOAT(v58);
  v68 = COERCE_FLOAT(v58);
  v8 = alloca(12 * num_ringsa * LODWORD(num_rings));
  v9 = v58;
  v62 = v58;
  if ( num_ringsa != -1 )
  {
    v10 = SNaN;
    v11 = num_ringsa + 1;
    do
    {
      v12 = vertices_it++;
      if ( v12 )
      {
        v12->uv.x = v10;
        v12->uv.y = v10;
      }
      --v11;
    }
    while ( v11 );
  }
  s = 0;
  if ( num_ringsa != -1 )
  {
    *(float *)&vertices_it = (float)num_ringsa;
    v13 = (float *)(LODWORD(v68) + 8);
    do
    {
      v14 = (double)s / *(float *)&vertices_it;
      texcoord_u = v14;
      angle = v14 * 3.1415927;
      *(v13 - 2) = sinf(angle);
      v15 = cosf(angle);
      v16 = s;
      *(v13 - 1) = v15;
      v17 = clear_value;
      v13[3] = texcoord_u;
      *v13 = 0.0;
      *((_DWORD *)v13 + 1) = v17;
      v13[2] = 0.0;
      v13 += 6;
      s = v16 + 1;
    }
    while ( v16 + 1 < v5 );
    v4 = num_sides;
  }
  v18 = num_rings;
  s = 0;
  if ( num_rings != NAN )
  {
    texcoord_u = num_rings;
    v19 = (double)LODWORD(num_rings);
    angle = v19;
    vertices_it = (vostok::render::sphere_geometry::vertex_type *)((char *)data + 20);
    do
    {
      v20 = (double)s;
      texcoord_u = v20;
      _X = v20 * 6.2831855 / v19;
      vostok::math::create_rotation_y(&rotation_matrix, (vostok::math::float4x4 *)LODWORD(_X));
      v19 = angle;
      texcoord_u = texcoord_u / angle;
      if ( num_ringsa != -1 )
      {
        v21 = vertices_it;
        z = rotation_matrix.c.z;
        y = rotation_matrix.c.y;
        HIDWORD(v61) = clear_value;
        v24 = (float *)(LODWORD(v68) + 8);
        v25 = num_ringsa + 1;
        do
        {
          v26 = *(v24 - 1);
          v27 = *(v24 - 2);
          v28 = (float)((float)(rotation_matrix.k.y * *v24) + (float)(rotation_matrix.i.y * v27))
              + (float)(rotation_matrix.j.y * v26);
          v29 = (float)(rotation_matrix.k.z * *v24) + (float)(rotation_matrix.i.z * v27);
          *(float *)&v60 = (float)((float)((float)(rotation_matrix.j.x * v26) + (float)(rotation_matrix.k.x * *v24))
                                 + (float)(v27 * rotation_matrix.i.x))
                         + rotation_matrix.c.x;
          v30 = v29 + (float)(rotation_matrix.j.z * v26);
          *((float *)&v60 + 1) = v28 + y;
          *(_QWORD *)&v21[-1].position.elements[1] = v60;
          *(float *)&v61 = v30 + z;
          *(_QWORD *)&v21[-1].position.elements[3] = v61;
          v21[-1].uv.y = texcoord_u;
          v21->position.x = v24[3];
          ++v21;
          v24 += 6;
          --v25;
        }
        while ( v25 );
      }
      vertices_it = (vostok::render::sphere_geometry::vertex_type *)((char *)vertices_it + v64);
      ++s;
    }
    while ( s < LODWORD(num_rings) + 1 );
    v4 = num_sides;
    v18 = num_rings;
  }
  if ( v18 != 0.0 )
  {
    *(float *)&v31 = 0.0;
    *(float *)&vertices_it = 0.0;
    num_sidesa = num_ringsa + 1;
    v68 = v18;
    do
    {
      v32 = 0;
      if ( num_ringsa )
      {
        do
        {
          *v9 = (_WORD)v31 + v32;
          v33 = v9 + 1;
          v34 = (_WORD)v31 + v32 + 1;
          *v33++ = v34;
          *v33++ = v32 + num_sidesa;
          *v33++ = v32 + num_sidesa;
          *v33++ = v34;
          v31 = vertices_it;
          *v33 = num_sidesa + v32++ + 1;
          v9 = v33 + 1;
        }
        while ( v32 < num_ringsa );
        v4 = num_sides;
      }
      num_sidesa += v5;
      v31 = (vostok::render::sphere_geometry::vertex_type *)((char *)v31 + v5);
      v35 = LODWORD(v68)-- == 1;
      vertices_it = v31;
    }
    while ( !v35 );
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  2u,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  (stlp_std::forward_iterator_tag *)sphere_geometry_vertex_layout);
  v37 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v37 = declaration;
  }
  m_object = v4->m_vertext_declaration.m_object;
  v4->m_vertext_declaration.m_object = v37;
  if ( m_object )
  {
    v35 = m_object->m_reference_count-- == 1;
    if ( v35 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  buffer = vostok::render::resource_manager::create_buffer(
             num_vertices * v4->m_stride,
             (bool)v9,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             data,
             enum_buffer_type_vertex,
             0,
             0);
  v40 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v40 = buffer;
  }
  v41 = v4->m_vertex_buffer.m_object;
  v4->m_vertex_buffer.m_object = v40;
  if ( v41 )
  {
    v35 = v41->m_reference_count-- == 1;
    if ( v35 )
    {
      v42 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game;
      m_movie = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      p_m_movie = &`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      num_ringsb = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( m_game == (survarium::game *)m_movie )
        goto LABEL_42;
      while ( (vostok::render::untyped_buffer *)m_game->vostok::engine_user::world::__vftable != v41 )
      {
        m_game = (survarium::game *)((char *)m_game + 4);
        if ( m_game == (survarium::game *)m_movie )
          goto LABEL_42;
      }
      if ( &m_game->survarium::scaleform_game_engine != (survarium::scaleform_game_engine *)m_movie )
        stlp_std::priv::__copy_ptrs<void * *,void * *>(
          (void **)&m_game->survarium::scaleform_game_engine::__vftable,
          (void **)&m_movie->m_object,
          (void **)&m_game->vostok::engine_user::world::__vftable);
      --*p_m_movie;
      num_ringsb[2].m_options = (survarium::options_item_base **)((char *)num_ringsb[2].m_options - v41->m_size);
      m_hardware_buffer = v41->m_hardware_buffer;
      v47 = vostok::render::g_allocator.m_object;
      if ( m_hardware_buffer )
      {
        m_hardware_buffer->Release(v41->m_hardware_buffer);
        v41->m_hardware_buffer = 0;
      }
      BYTE2(v47->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v47->m_reconstruction_info_actuality_tick), v41);
      v4 = num_sides;
    }
  }
  v42 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
LABEL_42:
  v48 = vostok::render::resource_manager::create_buffer(
          2 * num_indices,
          (bool)v41,
          v42,
          v62,
          enum_buffer_type_index,
          0,
          0);
  v49 = 0;
  if ( v48 )
  {
    ++v48->m_reference_count;
    v49 = v48;
  }
  v50 = v4->m_index_buffer.m_object;
  v4->m_index_buffer.m_object = v49;
  if ( v50 )
  {
    v35 = v50->m_reference_count-- == 1;
    if ( v35 )
    {
      v51 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game;
      v52 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      v53 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      v54 = &`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      num_ringsc = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( v51 != (survarium::game *)v52 )
      {
        while ( (vostok::render::untyped_buffer *)v51->vostok::engine_user::world::__vftable != v50 )
        {
          v51 = (survarium::game *)((char *)v51 + 4);
          if ( v51 == (survarium::game *)v52 )
            goto LABEL_55;
        }
        if ( &v51->survarium::scaleform_game_engine != (survarium::scaleform_game_engine *)v52 )
        {
          stlp_std::priv::__copy_ptrs<void * *,void * *>(
            (void **)&v51->survarium::scaleform_game_engine::__vftable,
            (void **)&v52->m_object,
            (void **)&v51->vostok::engine_user::world::__vftable);
          v53 = num_ringsc;
        }
        --*v54;
        v53[2].m_options = (survarium::options_item_base **)((char *)v53[2].m_options - v50->m_size);
        v55 = v50->m_hardware_buffer;
        v56 = vostok::render::g_allocator.m_object;
        if ( v55 )
        {
          v55->Release(v50->m_hardware_buffer);
          v50->m_hardware_buffer = 0;
        }
        BYTE2(v56->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(v56->m_reconstruction_info_actuality_tick), v50);
        v4 = num_sides;
      }
    }
  }
LABEL_55:
  v4->m_num_indices = num_indices;
}
