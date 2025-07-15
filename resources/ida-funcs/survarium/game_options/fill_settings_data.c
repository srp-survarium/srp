void __thiscall survarium::game_options::fill_settings_data(
        survarium::game_options *this,
        survarium::game_options *thisa)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::fixed_string<64> *v3; // esi
  const char *m_begin; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // eax
  vostok::fixed_string<64> *v14; // esi
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  const char *v30; // eax
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  vostok::memory::doug_lea_allocator *v34; // eax
  vostok::fixed_string<64> *v35; // esi
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  const char *v42; // eax
  vostok::memory::doug_lea_allocator *v43; // eax
  vostok::fixed_string<64> *v44; // esi
  const char *v45; // eax
  const char *v46; // eax
  vostok::fixed_string<64> *v47; // esi
  unsigned __int8 v48; // bl
  survarium::flash_value *v49; // eax
  int i; // ecx
  survarium::flash_movie_resource *m_object; // eax
  int v52; // edx
  survarium::game_options *v53; // ebx
  int v54; // ebp
  survarium::flash_movie_resource *v55; // ecx
  const char *v56; // edi
  survarium::text_translator *p_m_text_translator; // eax
  int v58; // ecx
  survarium::options_item_base *v59; // esi
  survarium::option_item_type_enum m_type; // eax
  char *v61; // esi
  int j; // edi
  int v63; // eax
  vostok::sound::sound_world *v64; // ecx
  malloc_state *m_start_time_high; // esi
  char *v66; // eax
  vostok::sound::sound_world *v67; // ecx
  malloc_state *v68; // esi
  char *v69; // eax
  vostok::sound::sound_world *v70; // ecx
  malloc_state *v71; // esi
  char *v72; // eax
  vostok::sound::sound_world *v73; // ecx
  malloc_state *v74; // esi
  char *v75; // eax
  survarium::options_tab **m_options; // [esp+58h] [ebp-4A4h]
  int v77; // [esp+5Ch] [ebp-4A0h]
  survarium::flash_value options_item_member; // [esp+60h] [ebp-49Ch] BYREF
  const char **p_m_begin; // [esp+78h] [ebp-484h]
  survarium::flash_value options_item; // [esp+7Ch] [ebp-480h] BYREF
  vostok::fixed_string<64> *video_options_labels; // [esp+94h] [ebp-468h]
  int v82; // [esp+98h] [ebp-464h]
  vostok::fixed_string<64> *gameplay_options_labels; // [esp+9Ch] [ebp-460h]
  vostok::fixed_string<64> *sound_options_labels; // [esp+A0h] [ebp-45Ch]
  int v85; // [esp+A4h] [ebp-458h]
  vostok::fixed_string<64> *controllers_options_labels; // [esp+A8h] [ebp-454h]
  int v87; // [esp+ACh] [ebp-450h] BYREF
  int v88; // [esp+B0h] [ebp-44Ch]
  wchar_t *v89; // [esp+B4h] [ebp-448h]
  survarium::flash_value options_args[2]; // [esp+C8h] [ebp-434h] BYREF
  char v91; // [esp+F8h] [ebp-404h] BYREF
  wchar_t label_txt[512]; // [esp+FCh] [ebp-400h] BYREF

  v2 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v3 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(v2, 9u);
  m_begin = v3->m_begin;
  gameplay_options_labels = v3;
  if ( m_begin != "st_invite_from_friends_option" )
  {
    v3->m_end = (char *)m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(v3, "st_invite_from_friends_option");
  }
  v5 = v3[1].m_begin;
  if ( v5 != "st_friends_signin_notification_option" )
  {
    v3[1].m_end = (char *)v5;
    *v5 = 0;
    vostok::buffer_string::operator+=(v3 + 1, "st_friends_signin_notification_option");
  }
  v6 = v3[2].m_begin;
  if ( v6 != "st_messages_censor_option" )
  {
    v3[2].m_end = (char *)v6;
    *v6 = 0;
    vostok::buffer_string::operator+=(v3 + 2, "st_messages_censor_option");
  }
  v7 = v3[3].m_begin;
  if ( v7 != "st_messages_only_from_friends_option" )
  {
    v3[3].m_end = (char *)v7;
    *v7 = 0;
    vostok::buffer_string::operator+=(v3 + 3, "st_messages_only_from_friends_option");
  }
  v8 = v3[4].m_begin;
  if ( v8 != "st_private_messages_in_game_option" )
  {
    v3[4].m_end = (char *)v8;
    *v8 = 0;
    vostok::buffer_string::operator+=(v3 + 4, "st_private_messages_in_game_option");
  }
  v9 = v3[5].m_begin;
  if ( v9 != "st_hide_spam_option" )
  {
    v3[5].m_end = (char *)v9;
    *v9 = 0;
    vostok::buffer_string::operator+=(v3 + 5, "st_hide_spam_option");
  }
  v10 = v3[6].m_begin;
  if ( v10 != "st_crosshair_type_option" )
  {
    v3[6].m_end = (char *)v10;
    *v10 = 0;
    vostok::buffer_string::operator+=(v3 + 6, "st_crosshair_type_option");
  }
  v11 = v3[7].m_begin;
  if ( v11 != "st_crosshair_static_option" )
  {
    v3[7].m_end = (char *)v11;
    *v11 = 0;
    vostok::buffer_string::operator+=(v3 + 7, "st_crosshair_static_option");
  }
  v12 = v3[8].m_begin;
  if ( v12 != "st_minimap_rotable_option" )
  {
    v3[8].m_end = (char *)v12;
    *v12 = 0;
    vostok::buffer_string::operator+=(v3 + 8, "st_minimap_rotable_option");
  }
  v13 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v14 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(v13, 0x13u);
  v15 = v14->m_begin;
  video_options_labels = v14;
  if ( v15 != "st_monitor_count_option" )
  {
    v14->m_end = (char *)v15;
    *v15 = 0;
    vostok::buffer_string::operator+=(v14, "st_monitor_count_option");
  }
  v16 = v14[1].m_begin;
  if ( v16 != "st_resolution_option" )
  {
    v14[1].m_end = (char *)v16;
    *v16 = 0;
    vostok::buffer_string::operator+=(v14 + 1, "st_resolution_option");
  }
  v17 = v14[2].m_begin;
  if ( v17 != "st_fullscreen_option" )
  {
    v14[2].m_end = (char *)v17;
    *v17 = 0;
    vostok::buffer_string::operator+=(v14 + 2, "st_fullscreen_option");
  }
  v18 = v14[3].m_begin;
  if ( v18 != "st_vsync_option" )
  {
    v14[3].m_end = (char *)v18;
    *v18 = 0;
    vostok::buffer_string::operator+=(v14 + 3, "st_vsync_option");
  }
  v19 = v14[4].m_begin;
  if ( v19 != "st_antialiasing_option" )
  {
    v14[4].m_end = (char *)v19;
    *v19 = 0;
    vostok::buffer_string::operator+=(v14 + 4, "st_antialiasing_option");
  }
  v20 = v14[5].m_begin;
  if ( v20 != "st_aniso_filtering_option" )
  {
    v14[5].m_end = (char *)v20;
    *v20 = 0;
    vostok::buffer_string::operator+=(v14 + 5, "st_aniso_filtering_option");
  }
  v21 = v14[6].m_begin;
  if ( v21 != "st_options_adjust_gamma" )
  {
    v14[6].m_end = (char *)v21;
    *v21 = 0;
    vostok::buffer_string::operator+=(v14 + 6, "st_options_adjust_gamma");
  }
  v22 = v14[7].m_begin;
  if ( v22 != "st_fov_option" )
  {
    v14[7].m_end = (char *)v22;
    *v22 = 0;
    vostok::buffer_string::operator+=(v14 + 7, "st_fov_option");
  }
  v23 = v14[8].m_begin;
  if ( v23 != "st_graphics_quality_option" )
  {
    v14[8].m_end = (char *)v23;
    *v23 = 0;
    vostok::buffer_string::operator+=(v14 + 8, "st_graphics_quality_option");
  }
  v24 = v14[9].m_begin;
  if ( v24 != "st_texture_quality_option" )
  {
    v14[9].m_end = (char *)v24;
    *v24 = 0;
    vostok::buffer_string::operator+=(v14 + 9, "st_texture_quality_option");
  }
  v25 = v14[10].m_begin;
  if ( v25 != "st_geometry_quality_option" )
  {
    v14[10].m_end = (char *)v25;
    *v25 = 0;
    vostok::buffer_string::operator+=(v14 + 10, "st_geometry_quality_option");
  }
  v26 = v14[11].m_begin;
  if ( v26 != "st_shadow_quality_option" )
  {
    v14[11].m_end = (char *)v26;
    *v26 = 0;
    vostok::buffer_string::operator+=(v14 + 11, "st_shadow_quality_option");
  }
  v27 = v14[12].m_begin;
  if ( v27 != "st_lightning_quality_option" )
  {
    v14[12].m_end = (char *)v27;
    *v27 = 0;
    vostok::buffer_string::operator+=(v14 + 12, "st_lightning_quality_option");
  }
  v28 = v14[13].m_begin;
  if ( v28 != "st_shading_quality_option" )
  {
    v14[13].m_end = (char *)v28;
    *v28 = 0;
    vostok::buffer_string::operator+=(v14 + 13, "st_shading_quality_option");
  }
  v29 = v14[14].m_begin;
  if ( v29 != "st_decorations_options" )
  {
    v14[14].m_end = (char *)v29;
    *v29 = 0;
    vostok::buffer_string::operator+=(v14 + 14, "st_decorations_options");
  }
  v30 = v14[15].m_begin;
  if ( v30 != "st_post_process_options" )
  {
    v14[15].m_end = (char *)v30;
    *v30 = 0;
    vostok::buffer_string::operator+=(v14 + 15, "st_post_process_options");
  }
  v31 = v14[16].m_begin;
  if ( v31 != "st_ambient_occlusion_options" )
  {
    v14[16].m_end = (char *)v31;
    *v31 = 0;
    vostok::buffer_string::operator+=(v14 + 16, "st_ambient_occlusion_options");
  }
  v32 = v14[17].m_begin;
  if ( v32 != "st_particles_quality_options" )
  {
    v14[17].m_end = (char *)v32;
    *v32 = 0;
    vostok::buffer_string::operator+=(v14 + 17, "st_particles_quality_options");
  }
  v33 = v14[18].m_begin;
  if ( v33 != "st_motion_blur_amount_options" )
  {
    v14[18].m_end = (char *)v33;
    *v33 = 0;
    vostok::buffer_string::operator+=(v14 + 18, "st_motion_blur_amount_options");
  }
  v34 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v35 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(v34, 7u);
  v36 = v35->m_begin;
  sound_options_labels = v35;
  if ( v36 != "st_general_volume_option" )
  {
    v35->m_end = (char *)v36;
    *v36 = 0;
    vostok::buffer_string::operator+=(v35, "st_general_volume_option");
  }
  v37 = v35[1].m_begin;
  if ( v37 != "st_ingame_volume_option" )
  {
    v35[1].m_end = (char *)v37;
    *v37 = 0;
    vostok::buffer_string::operator+=(v35 + 1, "st_ingame_volume_option");
  }
  v38 = v35[2].m_begin;
  if ( v38 != "st_music_volume_option" )
  {
    v35[2].m_end = (char *)v38;
    *v38 = 0;
    vostok::buffer_string::operator+=(v35 + 2, "st_music_volume_option");
  }
  v39 = v35[3].m_begin;
  if ( v39 != "st_voice_chat_volume_option" )
  {
    v35[3].m_end = (char *)v39;
    *v39 = 0;
    vostok::buffer_string::operator+=(v35 + 3, "st_voice_chat_volume_option");
  }
  v40 = v35[4].m_begin;
  if ( v40 != "st_use_microphone_option" )
  {
    v35[4].m_end = (char *)v40;
    *v40 = 0;
    vostok::buffer_string::operator+=(v35 + 4, "st_use_microphone_option");
  }
  v41 = v35[5].m_begin;
  if ( v41 != "st_microphone_sensitivity_option" )
  {
    v35[5].m_end = (char *)v41;
    *v41 = 0;
    vostok::buffer_string::operator+=(v35 + 5, "st_microphone_sensitivity_option");
  }
  v42 = v35[6].m_begin;
  if ( v42 != "st_ptt_button_option" )
  {
    v35[6].m_end = (char *)v42;
    *v42 = 0;
    vostok::buffer_string::operator+=(v35 + 6, "st_ptt_button_option");
  }
  v43 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v44 = vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>(v43, 2u);
  v45 = v44->m_begin;
  controllers_options_labels = v44;
  if ( v45 != "st_mouse_invertion_option" )
  {
    v44->m_end = (char *)v45;
    *v45 = 0;
    vostok::buffer_string::operator+=(v44, "st_mouse_invertion_option");
  }
  v46 = v44[1].m_begin;
  if ( v46 != "st_mouse_sensitivity_option" )
  {
    v44[1].m_end = (char *)v46;
    *v46 = 0;
    vostok::buffer_string::operator+=(v44 + 1, "st_mouse_sensitivity_option");
  }
  v77 = 0;
  m_options = thisa->m_options;
  v82 = 4;
  do
  {
    v47 = 0;
    v48 = 0;
    switch ( v77 )
    {
      case 0:
        v47 = gameplay_options_labels;
        v48 = 9;
        break;
      case 1:
        v47 = controllers_options_labels;
        v48 = 2;
        break;
      case 2:
        v47 = video_options_labels;
        v48 = 19;
        break;
      case 3:
        v47 = sound_options_labels;
        v48 = 7;
        break;
      default:
        break;
    }
    v49 = options_args;
    for ( i = 1; i >= 0; --i )
    {
      if ( v49 )
      {
        *(_DWORD *)v49->body = 0;
        *(_DWORD *)&v49->body[4] = 0;
      }
      ++v49;
    }
    if ( (options_args[0].body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_args[0].body + 8))(
        *(_DWORD *)options_args[0].body,
        options_args,
        *(_DWORD *)&options_args[0].body[8]);
      *(_DWORD *)options_args[0].body = 0;
    }
    m_object = thisa->m_options_ui.m_object;
    *(_DWORD *)&options_args[0].body[4] = 4;
    *(_DWORD *)&options_args[0].body[8] = v77;
    Scaleform::GFx::Movie::CreateArray(m_object->movie->m_movie, (Scaleform::GFx::Value *)&options_args[1]);
    if ( v48 )
    {
      v52 = v48;
      v53 = thisa;
      v54 = 0;
      p_m_begin = (const char **)&v47->m_begin;
      v85 = v52;
      while ( 1 )
      {
        v55 = thisa->m_options_ui.m_object;
        *(_DWORD *)options_item.body = 0;
        *(_DWORD *)&options_item.body[4] = 0;
        Scaleform::GFx::Movie::CreateObject(v55->movie->m_movie, (Scaleform::GFx::Value *)&options_item, 0, 0, 0);
        v56 = *p_m_begin;
        p_m_text_translator = &thisa->m_game->m_text_translator;
        *(_DWORD *)options_item_member.body = 0;
        *(_DWORD *)&options_item_member.body[4] = 0;
        survarium::text_translator::translate_text(p_m_text_translator, v56, label_txt);
        v58 = 0;
        v87 = 0;
        v88 = 7;
        v89 = label_txt;
        if ( (options_item_member.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_item_member.body + 8))(
            *(_DWORD *)options_item_member.body,
            &options_item_member,
            *(_DWORD *)&options_item_member.body[8]);
          v58 = v87;
          *(_DWORD *)options_item_member.body = 0;
        }
        *(_DWORD *)&options_item_member.body[4] = 7;
        *(_DWORD *)&options_item_member.body[8] = label_txt;
        if ( (v88 & 0x40) != 0 )
          (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v58 + 8))(v58, &v87, v89);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)options_item.body
                                                                                             + 20))(
          *(_DWORD *)options_item.body,
          *(_DWORD *)&options_item.body[8],
          "label",
          &options_item_member,
          (options_item.body[4] & 0x8F) == 10);
        if ( !*m_options )
          goto LABEL_99;
        v59 = (*m_options)->m_options[v54];
        Scaleform::GFx::Movie::CreateFunction(
          thisa->m_options_ui.m_object->movie->m_movie,
          (Scaleform::GFx::Value *)&options_item_member,
          v59->impl,
          0);
        (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)options_item.body
                                                                                             + 20))(
          *(_DWORD *)options_item.body,
          *(_DWORD *)&options_item.body[8],
          "setter",
          &options_item_member,
          (options_item.body[4] & 0x8F) == 10);
        m_type = v59->m_type;
        if ( m_type == string_selector )
          break;
        if ( m_type == slider_selector )
        {
          Scaleform::GFx::Movie::CreateObject(
            thisa->m_options_ui.m_object->movie->m_movie,
            (Scaleform::GFx::Value *)&options_item_member,
            0,
            0,
            0);
          goto LABEL_98;
        }
LABEL_99:
        (*(void (__thiscall **)(_DWORD, _DWORD, int, survarium::flash_value *))(**(_DWORD **)options_args[1].body + 52))(
          *(_DWORD *)options_args[1].body,
          *(_DWORD *)&options_args[1].body[8],
          v54,
          &options_item);
        if ( (options_item_member.body[4] & 0x40) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_item_member.body + 8))(
            *(_DWORD *)options_item_member.body,
            &options_item_member,
            *(_DWORD *)&options_item_member.body[8]);
          *(_DWORD *)options_item_member.body = 0;
        }
        *(_DWORD *)&options_item_member.body[4] = 0;
        if ( (options_item.body[4] & 0x40) != 0 )
          (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_item.body + 8))(
            *(_DWORD *)options_item.body,
            &options_item,
            *(_DWORD *)&options_item.body[8]);
        p_m_begin += 19;
        ++v54;
        if ( !--v85 )
          goto LABEL_106;
      }
      Scaleform::GFx::Movie::CreateArray(
        thisa->m_options_ui.m_object->movie->m_movie,
        (Scaleform::GFx::Value *)&options_item_member);
LABEL_98:
      v59->fill_data(v59, &options_item_member);
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)options_item.body
                                                                                           + 20))(
        *(_DWORD *)options_item.body,
        *(_DWORD *)&options_item.body[8],
        "dataProvider",
        &options_item_member,
        (options_item.body[4] & 0x8F) == 10);
      goto LABEL_99;
    }
    v53 = thisa;
LABEL_106:
    Scaleform::GFx::Movie::Invoke(
      v53->m_options_ui.m_object->movie->m_movie,
      "root.set_settings",
      0,
      (const Scaleform::GFx::Value *)options_args,
      2u);
    v61 = &v91;
    for ( j = 1; j >= 0; --j )
    {
      v63 = *((_DWORD *)v61 - 5);
      v61 -= 24;
      if ( (v63 & 0x40) != 0 )
      {
        (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v61 + 8))(v61, *((_DWORD *)v61 + 2));
        *(_DWORD *)v61 = 0;
      }
      *((_DWORD *)v61 + 1) = 0;
    }
    ++v77;
    ++m_options;
    --v82;
  }
  while ( v82 );
  v64 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  m_start_time_high = (malloc_state *)HIDWORD(v64->m_timer.m_start_time);
  v66 = &gameplay_options_labels[-1].m_buffer[56];
  BYTE2(v64->m_xaudio_callback_orders.m_pop_thread_id) = 0;
  vostok_mspace_free(m_start_time_high, v66);
  v67 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v68 = (malloc_state *)HIDWORD(v67->m_timer.m_start_time);
  v69 = &video_options_labels[-1].m_buffer[56];
  BYTE2(v67->m_xaudio_callback_orders.m_pop_thread_id) = 0;
  vostok_mspace_free(v68, v69);
  v70 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v71 = (malloc_state *)HIDWORD(v70->m_timer.m_start_time);
  v72 = &sound_options_labels[-1].m_buffer[56];
  BYTE2(v70->m_xaudio_callback_orders.m_pop_thread_id) = 0;
  vostok_mspace_free(v71, v72);
  v73 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v74 = (malloc_state *)HIDWORD(v73->m_timer.m_start_time);
  v75 = &controllers_options_labels[-1].m_buffer[56];
  BYTE2(v73->m_xaudio_callback_orders.m_pop_thread_id) = 0;
  vostok_mspace_free(v74, v75);
}
