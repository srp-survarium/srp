void __thiscall vostok::ui::ui_world::create_dialog(vostok::ui::ui_world *this)
{
  vostok::ui::ui_dialog *v2; // eax

  v2 = (vostok::ui::ui_dialog *)this->m_allocator->call_malloc(this->m_allocator, 72);
  if ( v2 )
    vostok::ui::ui_dialog::ui_dialog(v2, this->m_allocator);
}
