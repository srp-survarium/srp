char __thiscall vostok::ui::ui_scroll_view::on_focus(
        vostok::ui::ui_scroll_view *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::window *v5; // eax
  vostok::ui::window_vtbl *v6; // edx
  char (__thiscall *savedregs)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int); // [esp+8h] [ebp+0h]

  v5 = this->get_root(&this->vostok::ui::ui_window);
  savedregs = vostok::ui::ui_scroll_view::on_keyb_action;
  v6 = v5->__vftable;
  if ( p1 )
    ((void (__thiscall *)(vostok::ui::window *, int, vostok::ui::ui_scroll_view *, char (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))v6->subscribe_event)(
      v5,
      3,
      this,
      vostok::ui::ui_scroll_view::on_keyb_action);
  else
    ((void (__thiscall *)(vostok::ui::window *, int, vostok::ui::ui_scroll_view *, char (__thiscall *)(vostok::ui::ui_scroll_view *, vostok::ui::window *, int, int)))v6->unsubscribe_event)(
      v5,
      3,
      this,
      vostok::ui::ui_scroll_view::on_keyb_action);
  return 1;
}
