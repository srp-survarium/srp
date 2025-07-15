char __thiscall vostok::ui::ui_text_edit::on_focus(
        vostok::ui::ui_text_edit *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_window_vtbl *v5; // eax
  int v6; // eax
  int v7; // eax

  v5 = this->vostok::ui::ui_text<vostok::ui::dynamic_text>::vostok::ui::ui_window::vostok::ui::window::__vftable;
  if ( p1 )
  {
    this->m_last_action = 0;
    v6 = ((int (*)(void))v5->get_root)();
    (*(void (__thiscall **)(int, int, vostok::ui::ui_text_edit *, char (__thiscall *)(vostok::ui::ui_text_edit *, vostok::ui::window *, int, vostok::input::enum_keyboard_action)))(*(_DWORD *)v6 + 84))(
      v6,
      3,
      this,
      vostok::ui::ui_text_edit::on_keyb_action);
  }
  else
  {
    v7 = ((int (*)(void))v5->get_root)();
    (*(void (__thiscall **)(int, int, vostok::ui::ui_text_edit *, char (__thiscall *)(vostok::ui::ui_text_edit *, vostok::ui::window *, int, vostok::input::enum_keyboard_action)))(*(_DWORD *)v7 + 88))(
      v7,
      3,
      this,
      vostok::ui::ui_text_edit::on_keyb_action);
    this->m_last_action = 0;
  }
  return 1;
}
