void __usercall vostok::ui::ui_font::init_font(vostok::ui::ui_font *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ecx
  int v3; // edi
  int v4; // eax
  unsigned int v5; // edx
  vostok::math::float4 *v6; // ecx
  float *v7; // eax

  v2 = a2[1];
  a2[2] = 1101529088;
  a2[5] = 256;
  a2[3] = 1132462080;
  a2[4] = 1132462080;
  v3 = 0;
  if ( a2[6] )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 24))(v2, a2[6]);
    a2[6] = 0;
  }
  v4 = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)a2[1] + 16))(a2[1], 12 * a2[5]);
  v5 = 0;
  a2[6] = v4;
  if ( a2[5] )
  {
    v6 = vostok::ui::arial_21_symb;
    do
    {
      v7 = (float *)(v3 + a2[6]);
      *v7 = v6->x;
      ++v5;
      v3 += 12;
      v7[1] = v6->y;
      v7[2] = v6->z - v6->x;
      ++v6;
    }
    while ( v5 < a2[5] );
  }
}
