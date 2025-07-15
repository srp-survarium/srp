void __usercall vostok::console_impl::console_impl(
        vostok::console_impl *this@<esi>,
        vostok::ui::world *uw@<eax>,
        vostok::memory::base_allocator *a@<ecx>)
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
  int v13; // eax
  vostok::ui::scroll_view *v14; // eax
  vostok::ui::window *v15; // eax
  vostok::ui::window *v16; // eax
  vostok::ui::window *v17; // eax
  vostok::ui::window *v18; // eax
  vostok::ui::window_vtbl *v19; // edi
  int v20; // eax
  vostok::ui::text_edit *v21; // eax
  float v22; // xmm1_4
  vostok::ui::window *v23; // eax
  vostok::ui::window *v24; // eax
  vostok::ui::window *v25; // eax
  vostok::ui::text *v26; // eax
  vostok::ui::text *v27; // eax
  vostok::ui::text *v28; // eax
  vostok::ui::image *v29; // edi
  int v30; // eax
  vostok::ui::window *v31; // eax
  int v32; // eax
  int v33; // eax
  vostok::ui::window *v34; // eax
  vostok::ui::window_vtbl *v35; // edi
  vostok::ui::text_edit *m_text_edit; // ecx
  int v37; // eax
  vostok::ui::text *v38; // eax
  vostok::ui::window *v39; // eax
  vostok::ui::window *v40; // eax
  vostok::ui::image *v41; // eax
  vostok::ui::window *v42; // eax
  vostok::ui::window *v43; // eax
  vostok::ui::window *v44; // eax
  vostok::ui::window *v45; // eax
  vostok::ui::window_vtbl *v46; // ebx
  vostok::ui::image *m_ui_tips_view; // ecx
  int v48; // eax
  vostok::ui::image *v49; // eax
  vostok::ui::window *v50; // eax
  vostok::ui::window *v51; // eax
  vostok::ui::window *v52; // eax
  vostok::ui::window *v53; // [esp+B0h] [ebp-28h]
  void (__thiscall **p_set_size)(vostok::ui::window *, int); // [esp+B0h] [ebp-28h]
  vostok::ui::window *v55; // [esp+B4h] [ebp-24h]
  vostok::ui::window *v56; // [esp+B4h] [ebp-24h]
  float v57; // [esp+B8h] [ebp-20h] BYREF
  float v58; // [esp+BCh] [ebp-1Ch]
  float v59; // [esp+C0h] [ebp-18h] BYREF
  float v60; // [esp+C4h] [ebp-14h]
  float v61; // [esp+C8h] [ebp-10h] BYREF
  float v62; // [esp+CCh] [ebp-Ch]
  float v63; // [esp+D0h] [ebp-8h] BYREF
  float v64; // [esp+D4h] [ebp-4h]

  this->m_ui_world = uw;
  this->m_allocator = a;
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
  v59 = *v4;
  v60 = v4[1] * 0.5;
  v6 = v5->create_dialog(v5);
  this->m_ui_dialog = v6;
  v7 = (void (__thiscall ***)(_DWORD, float *))v6->w(v6);
  v57 = 0.0;
  v58 = 0.0;
  (**v7)(v7, &v57);
  v8 = this->m_ui_dialog->w(this->m_ui_dialog);
  v8->set_size(v8, (const vostok::math::float2 *)&v59);
  v9 = this->m_ui_world->create_image(this->m_ui_world);
  v9->init_texture(v9, "ui_rect");
  v9->set_color(v9, -2059386816u);
  v53 = this->m_ui_dialog->w(this->m_ui_dialog);
  v55 = v9->w(v9);
  LODWORD(v57) = &v55->set_size;
  v10 = (int)v53->get_size(v53);
  (*(void (__thiscall **)(vostok::ui::window *, int))LODWORD(v57))(v55, v10);
  v11 = v9->w(v9);
  v57 = 0.0;
  v58 = 0.0;
  v11->set_position(v11, (const vostok::math::float2 *)&v57);
  v12 = (int)v9->w(v9);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 16))(v12, 1);
  v57 = COERCE_FLOAT((int)this->m_ui_dialog->w(this->m_ui_dialog));
  v13 = ((int (__thiscall *)(vostok::ui::image *, int))v9->w)(v9, 1);
  (*(void (__thiscall **)(float, int))LODWORD(v57))(COERCE_FLOAT(LODWORD(v58)), v13);
  v14 = this->m_ui_world->create_scroll_view(this->m_ui_world);
  this->m_ui_view = v14;
  v15 = v14->w(v14);
  v57 = s_bm_current_air_resistance;
  v58 = s_bm_current_air_resistance;
  v15->set_position(v15, (const vostok::math::float2 *)&v57);
  v16 = this->m_ui_view->w(this->m_ui_view);
  v57 = v59 - 2.0;
  v58 = v60 - 30.0;
  v16->set_size(v16, (const vostok::math::float2 *)&v57);
  v17 = this->m_ui_view->w(this->m_ui_view);
  v17->set_visible(v17, 1);
  *(float *)&v18 = COERCE_FLOAT((int)this->m_ui_dialog->w(this->m_ui_dialog));
  v19 = v18->__vftable;
  v57 = *(float *)&v18;
  v20 = ((int (__thiscall *)(vostok::ui::scroll_view *, int))this->m_ui_view->w)(this->m_ui_view, 1);
  ((void (__thiscall *)(float, int))v19->add_child)(COERCE_FLOAT(LODWORD(v58)), v20);
  v21 = this->m_ui_world->create_text_edit(this->m_ui_world);
  v22 = s_bm_current_air_resistance;
  v62 = v60 - 20.0;
  v63 = v59 - 2.0;
  this->m_text_edit = v21;
  v61 = v22;
  v64 = FLOAT_18_0;
  v23 = v21->w(v21);
  v23->set_position(v23, (const vostok::math::float2 *)&v61);
  v24 = this->m_text_edit->w(this->m_text_edit);
  v24->set_size(v24, (const vostok::math::float2 *)&v63);
  v25 = this->m_text_edit->w(this->m_text_edit);
  v25->set_visible(v25, 1);
  v26 = this->m_text_edit->text(this->m_text_edit);
  v26->set_font(v26, fnt_arial);
  v27 = this->m_text_edit->text(this->m_text_edit);
  v27->set_color(v27, -986896u);
  v28 = this->m_text_edit->text(this->m_text_edit);
  v28->set_text_mode(v28, tm_default);
  v29 = this->m_ui_world->create_image(this->m_ui_world);
  v29->init_texture(v29, "ui_rect");
  v29->set_color(v29, 1144337717u);
  v57 = COERCE_FLOAT((int)this->m_text_edit->w(this->m_text_edit));
  v56 = v29->w(v29);
  p_set_size = (void (__thiscall **)(vostok::ui::window *, int))&v56->set_size;
  v30 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v57) + 12))(COERCE_FLOAT(LODWORD(v57)));
  (*p_set_size)(v56, v30);
  v31 = v29->w(v29);
  v31->set_position(v31, (const vostok::math::float2 *)&v61);
  v32 = (int)v29->w(v29);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v32 + 16))(v32, 1);
  v57 = COERCE_FLOAT((int)this->m_ui_dialog->w(this->m_ui_dialog));
  v33 = ((int (__thiscall *)(vostok::ui::image *, int))v29->w)(v29, 1);
  (*(void (__thiscall **)(float, int))LODWORD(v57))(COERCE_FLOAT(LODWORD(v58)), v33);
  *(float *)&v34 = COERCE_FLOAT((int)this->m_ui_dialog->w(this->m_ui_dialog));
  v35 = v34->__vftable;
  m_text_edit = this->m_text_edit;
  v57 = *(float *)&v34;
  v37 = ((int (__thiscall *)(vostok::ui::text_edit *, int))m_text_edit->w)(m_text_edit, 1);
  ((void (__thiscall *)(float, int))v35->add_child)(COERCE_FLOAT(LODWORD(v58)), v37);
  v38 = this->m_text_edit->text(this->m_text_edit);
  v38->set_text(v38, uri);
  v39 = this->m_text_edit->w(this->m_text_edit);
  ((void (__thiscall *)(vostok::ui::window *, int, vostok::console_impl *, char (__thiscall *)(vostok::console_impl *, vostok::ui::window *, int, int)))v39->subscribe_event)(
    v39,
    6,
    this,
    vostok::console_impl::on_text_commit);
  v40 = this->m_text_edit->w(this->m_text_edit);
  ((void (__thiscall *)(vostok::ui::window *, int, vostok::console_impl *, bool (__thiscall *)(vostok::console_impl *, vostok::ui::window *, int, int)))v40->subscribe_event)(
    v40,
    5,
    this,
    vostok::console_impl::on_text_changed);
  v41 = this->m_ui_world->create_image(this->m_ui_world);
  this->m_ui_tips_view = v41;
  v41->init_texture(v41, "ui_rect");
  this->m_ui_tips_view->set_color(this->m_ui_tips_view, -2060110539u);
  v42 = this->m_ui_tips_view->w(this->m_ui_tips_view);
  v57 = v61;
  v58 = v62 + v64;
  v42->set_position(v42, (const vostok::math::float2 *)&v57);
  v43 = this->m_ui_tips_view->w(this->m_ui_tips_view);
  v57 = s_spot_max_distance;
  v58 = s_spot_max_distance;
  v43->set_size(v43, (const vostok::math::float2 *)&v57);
  v44 = this->m_ui_tips_view->w(this->m_ui_tips_view);
  v44->set_visible(v44, 0);
  *(float *)&v45 = COERCE_FLOAT((int)this->m_ui_dialog->w(this->m_ui_dialog));
  v46 = v45->__vftable;
  m_ui_tips_view = this->m_ui_tips_view;
  v57 = *(float *)&v45;
  v48 = ((int (__thiscall *)(vostok::ui::image *, int))m_ui_tips_view->w)(m_ui_tips_view, 1);
  ((void (__thiscall *)(float, int))v46->add_child)(COERCE_FLOAT(LODWORD(v58)), v48);
  v49 = this->m_ui_world->create_image(this->m_ui_world);
  this->m_ui_tips_view_hl = v49;
  v49->init_texture(v49, "ui_rect");
  this->m_ui_tips_view_hl->set_color(this->m_ui_tips_view_hl, 2132803584u);
  v50 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  v57 = 0.0;
  v58 = 0.0;
  v50->set_position(v50, (const vostok::math::float2 *)&v57);
  v51 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  v57 = s_spot_max_distance;
  v58 = s_spot_max_distance;
  v51->set_size(v51, (const vostok::math::float2 *)&v57);
  v52 = this->m_ui_tips_view_hl->w(this->m_ui_tips_view_hl);
  v52->set_visible(v52, 1);
}
