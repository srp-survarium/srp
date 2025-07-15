void __usercall vostok::ui::ui_font::init_font(vostok::ui::ui_font *this@<ecx>, int a2@<esi>)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edi
  char *v5; // eax
  int v6; // eax
  int v7; // edi
  unsigned int v8; // edx
  vostok::math::float4 *v9; // ecx
  float *v10; // eax

  v2 = *(_DWORD *)(a2 + 4);
  *(float *)(a2 + 8) = FLOAT_21_0;
  *(_DWORD *)(a2 + 20) = 256;
  *(float *)(a2 + 12) = FLOAT_256_0;
  *(float *)(a2 + 16) = FLOAT_256_0;
  v3 = *(_DWORD *)(a2 + 24);
  if ( v3 )
  {
    (*(void (__thiscall **)(int, int, const char *, const char *, int))(*(_DWORD *)v2 + 24))(
      v2,
      v3,
      "vostok::ui::ui_font::init_font",
      ".\\ui_font.cpp",
      35);
    *(_DWORD *)(a2 + 24) = 0;
  }
  v4 = *(_DWORD *)(a2 + 4);
  v5 = type_info::raw_name(&vostok::math::float3 `RTTI Type Descriptor');
  v6 = (*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v4 + 16))(
         v4,
         12 * *(_DWORD *)(a2 + 20),
         v5,
         "vostok::ui::ui_font::init_font",
         ".\\ui_font.cpp",
         36);
  v7 = 0;
  v8 = 0;
  *(_DWORD *)(a2 + 24) = v6;
  if ( *(_DWORD *)(a2 + 20) )
  {
    v9 = vostok::ui::arial_21_symb;
    do
    {
      v10 = (float *)(v7 + *(_DWORD *)(a2 + 24));
      *v10 = v9->x;
      ++v8;
      v7 += 12;
      v10[1] = v9->y;
      v10[2] = v9->z - v9->x;
      ++v9;
    }
    while ( v8 < *(_DWORD *)(a2 + 20) );
  }
}
