void __usercall vostok::ui::font_manager::~font_manager(vostok::ui::font_manager *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ecx

  v2 = a2[2];
  a2[1] = &vostok::ui::ui_font::`vftable';
  if ( a2[7] )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 24))(v2, a2[7]);
    a2[7] = 0;
  }
}
