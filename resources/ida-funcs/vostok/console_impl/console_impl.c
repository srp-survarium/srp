void __usercall vostok::console_impl::console_impl(
        vostok::console_impl *this@<esi>,
        vostok::ui::world *uw@<ecx>,
        vostok::memory::base_allocator *a@<eax>)
{
  vostok::ui::world *m_ui_world; // ecx
  float *v4; // eax
  vostok::ui::world *v5; // ecx
  vostok::ui::dialog *v6; // eax
  void (__thiscall ***v7)(_DWORD, float *); // eax
  vostok::ui::window *v8; // eax
  vostok::ui::image *v9; // edi
  int v10; // eax
  vostok::ui::window *v11; // eax
  int v12; // eax
  vostok::ui::window *v13; // eax
  vostok::ui::image_vtbl *v14; // edx
  int v15; // eax
  vostok::ui::scroll_view *v16; // eax
  vostok::ui::window *v17; // eax
  vostok::ui::window *v18; // eax
  vostok::ui::window *v19; // eax
  vostok::ui::window *v20; // eax
  vostok::ui::scroll_view *m_ui_view; // ecx
  vostok::ui::window_vtbl *v22; // edi
  vostok::ui::scroll_view_vtbl *v23; // edx
  int v24; // eax
  vostok::ui::text_edit *v25; // eax
  const vostok::math::float4x4 *v26; // xmm1_4
  vostok::ui::window *v27; // eax
  vostok::ui::window *v28; // eax
  vostok::ui::window *v29; // eax
  vostok::ui::text *v30; // eax
  vostok::ui::text *v31; // eax
  vostok::ui::text *v32; // eax
  vostok::ui::image *v33; // edi
  vostok::ui::window *v34; // eax
  vostok::ui::image_vtbl *v35; // edx
  int v36; // eax
  vostok::ui::window *v37; // eax
  int v38; // eax
  vostok::ui::window *v39; // eax
  vostok::ui::image_vtbl *v40; // edx
  int v41; // eax
  vostok::ui::window *v42; // eax
  vostok::ui::text_edit *m_text_edit; // ecx
  vostok::ui::window_vtbl *v44; // edi
  vostok::ui::text_edit_vtbl *v45; // edx
  int v46; // eax
  vostok::ui::text *v47; // eax
  vostok::ui::window *v48; // eax
  vostok::ui::window *v49; // eax
  vostok::ui::image *v50; // eax
  vostok::ui::window *v51; // eax
  vostok::ui::window *v52; // eax
  vostok::ui::window *v53; // eax
  vostok::ui::window *v54; // ebx
  void (__thiscall **p_add_child)(vostok::ui::window *, int); // edi
  int v56; // eax
  vostok::ui::image *v57; // eax
  vostok::ui::window *v58; // eax
  vostok::ui::window *v59; // eax
  vostok::ui::window *v60; // eax
  vostok::ui::window *v61; // [esp+B0h] [ebp-28h]
  void (__thiscall **p_set_size)(vostok::ui::window *, int); // [esp+B0h] [ebp-28h]
  vostok::ui::window *v63; // [esp+B4h] [ebp-24h]
  vostok::ui::window *v64; // [esp+B4h] [ebp-24h]
  float x; // [esp+B8h] [ebp-20h] BYREF
  float v66; // [esp+BCh] [ebp-1Ch]
  vostok::math::float2 screen_size; // [esp+C0h] [ebp-18h] BYREF
  vostok::math::float2 edit_pos; // [esp+C8h] [ebp-10h] BYREF
  vostok::math::float2 edit_size; // [esp+D0h] [ebp-8h] BYREF

  this->m_allocator = a;
  this->m_ui_world = uw;
  this->__vftable = (vostok::console_impl_vtbl *)&vostok::console_impl::`vftable';
  this->m_self_deactivate = 1;
  this->m_last_position = 0.0;
  this->m_last_item = 0;
  this->m_text_items._M_impl._M_start = 0;
  this->m_text_items._M_impl._M_finish = 0;
  this->m_text_items._M_impl._M_end_of_storage.m_allocator = a;
  this->m_text_items._M_impl._M_end_of_storage._M_data = 0;
  this->m_last_log_count = 0;
  this->m_executed_history._M_impl._M_start = 0;
  this->m_executed_history._M_impl._M_finish = 0;
  this->m_executed_history._M_impl._M_end_of_storage.m_allocator = a;
  this->m_executed_history._M_impl._M_end_of_storage._M_data = 0;
  this->m_tips._M_impl._M_start = 0;
  this->m_tips._M_impl._M_finish = 0;
  this->m_tips._M_impl._M_end_of_storage.m_allocator = a;
  this->m_tips._M_impl._M_end_of_storage._M_data = 0;
  m_ui_world = this->m_ui_world;
  this->m_tips_mode = tm_none;
  this->m_active = 0;
  v4 = (float *)m_ui_world->base_screen_size(m_ui_world);
  v5 = this->m_ui_world;
  screen_size.x = *v4;
  screen_size.y = v4[1] * 0.5;
  v6 = v5->create_dialog(v5);
  this->m_ui_dialog = v6;
  v7 = (void (__thiscall ***)(_DWORD, float *))v6->w(v6);
  x = 0.0;
  v66 = 0.0;
  (**v7)(v7, &x);
  v8 = this->m_ui_dialog->w(this->m_ui_dialog);
  v8->set_size(v8, &screen_size);
  v9 = this->m_ui_world->create_image(this->m_ui_world);
  v9->init_texture(v9, "ui_rect");
  v9->set_color(v9, -2059386816u);
  v61 = this->m_ui_dialog->w(this->m_ui_dialog);
  v63 = v9->w(v9);
  LODWORD(x) = &v63->set_size;
  v10 = (int)v61->get_size(v61);
  (*(void (__thiscall **)(vostok::ui::window *, int))LODWORD(x))(v63, v10);
  v11 = v9->w(v9);
  x = 0.0;
  v66 = 0.0;
  v11->set_position(v11, (const vostok::math::float2 *)&x);
  v12 = (int)v9->w(v9);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 16))(v12, 1);
  v13 = this->m_ui_dialog->w(this->m_ui_dialog);
  v14 = v9->__vftable;
  x = *(float *)&v13;
  v15 = ((int (__thiscall *)(vostok::ui::image *, int))v14->w)(v9, 1);
  (*(void (__thiscall **)(float, int))LODWORD(x))(COERCE_FLOAT(LODWORD(v66)), v15);
  v16 = this->m_ui_world->create_scroll_view(this->m_ui_world);
  this->m_ui_view = v16;
  v17 = v16->w(v16);
  x = *(float *)&clear_value;
  v66 = *(float *)&clear_value;
  v17->set_position(v17, (const vostok::math::float2 *)&x);
  v18 = this->m_ui_view->w(this->m_ui_view);
  x = screen_size.x - 2.0;
  v66 = screen_size.y - 30.0;
  v18->set_size(v18, (const vostok::math::float2 *)&x);
  v19 = this->m_ui_view->w(this->m_ui_view);
  v19->set_visible(v19, 1);
  v20 = this->m_ui_dialog->w(this->m_ui_dialog);
  m_ui_view = this->m_ui_view;
  v22 = v20->__vftable;
  v23 = m_ui_view->__vftable;
  x = *(float *)&v20;
  v24 = ((int (__thiscall *)(vostok::ui::scroll_view *, int))v23->w)(m_ui_view, 1);
  ((void (__thiscall *)(float, int))v22->add_child)(COERCE_FLOAT(LODWORD(v66)), v24);
  v25 = this->m_ui_world->create_text_edit(this->m_ui_world);
  v26 = clear_value;
  edit_pos.y = screen_size.y - 20.0;
  edit_size.x = screen_size.x - 2.0;
  this->m_text_edit = v25;
  LODWORD(edit_pos.x) = v26;
  edit_size.y = 18.0;
  v27 = v25->w(v25);
  v27->set_position(v27, &edit_pos);
  v28 = this->m_text_edit->w(this->m_text_edit);
  v28->set_size(v28, &edit_size);
  v29 = this->m_text_edit->w(this->m_text_edit);
  v29->set_visible(v29, 1);
  v30 = this->m_text_edit->text(this->m_text_edit);
  v30->set_font(v30, fnt_arial);
  v31 = this->m_text_edit->text(this->m_text_edit);
  v31->set_color(v31, -986896u);
  v32 = this->m_text_edit->text(this->m_text_edit);
  v32->set_text_mode(v32, tm_default);
  v33 = this->m_ui_world->create_image(this->m_ui_world);
  v33->init_texture(v33, "ui_rect");
  v33->set_color(v33, 1144337717u);
  v34 = this->m_text_edit->w(this->m_text_edit);
  v35 = v33->__vftable;
  x = *(float *)&v34;
  v64 = v35->w(v33);
  p_set_size = (void (__thiscall **)(vostok::ui::window *, int))&v64->set_size;
  v36 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(x) + 12))(COERCE_FLOAT(LODWORD(x)));
  (*p_set_size)(v64, v36);
  v37 = v33->w(v33);
  v37->set_position(v37, &edit_pos);
  v38 = (int)v33->w(v33);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v38 + 16))(v38, 1);
  v39 = this->m_ui_dialog->w(this->m_ui_dialog);
  v40 = v33->__vftable;
  x = *(float *)&v39;
  v41 = ((int (__thiscall *)(vostok::ui::image *, int))v40->w)(v33, 1);
  (*(void (__thiscall **)(float, int))LODWORD(x))(COERCE_FLOAT(LODWORD(v66)), v41);
  v42 = this->m_ui_dialog->w(this->m_ui_dialog);
  m_text_edit = this->m_text_edit;
  v44 = v42->__vftable;
  v45 = m_text_edit->__vftable;
  x = *(float *)&v42;
  v46 = ((int (__thiscall *)(vostok::ui::text_edit *, int))v45->w)(m_text_edit, 1);
  ((void (__thiscall *)(float, int))v44->add_child)(COERCE_FLOAT(LODWORD(v66)), v46);
  v47 = this->m_text_edit->text(this->m_text_edit);
  v47->set_text(v47, (const char *)&buf);
  v48 = this->m_text_edit->w(this->m_text_edit);
  ((void (__thiscall *)(vostok::ui::window *, int, vostok::console_impl *, char (__thiscall *)(vostok::console_impl *, vostok::ui::window *, int, int)))v48->subscribe_event)(
    v48,
    6,
    this,
    vostok::console_impl::on_text_commit);
  v49 = this->m_text_edit->w(this->m_text_edit);
  ((void (__thiscall *)(vostok::ui::window *, int, vostok::console_impl *, bool (__thiscall *)(vostok::console_impl *, vostok::ui::window *, int, int)))v49->subscribe_event)(
    v49,
    5,
    this,
    vostok::console_impl::on_text_changed);
  v50 = this->m_ui_world->create_image(this->m_ui_world);
  this->m_ui_tips_view = v50;
  v50->init_texture(v50, "ui_rect");
  this->m_ui_tips_view->set_color(this->m_ui_tips_view, -2060110539u);
  v51 = this->m_ui_tips_view->w(this->m_ui_tips_view);
  x = edit_pos.x;
  v66 = edit_pos.y + edit_size.y;
  v51->set_position(v51, (const vostok::math::float2 *)&x);
  v52 = this->m_ui_tips_view->w(this->m_ui_tips_view);
  x = 100.0;
  v66 = 100.0;
  v52->set_size(v52, (const vostok::math::float2 *)&x);
  v53 = this->m_ui_tips_view->w(this->m_ui_tips_view);
  v53->set_visible(v53, 0);
  v54 = this->m_ui_dialog->w(this->m_ui_dialog);
  p_add_child = (void (__thiscall **)(vostok::ui::window *, int))&v54->add_child;
  v56 = ((int (__thiscall *)(vostok::ui::image *, int))this->m_ui_tips_view->w)(this->m_ui_tips_view, 1);
  (*p_add_child)(v54, v56);
  v57 = this->m_ui_world->create_image(this->m_ui_world);
  this->m_ui_tips_view_hl = v57;
  v57->init_texture(v57, "ui_rect");
  this->m_ui_tips_view_hl->set_color(this->m_ui_tips_view_hl, 2132803584u);
  v58 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  x = 0.0;
  v66 = 0.0;
  v58->set_position(v58, (const vostok::math::float2 *)&x);
  v59 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  x = 100.0;
  v66 = 100.0;
  v59->set_size(v59, (const vostok::math::float2 *)&x);
  v60 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  v60->set_visible(v60, 1);
}
