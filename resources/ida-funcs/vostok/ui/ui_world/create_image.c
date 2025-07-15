void __thiscall vostok::ui::ui_world::create_image(vostok::ui::ui_world *this)
{
  vostok::ui::ui_image *v2; // eax

  v2 = (vostok::ui::ui_image *)this->m_allocator->call_malloc(this->m_allocator, 92);
  if ( v2 )
    vostok::ui::ui_image::ui_image(v2, this->m_allocator);
}
