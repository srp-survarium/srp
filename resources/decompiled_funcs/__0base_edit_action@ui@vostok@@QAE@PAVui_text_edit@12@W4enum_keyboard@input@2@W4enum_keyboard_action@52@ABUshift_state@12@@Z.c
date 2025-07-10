void __userpurge vostok::ui::base_edit_action::base_edit_action(
        vostok::ui::base_edit_action *this@<ecx>,
        int a2@<eax>,
        vostok::ui::ui_text_edit *parent,
        vostok::input::enum_keyboard_action key,
        const vostok::ui::shift_state *action,
        const vostok::ui::shift_state *state)
{
  *(_DWORD *)(a2 + 4) = this;
  *(_DWORD *)(a2 + 8) = parent;
  *(_DWORD *)a2 = &vostok::ui::base_edit_action::`vftable';
  *(_DWORD *)(a2 + 12) = key;
  *(vostok::ui::shift_state *)(a2 + 16) = (vostok::ui::shift_state)action->m_data.d;
}
