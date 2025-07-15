void __usercall vostok::ui::ui_font::~ui_font(vostok::ui::ui_font *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ecx
  int v3; // eax

  v2 = a2[1];
  *a2 = &vostok::ui::ui_font::`vftable';
  v3 = a2[6];
  if ( v3 )
  {
    (*(void (__thiscall **)(int, int, const char *, const char *, int))(*(_DWORD *)v2 + 24))(
      v2,
      v3,
      "vostok::ui::ui_font::~ui_font",
      ".\\ui_font.cpp",
      22);
    a2[6] = 0;
  }
}
