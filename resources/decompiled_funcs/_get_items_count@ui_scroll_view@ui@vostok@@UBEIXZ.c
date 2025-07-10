unsigned int __thiscall vostok::ui::ui_scroll_view::get_items_count(vostok::ui::ui_scroll_view *this)
{
  return this->m_pad.get_child_count(&this->m_pad);
}
