void __thiscall vostok::render::render_particle_emitter_instance::render_sprites(
        vostok::render::render_particle_emitter_instance *this,
        vostok::render::render_particle_emitter_instance *thisa)
{
  vostok::render::render_particle_emitter_instance *v2; // ebp
  vostok::particle::base_particle *m_first; // eax
  int v4; // ecx
  vostok::render::index_buffer *m_variable; // esi
  unsigned __int16 *v6; // ebx
  char *v7; // eax
  vostok::particle::base_particle *v8; // ecx
  _DWORD *v9; // edi
  _DWORD *v10; // esi
  _QWORD *v11; // edx
  _WORD *v12; // ebx
  float x; // xmm1_4
  bool v14; // zf
  float *p_x; // ebx
  float y; // xmm0_4
  __int64 v17; // xmm4_8
  float z; // ebp
  float gravity; // xmm5_4
  float rotation; // xmm6_4
  __int64 v21; // xmm2_8
  __int64 v22; // xmm3_8
  float v23; // ebp
  __int64 v24; // xmm4_8
  float v25; // xmm5_4
  float v26; // xmm6_4
  char *v27; // eax
  _DWORD *v28; // edi
  __int64 v29; // xmm4_8
  float v30; // xmm5_4
  float v31; // xmm6_4
  __int64 v32; // xmm7_8
  const vostok::math::float4x4 **v33; // esi
  _QWORD *v34; // edx
  const vostok::math::float4x4 *v35; // ebp
  float v36; // ebp
  float v37; // ebp
  __int64 v38; // xmm5_8
  float v39; // xmm1_4
  __int64 v40; // xmm0_8
  float v41; // ebp
  vostok::render::vertex_buffer *v42; // eax
  vostok::render::index_buffer *v43; // eax
  const char *m_conflicted_key_name; // edi
  unsigned int v45; // ebp
  unsigned int v46; // ebx
  bool v47; // al
  const char *v48; // esi
  vostok::render::statistics *v49; // ecx
  unsigned __int16 *_v; // [esp+14h] [ebp-94h]
  int v51; // [esp+18h] [ebp-90h]
  float *v52; // [esp+18h] [ebp-90h]
  __int16 p; // [esp+1Ch] [ebp-8Ch]
  unsigned int v_offset; // [esp+20h] [ebp-88h] BYREF
  unsigned int i_offset; // [esp+24h] [ebp-84h] BYREF
  int v56; // [esp+28h] [ebp-80h]
  const vostok::math::float4x4 *v57; // [esp+2Ch] [ebp-7Ch]
  float v58; // [esp+30h] [ebp-78h]
  float v59; // [esp+34h] [ebp-74h]
  const vostok::math::float4x4 *v60; // [esp+38h] [ebp-70h]
  const vostok::math::float4x4 *v61; // [esp+3Ch] [ebp-6Ch]
  float v62; // [esp+40h] [ebp-68h]
  float v63; // [esp+44h] [ebp-64h]
  float v64; // [esp+48h] [ebp-60h]
  float v65; // [esp+4Ch] [ebp-5Ch]
  float v66; // [esp+50h] [ebp-58h]
  float v67; // [esp+54h] [ebp-54h]
  int v68; // [esp+5Ch] [ebp-4Ch]
  const vostok::math::float4x4 *v69; // [esp+60h] [ebp-48h]
  const vostok::math::float4x4 *v70; // [esp+64h] [ebp-44h]
  int v71; // [esp+68h] [ebp-40h]
  int v72; // [esp+6Ch] [ebp-3Ch]
  vostok::math::float4 final_color; // [esp+74h] [ebp-34h]
  float v74; // [esp+8Ch] [ebp-1Ch]
  float v75; // [esp+98h] [ebp-10h]
  float v76; // [esp+A4h] [ebp-4h]

  v2 = thisa;
  m_first = thisa->m_particle_list->m_first;
  v4 = 0;
  if ( m_first )
  {
    do
    {
      m_first = m_first->next;
      ++v4;
    }
    while ( m_first );
    v51 = v4;
    if ( v4 )
    {
      m_variable = thisa->m_indices.m_variable;
      i_offset = 0;
      v_offset = 0;
      v68 = 6 * v4;
      v6 = vostok::render::index_buffer::lock(m_variable, 6 * v4, &i_offset);
      v7 = (char *)vostok::render::vertex_buffer::lock(thisa->m_vertices.m_variable, 4 * v51, 0x40u, &v_offset);
      v8 = thisa->m_particle_list->m_first;
      p = 0;
      if ( v8 )
      {
        v52 = (float *)(v7 + 52);
        v71 = 0;
        v72 = 0;
        v56 = 0;
        v57 = clear_value;
        v69 = clear_value;
        v70 = clear_value;
        v60 = clear_value;
        v61 = 0;
        v9 = v7 + 36;
        v10 = v7 + 28;
        v11 = v7 + 12;
        while ( 1 )
        {
          *v6 = 4 * p;
          v6[1] = 4 * p + 3;
          v12 = v6 + 2;
          *v12 = 4 * p + 2;
          v12[1] = 4 * p;
          v12 += 2;
          *v12++ = 4 * p + 2;
          *v12 = 4 * p + 1;
          x = v8->size.x;
          v14 = thisa->m_screen_alignment == particle_screen_alignment_square;
          _v = v12 + 1;
          p_x = &thisa->m_instance_color->x;
          final_color.x = *p_x * v8->color.x;
          final_color.y = p_x[1] * v8->color.y;
          final_color.z = p_x[2] * v8->color.z;
          final_color.w = p_x[3] * v8->color.w;
          y = v8->size.y;
          if ( v14 )
            y = x;
          v17 = *(_QWORD *)&v8->render_old_position.x;
          z = v8->render_old_position.z;
          gravity = v8->gravity;
          rotation = v8->rotation;
          *(_QWORD *)v7 = *(_QWORD *)&v8->render_position.x;
          *((_DWORD *)v7 + 2) = LODWORD(v8->render_position.z);
          *v10 = v71;
          v10[1] = v72;
          v21 = *(_QWORD *)&final_color.x;
          v22 = *(_QWORD *)&final_color.elements[2];
          *v11 = *(_QWORD *)&final_color.x;
          v11[1] = v22;
          *((float *)v7 + 11) = rotation;
          *((float *)v7 + 12) = gravity;
          v62 = x;
          *(float *)v9 = x;
          v63 = y;
          *((float *)v9 + 1) = y;
          *(_QWORD *)v52 = v17;
          v52[2] = z;
          v23 = v8->render_old_position.z;
          v24 = *(_QWORD *)&v8->render_old_position.x;
          v25 = v8->gravity;
          v26 = v8->rotation;
          *((_QWORD *)v7 + 8) = *(_QWORD *)&v8->render_position.x;
          v74 = v23;
          *((_DWORD *)v7 + 18) = LODWORD(v8->render_position.z);
          v10[16] = v56;
          v10[17] = v57;
          v27 = v7 + 64;
          v11[8] = v21;
          *((_QWORD *)v52 + 8) = v24;
          v11[9] = v22;
          *((float *)v27 + 11) = v26;
          *((float *)v27 + 12) = v25;
          v28 = v9 + 16;
          v66 = x;
          *(float *)v28 = x;
          v67 = y;
          *((float *)v28 + 1) = y;
          v52[18] = v74;
          v29 = *(_QWORD *)&v8->render_old_position.x;
          v30 = v8->gravity;
          v31 = v8->rotation;
          v32 = *(_QWORD *)&v8->render_position.x;
          v27 += 64;
          v76 = v8->render_old_position.z;
          *(_QWORD *)v27 = v32;
          *((_DWORD *)v27 + 2) = LODWORD(v8->render_position.z);
          v33 = (const vostok::math::float4x4 **)(v10 + 32);
          v34 = v11 + 16;
          *v33 = v69;
          v35 = v70;
          v28 += 16;
          v58 = x;
          *v34 = v21;
          v33[1] = v35;
          v36 = v58;
          v59 = y;
          v34[1] = v22;
          *(float *)v28 = v36;
          *((float *)v28 + 1) = v59;
          v37 = v76;
          *((_QWORD *)v52 + 16) = v29;
          v52[34] = v37;
          *((float *)v27 + 11) = v31;
          *((float *)v27 + 12) = v30;
          *(float *)&v29 = v8->rotation;
          v38 = *(_QWORD *)&v8->render_position.x;
          ++p;
          v27 += 64;
          v75 = v8->render_old_position.z;
          v64 = x;
          v39 = v8->gravity;
          v65 = y;
          v40 = *(_QWORD *)&v8->render_old_position.x;
          *(_QWORD *)v27 = v38;
          *((_DWORD *)v27 + 2) = LODWORD(v8->render_position.z);
          v33 += 16;
          *v33 = v60;
          v33[1] = v61;
          v28 += 16;
          *(float *)v28 = v64;
          v34 += 8;
          *((float *)v28 + 1) = v65;
          v41 = v75;
          *v34 = v21;
          *((_QWORD *)v52 + 24) = v40;
          v34[1] = v22;
          *((_DWORD *)v27 + 11) = v29;
          v52[50] = v41;
          *((float *)v27 + 12) = v39;
          v8 = v8->next;
          v7 = v27 + 64;
          v11 = v34 + 8;
          v10 = v33 + 16;
          v9 = v28 + 16;
          v52 += 64;
          if ( !v8 )
            break;
          v6 = _v;
        }
        v2 = thisa;
      }
      v42 = v2->m_vertices.m_variable;
      v42->m_position += v42->m_lock_count * v42->m_lock_stride;
      (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                         + 60))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v42->m_buffer.m_object->m_hardware_buffer,
        0);
      v43 = v2->m_indices.m_variable;
      v43->m_position += v43->m_lock_size;
      (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                         + 60))(
        `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
        v43->m_buffer.m_object->m_hardware_buffer,
        0);
      vostok::render::res_geometry::apply(v2->m_particle_sprite_geometry.m_object);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v45 = v68;
      v46 = v68;
      v47 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
      v48 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v47;
      if ( v47 )
        *((_DWORD *)m_conflicted_key_name + 529) = 4;
      vostok::render::backend::flush((vostok::render::backend *)4, (int)m_conflicted_key_name);
      if ( v48[104] )
      {
        ++*((_DWORD *)v48 + 25);
        v46 += 3 * s_max_triagles_per_dip_value < v46 ? 3 * s_max_triagles_per_dip_value - v46 : 0;
      }
      if ( !v48[37] )
        (*(void (__stdcall **)(int, unsigned int, unsigned int, unsigned int))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                             + 48))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v46,
          i_offset,
          v_offset);
      v49 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
      *((_DWORD *)v48 + 21) += v46 / 3;
      v49->visibility_stat_group.num_triangles.value += v45 / 3;
    }
  }
}
