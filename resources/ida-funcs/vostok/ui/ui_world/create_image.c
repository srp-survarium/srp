void __thiscall vostok::ui::ui_world::create_image(vostok::ui::ui_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  vostok::ui::ui_image *v4; // eax

  m_allocator = this->m_allocator;
  v3 = type_info::raw_name(&vostok::ui::ui_image `RTTI Type Descriptor');
  v4 = (vostok::ui::ui_image *)m_allocator->call_malloc(
                                 m_allocator,
                                 92u,
                                 v3,
                                 "vostok::ui::ui_world::create_image",
                                 ".\\ui_world_factory.cpp",
                                 40u);
  if ( v4 )
    vostok::ui::ui_image::ui_image(v4, this->m_allocator);
}
