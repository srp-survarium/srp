void __thiscall vostok::ui::ui_text_edit::redo(vostok::ui::ui_text_edit *this)
{
  vostok::ui::undo_ *M_finish; // edi
  char *text; // eax

  if ( this->m_redo_history._M_impl._M_start != this->m_redo_history._M_impl._M_finish )
  {
    M_finish = this->m_redo_history._M_impl._M_finish;
    this->m_b_redo = 1;
    --M_finish;
    ((void (__stdcall *)(const char *))this->set_text)(M_finish->text);
    this->set_caret_position(this, M_finish->caret, 0);
    text = (char *)this->m_redo_history._M_impl._M_finish[-1].text;
    if ( text )
      this->m_allocator->call_free(
        this->m_allocator,
        text,
        "vostok::ui::ui_text_edit::redo",
        ".\\ui_text_edit.cpp",
        341u);
    --this->m_redo_history._M_impl._M_finish;
    this->m_b_redo = 0;
  }
}
