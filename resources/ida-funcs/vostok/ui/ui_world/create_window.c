void __thiscall vostok::ui::ui_world::create_window(vostok::ui::ui_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  vostok::ui::ui_window *v4; // eax

  m_allocator = this->m_allocator;
  v3 = type_info::raw_name(&vostok::ui::ui_window `RTTI Type Descriptor');
  v4 = (vostok::ui::ui_window *)m_allocator->call_malloc(
                                  m_allocator,
                                  64u,
                                  v3,
                                  "vostok::ui::ui_world::create_window",
                                  ".\\ui_world_factory.cpp",
                                  20u);
  if ( v4 )
    vostok::ui::ui_window::ui_window(v4, this->m_allocator);
}
