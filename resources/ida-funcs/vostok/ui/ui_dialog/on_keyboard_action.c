bool __thiscall vostok::ui::ui_dialog::on_keyboard_action(
        vostok::ui::ui_dialog *this,
        vostok::input::world *input_world,
        int key,
        int action)
{
  vostok::ui::ui_base *v4; // edi
  vostok::memory::base_allocator *m_allocator; // esi
  char v6; // al

  if ( key != 70 || action != 1 )
    return vostok::ui::ui_window::process_event(
             (vostok::ui::ui_window *)3,
             (vostok::ui::ui_window *)&this[-1].vostok::ui::ui_base,
             key,
             action) != 0;
  v4 = &this[-1].vostok::ui::ui_base;
  m_allocator = this[-1].m_allocator;
  v6 = ((int (__thiscall *)(vostok::ui::ui_base *))m_allocator[1].__vftable)(&this[-1].vostok::ui::ui_base);
  (*(void (__thiscall **)(vostok::ui::ui_base *, bool))&m_allocator->m_use_memory_monitor)(v4, v6 == 0);
  return 1;
}
