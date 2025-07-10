void __usercall vostok::ui::font_manager::font_manager(
        vostok::ui::font_manager *this@<edi>,
        vostok::memory::base_allocator *a@<eax>,
        vostok::ui::ui_font *a3@<ecx>)
{
  float v3; // xmm0_4

  v3 = SNaN;
  this->m_allocator = a;
  this->m_font.m_allocator = a;
  this->m_font.__vftable = (vostok::ui::ui_font_vtbl *)&vostok::ui::ui_font::`vftable';
  this->m_font.m_ts_size.x = v3;
  this->m_font.m_ts_size.y = v3;
  this->m_font.m_char_map = 0;
  vostok::ui::ui_font::init_font(a3, &this->m_font.__vftable);
}
