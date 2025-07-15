void __userpurge vostok::ui::ui_text_edit::ui_text_edit(
        vostok::ui::ui_world *w@<edi>,
        vostok::ui::ui_text_edit *this,
        vostok::memory::base_allocator *mode,
        vostok::memory::base_allocator *a)
{
  vostok::ui::ui_text_edit *v4; // ecx

  vostok::ui::ui_text<vostok::ui::dynamic_text>::ui_text<vostok::ui::dynamic_text>(
    &this->vostok::ui::ui_text<vostok::ui::dynamic_text>,
    w);
  this->vostok::ui::text_edit::__vftable = (vostok::ui::ui_text_edit_vtbl *)&vostok::ui::ui_text_edit::`vftable';
  this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *)&vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::text'};
  this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::ui_window'};
  this->m_edit_actions._M_impl._M_start = 0;
  this->m_edit_actions._M_impl._M_finish = 0;
  this->m_edit_actions._M_impl._M_end_of_storage.m_allocator = mode;
  this->m_edit_actions._M_impl._M_end_of_storage._M_data = 0;
  this->m_last_action = 0;
  this->m_last_action_time = 0.0;
  this->m_undo_history._M_impl._M_start = 0;
  this->m_undo_history._M_impl._M_finish = 0;
  this->m_undo_history._M_impl._M_end_of_storage.m_allocator = mode;
  this->m_undo_history._M_impl._M_end_of_storage._M_data = 0;
  this->m_redo_history._M_impl._M_start = 0;
  this->m_redo_history._M_impl._M_finish = 0;
  this->m_redo_history._M_impl._M_end_of_storage.m_allocator = mode;
  this->m_redo_history._M_impl._M_end_of_storage._M_data = 0;
  this->m_max_chars_count = 255;
  this->m_caret_pos = 0;
  this->m_sel_start = 0;
  this->m_sel_end = 0;
  this->m_cursor_color = -1;
  this->m_b_undo = 0;
  this->m_b_redo = 0;
  this->m_b_insert_mode = 0;
  this->m_shift_state.m_data.dummy = 0;
  vostok::ui::ui_window::subscribe_event(
    &this->vostok::ui::ui_window,
    ev_focus,
    (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>)__PAIR64__(
                                                                              vostok::ui::ui_text_edit::on_focus,
                                                                              (unsigned int)this));
  this->m_b_tab_stop = 1;
  vostok::ui::ui_text_edit::init_internals(v4, (vostok::ui::base_edit_action *)this);
}
