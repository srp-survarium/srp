void __thiscall vostok::ui::ui_world::create_text(vostok::ui::ui_world *this)
{
  vostok::memory::base_allocator *m_allocator; // esi
  char *v3; // eax
  vostok::ui::ui_text<vostok::ui::static_text> *v4; // eax

  m_allocator = this->m_allocator;
  v3 = type_info::raw_name(&vostok::ui::ui_text<vostok::ui::static_text> `RTTI Type Descriptor');
  v4 = (vostok::ui::ui_text<vostok::ui::static_text> *)m_allocator->call_malloc(
                                                         m_allocator,
                                                         612u,
                                                         v3,
                                                         "vostok::ui::ui_world::create_text",
                                                         ".\\ui_world_factory.cpp",
                                                         30u);
  if ( v4 )
    vostok::ui::ui_text<vostok::ui::static_text>::ui_text<vostok::ui::static_text>(v4, this);
}
