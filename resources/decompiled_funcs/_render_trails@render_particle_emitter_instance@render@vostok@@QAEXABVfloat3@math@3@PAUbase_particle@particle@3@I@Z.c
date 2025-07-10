void __thiscall vostok::render::render_particle_emitter_instance::render_trails(
        vostok::render::render_particle_emitter_instance *this,
        vostok::render::render_particle_emitter_instance *view_location,
        const vostok::math::float3 *start_particle,
        vostok::particle::base_particle *num_particles,
        unsigned int num_particlesa)
{
  float v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // eax
  int v8; // ebp
  float v9; // esi
  unsigned __int16 *v10; // ebx
  float v11; // esi
  char *v12; // eax
  unsigned int v13; // esi
  float v14; // xmm4_4
  float v15; // xmm3_4
  unsigned int v16; // ecx
  char *v17; // ebp
  unsigned int v18; // eax
  float v19; // xmm5_4
  unsigned int v20; // edi
  int v21; // ecx
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  float *v33; // ecx
  float v34; // xmm1_4
  float v35; // xmm0_4
  unsigned int v36; // edi
  const vostok::math::float4x4 *v37; // xmm3_4
  vostok::particle::base_particle *v38; // ebx
  float v39; // xmm4_4
  vostok::particle::base_particle *next; // eax
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  const vostok::math::float4 *m_instance_color; // eax
  const vostok::math::float3 *v45; // eax
  float v46; // xmm0_4
  float v47; // xmm1_4
  float y; // xmm4_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  float v51; // xmm6_4
  float v52; // xmm4_4
  float z; // xmm5_4
  float v54; // xmm3_4
  float v55; // xmm3_4
  char *v56; // ebp
  float v57; // xmm6_4
  float v58; // xmm4_4
  float v59; // xmm5_4
  float w; // xmm3_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  vostok::particle::base_particle *v63; // eax
  float v64; // xmm4_4
  float v65; // xmm3_4
  float v66; // xmm7_4
  float v67; // xmm5_4
  float v68; // xmm6_4
  float x; // xmm5_4
  float v70; // xmm6_4
  float *v71; // ebp
  float v72; // xmm3_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  float v75; // xmm3_4
  float v76; // xmm0_4
  float v77; // xmm1_4
  float v78; // xmm0_4
  float v79; // xmm0_4
  bool v80; // zf
  __int16 v81; // bp
  unsigned int i; // ecx
  unsigned __int16 v83; // ax
  unsigned __int16 *v84; // ebx
  float v85; // eax
  float v86; // eax
  int v87; // esi
  const char *m_conflicted_key_name; // edi
  unsigned int v89; // esi
  unsigned int v90; // ebp
  bool v91; // al
  const char *v92; // ebx
  vostok::render::statistics *v93; // ecx
  const unsigned int *p_num_texture_tiles; // [esp-Ch] [ebp-174h]
  float current_angle; // [esp+18h] [ebp-150h]
  unsigned int i_offset; // [esp+1Ch] [ebp-14Ch] BYREF
  float scaleUV; // [esp+20h] [ebp-148h]
  float current_uv_start; // [esp+24h] [ebp-144h]
  unsigned int s; // [esp+28h] [ebp-140h]
  int v100; // [esp+2Ch] [ebp-13Ch]
  unsigned int p; // [esp+30h] [ebp-138h]
  unsigned int num_quads; // [esp+34h] [ebp-134h]
  vostok::math::float4 final_color; // [esp+38h] [ebp-130h]
  float v104; // [esp+48h] [ebp-120h]
  vostok::math::float3 particle_dir; // [esp+4Ch] [ebp-11Ch] BYREF
  vostok::particle::base_particle *nextP; // [esp+58h] [ebp-110h]
  vostok::particle::base_particle *prevP; // [esp+5Ch] [ebp-10Ch]
  float current_v_pos; // [esp+60h] [ebp-108h]
  float angle_incrase; // [esp+64h] [ebp-104h]
  unsigned int v_offset; // [esp+68h] [ebp-100h] BYREF
  unsigned __int16 *pib; // [esp+6Ch] [ebp-FCh]
  vostok::math::float3 right_a; // [esp+70h] [ebp-F8h] BYREF
  float distance_from_first_to_last; // [esp+7Ch] [ebp-ECh]
  unsigned int texture_tiles; // [esp+80h] [ebp-E8h]
  float v115; // [esp+84h] [ebp-E4h]
  unsigned __int64 v116; // [esp+88h] [ebp-E0h]
  float v117; // [esp+90h] [ebp-D8h]
  vostok::math::float3_pod v118; // [esp+94h] [ebp-D4h] BYREF
  vostok::math::float3 view_dir; // [esp+A0h] [ebp-C8h] BYREF
  vostok::math::float3_pod v120; // [esp+ACh] [ebp-BCh] BYREF
  vostok::math::float3_pod v121; // [esp+B8h] [ebp-B0h] BYREF
  vostok::math::float3_pod v122; // [esp+C4h] [ebp-A4h] BYREF
  vostok::math::float3_pod v123; // [esp+D0h] [ebp-98h] BYREF
  vostok::math::float3 prev_particle_dir; // [esp+DCh] [ebp-8Ch]
  vostok::math::float3_pod object; // [esp+E8h] [ebp-80h] BYREF
  vostok::math::float3_pod result_in_case_of_zero; // [esp+F4h] [ebp-74h] BYREF
  vostok::math::float3_pod v127; // [esp+100h] [ebp-68h] BYREF
  float v128; // [esp+110h] [ebp-58h]
  vostok::math::float4x4 rot_matrix; // [esp+114h] [ebp-54h]
  vostok::math::float3 v130; // [esp+158h] [ebp-10h] BYREF

  v5 = *(float *)&view_location->m_beamtrail_parameters;
  if ( v5 != 0.0 && num_particlesa )
  {
    scaleUV = 0.0;
    i_offset = 1;
    v6 = vostok::math::max<unsigned int>((const unsigned int *)LODWORD(v5), &i_offset);
    p_num_texture_tiles = &view_location->m_beamtrail_parameters->num_texture_tiles;
    s = v6;
    i_offset = 1;
    v7 = vostok::math::max<unsigned int>(p_num_texture_tiles, &i_offset);
    v8 = num_particlesa * v6;
    v9 = *(float *)&view_location->m_indices.m_variable;
    texture_tiles = v7;
    num_quads = num_particlesa - 1;
    i_offset = 0;
    v_offset = 0;
    v10 = vostok::render::index_buffer::lock((vostok::render::index_buffer *)LODWORD(v9), 6 * v8, &i_offset);
    v11 = *(float *)&view_location->m_vertices.m_variable;
    pib = v10;
    v12 = (char *)vostok::render::vertex_buffer::lock(
                    (vostok::render::vertex_buffer *)LODWORD(v11),
                    2 * v8,
                    0x24u,
                    &v_offset);
    v13 = num_quads;
    v14 = 0.0;
    v15 = scaleUV;
    v16 = 0;
    v17 = v12;
    v18 = (unsigned int)num_particles;
    v19 = 0.0;
    if ( (int)num_quads >= 2 )
    {
      v20 = ((num_quads - 2) >> 1) + 1;
      p = 2 * v20;
      do
      {
        --v20;
        v21 = *(_DWORD *)(v18 + 128);
        v22 = *(float *)(v21 + 44) - *(float *)(v18 + 44);
        v23 = *(float *)(v21 + 52) - *(float *)(v18 + 52);
        v24 = *(float *)(v21 + 48) - *(float *)(v18 + 48);
        v18 = *(_DWORD *)(v21 + 128);
        v25 = v22 * v22;
        v26 = v23 * v23;
        v27 = *(float *)(v18 + 52) - *(float *)(v21 + 52);
        v28 = v25 + v26;
        v29 = v24 * v24;
        v30 = *(float *)(v18 + 48) - *(float *)(v21 + 48);
        v31 = v28 + v29;
        v32 = *(float *)(v18 + 44) - *(float *)(v21 + 44);
        v15 = v31 + v15;
        v14 = (float)((float)((float)(v32 * v32) + (float)(v27 * v27)) + (float)(v30 * v30)) + v14;
      }
      while ( v20 );
      v16 = p;
    }
    if ( v16 < num_quads )
    {
      v33 = *(float **)(v18 + 128);
      v34 = v33[13] - *(float *)(v18 + 52);
      v35 = v33[12] - *(float *)(v18 + 48);
      v19 = (float)((float)((float)(v33[11] - *(float *)(v18 + 44)) * (float)(v33[11] - *(float *)(v18 + 44)))
                  + (float)(v34 * v34))
          + (float)(v35 * v35);
    }
    v36 = s;
    distance_from_first_to_last = (float)(v15 + v14) + v19;
    current_angle = 0.0;
    angle_incrase = 3.1415927 / (double)s;
    if ( s )
    {
      v37 = clear_value;
      p = s;
      do
      {
        v38 = num_particles;
        current_uv_start = 0.0;
        prevP = 0;
        v100 = 0;
        if ( num_quads )
        {
          v39 = *(float *)&v37 / distance_from_first_to_last;
          v115 = *(float *)&v37 / distance_from_first_to_last;
          *(_QWORD *)&result_in_case_of_zero.x = 0;
          LODWORD(result_in_case_of_zero.z) = v37;
          *(_QWORD *)&v121.x = 0;
          LODWORD(v121.z) = v37;
          *(_QWORD *)&v120.x = 0;
          LODWORD(v120.z) = v37;
          v104 = (float)texture_tiles;
          while ( 1 )
          {
            next = v38->next;
            v41 = next->position.z - v38->position.z;
            v42 = next->position.x - v38->position.x;
            v43 = next->position.y - v38->position.y;
            scaleUV = (float)((float)((float)(v42 * v42) + (float)(v41 * v41)) + (float)(v43 * v43)) * v39;
            nextP = next;
            object.x = start_particle->x - v38->position.x;
            object.y = start_particle->y - v38->position.y;
            object.z = start_particle->z - v38->position.z;
            vostok::math::normalize_safe(&object, &view_dir, (vostok::math::float3 *)&result_in_case_of_zero);
            v118.x = nextP->position.x - v38->position.x;
            v118.y = nextP->position.y - v38->position.y;
            v118.z = nextP->position.z - v38->position.z;
            vostok::math::normalize_safe(&v118, &particle_dir, (vostok::math::float3 *)&v121);
            if ( v100 )
            {
              *(_QWORD *)&v123.x = 0;
              LODWORD(v123.z) = clear_value;
              v127.x = nextP->position.x - prevP->position.x;
              v127.y = nextP->position.y - prevP->position.y;
              v127.z = nextP->position.z - prevP->position.z;
              particle_dir = *vostok::math::normalize_safe(&v127, &v130, (vostok::math::float3 *)&v123);
            }
            m_instance_color = view_location->m_instance_color;
            final_color.x = m_instance_color->x * v38->color.x;
            final_color.y = m_instance_color->y * v38->color.y;
            final_color.z = m_instance_color->z * v38->color.z;
            final_color.w = m_instance_color->w * v38->color.w;
            current_v_pos = v104 * current_uv_start;
            v122.x = (float)(particle_dir.z * view_dir.y) - (float)(particle_dir.y * view_dir.z);
            v122.y = (float)(view_dir.z * particle_dir.x) - (float)(particle_dir.z * view_dir.x);
            v122.z = (float)(particle_dir.y * view_dir.x) - (float)(view_dir.y * particle_dir.x);
            vostok::math::normalize_safe(&v122, &right_a, (vostok::math::float3 *)&v120);
            if ( num_particlesa != 2 && v100 == num_particlesa - 2 )
              particle_dir = prev_particle_dir;
            v45 = vostok::math::float3_pod::normalize_safe(&particle_dir, &particle_dir);
            vostok::math::create_rotation(v45, current_angle);
            v46 = (float)((float)((float)(rot_matrix.k.x * right_a.z) + (float)(rot_matrix.j.x * right_a.y))
                        + (float)(rot_matrix.i.x * right_a.x))
                + rot_matrix.c.x;
            v47 = (float)((float)((float)(rot_matrix.i.y * right_a.x) + (float)(rot_matrix.k.y * right_a.z))
                        + (float)(rot_matrix.j.y * right_a.y))
                + rot_matrix.c.y;
            y = v38->size.y;
            v49 = (float)((float)((float)(rot_matrix.i.z * right_a.x) + (float)(rot_matrix.k.z * right_a.z))
                        + (float)(rot_matrix.j.z * right_a.y))
                + rot_matrix.c.z;
            v116 = __PAIR64__(LODWORD(v47), LODWORD(v46));
            *(_QWORD *)&right_a.x = __PAIR64__(LODWORD(v47), LODWORD(v46));
            v50 = (float)(v46 * y) + v38->position.x;
            v51 = v49 * y;
            v52 = v38->position.y + (float)(v47 * y);
            z = v38->position.z;
            *(float *)v17 = v50;
            *(vostok::math::float4 *)(v17 + 12) = final_color;
            v54 = current_v_pos;
            *((float *)v17 + 1) = v52;
            *((float *)v17 + 2) = z + v51;
            v117 = v49;
            *((_DWORD *)v17 + 7) = 0;
            *((float *)v17 + 8) = v54;
            v55 = v38->size.y;
            right_a.z = v49;
            v56 = v17 + 36;
            v57 = v49 * v55;
            v58 = v38->position.y - (float)(v47 * v55);
            v59 = v38->position.z;
            *(float *)v56 = v38->position.x - (float)(v46 * v55);
            *(_QWORD *)(v56 + 12) = *(_QWORD *)&final_color.x;
            *((_DWORD *)v56 + 5) = LODWORD(final_color.z);
            w = final_color.w;
            *((float *)v56 + 1) = v58;
            v61 = current_v_pos;
            *((float *)v56 + 6) = w;
            v37 = clear_value;
            *((float *)v56 + 2) = v59 - v57;
            *((float *)v56 + 7) = *(float *)&v37;
            *((float *)v56 + 8) = v61;
            v17 = v56 + 36;
            if ( num_particlesa == 2 || v100 == num_particlesa - 2 )
            {
              v62 = v38->size.y;
              v63 = nextP;
              v64 = v104 * (float)(scaleUV + current_uv_start);
              current_uv_start = scaleUV + current_uv_start;
              v65 = (float)(v46 * v62) + nextP->position.x;
              v66 = v49 * v62;
              v67 = nextP->position.y + (float)(v47 * v62);
              v68 = nextP->position.z;
              *(float *)v17 = v65;
              *(_QWORD *)(v17 + 20) = *(_QWORD *)&final_color.elements[2];
              *((float *)v17 + 1) = v67;
              x = final_color.x;
              *((_DWORD *)v17 + 3) = LODWORD(final_color.x);
              *((float *)v17 + 2) = v68 + v66;
              v70 = final_color.y;
              *((_DWORD *)v17 + 4) = LODWORD(final_color.y);
              *((_DWORD *)v17 + 7) = 0;
              v71 = (float *)(v17 + 36);
              *(v71 - 1) = v64;
              v72 = v38->size.y;
              v73 = v47 * v72;
              v74 = v49 * v72;
              v75 = v63->position.x - (float)(v46 * v72);
              v76 = v63->position.y - v73;
              v77 = v63->position.z;
              v71[1] = v76;
              v78 = final_color.z;
              *v71 = v75;
              v37 = clear_value;
              v71[5] = v78;
              v79 = final_color.w;
              v71[2] = v77 - v74;
              v71[3] = x;
              v71[4] = v70;
              v71[6] = v79;
              v71[7] = *(float *)&v37;
              v71[8] = v64;
              v128 = v64;
              v17 = (char *)(v71 + 9);
            }
            current_uv_start = scaleUV + current_uv_start;
            prevP = v38;
            v38 = v38->next;
            prev_particle_dir = particle_dir;
            if ( ++v100 >= num_quads )
              break;
            v39 = v115;
          }
        }
        v80 = p-- == 1;
        current_angle = angle_incrase + current_angle;
      }
      while ( !v80 );
      v10 = pib;
      v36 = s;
      v13 = num_quads;
    }
    v81 = 0;
    for ( s = 0; (unsigned __int16)s < v36; ++s )
    {
      for ( i = 0; i < v13; v10 = v84 + 1 )
      {
        v83 = 2 * (i + v81);
        *v10 = v83;
        v84 = v10 + 1;
        *v84++ = v83 + 1;
        *v84++ = v83 + 3;
        *v84++ = v83;
        *v84++ = v83 + 3;
        *v84 = v83 + 2;
        ++i;
      }
      v81 += num_particlesa;
    }
    v85 = *(float *)&view_location->m_vertices.m_variable;
    *(_DWORD *)(LODWORD(v85) + 8) += *(_DWORD *)(LODWORD(v85) + 16) * *(_DWORD *)(LODWORD(v85) + 20);
    (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                               + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      *(_DWORD *)(*(_DWORD *)LODWORD(v85) + 4),
      0);
    v86 = *(float *)&view_location->m_indices.m_variable;
    *(_DWORD *)(LODWORD(v86) + 8) += *(_DWORD *)(LODWORD(v86) + 16);
    (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                               + 60))(
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
      *(_DWORD *)(*(_DWORD *)LODWORD(v86) + 4),
      0);
    vostok::render::res_geometry::apply(view_location->m_particle_beamtrail_geometry.m_object);
    v87 = v36 * v13;
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    v89 = 6 * v87;
    v90 = v89;
    v91 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
    v92 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v91;
    if ( v91 )
      *((_DWORD *)m_conflicted_key_name + 529) = 4;
    vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
    if ( v92[104] )
    {
      ++*((_DWORD *)v92 + 25);
      v90 = (3 * s_max_triagles_per_dip_value < v89 ? 3 * s_max_triagles_per_dip_value - v89 : 0) + v89;
    }
    if ( !v92[37] )
      (*(void (__stdcall **)(int, unsigned int, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                           + 48))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v90,
        i_offset,
        v_offset);
    v93 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
    *((_DWORD *)v92 + 21) += v90 / 3;
    v93->visibility_stat_group.num_triangles.value += v89 / 3;
  }
}
