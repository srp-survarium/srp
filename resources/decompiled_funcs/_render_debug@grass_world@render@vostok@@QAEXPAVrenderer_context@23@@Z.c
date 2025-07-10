void __thiscall vostok::render::grass_world::render_debug(vostok::render::grass_world *this)
{
  void **M_finish; // edx
  vostok::render::grass_patch *const *M_start; // eax
  float v3; // xmm3_4
  const vostok::math::float4x4 *v4; // xmm0_4
  float v5; // xmm2_4
  signed int v6; // esi
  int v7; // ecx
  unsigned int v8; // ebx
  int v9; // edx
  vostok::render::grass_instance **v10; // eax
  double v11; // st7
  float v12; // xmm1_4
  float v13; // xmm2_4
  vostok::render::grass_instance *v14; // eax
  __int64 v15; // xmm3_8
  signed int v16; // esi
  int v17; // ecx
  unsigned int v18; // ebx
  int v19; // edx
  __int64 v20; // xmm0_8
  double v21; // st7
  vostok::render::grass_instance **it_instance; // [esp+10h] [ebp-9Ch]
  vostok::render::grass_patch *fnum_instancesa; // [esp+14h] [ebp-98h]
  float fnum_instances; // [esp+14h] [ebp-98h]
  unsigned int fnum_instancesb; // [esp+14h] [ebp-98h]
  vostok::math::color color; // [esp+24h] [ebp-88h] BYREF
  unsigned int v27; // [esp+28h] [ebp-84h]
  int v28; // [esp+2Ch] [ebp-80h]
  int v29; // [esp+30h] [ebp-7Ch]
  float finstance_index; // [esp+34h] [ebp-78h]
  int v31; // [esp+38h] [ebp-74h]
  int v32; // [esp+3Ch] [ebp-70h]
  unsigned __int16 indices[2]; // [esp+40h] [ebp-6Ch] BYREF
  unsigned __int16 indices_end[2]; // [esp+44h] [ebp-68h] BYREF
  int v35; // [esp+48h] [ebp-64h]
  int v36; // [esp+4Ch] [ebp-60h]
  vostok::render::grass_patch *const *it; // [esp+50h] [ebp-5Ch]
  int v38; // [esp+54h] [ebp-58h]
  vostok::math::random32 r; // [esp+58h] [ebp-54h]
  vostok::render::grass_instance **end_instance; // [esp+5Ch] [ebp-50h]
  float fpatch_index; // [esp+60h] [ebp-4Ch]
  vostok::render::grass_patch *const *end; // [esp+64h] [ebp-48h]
  float v43; // [esp+68h] [ebp-44h]
  float v44; // [esp+6Ch] [ebp-40h]
  vostok::math::float3 origin; // [esp+70h] [ebp-3Ch]
  __int64 v46; // [esp+7Ch] [ebp-30h]
  float v47; // [esp+84h] [ebp-28h]
  vostok::render::vertex_colored vertices[2]; // [esp+88h] [ebp-24h] BYREF
  char v49; // [esp+A8h] [ebp-4h] BYREF

  if ( s_draw_grass_debug_value )
  {
    M_finish = this->m_visible_patches._M_impl._M_finish;
    M_start = (vostok::render::grass_patch *const *)this->m_visible_patches._M_impl._M_start;
    end_instance = (vostok::render::grass_instance **)(((char *)M_finish - (char *)M_start) >> 2);
    it = M_start;
    end = (vostok::render::grass_patch *const *)M_finish;
    v3 = 0.0;
    finstance_index = (float)(unsigned int)end_instance;
    fpatch_index = 0.0;
    r.m_seed = 0;
    if ( M_start != (vostok::render::grass_patch *const *)M_finish )
    {
      v4 = clear_value;
      v5 = *(float *)&clear_value / finstance_index;
      v44 = *(float *)&clear_value / finstance_index;
      while ( 1 )
      {
        fnum_instancesa = *M_start;
        v36 = -72;
        v6 = ~(~(COERCE_INT((float)(*(float *)&v4 - (float)(v5 * v3)) * 255.0) - 1) & 0x80000000)
           & COERCE_UNSIGNED_INT((float)(*(float *)&v4 - (float)(v5 * v3)) * 255.0);
        v35 = 0;
        v7 = 158 - (unsigned __int8)(v6 >> 23);
        v8 = (v6 | 0xFF800000) << 8 >> v7;
        *(_DWORD *)indices_end = v7 - 96;
        v38 = v6 >> 31;
        v27 = v8;
        v9 = -((v6 & (((1 << (v7 - 96)) - 1) >> 8)) != 0);
        v28 = v6 >> 31;
        color = (vostok::math::color)((unsigned __int8)((v6 >> 31)
                                                      ^ ((v7 - 96 + 64) >> 31)
                                                      & (v8 - ((v6 >> 31) & ((v6 & (((1 << (v7 - 96)) - 1) >> 8)) == 0))))
                                    | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                    & ((v38 << 16)
                                     ^ ((v7 - 96 + 64) >> 31 << 16)
                                     & ((v8 - (v38 & (v9 + 1))) << 16))
                                    | ((unsigned __int16)((_WORD)v28 << 8)
                                     ^ (unsigned __int16)(((unsigned __int16)((v7 - 96 + 64) >> 31) << 8)
                                                        & (((_WORD)v8
                                                          - ((unsigned __int16)v28 & (unsigned __int16)(v9 + 1))) << 8)))
                                    & 0xFF00
                                    | 0xFF000000);
        vostok::render::system_renderer::draw_aabb(
          (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
          &fnum_instancesa->m_aabb,
          &color);
        v10 = (vostok::render::grass_instance **)fnum_instancesa->m_instances._M_impl._M_start;
        v11 = (double)(unsigned int)(((char *)fnum_instancesa->m_instances._M_impl._M_finish - (char *)v10) >> 2);
        it_instance = v10;
        end_instance = (vostok::render::grass_instance **)fnum_instancesa->m_instances._M_impl._M_finish;
        v12 = 0.0;
        fnum_instances = v11;
        v4 = clear_value;
        finstance_index = 0.0;
        if ( v10 != end_instance )
        {
          v13 = *(float *)&clear_value / fnum_instances;
          v43 = *(float *)&clear_value / fnum_instances;
          while ( 1 )
          {
            v14 = *v10;
            v15 = *(_QWORD *)&v14->m_transform.lines[3].x;
            origin.z = v14->m_transform.c.z;
            v36 = -72;
            v16 = ~(~(COERCE_INT((float)(*(float *)&v4 - (float)(v13 * v12)) * 255.0) - 1) & 0x80000000)
                & COERCE_UNSIGNED_INT((float)(*(float *)&v4 - (float)(v13 * v12)) * 255.0);
            v32 = 0;
            v17 = 158 - (unsigned __int8)(v16 >> 23);
            v18 = (v16 | 0xFF800000) << 8 >> v17;
            color = (vostok::math::color)(v17 - 96);
            v31 = v16 >> 31;
            *(_QWORD *)&origin.x = v15;
            v19 = -((v16 & (((1 << (v17 - 96)) - 1) >> 8)) != 0);
            v29 = v16 >> 31;
            v27 = v17 - 96;
            *(_DWORD *)indices_end = v18;
            v20 = *(_QWORD *)&(*it_instance)->m_transform.lines[3].x;
            vertices[0].position.z = (*it_instance)->m_transform.c.z;
            *(_QWORD *)&vertices[0].position.x = v20;
            vertices[0].color.m_value = (unsigned __int8)((v16 >> 31)
                                                        ^ ((v17 - 96 + 64) >> 31)
                                                        & (v18
                                                         - ((v16 >> 31) & ((v16 & (((1 << (v17 - 96)) - 1) >> 8)) == 0))))
                                      | (unsigned int)&vostok::memory::s_CRT_arena[5508664]
                                      & ((v31 << 16)
                                       ^ ((v17 - 96 + 64) >> 31 << 16)
                                       & ((v18 - (v31 & (v19 + 1))) << 16))
                                      | ((unsigned __int16)((_WORD)v29 << 8)
                                       ^ (unsigned __int16)(((unsigned __int16)((v17 - 96 + 64) >> 31) << 8)
                                                          & (((_WORD)v18
                                                            - ((unsigned __int16)v29 & (unsigned __int16)(v19 + 1))) << 8)))
                                      & 0xFF00
                                      | 0xFF000000;
            v21 = (double)((unsigned __int64)(134775813 * r.m_seed + 1) >> 12) * 0.00000095367432 * 2.0 - 1.0;
            fnum_instancesb = (unsigned __int64)(134775813 * (134775813 * r.m_seed + 1) + 1) >> 12;
            r.m_seed = 134775813 * (134775813 * r.m_seed + 1) + 1;
            vertices[1].color.m_value = vertices[0].color.m_value;
            indices[0] = 0;
            indices[1] = 1;
            *((float *)&v46 + 1) = *((float *)&v15 + 1) + 1.2;
            *(float *)&v46 = 2.0 * (0.00000095367432 * (double)fnum_instancesb) - 1.0 + *(float *)&v15;
            *(_QWORD *)&vertices[1].position.x = v46;
            v47 = v21 + origin.z;
            vertices[1].position.z = v47;
            vostok::render::system_renderer::draw_lines(
              (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
              vertices,
              (const vostok::render::vertex_colored *const)&v49,
              indices,
              indices_end,
              0);
            v4 = clear_value;
            v12 = finstance_index + *(float *)&clear_value;
            finstance_index = finstance_index + *(float *)&clear_value;
            if ( ++it_instance == end_instance )
              break;
            v13 = v43;
            v10 = it_instance;
          }
        }
        v3 = fpatch_index + *(float *)&v4;
        fpatch_index = fpatch_index + *(float *)&v4;
        if ( ++it == end )
          break;
        v5 = v44;
        M_start = it;
      }
    }
  }
}
