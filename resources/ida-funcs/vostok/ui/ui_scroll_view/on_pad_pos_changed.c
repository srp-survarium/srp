bool __thiscall vostok::ui::ui_scroll_view::on_pad_pos_changed(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_scroll_bar::update_self((vostok::ui::ui_scroll_bar *)this, (int)&this->m_scroll_bar_v);
  return 0;
}
