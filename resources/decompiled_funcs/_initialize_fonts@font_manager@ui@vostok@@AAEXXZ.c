void __usercall vostok::ui::font_manager::initialize_fonts(vostok::ui::font_manager *this@<ecx>, int a2@<eax>)
{
  vostok::ui::ui_font::init_font((vostok::ui::ui_font *)this, (_DWORD *)(a2 + 4));
}
