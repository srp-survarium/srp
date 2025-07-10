void __thiscall vostok::ui::ui_text_edit::commit_text(vostok::ui::ui_text_edit *this)
{
  if ( LOWORD(this->m_text.m_text.m_end) != LOWORD(this->m_text.m_text.m_begin) )
    vostok::ui::ui_window::emit_event(
      (vostok::ui::ui_window *)this,
      ev_edit_text_commit,
      &this->vostok::ui::ui_window,
      0,
      0);
}
