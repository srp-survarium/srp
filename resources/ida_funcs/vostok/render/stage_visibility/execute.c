void __thiscall vostok::render::stage_visibility::execute(vostok::render::stage_visibility *this)
{
  vostok::render::stage_visibility *v1; // esi
  char *m_begin; // ecx
  vostok::render::stage_visibility *v3; // ecx
  vostok::render::base_scene_view *m_object; // esi
  vostok::sound::sound_world *v5; // ebp
  vostok::sound::sound_world *v6; // esi
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v7; // ecx
  vostok::sound::world_user *(__thiscall *get_logic_world_user)(vostok::sound::world *); // edi
  char *m_buffer; // eax
  const char *v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  char v20; // al
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  void **M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::vector<vostok::render::render_model_instance_impl *> models; // [esp+14h] [ebp-9Ch] BYREF
  vostok::fixed_string<128> model_name; // [esp+20h] [ebp-90h] BYREF
  char v35; // [esp+ACh] [ebp-4h] BYREF

  v1 = this;
  if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 288) )
  {
    this->m_data_ready = vostok::render::hw_hiz_occlusion_manager::quary_and_get_results_if_ready(
                           (vostok::render::hw_hiz_occlusion_manager *)this->m_current_occlusion_buffer_size,
                           this->m_static_results_array,
                           this->m_current_occlusion_buffer_size);
    vostok::render::stage_visibility::frustum_culling(v3, v1);
    if ( v1->m_data_ready )
    {
      vostok::render::stage_visibility::occlusion_culling((vostok::render::stage_visibility *)m_begin, v1);
      v1->m_data_ready = 0;
    }
  }
  else
  {
    vostok::render::stage_visibility::frustum_culling(this, this);
  }
  if ( s_no_trees_value
    || s_no_bushes_value
    || s_no_terrain_value
    || LOWORD(blend_alpha.elements[1])
    || __PAIR16__(BYTE2(blend_alpha.elements[1]), 0) != HIBYTE(blend_alpha.elements[1]) )
  {
    m_object = v1->m_context->m_scene_view.m_object;
    v5 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)m_object[4].m_reference_count);
    v6 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)m_object[4].vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_resource::vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags);
    memset(&models, 0, sizeof(models));
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(v7, (int)&models, 0x400u);
    if ( v5 != v6 )
    {
      while ( 1 )
      {
        get_logic_world_user = v5->get_logic_world_user;
        m_buffer = model_name.m_buffer;
        model_name.m_max_end = &v35;
        model_name.m_begin = model_name.m_buffer;
        model_name.m_end = model_name.m_buffer;
        model_name.m_buffer[0] = 0;
        v10 = "<unknown>";
        do
        {
          if ( m_buffer >= model_name.m_max_end )
            break;
          *m_buffer = *v10;
          m_buffer = model_name.m_end + 1;
          ++v10;
          ++model_name.m_end;
        }
        while ( *v10 );
        *m_buffer = 0;
        if ( !HIBYTE(blend_alpha.elements[1]) )
          break;
        strstr((unsigned __int8 *)model_name.m_begin, "flora");
        m_begin = model_name.m_begin;
        if ( v11 && v11 - (unsigned int)model_name.m_begin != -1 )
          goto LABEL_34;
        strstr((unsigned __int8 *)model_name.m_begin, "terrain");
        m_begin = model_name.m_begin;
        if ( v12 )
        {
          if ( v12 - (unsigned int)model_name.m_begin != -1 )
            goto LABEL_34;
        }
        strstr((unsigned __int8 *)model_name.m_begin, "house");
        m_begin = model_name.m_begin;
        if ( v13 )
        {
          if ( v13 - (unsigned int)model_name.m_begin != -1 )
            goto LABEL_34;
        }
        strstr((unsigned __int8 *)model_name.m_begin, "background");
        m_begin = model_name.m_begin;
        if ( v14 )
        {
          if ( v14 - (unsigned int)model_name.m_begin != -1 )
            goto LABEL_34;
        }
        strstr((unsigned __int8 *)model_name.m_begin, "cane");
        m_begin = model_name.m_begin;
        if ( v15 )
        {
          if ( v15 - (unsigned int)model_name.m_begin != -1 )
            goto LABEL_34;
        }
        strstr((unsigned __int8 *)model_name.m_begin, "poplar");
        m_begin = model_name.m_begin;
        if ( v16 )
        {
          if ( v16 - (unsigned int)model_name.m_begin != -1 )
            goto LABEL_34;
        }
        if ( (strstr((unsigned __int8 *)model_name.m_begin, "fruit"), m_begin = model_name.m_begin, v17)
          && v17 - (unsigned int)model_name.m_begin != -1
          || (strstr((unsigned __int8 *)model_name.m_begin, "tree"), m_begin = model_name.m_begin, v18)
          && v18 - (unsigned int)model_name.m_begin != -1
          || (strstr((unsigned __int8 *)model_name.m_begin, "elka"), m_begin = model_name.m_begin, v19)
          && v19 - (unsigned int)model_name.m_begin != -1 )
        {
LABEL_34:
          v20 = 0;
        }
        else
        {
          v20 = 1;
        }
        if ( !HIBYTE(blend_alpha.elements[1]) || !v20 )
          goto LABEL_39;
        m_begin = (char *)v5->__vftable;
        BYTE1(v5->get_calculation_type) = 1;
LABEL_72:
        v5 = (vostok::sound::sound_world *)((char *)v5 + 4);
        if ( v5 == v6 )
          goto LABEL_73;
      }
      m_begin = model_name.m_begin;
LABEL_39:
      if ( BYTE2(blend_alpha.elements[1]) )
      {
        strstr((unsigned __int8 *)m_begin, "flora");
        m_begin = model_name.m_begin;
        if ( v21 )
        {
          if ( v21 - (unsigned int)model_name.m_begin != -1 )
          {
            BYTE1(v5->get_calculation_type) = 1;
            m_begin = model_name.m_begin;
          }
        }
      }
      if ( s_no_terrain_value )
      {
        strstr((unsigned __int8 *)m_begin, "terrain");
        m_begin = model_name.m_begin;
        if ( v22 )
        {
          if ( v22 - (unsigned int)model_name.m_begin != -1 )
          {
            BYTE1(v5->get_calculation_type) = 1;
            m_begin = model_name.m_begin;
          }
        }
      }
      if ( LOBYTE(blend_alpha.elements[1]) )
      {
        strstr((unsigned __int8 *)m_begin, "house");
        m_begin = model_name.m_begin;
        if ( v23 )
        {
          if ( v23 - (unsigned int)model_name.m_begin != -1 )
          {
            BYTE1(v5->get_calculation_type) = 1;
            m_begin = model_name.m_begin;
          }
        }
      }
      if ( BYTE1(blend_alpha.elements[1]) )
      {
        strstr((unsigned __int8 *)m_begin, "background");
        m_begin = model_name.m_begin;
        if ( v24 )
        {
          if ( v24 - (unsigned int)model_name.m_begin != -1 )
          {
            BYTE1(v5->get_calculation_type) = 1;
            m_begin = model_name.m_begin;
          }
        }
      }
      if ( s_no_bushes_value )
      {
        strstr((unsigned __int8 *)m_begin, "cane");
        if ( v25 && v25 - (unsigned int)model_name.m_begin != -1 )
          BYTE1(v5->get_calculation_type) = 1;
        if ( s_no_bushes_value
          && (*(int (__thiscall **)(_DWORD))(*(_DWORD *)get_logic_world_user + 40))(get_logic_world_user) == 1 )
        {
          goto LABEL_63;
        }
      }
      if ( s_no_trees_value
        && (unsigned int)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)get_logic_world_user + 40))(get_logic_world_user) > 1 )
      {
LABEL_63:
        strstr((unsigned __int8 *)model_name.m_begin, "poplar");
        m_begin = model_name.m_begin;
        if ( v26 && v26 - (unsigned int)model_name.m_begin != -1
          || (strstr((unsigned __int8 *)model_name.m_begin, "fruit"), m_begin = model_name.m_begin, v27)
          && v27 - (unsigned int)model_name.m_begin != -1
          || (strstr((unsigned __int8 *)model_name.m_begin, "tree"), m_begin = model_name.m_begin, v28)
          && v28 - (unsigned int)model_name.m_begin != -1
          || (strstr((unsigned __int8 *)model_name.m_begin, "elka"), v29)
          && v29 - (unsigned int)model_name.m_begin != -1 )
        {
          BYTE1(v5->get_calculation_type) = 1;
        }
      }
      goto LABEL_72;
    }
LABEL_73:
    M_start = models._M_impl._M_start;
    if ( models._M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
    }
    v1 = this;
  }
  vostok::render::stage_visibility::gather_statistics((vostok::render::stage_visibility *)m_begin, (int)v1);
}
