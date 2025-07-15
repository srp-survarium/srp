vostok::ui::dialog *__thiscall vostok::ui::ui_world::create_dialog(vostok::ui::ui_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax

  m_allocator = this->m_allocator;
  v3 = type_info::raw_name(&vostok::ui::ui_dialog `RTTI Type Descriptor');
  v4 = (int)m_allocator->call_malloc(
              m_allocator,
              72u,
              v3,
              "vostok::ui::ui_world::create_dialog",
              ".\\ui_world_factory.cpp",
              25u);
  v5 = (_DWORD *)v4;
  if ( !v4 )
    return 0;
  vostok::ui::ui_window::ui_window((vostok::ui::ui_window *)(v4 + 4), this->m_allocator);
  *v6 = &vostok::ui::ui_dialog::`vftable'{for `vostok::ui::ui_window'};
  *v5 = &vostok::ui::ui_dialog::`vftable'{for `vostok::ui::dialog'};
  v5[17] = &vostok::ui::ui_dialog::`vftable'{for `vostok::input::handler'};
  return (vostok::ui::dialog *)v5;
}
