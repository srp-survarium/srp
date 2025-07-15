void __thiscall vostok::ui::ui_world::create_text_edit(vostok::ui::ui_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  unsigned int v4; // eax
  vostok::ui::ui_text_edit *v5; // ecx
  vostok::memory::base_allocator *v6; // [esp+0h] [ebp-8h]

  m_allocator = this->m_allocator;
  v3 = type_info::raw_name(&vostok::ui::ui_text_edit `RTTI Type Descriptor');
  v4 = (unsigned int)m_allocator->call_malloc(
                       m_allocator,
                       688u,
                       v3,
                       "vostok::ui::ui_world::create_text_edit",
                       ".\\ui_world_factory.cpp",
                       35u);
  if ( v4 )
    vostok::ui::ui_text_edit::ui_text_edit(v5, v4, this, (vostok::ui::enum_text_edit_mode)this->m_allocator, v6);
}
