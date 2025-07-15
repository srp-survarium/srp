void __userpurge vostok::console_impl::tick(
        vostok::console_impl *this@<ecx>,
        int a2@<eax>,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  vostok::logging::log_file *v3; // ebx
  int v5; // eax
  int (__thiscall ***v6)(_DWORD); // ecx
  vostok::ui::window *m_ui_window; // esi
  unsigned int lines_count; // ebx
  vostok::ui::scroll_source *v9; // eax
  vostok::ui::scroll_source v10; // edx
  char v11; // al
  int v12; // eax
  int v13; // esi
  float *v14; // eax
  vostok::ui::scroll_source *v15; // ecx
  int v16; // ecx
  int v17; // eax
  unsigned int v18; // eax
  vostok::console_impl *v19; // ecx
  int v20; // eax
  int v21; // eax
  vostok::ui::text *item; // esi
  int v23; // eax
  vostok::ui::window *(__thiscall *w)(vostok::ui::text *); // eax
  int v25; // eax
  unsigned int v26; // eax
  vostok::ui::text *v27; // esi
  vostok::console_impl *v28; // ecx
  vostok::ui::window *v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  double v36; // st7
  vostok::ui::text *v37; // esi
  int v38; // eax
  vostok::ui::window *(__thiscall *v39)(vostok::ui::text *); // eax
  int v40; // eax
  vostok::ui::scroll_source *v41; // ecx
  float visible_heighta; // [esp+4Ch] [ebp-44Ch]
  float visible_height; // [esp+4Ch] [ebp-44Ch]
  bool follow_last_line; // [esp+53h] [ebp-445h]
  vostok::logging::log_file *l; // [esp+54h] [ebp-444h]
  float scroll_pos; // [esp+58h] [ebp-440h]
  int v47; // [esp+5Ch] [ebp-43Ch] BYREF
  float v48; // [esp+60h] [ebp-438h]
  vostok::render::ui::renderer *v49; // [esp+64h] [ebp-434h]
  vostok::ui::scroll_source *scroll_v; // [esp+68h] [ebp-430h]
  vostok::math::float2 sz; // [esp+6Ch] [ebp-42Ch] BYREF
  unsigned int need_lines_count[2]; // [esp+74h] [ebp-424h] BYREF
  vostok::math::float2 tail_size; // [esp+7Ch] [ebp-41Ch] BYREF
  _DWORD v54[2]; // [esp+84h] [ebp-414h] BYREF
  vostok::dialog_guard dialog_updater; // [esp+8Ch] [ebp-40Ch]
  char log_str_buffer[1024]; // [esp+98h] [ebp-400h] BYREF

  v3 = vostok::core::g_log_file;
  l = vostok::core::g_log_file;
  vostok::logging::log_file::start_transaction(vostok::core::g_log_file);
  v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 32) + 52))(*(_DWORD *)(a2 + 32));
  v6 = *(int (__thiscall ****)(_DWORD))(a2 + 20);
  v49 = (vostok::render::ui::renderer *)v5;
  m_ui_window = (vostok::ui::window *)(**v6)(v6);
  dialog_updater.m_ui_window = m_ui_window;
  lines_count = vostok::logging::log_file::get_lines_count(v3);
  LODWORD(sz.x) = lines_count;
  if ( !lines_count )
    goto LABEL_6;
  v9 = (vostok::ui::scroll_source *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 24) + 28))(*(_DWORD *)(a2 + 24));
  v10.__vftable = v9->__vftable;
  scroll_v = v9;
  visible_heighta = v10.get_position(v9);
  LODWORD(scroll_pos) = LODWORD(visible_heighta) & 0x7FFFFFFF;
  v11 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 24) + 12))(*(_DWORD *)(a2 + 24));
  follow_last_line = v11;
  if ( fabs(COERCE_FLOAT(LODWORD(visible_heighta) & 0x7FFFFFFF) - *(float *)(a2 + 12)) >= 0.0000099999997 )
    goto LABEL_8;
  if ( !v11 )
  {
    if ( lines_count != *(_DWORD *)(a2 + 52) )
    {
      v12 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 24) + 20))(*(_DWORD *)(a2 + 24));
      v13 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 24) + 24))(*(_DWORD *)(a2 + 24), v12 - 1);
      v14 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v13 + 12))(v13);
      v15 = (vostok::ui::scroll_source *)(lines_count - *(_DWORD *)(a2 + 52));
      sz.x = *v14;
      scroll_v = v15;
      sz.y = (double)(unsigned int)v15 * 20.0 + v14[1];
      (*(void (__thiscall **)(int, vostok::math::float2 *))(*(_DWORD *)v13 + 8))(v13, &sz);
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 24) + 4))(*(_DWORD *)(a2 + 24), v13);
      (***(void (__thiscall ****)(_DWORD, int, _DWORD))(a2 + 24))(*(_DWORD *)(a2 + 24), v13, 0);
      m_ui_window = dialog_updater.m_ui_window;
      *(_DWORD *)(a2 + 52) = lines_count;
    }
LABEL_6:
    m_ui_window->tick(m_ui_window);
    m_ui_window->draw(m_ui_window, v49, scene_view);
    vostok::logging::log_file::end_transaction(l);
    return;
  }
  if ( lines_count != *(_DWORD *)(a2 + 52) )
  {
LABEL_8:
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 24) + 8))(*(_DWORD *)(a2 + 24));
    v16 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(a2 + 8) = 0;
    v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 36))(v16);
    visible_height = *(float *)((*(int (__thiscall **)(int))(*(_DWORD *)v17 + 12))(v17) + 4);
    v18 = vostok::math::floor(visible_height * 0.050000001);
    need_lines_count[0] = v18;
    if ( follow_last_line && lines_count > v18 )
    {
      v20 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 28) + 20))(*(_DWORD *)(a2 + 28));
      v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 12))(v20);
      v19 = (vostok::console_impl *)lines_count;
      v47 = lines_count;
      scroll_pos = (double)lines_count * 20.0 - visible_height + *(float *)(v21 + 4);
    }
    item = vostok::console_impl::get_item(
             v19,
             (const stlp_std::__true_type *)lines_count,
             a2,
             (unsigned int)m_ui_window);
    v23 = (int)item->w(item);
    v47 = 1148846080;
    v48 = scroll_pos;
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v23 + 8))(v23, &v47);
    w = item->w;
    v47 = **(_DWORD **)(a2 + 24);
    v25 = ((int (__thiscall *)(vostok::ui::text *, _DWORD))w)(item, 0);
    (*(void (__thiscall **)(_DWORD, int))LODWORD(v48))(*(_DWORD *)(a2 + 24), v25);
    v26 = vostok::math::floor(scroll_pos * 0.050000001);
    v27 = (vostok::ui::text *)need_lines_count[0];
    if ( need_lines_count[0] )
    {
      if ( need_lines_count[0] > lines_count )
        v27 = (vostok::ui::text *)lines_count;
    }
    else
    {
      v27 = 0;
    }
    if ( v26 )
    {
      if ( v26 > lines_count - (unsigned int)v27 )
        v26 = lines_count - (_DWORD)v27;
    }
    else
    {
      v26 = 0;
    }
    vostok::logging::log_file::goto_line(l, v26);
    if ( v27 )
    {
      v47 = (int)v27;
      do
      {
        v27 = vostok::console_impl::get_item(v28, (const stlp_std::__true_type *)lines_count, a2, (unsigned int)v27);
        v29 = v27->w(v27);
        need_lines_count[0] = 0;
        need_lines_count[1] = 0;
        v29->set_position(v29, (const vostok::math::float2 *)need_lines_count);
        v30 = (int)v27->w(v27);
        v54[0] = 1148846080;
        v54[1] = 1101004800;
        (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v30 + 8))(v30, v54);
        v31 = (int)v27->w(v27);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v31 + 16))(v31, 1);
        v27->set_text_mode(v27, tm_default);
        v27->set_font(v27, fnt_arial);
        vostok::logging::log_file::read_next_line(l, log_str_buffer, 0x400u);
        v27->set_text(v27, log_str_buffer);
        strstr((unsigned __int8 *)log_str_buffer, "<Warning>");
        if ( v32 )
        {
          v33 = -939458561;
        }
        else
        {
          strstr((unsigned __int8 *)log_str_buffer, "<ERROR>");
          v33 = v34 != 0 ? -939523841 : -922746881;
        }
        v27->set_color(v27, v33);
        lines_count = **(_DWORD **)(a2 + 24);
        v35 = ((int (__thiscall *)(vostok::ui::text *, _DWORD))v27->w)(v27, 0);
        (*(void (__thiscall **)(_DWORD, int))lines_count)(*(_DWORD *)(a2 + 24), v35);
        --v47;
      }
      while ( v47 );
      lines_count = LODWORD(sz.x);
    }
    LODWORD(sz.x) = lines_count;
    tail_size.x = 1000.0;
    v36 = (double)lines_count * 20.0 - scroll_pos - visible_height;
    tail_size.y = v36;
    if ( v36 > 0.0 )
    {
      v37 = vostok::console_impl::get_item(v28, (const stlp_std::__true_type *)lines_count, a2, (unsigned int)v27);
      v38 = (int)v37->w(v37);
      (*(void (__thiscall **)(int, vostok::math::float2 *))(*(_DWORD *)v38 + 8))(v38, &tail_size);
      v39 = v37->w;
      v47 = **(_DWORD **)(a2 + 24);
      v40 = ((int (__thiscall *)(vostok::ui::text *, _DWORD))v39)(v37, 0);
      (*(void (__thiscall **)(_DWORD, int))LODWORD(v48))(*(_DWORD *)(a2 + 24), v40);
    }
    v41 = scroll_v;
    *(_DWORD *)(a2 + 52) = lines_count;
    *(float *)(a2 + 12) = scroll_pos;
    ((void (__stdcall *)(_DWORD))v41->set_step_size)(20.0);
    m_ui_window = dialog_updater.m_ui_window;
  }
  m_ui_window->tick(m_ui_window);
  m_ui_window->draw(m_ui_window, v49, scene_view);
  vostok::logging::log_file::end_transaction(l);
}
