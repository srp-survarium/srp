void __thiscall vostok::ui::ui_text_edit::~ui_text_edit(vostok::ui::ui_text_edit *this)
{
  void **M_finish; // ebx
  void **M_start; // edi
  vostok::vectora<vostok::ui::undo_> *p_m_undo_history; // ebx
  vostok::ui::ui_window *v5; // esi
  vostok::vectora<vostok::ui::window *> *p_m_children; // edi
  survarium::link_resolver **v7; // eax

  M_finish = this->m_edit_actions._M_impl._M_finish;
  M_start = this->m_edit_actions._M_impl._M_start;
  this->vostok::ui::text_edit::__vftable = (vostok::ui::ui_text_edit_vtbl *)&vostok::ui::ui_text_edit::`vftable';
  this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *)&vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::text'};
  for ( this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::ui_window'};
        M_start != M_finish;
        ++M_start )
  {
    if ( *M_start )
    {
      this->m_allocator->call_free(this->m_allocator, *M_start);
      *M_start = 0;
    }
  }
  p_m_undo_history = &this->m_undo_history;
  vostok::ui::clear_history_container(&this->m_undo_history, this->m_allocator);
  vostok::ui::clear_history_container(&this->m_redo_history, this->m_allocator);
  if ( this->m_redo_history._M_impl._M_start )
    this->m_redo_history._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_redo_history._M_impl._M_end_of_storage.m_allocator,
      this->m_redo_history._M_impl._M_start);
  if ( p_m_undo_history->_M_impl._M_start )
    this->m_undo_history._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_undo_history._M_impl._M_end_of_storage.m_allocator,
      p_m_undo_history->_M_impl._M_start);
  if ( this->m_edit_actions._M_impl._M_start )
    this->m_edit_actions._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_edit_actions._M_impl._M_end_of_storage.m_allocator,
      this->m_edit_actions._M_impl._M_start);
  this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *)&vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::text'};
  v5 = &this->vostok::ui::ui_window;
  v5->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text<vostok::ui::dynamic_text>::`vftable'{for `vostok::ui::ui_window'};
  p_m_children = &v5->m_children;
  v5->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  while ( v5->m_children._M_impl._M_start != v5->m_children._M_impl._M_finish )
  {
    v7 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::back(&v5->m_children._M_impl);
    v5->remove_child(v5, (vostok::ui::window *)*v7);
  }
  if ( p_m_children->_M_impl._M_start )
    v5->m_children._M_impl._M_end_of_storage.m_allocator->call_free(
      v5->m_children._M_impl._M_end_of_storage.m_allocator,
      p_m_children->_M_impl._M_start);
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::ui::typed_handlers *>,vostok::ui::typed_handlers>(
    (stlp_std::reverse_iterator<vostok::ui::typed_handlers *>)v5->m_event_manager._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::ui::typed_handlers *>)v5->m_event_manager._M_impl._M_start);
  if ( v5->m_event_manager._M_impl._M_start )
    v5->m_event_manager._M_impl._M_end_of_storage.m_allocator->call_free(
      v5->m_event_manager._M_impl._M_end_of_storage.m_allocator,
      v5->m_event_manager._M_impl._M_start);
}
