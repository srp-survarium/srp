void __userpurge vostok::render::stage_forward::render_forward_models(
        vostok::render::vector<vostok::render::render_surface_instance *> *dynamic_visuals@<eax>,
        vostok::render::stage_forward *this,
        unsigned int pass_index)
{
  vostok::render::stage_forward *v3; // ebx
  void **M_start; // ebp
  void **M_finish; // edi
  vostok::render::render_target *m_object; // eax
  vostok::render::resource_manager *v7; // ecx
  ID3D11RenderTargetView *m_rt; // edx
  const char *m_conflicted_key_name; // eax
  bool v10; // zf
  int v11; // esi
  int *v12; // esi
  int v13; // eax
  vostok::render::material_effects *v14; // edi
  vostok::render::res_effect *v15; // ecx
  _DWORD *v16; // eax
  vostok::render::shader_constant_host *m_eye_ray_corner_parameter; // eax
  const char *v18; // edi
  int m_buffer_index; // edx
  const char *v20; // eax
  vostok::render::shader_constant_host *m_view_to_shadow_parameter; // ecx
  int v22; // edx
  vostok::render::shader_constant_host *m_rain_offset_parameter; // eax
  int v24; // ecx
  _DWORD *v25; // eax
  int v26; // xmm0_4
  vostok::render::shader_constant_host *m_far_fog_color_and_distance; // eax
  unsigned int v28; // ecx
  int v29; // ecx
  vostok::render::shader_constant_host *m_fog_alpha; // eax
  int v31; // edx
  vostok::render::shader_constant_host *m_near_fog_distance; // eax
  int v33; // edx
  vostok::render::stage_forward *v34; // xmm0_4
  vostok::render::shader_constant_host *m_use_rain_parameter; // eax
  unsigned int v36; // edx
  int v37; // ecx
  unsigned int v38; // ebp
  bool v39; // al
  __int64 v40; // rax
  unsigned int v41; // [esp+0h] [ebp-74h]
  int v42; // [esp+14h] [ebp-60h]
  void **it_d; // [esp+18h] [ebp-5Ch]
  void **v44; // [esp+1Ch] [ebp-58h]
  char src_ptr[4]; // [esp+20h] [ebp-54h] BYREF
  int v46; // [esp+24h] [ebp-50h]
  int v47; // [esp+28h] [ebp-4Ch]
  int v48; // [esp+2Ch] [ebp-48h]
  vostok::math::float4x4 result; // [esp+30h] [ebp-44h] BYREF

  v3 = this;
  M_start = dynamic_visuals->_M_impl._M_start;
  M_finish = dynamic_visuals->_M_impl._M_finish;
  it_d = dynamic_visuals->_M_impl._M_start;
  v44 = M_finish;
  if ( (((char *)M_finish - (char *)dynamic_visuals->_M_impl._M_start) & 0xFFFFFFFC) != 0 )
  {
    m_object = this->m_context->m_targets->m_family[47].target.m_object;
    v7 = 0;
    if ( m_object )
    {
      v7 = (vostok::render::resource_manager *)this->m_context->m_targets->m_family[47].target.m_object;
      ++m_object->m_reference_count;
      m_rt = m_object->m_rt;
    }
    else
    {
      m_rt = 0;
    }
    m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    if ( *((ID3D11RenderTargetView **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
         + 535) != m_rt )
    {
      *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 535) = m_rt;
      *((_BYTE *)m_conflicted_key_name + 163) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 536) )
    {
      *((_DWORD *)m_conflicted_key_name + 536) = 0;
      *((_BYTE *)m_conflicted_key_name + 164) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 537) )
    {
      *((_DWORD *)m_conflicted_key_name + 537) = 0;
      *((_BYTE *)m_conflicted_key_name + 165) = 1;
    }
    if ( *((_DWORD *)m_conflicted_key_name + 538) )
    {
      *((_DWORD *)m_conflicted_key_name + 538) = 0;
      *((_BYTE *)m_conflicted_key_name + 166) = 1;
    }
    if ( v7 )
    {
      v10 = v7->sh_created-- == 1;
      if ( v10 )
      {
        vostok::render::resource_manager::release(
          v7,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)v7);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      }
    }
    v11 = *((_DWORD *)m_conflicted_key_name + 547);
    v10 = *((_DWORD *)m_conflicted_key_name + 539) == v11;
    *((_DWORD *)m_conflicted_key_name + 539) = v11;
    *((_BYTE *)m_conflicted_key_name + 167) |= !v10;
  }
  if ( M_start != M_finish )
  {
    do
    {
      v12 = (int *)*M_start;
      if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
            + 288)
        || !*((_BYTE *)v12 + 25) )
      {
        v13 = *(_DWORD *)(*v12 + 148);
        v42 = *v12;
        if ( !v13 || s_use_one_material_value )
          v14 = s_nomaterial_material_effects[*(_DWORD *)(*v12 + 4)];
        else
          v14 = (vostok::render::material_effects *)(v13 + 264);
        if ( pass_index )
        {
          if ( pass_index != 1 || v14->is_forward_after_fog )
          {
LABEL_29:
            (*(void (__thiscall **)(int))(*(_DWORD *)v12[2] + 56))(v12[2]);
            vostok::render::renderer_context::set_w(v3->m_context, (const vostok::math::float4x4 *)v12[1]);
            v16 = &v14->m_effects[17].m_object->__vftable;
            if ( (v16[71] - v16[70]) >> 2 )
            {
              v16[69] = 0;
              vostok::render::res_effect::apply_pass(v15, v41);
            }
            vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v42 + 48));
            m_eye_ray_corner_parameter = v3->m_eye_ray_corner_parameter;
            v18 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
            if ( m_eye_ray_corner_parameter->m_update_markers[1] == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                    + 573) )
            {
              m_buffer_index = m_eye_ray_corner_parameter->m_shader_slots[1].m_buffer_index;
              if ( m_buffer_index != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_eye_ray_corner_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_eye_ray_corner_parameter->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                           + 371)
                                                                         + 16)
                                                             + 4 * m_buffer_index),
                  (const char *)v3->m_context->m_eye_rays);
            }
            ++*((_DWORD *)v18 + 23);
            v20 = (const char *)vostok::math::transpose(&result, &v3->m_renderer->m_view_to_rain_shadow);
            m_view_to_shadow_parameter = v3->m_view_to_shadow_parameter;
            if ( m_view_to_shadow_parameter->m_update_markers[1] == *((_DWORD *)v18 + 573) )
            {
              v22 = m_view_to_shadow_parameter->m_shader_slots[1].m_buffer_index;
              if ( v22 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_view_to_shadow_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_view_to_shadow_parameter->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 371) + 16) + 4 * v22),
                  v20);
            }
            ++*((_DWORD *)v18 + 23);
            m_rain_offset_parameter = v3->m_rain_offset_parameter;
            if ( m_rain_offset_parameter->m_update_markers[1] == *((_DWORD *)v18 + 573) )
            {
              v24 = m_rain_offset_parameter->m_shader_slots[1].m_buffer_index;
              if ( v24 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_rain_offset_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_rain_offset_parameter->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 371) + 16) + 4 * v24),
                  (const char *)&v3->m_rain_offset);
            }
            ++*((_DWORD *)v18 + 23);
            v25 = &v3->m_context->m_scene_view.m_object->__vftable;
            *(_DWORD *)src_ptr = v25[112];
            v46 = v25[113];
            v47 = v25[114];
            v26 = v25[121];
            m_far_fog_color_and_distance = v3->m_far_fog_color_and_distance;
            v28 = m_far_fog_color_and_distance->m_update_markers[1];
            v48 = v26;
            if ( v28 == *((_DWORD *)v18 + 573) )
            {
              v29 = m_far_fog_color_and_distance->m_shader_slots[1].m_buffer_index;
              if ( v29 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_far_fog_color_and_distance->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_far_fog_color_and_distance->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 371) + 16) + 4 * v29),
                  src_ptr);
            }
            ++*((_DWORD *)v18 + 23);
            m_fog_alpha = v3->m_fog_alpha;
            if ( m_fog_alpha->m_update_markers[1] == *((_DWORD *)v18 + 573) )
            {
              v31 = m_fog_alpha->m_shader_slots[1].m_buffer_index;
              if ( v31 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_fog_alpha->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_fog_alpha->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 371) + 16) + 4 * v31),
                  (const char *)&v3->m_context->m_scene_view.m_object[1].m_sub_fat);
            }
            ++*((_DWORD *)v18 + 23);
            m_near_fog_distance = v3->m_near_fog_distance;
            if ( m_near_fog_distance->m_update_markers[1] == *((_DWORD *)v18 + 573) )
            {
              v33 = m_near_fog_distance->m_shader_slots[1].m_buffer_index;
              if ( v33 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_near_fog_distance->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_near_fog_distance->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 371) + 16) + 4 * v33),
                  (const char *)&v3->m_context->m_scene_view.m_object[1].vostok::resources::unmanaged_intrusive_base);
            }
            ++*((_DWORD *)v18 + 23);
            if ( LOBYTE(v3->m_context->m_scene_view.m_object[2].m_children_resources.m_thread_id) )
              v34 = (vostok::render::stage_forward *)clear_value;
            else
              v34 = 0;
            m_use_rain_parameter = v3->m_use_rain_parameter;
            v36 = m_use_rain_parameter->m_update_markers[1];
            this = v34;
            if ( v36 == *((_DWORD *)v18 + 573) )
            {
              v37 = m_use_rain_parameter->m_shader_slots[1].m_buffer_index;
              if ( v37 != 0xFFFF )
                vostok::render::shader_constant_buffer::set_memory(
                  m_use_rain_parameter->m_shader_slots[1].m_slot_index,
                  (unsigned __int8)m_use_rain_parameter->m_shader_slots[1].m_class_id,
                  *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)v18 + 371) + 16) + 4 * v37),
                  (const char *)&this);
            }
            ++*((_DWORD *)v18 + 23);
            v38 = 3 * *(_DWORD *)(v42 + 68);
            v39 = *((_DWORD *)v18 + 529) != 4;
            *((_BYTE *)v18 + 162) = v39;
            if ( v39 )
              *((_DWORD *)v18 + 529) = 4;
            vostok::render::backend::flush((vostok::render::backend *)4, (int)v18);
            if ( v18[104] )
            {
              ++*((_DWORD *)v18 + 25);
              v38 += 3 * s_max_triagles_per_dip_value < v38 ? 3 * s_max_triagles_per_dip_value - v38 : 0;
            }
            if ( !v18[37] )
              (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                       + 48))(
                `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
                v38,
                0,
                0);
            v40 = 2863311531LL * v38;
            M_start = it_d;
            *((_DWORD *)v18 + 21) += HIDWORD(v40) >> 1;
          }
        }
        else if ( !v14->is_forward_after_fog )
        {
          goto LABEL_29;
        }
      }
      it_d = ++M_start;
    }
    while ( M_start != v44 );
  }
}
