void __thiscall vostok::ui::ui_text_edit::~ui_text_edit(vostok::ui::ui_text_edit *this)
{
  void **M_finish; // ebx
  void **M_start; // esi
  vostok::vectora<vostok::ui::undo_> *v4; // ecx
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v5; // ecx
  vostok::vectora<vostok::ui::undo_> *v6; // [esp-4h] [ebp-18h]
  vostok::ui::ui_text<vostok::ui::dynamic_text> *v7; // [esp+Ch] [ebp-8h]
  vostok::vectora<vostok::ui::base_edit_action *> *p_m_edit_actions; // [esp+10h] [ebp-4h]

  M_finish = this->m_edit_actions._M_impl._M_finish;
  v7 = &this->vostok::ui::ui_text<vostok::ui::dynamic_text>;
  this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::text::__vftable = (vostok::ui::ui_text<vostok::ui::dynamic_text>_vtbl *)&vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::text'};
  M_start = this->m_edit_actions._M_impl._M_start;
  this->vostok::ui::text_edit::__vftable = (vostok::ui::ui_text_edit_vtbl *)&vostok::ui::ui_text_edit::`vftable';
  this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_text_edit::`vftable'{for `vostok::ui::ui_window'};
  p_m_edit_actions = &this->m_edit_actions;
  while ( M_start != M_finish )
  {
    if ( *M_start )
    {
      this->m_allocator->call_free(
        this->m_allocator,
        *M_start,
        "vostok::ui::ui_text_edit::~ui_text_edit",
        ".\\ui_text_edit.cpp",
        55u);
      *M_start = 0;
    }
    ++M_start;
  }
  vostok::ui::clear_history_container(&this->m_undo_history, this->m_allocator);
  vostok::ui::clear_history_container(&this->m_redo_history, this->m_allocator);
  vostok::vectora<vostok::ui::undo_>::~vectora<vostok::ui::undo_>(v6, (int)&this->m_redo_history);
  vostok::vectora<vostok::ui::undo_>::~vectora<vostok::ui::undo_>(v4, (int)&this->m_undo_history);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v5,
    (int)p_m_edit_actions);
  vostok::ui::ui_text<vostok::ui::dynamic_text>::~ui_text<vostok::ui::dynamic_text>(v7);
}
