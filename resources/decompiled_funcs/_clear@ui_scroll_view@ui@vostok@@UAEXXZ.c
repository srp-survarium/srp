void __thiscall vostok::ui::ui_scroll_view::clear(vostok::ui::ui_scroll_view *this)
{
  this->m_pad.remove_all_children(&this->m_pad);
  this->m_flags |= 1u;
}
