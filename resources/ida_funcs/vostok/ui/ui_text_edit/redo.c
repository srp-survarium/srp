void __thiscall vostok::ui::ui_text_edit::redo(vostok::ui::ui_text_edit *this)
{
  void (__thiscall *set_text)(struct vostok::ui::ui_text<vostok::ui::dynamic_text> *, const char *); // edx
  vostok::ui::undo_ *M_finish; // edi

  if ( this->m_redo_history._M_impl._M_start != this->m_redo_history._M_impl._M_finish )
  {
    set_text = this->set_text;
    M_finish = this->m_redo_history._M_impl._M_finish;
    this->m_b_redo = 1;
    set_text(&this->vostok::ui::ui_text<vostok::ui::dynamic_text>, M_finish[-1].text);
    this->set_caret_position(this, M_finish[-1].caret, 0);
    if ( this->m_redo_history._M_impl._M_finish[-1].text )
      this->m_allocator->call_free(this->m_allocator, (void *)this->m_redo_history._M_impl._M_finish[-1].text);
    --this->m_redo_history._M_impl._M_finish;
    this->m_b_redo = 0;
  }
}
