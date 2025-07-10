void __thiscall vostok::ui::ui_world::create_text(vostok::ui::ui_world *this)
{
  vostok::ui::ui_text<vostok::ui::static_text> *v2; // eax

  v2 = (vostok::ui::ui_text<vostok::ui::static_text> *)this->m_allocator->call_malloc(this->m_allocator, 92);
  if ( v2 )
    vostok::ui::ui_text<vostok::ui::static_text>::ui_text<vostok::ui::static_text>(v2, this);
}
