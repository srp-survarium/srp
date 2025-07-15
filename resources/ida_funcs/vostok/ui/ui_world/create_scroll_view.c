void __thiscall vostok::ui::ui_world::create_scroll_view(vostok::ui::ui_world *this)
{
  vostok::ui::ui_scroll_view *v2; // eax
  int v3; // ecx

  v2 = (vostok::ui::ui_scroll_view *)this->m_allocator->call_malloc(this->m_allocator, 468);
  if ( v2 )
    vostok::ui::ui_scroll_view::ui_scroll_view(v3, this->m_allocator, v2);
}
