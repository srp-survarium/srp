void __thiscall vostok::ui::ui_world::create_progress_bar(vostok::ui::ui_world *this)
{
  void *v2; // eax

  v2 = this->m_allocator->call_malloc(this->m_allocator, 152);
  if ( v2 )
    vostok::ui::ui_progress_bar::ui_progress_bar((vostok::ui::ui_progress_bar *)this, (int)v2);
}
