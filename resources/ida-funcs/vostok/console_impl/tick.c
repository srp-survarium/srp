void __thiscall vostok::console_impl::tick(
        vostok::console_impl *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view,
        int a3)
{
  vostok::logging::log_file *v3; // edi
  int v4; // eax
  vostok::render::base_scene_view *m_object; // ecx
  int v6; // eax
  vostok::render::base_scene_view *m_last_line; // edi
  int v8; // esi
  _DWORD *v9; // eax
  int v10; // edx
  int v11; // eax
  vostok::fixed_string<512> *v12; // esi
  int v13; // eax
  unsigned int v14; // ecx
  vostok::render::base_scene_view *v15; // ecx
  int v16; // eax
  char *v17; // eax
  vostok::console_impl *v18; // ecx
  int v19; // eax
  int v20; // eax
  vostok::ui::text *item; // esi
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax
  char *buffer_ptr; // esi
  vostok::logging::log_file *v26; // ecx
  vostok::console_impl *v27; // ecx
  vostok::ui::text *v28; // esi
  vostok::ui::window *v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  vostok::render::base_scene_view_vtbl *v35; // edi
  int v36; // eax
  vostok::ui::text *v37; // esi
  int v38; // eax
  int v39; // eax
  _DWORD *v40; // ecx
  vostok::logging::log_file *v41; // ecx
  vostok::console_impl *value; // [esp+3Ch] [ebp-264h]
  char v43; // [esp+53h] [ebp-24Dh]
  float v44; // [esp+54h] [ebp-24Ch]
  float v45; // [esp+54h] [ebp-24Ch]
  void (__thiscall *line)(vostok::render::stage_screen_space_reflections *); // [esp+58h] [ebp-248h]
  int v47; // [esp+5Ch] [ebp-244h]
  float v48; // [esp+60h] [ebp-240h] BYREF
  void (__thiscall **v49)(vostok::render::base_scene_view *, int); // [esp+64h] [ebp-23Ch]
  int v50; // [esp+68h] [ebp-238h]
  vostok::logging::processor processor; // [esp+6Ch] [ebp-234h] BYREF
  _DWORD *v52; // [esp+70h] [ebp-230h]
  _DWORD v53[2]; // [esp+74h] [ebp-22Ch] BYREF
  float v54; // [esp+7Ch] [ebp-224h] BYREF
  float v55; // [esp+80h] [ebp-220h]
  _DWORD v56[2]; // [esp+84h] [ebp-21Ch] BYREF
  _DWORD v57[2]; // [esp+8Ch] [ebp-214h] BYREF
  int v58; // [esp+94h] [ebp-20Ch]
  unsigned __int8 str1[512]; // [esp+A0h] [ebp-200h] BYREF

  v3 = vostok::core::g_log_file;
  line = (void (__thiscall *)(vostok::render::stage_screen_space_reflections *))vostok::core::g_log_file;
  vostok::logging::log_file::start_transaction((vostok::logging::log_file *)this, (int)vostok::core::g_log_file);
  v4 = ((int (__thiscall *)(vostok::render::base_scene_view *))scene_view[8].m_object->__vftable[1].is_increasing_quality)(scene_view[8].m_object);
  m_object = scene_view[5].m_object;
  v50 = v4;
  v6 = ((int (__thiscall *)(vostok::render::base_scene_view *))m_object->~vostok::render::base_scene_view)(m_object);
  m_last_line = (vostok::render::base_scene_view *)v3->m_last_line;
  v8 = v6;
  v58 = v6;
  v53[0] = m_last_line;
  if ( m_last_line )
  {
    v9 = (_DWORD *)((int (__thiscall *)(vostok::render::base_scene_view *))scene_view[6].m_object->__vftable[1].~vostok::render::base_scene_view)(scene_view[6].m_object);
    v10 = *v9;
    v52 = v9;
    v44 = ((double (__thiscall *)(_DWORD *))*(_DWORD *)(v10 + 4))(v9);
    v47 = LODWORD(v44) & 0x7FFFFFFF;
    v43 = ((int (__thiscall *)(vostok::render::base_scene_view *))scene_view[6].m_object->unlink_child_resource)(scene_view[6].m_object);
    if ( fabs(COERCE_FLOAT(LODWORD(v44) & 0x7FFFFFFF) - *(float *)&scene_view[3].m_object) < 0.0000099999997 )
    {
      if ( !v43 )
      {
        if ( m_last_line != scene_view[13].m_object )
        {
          v11 = ((int (__thiscall *)(vostok::render::base_scene_view *))scene_view[6].m_object->increase_quality_to_target)(scene_view[6].m_object);
          v12 = (vostok::fixed_string<512> *)((int (__thiscall *)(vostok::render::base_scene_view *, int))scene_view[6].m_object->is_increasing_quality)(
                                               scene_view[6].m_object,
                                               v11 - 1);
          v13 = (*((int (__thiscall **)(vostok::fixed_string<512> *))v12->m_begin + 3))(v12);
          v14 = (char *)m_last_line - (char *)scene_view[13].m_object;
          v53[0] = *(_DWORD *)v13;
          v52 = (_DWORD *)v14;
          *(float *)&v53[1] = (double)v14 * 20.0 + *(float *)(v13 + 4);
          (*((void (__thiscall **)(vostok::fixed_string<512> *, _DWORD *))v12->m_begin + 2))(v12, v53);
          scene_view[6].m_object->log_string(scene_view[6].m_object, v12);
          ((void (__thiscall *)(vostok::render::base_scene_view *, vostok::fixed_string<512> *, _DWORD))scene_view[6].m_object->~vostok::render::base_scene_view)(
            scene_view[6].m_object,
            v12,
            0);
          scene_view[13].m_object = m_last_line;
        }
        goto LABEL_28;
      }
      if ( m_last_line == scene_view[13].m_object )
      {
LABEL_28:
        v8 = v58;
        goto LABEL_29;
      }
    }
    ((void (__thiscall *)(vostok::render::base_scene_view *))scene_view[6].m_object->link_child_resource)(scene_view[6].m_object);
    v15 = scene_view[6].m_object;
    scene_view[2].m_object = 0;
    v16 = ((int (__thiscall *)(vostok::render::base_scene_view *))v15->__vftable[1].link_child_resource)(v15);
    v45 = *(float *)((*(int (__thiscall **)(int))(*(_DWORD *)v16 + 12))(v16) + 4);
    v17 = (char *)vostok::math::floor(v45 * 0.050000001);
    v18 = value;
    processor.buffer_ptr = v17;
    if ( v43 && m_last_line > (vostok::render::base_scene_view *)v17 )
    {
      v19 = ((int (__thiscall *)(vostok::render::base_scene_view *))scene_view[7].m_object->increase_quality_to_target)(scene_view[7].m_object);
      v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 12))(v19);
      v18 = (vostok::console_impl *)m_last_line;
      v48 = *(float *)&m_last_line;
      *(float *)&v47 = (double)(unsigned int)m_last_line * 20.0 - v45 + *(float *)(v20 + 4);
    }
    item = vostok::console_impl::get_item(v18, (int)scene_view);
    v22 = (int)item->w(item);
    v48 = FLOAT_1000_0;
    v49 = (void (__thiscall **)(vostok::render::base_scene_view *, int))v47;
    (*(void (__thiscall **)(int, float *))(*(_DWORD *)v22 + 8))(v22, &v48);
    v48 = *(float *)&scene_view[6].m_object->__vftable;
    v23 = ((int (__thiscall *)(vostok::ui::text *, _DWORD))item->w)(item, 0);
    (*v49)(scene_view[6].m_object, v23);
    v24 = vostok::math::floor(*(float *)&v47 * 0.050000001);
    buffer_ptr = processor.buffer_ptr;
    if ( processor.buffer_ptr )
    {
      if ( processor.buffer_ptr > (char *)m_last_line )
        buffer_ptr = (char *)m_last_line;
    }
    else
    {
      buffer_ptr = 0;
    }
    v26 = (vostok::logging::log_file *)((char *)m_last_line - buffer_ptr);
    if ( v24 )
    {
      if ( v24 <= (unsigned int)v26 )
        v26 = (vostok::logging::log_file *)v24;
    }
    else
    {
      v26 = 0;
    }
    vostok::logging::log_file::goto_line(v26, line, (unsigned int)v26);
    if ( buffer_ptr )
    {
      v48 = *(float *)&buffer_ptr;
      do
      {
        v28 = vostok::console_impl::get_item(v27, (int)scene_view);
        v29 = v28->w(v28);
        v56[0] = 0;
        v56[1] = 0;
        v29->set_position(v29, (const vostok::math::float2 *)v56);
        v30 = (int)v28->w(v28);
        *(float *)v57 = FLOAT_1000_0;
        *(float *)&v57[1] = FLOAT_20_0;
        (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v30 + 8))(v30, v57);
        v31 = (int)v28->w(v28);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v31 + 16))(v31, 1);
        v28->set_text_mode(v28, tm_default);
        v28->set_font(v28, fnt_arial);
        processor.buffer_ptr = (char *)str1;
        vostok::logging::log_file::process_next_line<vostok::logging::processor>(
          (vostok::logging::log_file *)line,
          &processor);
        v28->set_text(v28, (const char *)str1);
        strstr(str1, "<Warning>");
        if ( v32 )
        {
          v33 = -939458561;
        }
        else
        {
          strstr(str1, "<ERROR>");
          v33 = v34 != 0 ? -939523841 : -922746881;
        }
        v28->set_color(v28, v33);
        v35 = scene_view[6].m_object->__vftable;
        v36 = ((int (__thiscall *)(vostok::ui::text *, _DWORD))v28->w)(v28, 0);
        ((void (__thiscall *)(vostok::render::base_scene_view *, int))v35->~vostok::render::base_scene_view)(
          scene_view[6].m_object,
          v36);
        --LODWORD(v48);
      }
      while ( v48 != 0.0 );
      m_last_line = (vostok::render::base_scene_view *)v53[0];
    }
    v53[0] = m_last_line;
    v54 = FLOAT_1000_0;
    v55 = (double)(unsigned int)m_last_line * 20.0 - *(float *)&v47 - v45;
    if ( v55 > 0.0 )
    {
      v37 = vostok::console_impl::get_item(v27, (int)scene_view);
      v38 = (int)v37->w(v37);
      (*(void (__thiscall **)(int, float *))(*(_DWORD *)v38 + 8))(v38, &v54);
      v48 = *(float *)&scene_view[6].m_object->__vftable;
      v39 = ((int (__thiscall *)(vostok::ui::text *, _DWORD))v37->w)(v37, 0);
      (*v49)(scene_view[6].m_object, v39);
    }
    v40 = v52;
    scene_view[13].m_object = m_last_line;
    scene_view[3].m_object = (vostok::render::base_scene_view *)v47;
    (*(void (__stdcall **)(_DWORD))(*v40 + 16))(20.0);
    goto LABEL_28;
  }
LABEL_29:
  (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 28))(v8);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v8 + 24))(v8, v50, a3);
  vostok::logging::log_file::end_transaction(v41, (int)line);
}
