char __thiscall vostok::ui::ui_text_edit::on_focus(
        vostok::ui::ui_text_edit *this,
        vostok::ui::window *w,
        int p1,
        int p2)
{
  vostok::ui::ui_window *v5; // ecx
  vostok::ui::window *(__thiscall *get_root)(struct vostok::ui::ui_window *); // edx
  int v7; // eax
  int v9; // eax

  v5 = &this->vostok::ui::ui_window;
  if ( p1 )
  {
    get_root = v5->get_root;
    this->m_last_action = 0;
    v7 = (int)get_root(v5);
    (*(void (__thiscall **)(int, int, vostok::ui::ui_text_edit *, char (__userpurge *)@<al>(vostok::ui::ui_text_edit *@<ecx>, const vostok::ui::shift_state *@<esi>, vostok::ui::window *, int, vostok::input::enum_keyboard_action)))(*(_DWORD *)v7 + 84))(
      v7,
      3,
      this,
      vostok::ui::ui_text_edit::on_keyb_action);
  }
  else
  {
    v9 = (int)v5->get_root(v5);
    (*(void (__thiscall **)(int, int, vostok::ui::ui_text_edit *, char (__userpurge *)@<al>(vostok::ui::ui_text_edit *@<ecx>, const vostok::ui::shift_state *@<esi>, vostok::ui::window *, int, vostok::input::enum_keyboard_action)))(*(_DWORD *)v9 + 88))(
      v9,
      3,
      this,
      vostok::ui::ui_text_edit::on_keyb_action);
    this->m_last_action = 0;
  }
  return 1;
}
