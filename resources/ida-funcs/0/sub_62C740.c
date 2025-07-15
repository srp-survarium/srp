_BYTE *__cdecl sub_62C740(_BYTE *a1, __int16 a2, int a3)
{
  _BYTE *v4; // [esp+8h] [ebp+8h]

  *a1 = 112;
  v4 = a1 + 1;
  *v4++ = -1;
  *v4 = (unsigned __int16)(a2 - *(_WORD *)(a3 + 24)) >> 8;
  v4[1] = a2 - *(_BYTE *)(a3 + 24);
  v4[2] = 0;
  v4[3] = 0;
  return v4 + 4;
}
