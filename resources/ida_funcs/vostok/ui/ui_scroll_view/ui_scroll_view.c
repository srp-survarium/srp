void __fastcall vostok::ui::ui_scroll_view::ui_scroll_view(
        int a1,
        vostok::memory::base_allocator *a,
        vostok::ui::ui_scroll_view *this)
{
  vostok::ui::ui_scroll_view *v3; // esi
  vostok::ui::ui_window *v4; // ebx
  vostok::ui::ui_scroll_pad *p_m_pad; // edi
  void (__thiscall *set_parent)(struct vostok::ui::ui_scroll_pad *, vostok::ui::window *); // eax
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *M_finish; // ecx
  void (__thiscall *set_size)(struct vostok::ui::ui_scroll_pad *, const vostok::math::float2 *); // edx
  vostok::ui::ui_window *v9; // ecx
  stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *v10; // ecx
  int (*get_size)(void); // edx
  int v12; // xmm0_4
  void (__thiscall *set_position)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // eax
  void (__thiscall *v14)(struct vostok::ui::ui_window *, const vostok::math::float2 *); // edx
  const stlp_std::__true_type *v15; // [esp+Ch] [ebp-18h]
  unsigned int v16; // [esp+10h] [ebp-14h]
  bool v17; // [esp+14h] [ebp-10h]
  unsigned int __x; // [esp+1Ch] [ebp-8h] BYREF
  int v19; // [esp+20h] [ebp-4h]

  v3 = this;
  this->m_allocator = a;
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  v4 = &this->vostok::ui::ui_window;
  this->m_position = 0;
  this->m_size = 0;
  this->m_parent = 0;
  this->m_event_manager._M_impl._M_start = 0;
  this->m_event_manager._M_impl._M_finish = 0;
  this->m_event_manager._M_impl._M_end_of_storage._M_data = 0;
  this->m_event_manager._M_impl._M_end_of_storage.m_allocator = a;
  this->m_b_visible = 0;
  this->m_b_focused = 0;
  this->m_b_tab_stop = 0;
  this->m_b_orphan = 1;
  this->m_children._M_impl._M_start = 0;
  this->m_children._M_impl._M_finish = 0;
  this->m_children._M_impl._M_end_of_storage._M_data = 0;
  this->m_children._M_impl._M_end_of_storage.m_allocator = a;
  this->vostok::ui::scroll_view::__vftable = (vostok::ui::ui_scroll_view_vtbl *)&vostok::ui::ui_scroll_view::`vftable'{for `vostok::ui::scroll_view'};
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_scroll_view::`vftable'{for `vostok::ui::ui_window'};
  p_m_pad = &this->m_pad;
  this->m_flags = 2;
  this->m_pad.m_allocator = a;
  this->m_pad.m_position = 0;
  this->m_pad.m_size = 0;
  this->m_pad.m_parent = 0;
  this->m_pad.m_event_manager._M_impl._M_start = 0;
  this->m_pad.m_event_manager._M_impl._M_finish = 0;
  this->m_pad.m_event_manager._M_impl._M_end_of_storage._M_data = 0;
  this->m_pad.m_event_manager._M_impl._M_end_of_storage.m_allocator = a;
  this->m_pad.m_b_visible = 0;
  this->m_pad.m_b_focused = 0;
  this->m_pad.m_b_tab_stop = 0;
  this->m_pad.m_b_orphan = 1;
  this->m_pad.m_children._M_impl._M_start = 0;
  this->m_pad.m_children._M_impl._M_finish = 0;
  this->m_pad.m_children._M_impl._M_end_of_storage._M_data = 0;
  this->m_pad.m_children._M_impl._M_end_of_storage.m_allocator = a;
  this->m_pad.__vftable = (vostok::ui::ui_scroll_pad_vtbl *)&vostok::ui::ui_scroll_pad::`vftable';
  vostok::ui::ui_scroll_bar::ui_scroll_bar(2, a, &this->m_scroll_bar_v);
  this->m_scroll_source_v.__vftable = (vostok::ui::ui_scroll_v_source_vtbl *)&vostok::ui::ui_scroll_v_source::`vftable';
  this->m_scroll_source_v.m_pad = 0;
  this->m_scroll_source_v.m_step = 0.0;
  set_parent = this->m_pad.set_parent;
  __x = (unsigned int)&this->m_pad;
  ((void (__stdcall *)(vostok::ui::ui_window *))set_parent)(&this->vostok::ui::ui_window);
  ((void (__stdcall *)(_DWORD))this->m_pad.set_orphan)(0);
  M_finish = (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)this->m_children._M_impl._M_finish;
  if ( M_finish == (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)this->m_children._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      M_finish,
      (unsigned __int8 **)&this->m_children,
      (int)M_finish,
      &__x,
      v15,
      v16,
      v17);
    v3 = this;
  }
  else
  {
    M_finish->_M_start = (unsigned int *)p_m_pad;
    ++this->m_children._M_impl._M_finish;
  }
  p_m_pad->set_visible(p_m_pad, 1);
  set_size = p_m_pad->set_size;
  __x = 1101004800;
  v19 = 1101004800;
  set_size(p_m_pad, (const vostok::math::float2 *)&__x);
  if ( v3 == (vostok::ui::ui_scroll_view *)-136 )
  {
    __x = 0;
    v9 = 0;
  }
  else
  {
    v9 = &v3->m_scroll_bar_v.vostok::ui::ui_window;
    __x = (unsigned int)&v3->m_scroll_bar_v.vostok::ui::ui_window;
  }
  v9->set_parent(v9, v4);
  (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)__x + 48))(__x, 0);
  v10 = (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)this->m_children._M_impl._M_finish;
  if ( v10 == (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)this->m_children._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
      v10,
      (unsigned __int8 **)&this->m_children,
      (int)v10,
      &__x,
      v15,
      v16,
      v17);
    v3 = this;
  }
  else
  {
    v10->_M_start = (unsigned int *)__x;
    ++this->m_children._M_impl._M_finish;
  }
  v3->m_scroll_source_v.m_pad = p_m_pad;
  v3->m_scroll_bar_v.m_source = &v3->m_scroll_source_v;
  get_size = (int (*)(void))v3->m_scroll_bar_v.m_btn_lt.get_size;
  v3->m_scroll_bar_v.m_vertical = 1;
  v12 = *(_DWORD *)(get_size() + 4);
  set_position = v3->m_scroll_bar_v.m_track_button.set_position;
  __x = 0;
  v19 = v12;
  set_position(&v3->m_scroll_bar_v.m_track_button.vostok::ui::ui_window, (const vostok::math::float2 *)&__x);
  v14 = v3->m_scroll_bar_v.set_size;
  __x = 1101004800;
  v19 = 0;
  v14(&v3->m_scroll_bar_v.vostok::ui::ui_window, (const vostok::math::float2 *)&__x);
  v3->m_scroll_bar_v.set_visible(&v3->m_scroll_bar_v.vostok::ui::ui_window, 1);
  vostok::ui::ui_window::subscribe_event(
    v4,
    ev_size_changed,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_scroll_view::on_self_size_changed,
                                                                              (unsigned int)v3));
  vostok::ui::ui_window::subscribe_event(
    v4,
    ev_focus,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_scroll_view::on_focus,
                                                                              (unsigned int)v3));
  ((void (__thiscall *)(vostok::ui::ui_scroll_pad *, _DWORD, vostok::ui::ui_scroll_view *, bool (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))p_m_pad->subscribe_event)(
    p_m_pad,
    0,
    v3,
    vostok::ui::ui_scroll_view::on_pad_size_changed);
  ((void (__thiscall *)(vostok::ui::ui_scroll_pad *, int, vostok::ui::ui_scroll_view *, bool (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))p_m_pad->subscribe_event)(
    p_m_pad,
    1,
    v3,
    vostok::ui::ui_scroll_view::on_pad_pos_changed);
  v3->m_b_tab_stop = 1;
}
