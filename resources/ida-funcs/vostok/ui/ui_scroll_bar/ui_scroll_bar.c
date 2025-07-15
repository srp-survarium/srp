void __fastcall vostok::ui::ui_scroll_bar::ui_scroll_bar(
        int a1,
        vostok::memory::base_allocator *a,
        vostok::ui::ui_scroll_bar *this)
{
  vostok::ui::ui_scroll_bar *v3; // ebp
  vostok::memory::base_allocator *v4; // edx
  vostok::memory::base_allocator *v5; // edx
  vostok::ui::ui_window *p_m_btn_rb; // edi
  void (__thiscall *set_visible)(struct vostok::ui::ui_window *, bool); // edx
  void (__thiscall *set_size)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  void (__thiscall *v9)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  void (__thiscall *v10)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // eax
  void (__thiscall *set_parent)(struct vostok::ui::ui_window *, vostok::ui::window *); // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *M_finish; // ecx
  void (__thiscall *v13)(struct vostok::ui::ui_window *, vostok::ui::window *); // edx
  void **v14; // eax
  vostok::ui::ui_scroll_bar *v15; // edi
  void (__thiscall *set_color)(struct vostok::ui::ui_scroll_bar *, unsigned int); // eax
  void **v17; // eax
  const stlp_std::__true_type *v18; // [esp+20h] [ebp-18h]
  unsigned int v19; // [esp+24h] [ebp-14h]
  bool v20; // [esp+28h] [ebp-10h]
  unsigned int __x; // [esp+30h] [ebp-8h] BYREF
  int v22; // [esp+34h] [ebp-4h]

  v3 = this;
  vostok::ui::ui_image::ui_image(this, a);
  v3->vostok::ui::ui_image::vostok::ui::image::__vftable = (vostok::ui::ui_scroll_bar_vtbl *)&vostok::ui::ui_scroll_bar::`vftable'{for `vostok::ui::image'};
  v3->vostok::ui::ui_image::vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_scroll_bar::`vftable'{for `vostok::ui::ui_window'};
  this = (vostok::ui::ui_scroll_bar *)&v3->m_track_button;
  vostok::ui::ui_image::ui_image(&v3->m_track_button, v4);
  v3->m_source = 0;
  v3->m_btn_lt.m_allocator = v5;
  v3->m_btn_lt.__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  v3->m_btn_lt.m_position.x = 0.0;
  v3->m_btn_lt.m_position.y = 0.0;
  v3->m_btn_lt.m_size.x = 0.0;
  v3->m_btn_lt.m_size.y = 0.0;
  v3->m_btn_lt.m_parent = 0;
  v3->m_btn_lt.m_event_manager._M_impl._M_start = 0;
  v3->m_btn_lt.m_event_manager._M_impl._M_finish = 0;
  v3->m_btn_lt.m_event_manager._M_impl._M_end_of_storage.m_allocator = v5;
  v3->m_btn_lt.m_event_manager._M_impl._M_end_of_storage._M_data = 0;
  v3->m_btn_lt.m_b_visible = 0;
  v3->m_btn_lt.m_b_orphan = 1;
  v3->m_btn_lt.m_b_focused = 0;
  v3->m_btn_lt.m_b_tab_stop = 0;
  v3->m_btn_lt.m_children._M_impl._M_start = 0;
  v3->m_btn_lt.m_children._M_impl._M_finish = 0;
  p_m_btn_rb = &v3->m_btn_rb;
  v3->m_btn_lt.m_children._M_impl._M_end_of_storage.m_allocator = v5;
  v3->m_btn_lt.m_children._M_impl._M_end_of_storage._M_data = 0;
  v3->m_btn_rb.m_allocator = v5;
  v3->m_btn_rb.__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  v3->m_btn_rb.m_position.x = 0.0;
  v3->m_btn_rb.m_position.y = 0.0;
  v3->m_btn_rb.m_size.x = 0.0;
  v3->m_btn_rb.m_size.y = 0.0;
  v3->m_btn_rb.m_parent = 0;
  v3->m_btn_rb.m_event_manager._M_impl._M_start = 0;
  v3->m_btn_rb.m_event_manager._M_impl._M_finish = 0;
  v3->m_btn_rb.m_event_manager._M_impl._M_end_of_storage.m_allocator = v5;
  v3->m_btn_rb.m_event_manager._M_impl._M_end_of_storage._M_data = 0;
  v3->m_btn_rb.m_b_visible = 0;
  v3->m_btn_rb.m_b_orphan = 1;
  v3->m_btn_rb.m_b_focused = 0;
  v3->m_btn_rb.m_b_tab_stop = 0;
  v3->m_btn_rb.m_children._M_impl._M_start = 0;
  v3->m_btn_rb.m_children._M_impl._M_finish = 0;
  v3->m_btn_rb.m_children._M_impl._M_end_of_storage.m_allocator = v5;
  v3->m_btn_rb.m_children._M_impl._M_end_of_storage._M_data = 0;
  set_visible = v3->m_btn_lt.set_visible;
  v3->m_vertical = 1;
  set_visible(&v3->m_btn_lt, 1);
  v3->m_btn_rb.set_visible(&v3->m_btn_rb, 1);
  v3->m_track_button.set_visible(&v3->m_track_button.vostok::ui::ui_window, 1);
  set_size = v3->m_btn_lt.set_size;
  __x = 1101004800;
  v22 = 1101004800;
  set_size(&v3->m_btn_lt, (const vostok::math::float2 *)&__x);
  v9 = v3->m_btn_rb.set_size;
  __x = 1101004800;
  v22 = 1101004800;
  v9(&v3->m_btn_rb, (const vostok::math::float2 *)&__x);
  v10 = v3->m_track_button.set_size;
  __x = 1101004800;
  v22 = 1101004800;
  v10(&v3->m_track_button.vostok::ui::ui_window, (const vostok::math::float2 *)&__x);
  this->init_texture(this, "ui_rect");
  this->set_color(this, -13027015u);
  set_parent = v3->m_btn_lt.set_parent;
  __x = (unsigned int)&v3->m_btn_lt;
  set_parent(&v3->m_btn_lt, &v3->vostok::ui::ui_window);
  v3->m_btn_lt.set_orphan(&v3->m_btn_lt, 0);
  M_finish = (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)v3->m_children._M_impl._M_finish;
  if ( M_finish == (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)v3->m_children._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      M_finish,
      (unsigned __int8 **)&v3->m_children,
      (int)M_finish,
      &__x,
      v18,
      v19,
      v20);
  }
  else
  {
    M_finish->_M_start = (unsigned int *)&v3->m_btn_lt;
    ++v3->m_children._M_impl._M_finish;
  }
  v13 = p_m_btn_rb->set_parent;
  __x = (unsigned int)&v3->m_btn_rb;
  v13(&v3->m_btn_rb, &v3->vostok::ui::ui_window);
  p_m_btn_rb->set_orphan(&v3->m_btn_rb, 0);
  v14 = v3->m_children._M_impl._M_finish;
  if ( v14 == v3->m_children._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&__x,
      (unsigned __int8 **)&v3->m_children,
      (int)v14,
      &__x,
      v18,
      v19,
      v20);
  }
  else
  {
    *v14 = p_m_btn_rb;
    ++v3->m_children._M_impl._M_finish;
  }
  v15 = this != 0 ? (vostok::ui::ui_scroll_bar *)&v3->m_track_button.vostok::ui::ui_window : 0;
  set_color = v15->vostok::ui::ui_image::vostok::ui::image::__vftable[2].set_color;
  this = v15;
  set_color(v15, (unsigned int)&v3->vostok::ui::ui_window);
  v15->vostok::ui::ui_image::vostok::ui::image::__vftable[3].init_texture(v15, 0);
  v17 = v3->m_children._M_impl._M_finish;
  if ( v17 == v3->m_children._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&this,
      (unsigned __int8 **)&v3->m_children,
      (int)v17,
      (const unsigned int *)&this,
      v18,
      v19,
      v20);
  }
  else
  {
    *v17 = v15;
    ++v3->m_children._M_impl._M_finish;
  }
  vostok::ui::ui_window::subscribe_event(
    &v3->vostok::ui::ui_window,
    ev_size_changed,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_scroll_bar::on_self_size_changed,
                                                                              (unsigned int)v3));
  vostok::ui::ui_image::init_texture(v3, "ui_rect");
  v3->m_color = -13619152;
}
