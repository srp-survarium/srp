void __thiscall vostok::ui::ui_world::create_scroll_view(vostok::ui::ui_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  vostok::ui::ui_scroll_view *v4; // eax

  m_allocator = this->m_allocator;
  v3 = type_info::raw_name(&vostok::ui::ui_scroll_view `RTTI Type Descriptor');
  v4 = (vostok::ui::ui_scroll_view *)m_allocator->call_malloc(
                                       m_allocator,
                                       468u,
                                       v3,
                                       "vostok::ui::ui_world::create_scroll_view",
                                       ".\\ui_world_factory.cpp",
                                       45u);
  if ( v4 )
    vostok::ui::ui_scroll_view::ui_scroll_view(v4, this->m_allocator);
}
