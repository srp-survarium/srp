void __thiscall vostok::ui::ui_world::create_text_edit(vostok::ui::ui_world *this)
{
  vostok::ui::ui_text_edit *v2; // eax
  vostok::memory::base_allocator *v3; // [esp+0h] [ebp-4h]

  v2 = (vostok::ui::ui_text_edit *)this->m_allocator->call_malloc(this->m_allocator, 688);
  if ( v2 )
    vostok::ui::ui_text_edit::ui_text_edit(this, v2, this->m_allocator, v3);
}
