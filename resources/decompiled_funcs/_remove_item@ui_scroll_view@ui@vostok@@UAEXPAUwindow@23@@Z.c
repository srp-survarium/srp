void __thiscall vostok::ui::ui_scroll_view::remove_item(vostok::ui::ui_scroll_view *this, vostok::ui::window *w)
{
  this->m_pad.remove_child(&this->m_pad, w);
  this->m_flags |= 1u;
}
