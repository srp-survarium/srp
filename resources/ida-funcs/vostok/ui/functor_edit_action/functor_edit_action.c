void __userpurge vostok::ui::functor_edit_action::functor_edit_action(
        vostok::ui::functor_edit_action *this@<ecx>,
        int a2@<eax>,
        vostok::ui::ui_text_edit *functor,
        vostok::ui::ui_text_edit *parent,
        const vostok::ui::shift_state *key,
        vostok::input::enum_keyboard_action action,
        const vostok::ui::shift_state *state)
{
  *(_DWORD *)(a2 + 4) = functor;
  *(_DWORD *)(a2 + 8) = parent;
  *(_DWORD *)a2 = &vostok::ui::base_edit_action::`vftable';
  *(_DWORD *)(a2 + 12) = 1;
  *(vostok::ui::shift_state *)(a2 + 16) = (vostok::ui::shift_state)key->m_data.d;
  *(_DWORD *)a2 = &vostok::ui::functor_edit_action::`vftable';
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 24) = this->m_parent;
  *(_DWORD *)(a2 + 20) = this->__vftable;
}
