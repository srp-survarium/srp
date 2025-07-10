void __usercall vostok::ui::ui_text<vostok::ui::static_text>::ui_text<vostok::ui::static_text>(
        vostok::ui::ui_text<vostok::ui::static_text> *this@<esi>,
        vostok::ui::ui_world *w@<edi>)
{
  vostok::memory::base_allocator *m_allocator; // edx

  m_allocator = w->m_allocator;
  this->m_allocator = m_allocator;
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  this->m_position = 0;
  this->m_size = 0;
  this->m_parent = 0;
  this->m_event_manager._M_impl._M_start = 0;
  this->m_event_manager._M_impl._M_finish = 0;
  this->m_event_manager._M_impl._M_end_of_storage.m_allocator = m_allocator;
  this->m_event_manager._M_impl._M_end_of_storage._M_data = 0;
  this->m_b_visible = 0;
  this->m_b_orphan = 1;
  this->m_b_focused = 0;
  this->m_b_tab_stop = 0;
  this->m_children._M_impl._M_start = 0;
  this->m_children._M_impl._M_finish = 0;
  this->m_children._M_impl._M_end_of_storage.m_allocator = m_allocator;
  this->m_children._M_impl._M_end_of_storage._M_data = 0;
  this->vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::static_text>_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::text'};
  this->vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::static_text>::`vftable'{for `vostok::ui::ui_window'};
  this->m_text.m_text.m_pointer.m_object = 0;
  this->m_font = 0;
  this->m_color = -1;
  this->m_ui_world = w;
  vostok::ui::ui_window::subscribe_event(
    &this->vostok::ui::ui_window,
    ev_text_changed,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_text<vostok::ui::static_text>::on_text_changed,
                                                                              (unsigned int)this));
}
