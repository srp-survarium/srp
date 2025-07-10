void __usercall vostok::ui::ui_window::ui_window(
        vostok::ui::ui_window *this@<eax>,
        vostok::memory::base_allocator *a@<edx>)
{
  this->m_allocator = a;
  this->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  this->m_position = 0;
  this->m_size = 0;
  this->m_parent = 0;
  this->m_event_manager._M_impl._M_start = 0;
  this->m_event_manager._M_impl._M_finish = 0;
  this->m_event_manager._M_impl._M_end_of_storage.m_allocator = a;
  this->m_event_manager._M_impl._M_end_of_storage._M_data = 0;
  this->m_b_visible = 0;
  this->m_b_orphan = 1;
  this->m_b_focused = 0;
  this->m_b_tab_stop = 0;
  this->m_children._M_impl._M_start = 0;
  this->m_children._M_impl._M_finish = 0;
  this->m_children._M_impl._M_end_of_storage.m_allocator = a;
  this->m_children._M_impl._M_end_of_storage._M_data = 0;
}
