void __usercall vostok::ui::ui_scroll_view::ui_scroll_view(
        vostok::ui::ui_scroll_view *this@<esi>,
        vostok::memory::base_allocator *a@<edx>)
{
  _DWORD *v2; // eax
  vostok::ui::ui_scroll_pad *p_m_pad; // ebx
  vostok::memory::base_allocator *v4; // edx
  vostok::memory::base_allocator *v5; // edx
  vostok::ui::ui_scroll_pad_vtbl *v6; // eax
  vostok::ui::ui_window *v7; // eax
  vostok::ui::ui_window_vtbl *v8; // eax
  float v9; // xmm0_4
  vostok::ui::ui_window_vtbl *v10; // eax
  vostok::ui::ui_window_vtbl *v11; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v12; // [esp-4h] [ebp-18h]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v13; // [esp-4h] [ebp-18h]
  float v14; // [esp+Ch] [ebp-8h] BYREF
  float v15; // [esp+10h] [ebp-4h]

  vostok::ui::ui_window::ui_window(&this->vostok::ui::ui_window, a);
  *v2 = &vostok::ui::ui_scroll_view::`vftable'{for `vostok::ui::ui_window'};
  this->m_flags = 2;
  p_m_pad = &this->m_pad;
  this->vostok::ui::scroll_view::__vftable = (vostok::ui::ui_scroll_view_vtbl *)&vostok::ui::ui_scroll_view::`vftable'{for `vostok::ui::scroll_view'};
  vostok::ui::ui_window::ui_window(&this->m_pad, v4);
  this->m_pad.__vftable = (vostok::ui::ui_scroll_pad_vtbl *)&vostok::ui::ui_scroll_pad::`vftable';
  vostok::ui::ui_scroll_bar::ui_scroll_bar(&this->m_scroll_bar_v, v5);
  this->m_scroll_source_v.m_pad = 0;
  *(_QWORD *)&v12._M_start = (unsigned int)&this->m_pad;
  this->m_scroll_source_v.__vftable = (vostok::ui::ui_scroll_v_source_vtbl *)&vostok::ui::ui_scroll_v_source::`vftable';
  this->m_scroll_source_v.m_step = 0.0;
  vostok::ui::ui_window::add_child(&this->vostok::ui::ui_window, v12);
  this->m_pad.set_visible(&this->m_pad, 1);
  v6 = this->m_pad.__vftable;
  v14 = FLOAT_20_0;
  v15 = FLOAT_20_0;
  v6->set_size(&this->m_pad, (const vostok::math::float2 *)&v14);
  if ( this == (vostok::ui::ui_scroll_view *)-136 )
    v7 = 0;
  else
    v7 = &this->m_scroll_bar_v.vostok::ui::ui_window;
  *(_QWORD *)&v13._M_start = (unsigned int)v7;
  vostok::ui::ui_window::add_child(&this->vostok::ui::ui_window, v13);
  this->m_scroll_source_v.m_pad = p_m_pad;
  this->m_scroll_bar_v.m_source = &this->m_scroll_source_v;
  v8 = this->m_scroll_bar_v.m_btn_lt.__vftable;
  this->m_scroll_bar_v.m_vertical = 1;
  v9 = *(float *)(((int (*)(void))v8->get_size)() + 4);
  v10 = this->m_scroll_bar_v.m_track_button.__vftable;
  v14 = 0.0;
  v15 = v9;
  v10->set_position(&this->m_scroll_bar_v.m_track_button.vostok::ui::ui_window, (const vostok::math::float2 *)&v14);
  v11 = this->m_scroll_bar_v.__vftable;
  v14 = FLOAT_20_0;
  v15 = 0.0;
  v11->set_size(&this->m_scroll_bar_v.vostok::ui::ui_window, (const vostok::math::float2 *)&v14);
  this->m_scroll_bar_v.set_visible(&this->m_scroll_bar_v.vostok::ui::ui_window, 1);
  vostok::ui::ui_window::subscribe_event(
    &this->vostok::ui::ui_window,
    ev_size_changed,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_scroll_view::on_self_size_changed,
                                                                              (unsigned int)this));
  vostok::ui::ui_window::subscribe_event(
    &this->vostok::ui::ui_window,
    ev_focus,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_scroll_view::on_focus,
                                                                              (unsigned int)this));
  ((void (__thiscall *)(vostok::ui::ui_scroll_pad *, _DWORD, vostok::ui::ui_scroll_view *, bool (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))p_m_pad->subscribe_event)(
    &this->m_pad,
    0,
    this,
    vostok::ui::ui_scroll_view::on_pad_pos_changed);
  ((void (__thiscall *)(vostok::ui::ui_scroll_pad *, int, vostok::ui::ui_scroll_view *, bool (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))p_m_pad->subscribe_event)(
    &this->m_pad,
    1,
    this,
    vostok::ui::ui_scroll_view::on_pad_pos_changed);
  this->m_b_tab_stop = 1;
}
