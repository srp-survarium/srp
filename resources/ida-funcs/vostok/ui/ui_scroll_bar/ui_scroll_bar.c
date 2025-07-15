void __usercall vostok::ui::ui_scroll_bar::ui_scroll_bar(
        vostok::ui::ui_scroll_bar *this@<edi>,
        vostok::memory::base_allocator *a@<edx>)
{
  vostok::memory::base_allocator *v2; // edx
  vostok::memory::base_allocator *v3; // edx
  vostok::memory::base_allocator *v4; // edx
  vostok::ui::ui_window_vtbl *v5; // eax
  vostok::ui::ui_window_vtbl *v6; // eax
  vostok::ui::ui_window_vtbl *v7; // eax
  vostok::ui::ui_window_vtbl *v8; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v9; // [esp-8h] [ebp-18h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v10; // [esp-8h] [ebp-18h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v11; // [esp-8h] [ebp-18h]
  float v12; // [esp+8h] [ebp-8h] BYREF
  float v13; // [esp+Ch] [ebp-4h]

  vostok::ui::ui_image::ui_image(this, a);
  this->vostok::ui::ui_image::vostok::ui::image::__vftable = (vostok::ui::ui_scroll_bar_vtbl *)&vostok::ui::ui_scroll_bar::`vftable'{for `vostok::ui::image'};
  this->vostok::ui::ui_image::vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_scroll_bar::`vftable'{for `vostok::ui::ui_window'};
  vostok::ui::ui_image::ui_image(&this->m_track_button, v2);
  this->m_source = 0;
  vostok::ui::ui_window::ui_window(&this->m_btn_lt, v3);
  vostok::ui::ui_window::ui_window(&this->m_btn_rb, v4);
  v5 = this->m_btn_lt.__vftable;
  this->m_vertical = 1;
  v5->set_visible(&this->m_btn_lt, 1);
  this->m_btn_rb.set_visible(&this->m_btn_rb, 1);
  this->m_track_button.set_visible(&this->m_track_button.vostok::ui::ui_window, 1);
  v6 = this->m_btn_lt.__vftable;
  v12 = FLOAT_20_0;
  v13 = FLOAT_20_0;
  v6->set_size(&this->m_btn_lt, (const vostok::math::float2 *)&v12);
  v7 = this->m_btn_rb.__vftable;
  v12 = FLOAT_20_0;
  v13 = FLOAT_20_0;
  v7->set_size(&this->m_btn_rb, (const vostok::math::float2 *)&v12);
  v8 = this->m_track_button.__vftable;
  v12 = FLOAT_20_0;
  v13 = FLOAT_20_0;
  v8->set_size(&this->m_track_button.vostok::ui::ui_window, (const vostok::math::float2 *)&v12);
  this->m_track_button.init_texture(&this->m_track_button, "ui_rect");
  this->m_track_button.set_color(&this->m_track_button, -13027015u);
  *(_QWORD *)&v9._M_start = (unsigned int)&this->m_btn_lt;
  vostok::ui::ui_window::add_child(&this->vostok::ui::ui_window, v9);
  *(_QWORD *)&v10._M_start = (unsigned int)&this->m_btn_rb;
  vostok::ui::ui_window::add_child(&this->vostok::ui::ui_window, v10);
  *(_QWORD *)&v11._M_start = &this->m_track_button != 0 ? (unsigned int)&this->m_track_button.vostok::ui::ui_window : 0;
  vostok::ui::ui_window::add_child(&this->vostok::ui::ui_window, v11);
  vostok::ui::ui_window::subscribe_event(
    &this->vostok::ui::ui_window,
    ev_size_changed,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_scroll_bar::on_self_size_changed,
                                                                              (unsigned int)this));
  vostok::ui::ui_image::init_texture(this, "ui_rect");
  this->m_color = -13619152;
}
