char __cdecl sub_376BE0(_DWORD *a1, int a2)
{
  _DWORD *v3; // edi
  char result; // al
  int v5; // eax
  int v6; // edx
  int v7; // ebx
  bool v8; // cc
  int v9; // ebp
  int v10; // ecx
  _WORD *v11; // eax
  int v12; // [esp+8h] [ebp-18h]
  unsigned __int8 *v13; // [esp+Ch] [ebp-14h] BYREF
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  _DWORD *v17; // [esp+1Ch] [ebp-4h]
  _WORD *v18; // [esp+24h] [ebp+4h]

  v3 = (_DWORD *)a1[106];
  v12 = 1 << a1[95];
  if ( !a1[63] || v3[10] || (result = sub_376710(a1)) != 0 )
  {
    v5 = a1[6];
    v6 = *(_DWORD *)(v5 + 4);
    v7 = 0;
    v8 = a1[81] <= 0;
    v9 = v3[2];
    v13 = *(unsigned __int8 **)v5;
    v10 = v3[3];
    v17 = a1;
    v14 = v6;
    if ( v8 )
    {
LABEL_11:
      *(_DWORD *)a1[6] = v13;
      *(_DWORD *)(a1[6] + 4) = v14;
      --v3[10];
      v3[2] = v9;
      v3[3] = v10;
      return 1;
    }
    while ( 1 )
    {
      v11 = *(_WORD **)(a2 + 4 * v7);
      v18 = v11;
      if ( v10 < 1 )
      {
        if ( !sub_376530(&v13, v9, v10, 1) )
          return 0;
        v9 = v15;
        v10 = v16;
        v11 = v18;
      }
      if ( ((v9 >> --v10) & 1) != 0 )
        *v11 |= v12;
      if ( ++v7 >= a1[81] )
        goto LABEL_11;
    }
  }
  return result;
}
