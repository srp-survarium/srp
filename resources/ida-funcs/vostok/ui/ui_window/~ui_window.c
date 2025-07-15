void __thiscall vostok::ui::ui_window::~ui_window(vostok::ui::ui_window *this)
{
  this->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  vostok::ui::ui_window::remove_all_children(this);
  if ( this->m_children._M_impl._M_start )
    this->m_children._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_children._M_impl._M_end_of_storage.m_allocator,
      this->m_children._M_impl._M_start);
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::ui::typed_handlers *>,vostok::ui::typed_handlers>(
    (stlp_std::reverse_iterator<vostok::ui::typed_handlers *>)this->m_event_manager._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::ui::typed_handlers *>)this->m_event_manager._M_impl._M_start);
  if ( this->m_event_manager._M_impl._M_start )
    this->m_event_manager._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_event_manager._M_impl._M_end_of_storage.m_allocator,
      this->m_event_manager._M_impl._M_start);
}
