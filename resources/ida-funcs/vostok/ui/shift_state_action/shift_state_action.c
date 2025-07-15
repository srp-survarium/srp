void __userpurge vostok::ui::shift_state_action::shift_state_action(
        vostok::ui::shift_state_action *this@<ecx>,
        int a2@<eax>,
        vostok::ui::ui_text_edit *parent,
        vostok::ui::enum_shift_state key,
        vostok::ui::enum_shift_state state)
{
  *(_DWORD *)(a2 + 4) = this;
  *(_DWORD *)(a2 + 8) = parent;
  *(_DWORD *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 16) = -86;
  *(_DWORD *)a2 = &vostok::ui::shift_state_action::`vftable';
  *(_DWORD *)(a2 + 20) = key;
}
