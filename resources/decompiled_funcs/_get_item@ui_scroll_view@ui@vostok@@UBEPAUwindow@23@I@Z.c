vostok::ui::window *__thiscall vostok::ui::ui_scroll_view::get_item(vostok::ui::ui_scroll_view *this, unsigned int idx)
{
  return this->m_pad.get_child(&this->m_pad, idx);
}
