void __thiscall vostok::ui::ui_world::create_progress_bar(vostok::ui::ui_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  vostok::ui::ui_progress_bar *v4; // eax

  m_allocator = this->m_allocator;
  v3 = type_info::raw_name(&vostok::ui::ui_progress_bar `RTTI Type Descriptor');
  v4 = (vostok::ui::ui_progress_bar *)m_allocator->call_malloc(
                                        m_allocator,
                                        152u,
                                        v3,
                                        "vostok::ui::ui_world::create_progress_bar",
                                        ".\\ui_world_factory.cpp",
                                        60u);
  if ( v4 )
    vostok::ui::ui_progress_bar::ui_progress_bar(v4, this);
}
