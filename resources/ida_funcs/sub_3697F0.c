_BYTE *__cdecl sub_3697F0(int a1, _BYTE *a2, _BYTE *a3)
{
  _BYTE *result; // eax
  int v4; // [esp+0h] [ebp-34h]
  int v5; // [esp+4h] [ebp-30h]
  int v6; // [esp+8h] [ebp-2Ch]
  int v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+14h] [ebp-20h]
  int v9; // [esp+18h] [ebp-1Ch]
  int v10; // [esp+1Ch] [ebp-18h]
  int v11; // [esp+20h] [ebp-14h]
  int v12; // [esp+24h] [ebp-10h]
  char v13; // [esp+28h] [ebp-Ch]
  _BYTE *v14; // [esp+2Ch] [ebp-8h]
  unsigned int v15; // [esp+2Ch] [ebp-8h]
  int v16; // [esp+30h] [ebp-4h]

  v16 = (*(unsigned __int8 *)(a1 + 11) + 7) >> 3;
  v14 = &a2[v16];
  while ( a2 < v14 )
  {
    v13 = *a3++ + *a2;
    *a2++ = v13;
  }
  result = (_BYTE *)a1;
  v15 = (unsigned int)&v14[*(_DWORD *)(a1 + 4) - v16];
  while ( (unsigned int)a2 < v15 )
  {
    v7 = (unsigned __int8)a3[-v16];
    v11 = (unsigned __int8)a2[-v16];
    v8 = (unsigned __int8)*a3++;
    v12 = v8 - v7;
    v10 = v11 - v7;
    if ( v8 - v7 >= 0 )
      v6 = v8 - v7;
    else
      v6 = v7 - v8;
    v9 = v6;
    if ( v10 >= 0 )
      v5 = v11 - v7;
    else
      v5 = v7 - v11;
    if ( v10 + v12 >= 0 )
      v4 = v10 + v12;
    else
      v4 = -(v10 + v12);
    if ( v5 < v6 )
    {
      v9 = v5;
      LOBYTE(v11) = v8;
    }
    if ( v4 < v9 )
      LOBYTE(v11) = v7;
    result = a2;
    *a2++ += v11;
  }
  return result;
}
