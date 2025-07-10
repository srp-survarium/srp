void __thiscall vostok::ui::ui_scroll_view::set_follow_last_line(vostok::ui::ui_scroll_view *this, bool val)
{
  if ( val )
    this->m_flags |= 2u;
  else
    this->m_flags &= ~2u;
}
