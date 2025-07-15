char __thiscall vostok::ui::ui_scroll_view::on_focus(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::window *v5; // eax

  v5 = this->get_root(&this->vostok::ui::ui_window);
  if ( p1 )
    ((void (__thiscall *)(vostok::ui::window *, int, vostok::ui::ui_scroll_view *, char (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))v5->subscribe_event)(
      v5,
      3,
      this,
      vostok::ui::ui_scroll_view::on_keyb_action);
  else
    ((void (__thiscall *)(vostok::ui::window *, int, vostok::ui::ui_scroll_view *, char (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))v5->unsubscribe_event)(
      v5,
      3,
      this,
      vostok::ui::ui_scroll_view::on_keyb_action);
  return 1;
}
