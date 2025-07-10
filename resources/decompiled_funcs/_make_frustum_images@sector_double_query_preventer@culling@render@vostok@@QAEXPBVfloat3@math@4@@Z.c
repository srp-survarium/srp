void __thiscall vostok::render::culling::sector_double_query_preventer::make_frustum_images(
        vostok::render::culling::sector_double_query_preventer *this,
        vostok::render::culling::sector_double_query_preventer *furthest_vertices,
        const vostok::math::float3 *furthest_verticesa)
{
  const vostok::math::float3 *v3; // ebx
  float v4; // ecx
  float v5; // eax
  const vostok::render::vector<vostok::math::frustum> *v6; // esi
  const vostok::math::frustum *M_finish; // edi
  int v8; // eax
  char v9; // bp
  int v10; // eax
  unsigned int v11; // ebp
  vostok::math::plane *M_start; // edx
  char *v13; // ebx
  float v14; // eax
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  __int64 v18; // xmm0_8
  vostok::math::frustum *p_f; // esi
  vostok::math::plane *v20; // edi
  const vostok::math::frustum *i; // ebx
  float v22; // eax
  const stlp_std::__true_type *v23; // [esp+0h] [ebp-17Ch]
  unsigned int v24; // [esp+4h] [ebp-178h]
  bool v25; // [esp+8h] [ebp-174h]
  const vostok::math::frustum *frustum_it; // [esp+14h] [ebp-168h]
  const vostok::render::vector<vostok::math::frustum> *it; // [esp+18h] [ebp-164h]
  float *p_y; // [esp+1Ch] [ebp-160h]
  const vostok::math::frustum *frutums_end; // [esp+20h] [ebp-15Ch]
  vostok::math::random32 color_randomizer; // [esp+24h] [ebp-158h]
  const vostok::render::vector<vostok::math::frustum> *sectors_max_frustums_end; // [esp+28h] [ebp-154h]
  __int64 v32; // [esp+2Ch] [ebp-150h]
  vostok::math::plane planes[6]; // [esp+38h] [ebp-144h] BYREF
  vostok::render::culling::sector_double_query_preventer::frustum_image __x; // [esp+9Ch] [ebp-E0h] BYREF
  vostok::math::frustum f; // [esp+100h] [ebp-7Ch] BYREF
  char v36; // [esp+178h] [ebp-4h] BYREF

  v3 = (const vostok::math::float3 *)furthest_vertices;
  v4 = *(float *)&furthest_vertices->m_frustum_images._M_impl._M_start;
  color_randomizer.m_seed = 0;
  if ( (vostok::render::culling::sector_double_query_preventer::frustum_image *)LODWORD(v4) != furthest_vertices->m_frustum_images._M_impl._M_finish )
    *(float *)&furthest_vertices->m_frustum_images._M_impl._M_finish = v4;
  v5 = *(float *)&furthest_vertices->m_sectors_max_frustums;
  v6 = *(const vostok::render::vector<vostok::math::frustum> **)LODWORD(v5);
  sectors_max_frustums_end = *(const vostok::render::vector<vostok::math::frustum> **)(LODWORD(v5) + 4);
  it = *(const vostok::render::vector<vostok::math::frustum> **)LODWORD(v5);
  if ( *(const vostok::render::vector<vostok::math::frustum> **)LODWORD(v5) != sectors_max_frustums_end )
  {
    p_y = &furthest_verticesa->y;
    while ( 1 )
    {
      M_finish = v6->_M_impl._M_finish;
      frutums_end = M_finish;
      if ( v6 == *(const vostok::render::vector<vostok::math::frustum> **)LODWORD(v3->y) )
      {
        for ( i = v6->_M_impl._M_start;
              i != M_finish;
              furthest_vertices->m_frustum_images._M_impl._M_finish[-1].c.m_value = -16711936 )
        {
          v22 = *(float *)&furthest_vertices->m_frustum_images._M_impl._M_finish;
          __x.c.m_value = -1;
          if ( (vostok::render::culling::sector_double_query_preventer::frustum_image *)LODWORD(v22) == furthest_vertices->m_frustum_images._M_impl._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<vostok::render::culling::sector_double_query_preventer::frustum_image,vostok::render::std_allocator<vostok::render::culling::sector_double_query_preventer::frustum_image>>::_M_insert_overflow(
              (vostok::render::culling::sector_double_query_preventer::frustum_image *)LODWORD(v22),
              &furthest_vertices->m_frustum_images._M_impl,
              &furthest_vertices->m_frustum_images._M_impl,
              &__x,
              v23,
              v24,
              v25);
          }
          else
          {
            qmemcpy((void *)LODWORD(v22), &__x, 0x64u);
            v6 = it;
            ++furthest_vertices->m_frustum_images._M_impl._M_finish;
          }
          vostok::math::get_frustum_vertices(
            i++,
            (vostok::math::float3 (*)[8])&furthest_vertices->m_frustum_images._M_impl._M_finish[-1]);
        }
      }
      else
      {
        v8 = 134775813 * color_randomizer.m_seed + 1;
        v9 = (unsigned __int64)(unsigned int)v8 >> 25;
        v10 = 134775813 * v8 + 1;
        color_randomizer.m_seed = 134775813 * v10 + 1;
        v11 = (unsigned __int8)(((unsigned __int64)color_randomizer.m_seed >> 25) + 0x80)
            | (((unsigned __int8)(((unsigned __int64)(unsigned int)v10 >> 25) + 0x80) | (((v9 + 0x80) | 0xFFFFFF00) << 8)) << 8);
        M_start = (vostok::math::plane *)v6->_M_impl._M_start;
        frustum_it = v6->_M_impl._M_start;
        if ( v6->_M_impl._M_start != M_finish )
        {
          v13 = (char *)&M_start[5].vector.elements[2];
          while ( 1 )
          {
            v14 = *(float *)&furthest_vertices->m_frustum_images._M_impl._M_finish;
            __x.c.m_value = -1;
            if ( (vostok::render::culling::sector_double_query_preventer::frustum_image *)LODWORD(v14) == furthest_vertices->m_frustum_images._M_impl._M_end_of_storage._M_data )
            {
              stlp_std::priv::_Impl_vector<vostok::render::culling::sector_double_query_preventer::frustum_image,vostok::render::std_allocator<vostok::render::culling::sector_double_query_preventer::frustum_image>>::_M_insert_overflow(
                (vostok::render::culling::sector_double_query_preventer::frustum_image *)LODWORD(v14),
                &furthest_vertices->m_frustum_images._M_impl,
                &furthest_vertices->m_frustum_images._M_impl,
                &__x,
                v23,
                v24,
                v25);
              M_start = (vostok::math::plane *)frustum_it;
            }
            else
            {
              qmemcpy((void *)LODWORD(v14), &__x, 0x64u);
              ++furthest_vertices->m_frustum_images._M_impl._M_finish;
            }
            v15 = *(float *)v13;
            v16 = *((float *)v13 - 2);
            planes[0] = *M_start;
            planes[1] = *(vostok::math::plane *)(v13 - 68);
            planes[2] = (vostok::math::plane)*((_OWORD *)v13 - 3);
            planes[3] = *(vostok::math::plane *)(v13 - 28);
            HIDWORD(v32) = *((_DWORD *)v13 - 1);
            *(float *)&v32 = v16;
            *(_QWORD *)&planes[4].normal.x = v32;
            planes[4].normal.z = v15;
            v17 = (float)((float)(*(p_y - 1) * v16) + (float)(p_y[1] * v15)) + (float)(*((float *)&v32 + 1) * *p_y);
            *(_QWORD *)&planes[5].normal.x = *(_QWORD *)(v13 + 12);
            v18 = *(_QWORD *)(v13 + 20);
            planes[4].d = -v17;
            *(_QWORD *)&planes[5].vector.elements[2] = v18;
            p_f = &f;
            v20 = planes;
            do
            {
              *(_QWORD *)&p_f->m_planes[0].plane.normal.x = *(_QWORD *)&v20->normal.x;
              *(_QWORD *)&p_f->m_planes[0].plane.vector.elements[2] = *(_QWORD *)&v20->vector.elements[2];
              vostok::math::aabb_plane::normalize(p_f->m_planes);
              p_f = (vostok::math::frustum *)((char *)p_f + 20);
              ++v20;
            }
            while ( p_f != (vostok::math::frustum *)&v36 );
            vostok::math::get_frustum_vertices(
              &f,
              (vostok::math::float3 (*)[8])&furthest_vertices->m_frustum_images._M_impl._M_finish[-1]);
            furthest_vertices->m_frustum_images._M_impl._M_finish[-1].c.m_value = v11;
            v13 += 120;
            if ( ++frustum_it == frutums_end )
              break;
            M_start = (vostok::math::plane *)frustum_it;
          }
          v6 = it;
        }
      }
      p_y += 3;
      it = ++v6;
      if ( v6 == sectors_max_frustums_end )
        break;
      v3 = (const vostok::math::float3 *)furthest_vertices;
    }
  }
}
