int __thiscall vostok::ui::ui_scroll_view::get_follow_last_line(vostok::ui::ui_scroll_view *this)
{
  return (this->m_flags >> 1) & 1;
}
