_DWORD *__cdecl sub_374770(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  int v3; // ebx
  unsigned int v4; // edi
  _DWORD *small; // esi
  int v6; // ecx

  v3 = a1[1];
  v4 = a3;
  if ( a3 > 0x3B9AC9F0 )
    sub_374620((int)a1, 3);
  if ( (a3 & 7) != 0 )
    v4 = 8 - (a3 & 7) + a3;
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*a1 + 20) = 15;
    *(_DWORD *)(*a1 + 24) = a2;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  small = (_DWORD *)jpeg_get_small((int)a1, v4 + 16);
  if ( !small )
    sub_374620((int)a1, 4);
  *(_DWORD *)(v3 + 76) += v4 + 16;
  v6 = *(_DWORD *)(v3 + 4 * a2 + 60);
  small[1] = v4;
  *small = v6;
  small[2] = 0;
  *(_DWORD *)(v3 + 4 * a2 + 60) = small;
  return small + 4;
}
