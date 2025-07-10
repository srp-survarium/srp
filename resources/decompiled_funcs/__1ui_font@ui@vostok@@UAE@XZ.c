void __usercall vostok::ui::ui_font::~ui_font(vostok::ui::ui_font *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ecx

  v2 = a2[1];
  *a2 = &vostok::ui::ui_font::`vftable';
  if ( a2[6] )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 24))(v2, a2[6]);
    a2[6] = 0;
  }
}
