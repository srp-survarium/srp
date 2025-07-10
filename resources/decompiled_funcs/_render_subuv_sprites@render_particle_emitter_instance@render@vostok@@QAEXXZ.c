// local variable allocation has failed, the output may be wrong!
void __thiscall vostok::render::render_particle_emitter_instance::render_subuv_sprites(
        vostok::render::render_particle_emitter_instance *this,
        vostok::render::render_particle_emitter_instance *thisa)
{
  vostok::particle::base_particle *m_first; // ecx
  int v3; // eax
  unsigned __int16 *v4; // ebx
  void *v5; // esi
  _DWORD *v6; // eax
  vostok::particle::base_particle *v7; // edi
  unsigned __int16 v8; // cx
  _DWORD *v9; // edx
  bool v10; // zf
  __m128 subimage_index_low; // xmm6
  float v12; // xmm0_4
  const vostok::math::float4x4 *v13; // xmm2_4
  const vostok::math::float4x4 *v14; // xmm3_4
  unsigned int v15; // ecx
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm5
  float v19; // xmm0_4
  float duration; // xmm0_4
  int v21; // ebx
  int v22; // ecx
  unsigned int v23; // edx
  BOOL v24; // eax
  unsigned int v25; // edx
  int v26; // edx
  int v27; // edx
  _WORD *v28; // ebx
  float *v29; // ecx
  float y; // xmm4_4
  float x; // xmm5_4
  double gravity; // st7
  vostok::render::subuv_particle_sprite_vertex *z_low; // ecx
  float z; // edx
  int v35; // esi
  double v36; // st7
  vostok::render::subuv_particle_sprite_vertex *v37; // ecx
  float v38; // edx
  _DWORD *v39; // eax
  vostok::render::index_buffer *m_variable; // eax
  const char *m_conflicted_key_name; // edi
  unsigned int v42; // ebx
  const char *v43; // esi
  bool v44; // al
  vostok::render::statistics *v45; // ecx
  vostok::math::float3 v46; // [esp-Ch] [ebp-138h]
  vostok::math::float3 v47; // [esp-Ch] [ebp-138h]
  vostok::math::float4 in_color; // [esp+0h] [ebp-12Ch]
  vostok::math::float4 in_colora; // [esp+0h] [ebp-12Ch]
  vostok::math::float4 in_colorb; // [esp+0h] [ebp-12Ch]
  vostok::math::float4 in_colorc; // [esp+0h] [ebp-12Ch]
  vostok::render::subuv_particle_sprite_vertex *v52; // [esp+10h] [ebp-11Ch]
  vostok::render::subuv_particle_sprite_vertex *v53; // [esp+10h] [ebp-11Ch]
  vostok::render::subuv_particle_sprite_vertex *v54; // [esp+10h] [ebp-11Ch]
  vostok::render::subuv_particle_sprite_vertex *v55; // [esp+10h] [ebp-11Ch]
  __int64 v56; // [esp+14h] [ebp-118h] OVERLAPPED
  __int64 v57; // [esp+14h] [ebp-118h] OVERLAPPED
  __int64 v58; // [esp+14h] [ebp-118h] OVERLAPPED
  __int64 v59; // [esp+14h] [ebp-118h] OVERLAPPED
  float v60; // [esp+1Ch] [ebp-110h]
  float v61; // [esp+1Ch] [ebp-110h]
  float v62; // [esp+1Ch] [ebp-110h]
  float v63; // [esp+1Ch] [ebp-110h]
  vostok::math::float3 v64; // [esp+28h] [ebp-104h]
  vostok::math::float3 v65; // [esp+28h] [ebp-104h]
  vostok::math::float3 v66; // [esp+28h] [ebp-104h]
  vostok::math::float3 v67; // [esp+28h] [ebp-104h]
  vostok::math::float2 v68; // [esp+34h] [ebp-F8h]
  vostok::math::float2 v69; // [esp+34h] [ebp-F8h]
  vostok::math::float4 v70; // [esp+3Ch] [ebp-F0h]
  vostok::math::float4 v71; // [esp+3Ch] [ebp-F0h]
  float next_posV; // [esp+58h] [ebp-D4h]
  float f_time; // [esp+5Ch] [ebp-D0h]
  float sizeU; // [esp+64h] [ebp-C8h]
  float posU; // [esp+68h] [ebp-C4h]
  unsigned __int16 i; // [esp+6Ch] [ebp-C0h]
  float sizeV; // [esp+70h] [ebp-BCh]
  int v78; // [esp+74h] [ebp-B8h]
  float lifetime; // [esp+74h] [ebp-B8h]
  float u_offset; // [esp+7Ch] [ebp-B0h]
  float posV; // [esp+84h] [ebp-A8h]
  float next_posU; // [esp+88h] [ebp-A4h]
  unsigned int v83; // [esp+8Ch] [ebp-A0h]
  __int64 final_color; // [esp+90h] [ebp-9Ch]
  float final_color_8; // [esp+98h] [ebp-94h]
  float final_color_12; // [esp+9Ch] [ebp-90h]
  unsigned __int16 *pib; // [esp+A0h] [ebp-8Ch]
  unsigned int i_offset; // [esp+A4h] [ebp-88h] BYREF
  unsigned int v_offset; // [esp+A8h] [ebp-84h] BYREF
  vostok::math::float2 size; // [esp+ACh] [ebp-80h]
  float v91; // [esp+B4h] [ebp-78h]
  float v92; // [esp+B8h] [ebp-74h]
  float next_subimage_index; // [esp+BCh] [ebp-70h]
  float v94; // [esp+C0h] [ebp-6Ch]
  float v95; // [esp+C4h] [ebp-68h]
  float v96; // [esp+C8h] [ebp-64h]
  float v97; // [esp+CCh] [ebp-60h]
  float subimage_index; // [esp+D0h] [ebp-5Ch]
  float v99; // [esp+D4h] [ebp-58h]
  int v100; // [esp+D8h] [ebp-54h]
  int v101; // [esp+DCh] [ebp-50h]
  float v102; // [esp+E0h] [ebp-4Ch]
  float v103; // [esp+E4h] [ebp-48h]
  float v104; // [esp+E8h] [ebp-44h]
  vostok::math::float4 v105; // [esp+ECh] [ebp-40h]
  vostok::math::float4 v106; // [esp+FCh] [ebp-30h]
  unsigned __int64 v107; // [esp+10Ch] [ebp-20h]
  __int64 v108; // [esp+114h] [ebp-18h]
  unsigned __int64 v109; // [esp+11Ch] [ebp-10h]
  __int64 v110; // [esp+124h] [ebp-8h]

  m_first = thisa->m_particle_list->m_first;
  v3 = 0;
  if ( m_first )
  {
    do
    {
      m_first = m_first->next;
      ++v3;
    }
    while ( m_first );
    v78 = v3;
    if ( v3 )
    {
      i_offset = 0;
      v_offset = 0;
      v83 = 6 * v3;
      v4 = vostok::render::index_buffer::lock(thisa->m_indices.m_variable, 6 * v3, &i_offset);
      pib = v4;
      v5 = vostok::render::vertex_buffer::lock(thisa->m_vertices.m_variable, 4 * v78, 0x58u, &v_offset);
      v6 = &thisa->__vftable;
      v7 = thisa->m_particle_list->m_first;
      if ( v7 )
      {
        v8 = 0;
        v105.w = 0.0;
        HIDWORD(v108) = 0;
        v106.w = 0.0;
        HIDWORD(v110) = 0;
        for ( i = 0; ; v8 = i )
        {
          v9 = (_DWORD *)v6[277];
          v10 = v9[3] == 0;
          subimage_index_low = (__m128)LODWORD(v7->subimage_index);
          v12 = v7->next_subimage_index;
          v13 = clear_value;
          v14 = clear_value;
          subimage_index = v7->subimage_index;
          next_subimage_index = v12;
          posU = 0.0;
          posV = 0.0;
          next_posU = 0.0;
          next_posV = 0.0;
          sizeU = *(float *)&clear_value;
          sizeV = *(float *)&clear_value;
          if ( !v10 )
          {
            v15 = v9[3];
            posU = (float)((unsigned int)(__int64)subimage_index % v15);
            posV = (float)((unsigned int)(__int64)subimage_index / v15);
            next_posU = (float)((unsigned int)(__int64)next_subimage_index % v15);
            next_posV = (float)((unsigned int)(__int64)next_subimage_index / v15);
            sizeU = 1.0 / (double)v15;
            *(float *)&v13 = sizeU;
            v6 = &thisa->__vftable;
            v8 = i;
            sizeV = 1.0 / (double)(unsigned int)v9[4];
            *(float *)&v14 = sizeV;
          }
          v16.m128_i32[0] = subimage_index_low.m128_i32[0] & 0x80000000;
          v17 = subimage_index_low;
          v17.m128_f32[0] = (float)(subimage_index_low.m128_f32[0] + COERCE_FLOAT(v16.m128_i32[0] | 0x4B000000))
                          - COERCE_FLOAT(v16.m128_i32[0] | 0x4B000000);
          v18 = v17;
          v101 = subimage_index_low.m128_i32[0];
          v18.m128_f32[0] = v17.m128_f32[0] - subimage_index_low.m128_f32[0];
          v100 = subimage_index_low.m128_i32[0] & 0x7FFFFFFF;
          v91 = v17.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v18, v16).m128_u32[0] & (unsigned int)clear_value);
          v19 = COERCE_FLOAT(subimage_index_low.m128_i32[0] & 0x7FFFFFFF) - fabs(v91);
          u_offset = v19;
          if ( v9[1] == 3 )
          {
            duration = v7->duration;
            if ( duration <= 0.001 )
              lifetime = v7->lifetime;
            else
              lifetime = v7->lifetime / duration;
            f_time = (double)(unsigned int)v9[5] * lifetime;
            v95 = f_time;
            v21 = ~(~(LODWORD(v95) - 1) & 0x80000000) & LODWORD(v95);
            v22 = 158 - (unsigned __int8)(v21 >> 23);
            v23 = (v21 | 0xFF800000) << 8 >> v22;
            v22 -= 96;
            v24 = (v21 & (((1 << v22) - 1) >> 8)) == 0;
            v21 >>= 31;
            v25 = v23 - (v21 & v24);
            v6 = &thisa->__vftable;
            v26 = ((v22 + 64) >> 31) & v25;
            v8 = i;
            v27 = v21 ^ v26;
            v4 = pib;
            v19 = f_time - (float)v27;
            u_offset = v19;
          }
          *v4 = v8;
          v28 = v4 + 1;
          *v28++ = v8 + 3;
          *v28 = v8 + 2;
          v28[1] = v8;
          ++v28;
          v28[1] = v8 + 2;
          v28 += 2;
          *v28 = v8 + 1;
          v29 = (float *)v6[279];
          v4 = v28 + 1;
          v10 = v6[282] == 0;
          *(float *)&final_color = *v29 * v7->color.x;
          y = v7->size.y;
          *((float *)&final_color + 1) = v29[1] * v7->color.y;
          x = v7->size.x;
          pib = v4;
          final_color_8 = v29[2] * v7->color.z;
          final_color_12 = v29[3] * v7->color.w;
          size.y = y;
          if ( v10 )
          {
            y = x;
            size.y = x;
          }
          v105.x = v19;
          v104 = *(float *)&v13 * next_posU;
          v105.y = *(float *)&v13 * next_posU;
          v92 = *(float *)&v14 * next_posV;
          v105.z = *(float *)&v14 * next_posV;
          *(_QWORD *)&v64.elements[1] = __PAIR64__(LODWORD(y), LODWORD(x));
          v97 = *(float *)&v13 * posU;
          v64.x = *(float *)&v14 * posV;
          gravity = v7->gravity;
          z_low = (vostok::render::subuv_particle_sprite_vertex *)LODWORD(v7->render_old_position.z);
          z = v7->render_position.z;
          v96 = *(float *)&v14 * posV;
          v56 = final_color;
          v60 = final_color_8;
          *(_QWORD *)&in_color.elements[2] = *(_QWORD *)&v7->render_old_position.x;
          v52 = z_low;
          in_color.y = gravity;
          in_color.x = v7->rotation;
          *(_QWORD *)&v46.x = *(_QWORD *)&v7->render_position.x;
          v46.z = z;
          vostok::render::subuv_particle_sprite_vertex::set(
            z_low,
            (int)v5,
            v46,
            in_color,
            *(vostok::math::float2 *)((char *)&v56 - 4),
            *(vostok::math::float2 *)((char *)&v56 + 4),
            final_color_12,
            COERCE_UNSIGNED_INT(*(float *)&v13 * posU),
            v64,
            0,
            v105);
          v107 = __PAIR64__(LODWORD(v104), LODWORD(u_offset));
          v103 = (float)(next_posV + *(float *)&clear_value) * sizeV;
          *(float *)&v108 = v103;
          *(_QWORD *)&v70.x = __PAIR64__(LODWORD(v104), LODWORD(u_offset));
          *(_QWORD *)&v70.elements[2] = v108;
          v35 = (int)v5 + 88;
          v68.x = 0.0;
          LODWORD(v68.y) = clear_value;
          *(_QWORD *)&v65.elements[1] = __PAIR64__(LODWORD(size.y), LODWORD(x));
          v65.x = (float)(posV + *(float *)&clear_value) * sizeV;
          v36 = v7->gravity;
          v37 = (vostok::render::subuv_particle_sprite_vertex *)LODWORD(v7->render_old_position.z);
          v38 = v7->render_position.z;
          v99 = v65.x;
          v57 = final_color;
          v61 = final_color_8;
          *(_QWORD *)&in_colora.elements[2] = *(_QWORD *)&v7->render_old_position.x;
          v53 = v37;
          in_colora.y = v36;
          in_colora.x = v7->rotation;
          *(_QWORD *)&v47.x = *(_QWORD *)&v7->render_position.x;
          v47.z = v38;
          vostok::render::subuv_particle_sprite_vertex::set(
            v37,
            v35,
            v47,
            in_colora,
            *(vostok::math::float2 *)((char *)&v57 - 4),
            *(vostok::math::float2 *)((char *)&v57 + 4),
            final_color_12,
            LODWORD(v97),
            v65,
            v68,
            v70);
          v106.x = u_offset;
          v102 = (float)(next_posU + *(float *)&clear_value) * sizeU;
          v106.y = v102;
          v106.z = v103;
          LODWORD(v69.x) = clear_value;
          LODWORD(v69.y) = clear_value;
          *(_QWORD *)&v66.elements[1] = __PAIR64__(LODWORD(size.y), LODWORD(x));
          v94 = (float)(posU + *(float *)&clear_value) * sizeU;
          v66.x = v99;
          v58 = final_color;
          v35 += 88;
          v62 = final_color_8;
          *(_QWORD *)&in_colorb.elements[2] = *(_QWORD *)&v7->render_old_position.x;
          v54 = (vostok::render::subuv_particle_sprite_vertex *)LODWORD(v7->render_old_position.z);
          in_colorb.y = v7->gravity;
          in_colorb.x = v7->rotation;
          vostok::render::subuv_particle_sprite_vertex::set(
            v54,
            v35,
            v7->render_position,
            in_colorb,
            *(vostok::math::float2 *)((char *)&v58 - 4),
            *(vostok::math::float2 *)((char *)&v58 + 4),
            final_color_12,
            LODWORD(v94),
            v66,
            v69,
            v106);
          v109 = __PAIR64__(LODWORD(v102), LODWORD(u_offset));
          *(float *)&v110 = v92;
          *(_QWORD *)&v71.x = __PAIR64__(LODWORD(v102), LODWORD(u_offset));
          *(_QWORD *)&v71.elements[2] = v110;
          *(_QWORD *)&v67.elements[1] = __PAIR64__(LODWORD(size.y), LODWORD(x));
          v67.x = v96;
          v59 = final_color;
          v63 = final_color_8;
          *(_QWORD *)&in_colorc.elements[2] = *(_QWORD *)&v7->render_old_position.x;
          v55 = (vostok::render::subuv_particle_sprite_vertex *)LODWORD(v7->render_old_position.z);
          in_colorc.y = v7->gravity;
          v35 += 88;
          in_colorc.x = v7->rotation;
          vostok::render::subuv_particle_sprite_vertex::set(
            v55,
            v35,
            v7->render_position,
            in_colorc,
            *(vostok::math::float2 *)((char *)&v59 - 4),
            *(vostok::math::float2 *)((char *)&v59 + 4),
            final_color_12,
            LODWORD(v94),
            v67,
            (vostok::math::float2)(unsigned int)clear_value,
            v71);
          v7 = v7->next;
          i += 4;
          v6 = &thisa->__vftable;
          v5 = (void *)(v35 + 88);
          if ( !v7 )
            break;
        }
      }
      v39 = (_DWORD *)v6[262];
      v39[2] += v39[4] * v39[5];
      (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                 + 60))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        *(_DWORD *)(*v39 + 4),
        0);
      m_variable = thisa->m_indices.m_variable;
      m_variable->m_position += m_variable->m_lock_size;
      (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                         + 60))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        m_variable->m_buffer.m_object->m_hardware_buffer,
        0);
      vostok::render::res_geometry::apply(thisa->m_subuv_particle_sprite_geometry.m_object);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v42 = v83;
      v43 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v44 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v44;
      if ( v44 )
        *((_DWORD *)m_conflicted_key_name + 529) = 4;
      vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
      if ( v43[104] )
      {
        ++*((_DWORD *)v43 + 25);
        v42 = (3 * s_max_triagles_per_dip_value < v83 ? 3 * s_max_triagles_per_dip_value - v83 : 0) + v83;
      }
      if ( !v43[37] )
        (*(void (__stdcall **)(int, unsigned int, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                             + 48))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v42,
          i_offset,
          v_offset);
      v45 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
      *((_DWORD *)v43 + 21) += v42 / 3;
      v45->visibility_stat_group.num_triangles.value += v83 / 3;
    }
  }
}
