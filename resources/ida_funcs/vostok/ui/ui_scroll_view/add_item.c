void __thiscall vostok::ui::ui_scroll_view::add_item(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        BOOL adopt)
{
  this->m_pad.add_child(&this->m_pad, w, adopt);
  this->m_flags |= 1u;
}
