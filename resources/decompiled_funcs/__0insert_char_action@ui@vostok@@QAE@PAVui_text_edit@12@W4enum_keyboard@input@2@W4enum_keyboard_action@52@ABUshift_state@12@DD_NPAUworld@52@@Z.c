void __userpurge vostok::ui::insert_char_action::insert_char_action(
        vostok::ui::insert_char_action *this@<ecx>,
        int a2@<eax>,
        vostok::ui::ui_text_edit *parent,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action,
        const vostok::ui::shift_state *state,
        vostok::input::world *c,
        char c_shift,
        bool b_translate,
        vostok::input::world *input_world)
{
  *(_DWORD *)(a2 + 4) = this;
  *(_DWORD *)(a2 + 8) = parent;
  *(_DWORD *)a2 = &vostok::ui::base_edit_action::`vftable';
  *(_DWORD *)(a2 + 12) = 1;
  *(vostok::ui::shift_state *)(a2 + 16) = st;
  *(_DWORD *)(a2 + 20) = c;
  *(_BYTE *)(a2 + 24) = (_BYTE)state;
  *(_DWORD *)a2 = &vostok::ui::insert_char_action::`vftable';
  *(_BYTE *)(a2 + 25) = key;
  *(_BYTE *)(a2 + 26) = action;
}
