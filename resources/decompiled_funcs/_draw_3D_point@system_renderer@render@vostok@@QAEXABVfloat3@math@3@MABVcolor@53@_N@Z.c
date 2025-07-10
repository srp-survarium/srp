void __userpurge vostok::render::system_renderer::draw_3D_point(
        vostok::render::system_renderer *this@<ecx>,
        vostok::render::system_renderer *position,
        float *width,
        const vostok::math::color *color,
        bool use_depth)
{
  int v5; // edx
  unsigned int v6; // eax
  int v7; // eax
  const void *v8; // ebp
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  long double v12; // st7
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm6_4
  unsigned int m_value; // eax
  float v23; // xmm3_4
  __int64 v24; // xmm0_8
  float v25; // [esp+14h] [ebp-150h]
  float v26; // [esp+14h] [ebp-150h]
  float v27; // [esp+18h] [ebp-14Ch]
  float v28; // [esp+18h] [ebp-14Ch]
  float v29; // [esp+1Ch] [ebp-148h]
  float v30; // [esp+20h] [ebp-144h]
  __int64 v31; // [esp+24h] [ebp-140h]
  vostok::math::float3 offset_by_x; // [esp+2Ch] [ebp-138h] BYREF
  __int16 v33; // [esp+38h] [ebp-12Ch]
  __int16 v34; // [esp+3Ah] [ebp-12Ah]
  __int16 v35; // [esp+3Ch] [ebp-128h]
  __int16 v36; // [esp+3Eh] [ebp-126h]
  unsigned int screen_width; // [esp+40h] [ebp-124h] BYREF
  float v38; // [esp+44h] [ebp-120h]
  float dist; // [esp+48h] [ebp-11Ch]
  vostok::math::float4x4 inv_view_proj_matrix; // [esp+4Ch] [ebp-118h] BYREF
  float v41; // [esp+90h] [ebp-D4h]
  float v42; // [esp+94h] [ebp-D0h]
  float v43; // [esp+98h] [ebp-CCh]
  vostok::fixed_vector<vostok::render::vertex_colored,4> vertices; // [esp+9Ch] [ebp-C8h] BYREF
  vostok::math::float4x4 inv_view_matrix; // [esp+E4h] [ebp-80h] BYREF
  vostok::math::float4x4 view_matrix; // [esp+124h] [ebp-40h] BYREF

  if ( vostok::render::system_renderer::is_effects_ready(this, position) )
  {
    if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 105) )
      v6 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 27);
    else
      v6 = *(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                       + 540)
                     + 144);
    screen_width = v6;
    v7 = *(_DWORD *)(v5 + 88);
    v8 = (const void *)(v7 + 15620);
    qmemcpy((void *)&view_matrix, (const void *)(v7 + 15620), sizeof(view_matrix));
    qmemcpy((void *)&inv_view_matrix, (const void *)(v7 + 15940), sizeof(inv_view_matrix));
    vostok::math::mul4x4(&view_matrix, &inv_view_matrix);
    vostok::math::float4x4::try_invert(&inv_view_proj_matrix, &inv_view_proj_matrix);
    qmemcpy((void *)&inv_view_matrix, v8, sizeof(inv_view_matrix));
    vostok::math::float4x4::try_invert(&inv_view_matrix, &inv_view_matrix);
    v27 = *width;
    dist = sqrtf(
             (float)((float)((float)(inv_view_matrix.c.z - width[2]) * (float)(inv_view_matrix.c.z - width[2]))
                   + (float)((float)(inv_view_matrix.c.y - width[1]) * (float)(inv_view_matrix.c.y - width[1])))
           + (float)((float)(inv_view_matrix.c.x - *width) * (float)(inv_view_matrix.c.x - *width)));
    v38 = (float)screen_width;
    v41 = v38;
    v9 = (float)((float)(inv_view_proj_matrix.j.x * 0.0) + (float)(inv_view_proj_matrix.i.x * 1000.0))
       + (float)(inv_view_proj_matrix.k.x * 0.0);
    v43 = inv_view_proj_matrix.k.x * 0.0;
    v42 = inv_view_proj_matrix.k.y * 0.0;
    v10 = (float)((float)(inv_view_proj_matrix.j.y * 0.0) + (float)(inv_view_proj_matrix.i.y * 1000.0))
        + (float)(inv_view_proj_matrix.k.y * 0.0);
    offset_by_x.x = v9;
    v11 = (float)((float)(inv_view_proj_matrix.j.z * 0.0) + (float)(inv_view_proj_matrix.i.z * 1000.0))
        + (float)(inv_view_proj_matrix.k.z * 0.0);
    offset_by_x.y = v10;
    v25 = inv_view_proj_matrix.k.z * 0.0;
    offset_by_x.z = v11;
    *(float *)&screen_width = 1.0 / sqrtf((float)((float)(v9 * v9) + (float)(v11 * v11)) + (float)(v10 * v10));
    offset_by_x.z = (float)((float)((float)((float)(v11 * *(float *)&screen_width)
                                          * (float)(*(float *)&clear_value / v41))
                                  * 3.0)
                          * 0.5)
                  * dist;
    offset_by_x.x = (float)((float)((float)((float)(*(float *)&clear_value / v41) * (float)(*(float *)&screen_width * v9))
                                  * 3.0)
                          * 0.5)
                  * dist;
    offset_by_x.y = (float)((float)((float)((float)(v10 * *(float *)&screen_width)
                                          * (float)(*(float *)&clear_value / v41))
                                  * 3.0)
                          * 0.5)
                  * dist;
    v29 = (float)((float)(inv_view_proj_matrix.i.x * 0.0) - (float)(inv_view_proj_matrix.j.x * 1000.0)) + v43;
    v30 = (float)((float)(inv_view_proj_matrix.i.y * 0.0) - (float)(inv_view_proj_matrix.j.y * 1000.0)) + v42;
    *(float *)&v31 = (float)((float)(inv_view_proj_matrix.i.z * 0.0) - (float)(inv_view_proj_matrix.j.z * 1000.0)) + v25;
    v12 = sqrtf((float)((float)(v29 * v29) + (float)(*(float *)&v31 * *(float *)&v31)) + (float)(v30 * v30));
    v13 = v27;
    v14 = width[2];
    v26 = 1.0 / v12;
    v15 = width[1];
    v16 = (float)((float)((float)((float)(*(float *)&clear_value / v38) * (float)(v26 * v29)) * 3.0) * 0.5) * dist;
    v17 = (float)((float)((float)((float)(v30 * v26) * (float)(*(float *)&clear_value / v38)) * 3.0) * 0.5) * dist;
    v18 = (float)((float)((float)((float)(*(float *)&v31 * v26) * (float)(*(float *)&clear_value / v38)) * 3.0) * 0.5)
        * dist;
    v19 = v27 - offset_by_x.x;
    inv_view_proj_matrix.i.x = (float)(v27 - offset_by_x.x) - v16;
    v28 = v15;
    v20 = v15 - offset_by_x.y;
    inv_view_proj_matrix.i.y = v20 - v17;
    *(float *)&v31 = v14 - offset_by_x.z;
    v21 = v13 + offset_by_x.x;
    inv_view_proj_matrix.i.w = v19 + v16;
    vertices.m_begin = (vostok::render::vertex_colored *)vertices.m_buffer;
    inv_view_proj_matrix.j.z = v21 + v16;
    LODWORD(offset_by_x.x) = &offset_by_x.z;
    m_value = color->m_value;
    HIDWORD(v31) = m_value;
    inv_view_proj_matrix.j.x = v20 + v17;
    inv_view_proj_matrix.j.y = (float)(v14 - offset_by_x.z) + v18;
    inv_view_proj_matrix.i.z = (float)(v14 - offset_by_x.z) - v18;
    *(float *)&v31 = inv_view_proj_matrix.i.z;
    v23 = v21 - v16;
    *(_QWORD *)vertices.m_buffer[0].m_store = *(_QWORD *)&inv_view_proj_matrix.i.x;
    *(_QWORD *)&vertices.m_buffer[0].m_store[8] = v31;
    *(float *)&v31 = inv_view_proj_matrix.j.y;
    HIDWORD(v31) = m_value;
    *(_QWORD *)vertices.m_buffer[1].m_store = *(_QWORD *)&inv_view_proj_matrix.lines[0].elements[3];
    inv_view_proj_matrix.k.x = (float)(offset_by_x.z + v14) + v18;
    *(_QWORD *)&vertices.m_buffer[1].m_store[8] = v31;
    HIDWORD(v31) = m_value;
    inv_view_proj_matrix.j.w = (float)(offset_by_x.y + v28) + v17;
    *(float *)&v31 = inv_view_proj_matrix.k.x;
    *(_QWORD *)vertices.m_buffer[2].m_store = *(_QWORD *)&inv_view_proj_matrix.lines[1].elements[2];
    v24 = v31;
    HIDWORD(v31) = m_value;
    inv_view_proj_matrix.k.w = (float)(offset_by_x.z + v14) - v18;
    *(float *)&v31 = inv_view_proj_matrix.k.w;
    LODWORD(offset_by_x.z) = 65538;
    *(_QWORD *)&vertices.m_buffer[2].m_store[8] = v24;
    inv_view_proj_matrix.k.y = v23;
    inv_view_proj_matrix.k.z = (float)(offset_by_x.y + v28) - v17;
    vertices.m_end = (vostok::render::vertex_colored *)&inv_view_matrix;
    v34 = 3;
    *(_QWORD *)vertices.m_buffer[3].m_store = *(_QWORD *)&inv_view_proj_matrix.lines[2].elements[1];
    v35 = 2;
    *(_QWORD *)&vertices.m_buffer[3].m_store[8] = v31;
    v33 = 0;
    v36 = 0;
    LODWORD(offset_by_x.y) = &screen_width;
    vostok::render::system_renderer::draw_triangles(
      (vostok::render::system_renderer *)vertices.m_buffer,
      position,
      (vostok::render::vertex_colored *)vertices.m_buffer,
      (const unsigned __int16 *)&inv_view_matrix,
      (unsigned __int8 *)&offset_by_x.elements[2],
      (const unsigned __int16 *)&screen_width,
      0);
  }
}
