bool __thiscall vostok::ui::ui_dialog::on_keyboard_action(
        vostok::ui::ui_dialog *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  vostok::ui::ui_base *v4; // esi
  vostok::memory::base_allocator *m_allocator; // edi
  char v6; // al

  if ( key != key_scroll || action != kb_key_down )
    return vostok::ui::ui_window::emit_event(
             (vostok::ui::ui_window *)this,
             ev_keyboard,
             (vostok::ui::window *)&this[-1].vostok::ui::ui_base,
             key,
             action);
  v4 = &this[-1].vostok::ui::ui_base;
  m_allocator = this[-1].m_allocator;
  v6 = ((int (__thiscall *)(vostok::ui::ui_base *))m_allocator[1].__vftable)(&this[-1].vostok::ui::ui_base);
  (*(void (__thiscall **)(vostok::ui::ui_base *, bool))&m_allocator->m_use_memory_monitor)(v4, v6 == 0);
  return 1;
}
