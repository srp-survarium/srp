void __thiscall vostok::ui::ui_text_edit::select_all(vostok::ui::ui_text_edit *this)
{
  this->m_sel_start = 0;
  this->m_sel_end = LOWORD(this->m_text.m_text.m_end) - LOWORD(this->m_text.m_text.m_begin);
}
