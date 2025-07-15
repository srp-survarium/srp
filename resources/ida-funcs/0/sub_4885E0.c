int __usercall sub_4885E0@<eax>(int *a1@<eax>, int a2, int a3)
{
  int v3; // ebp
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  int v8; // eax
  int v9; // edi
  unsigned __int16 *v10; // ebp
  int v11; // edx
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int result; // eax
  int v18; // [esp+10h] [ebp-38h]
  int v19; // [esp+14h] [ebp-34h]
  int v20; // [esp+18h] [ebp-30h]
  int v21; // [esp+1Ch] [ebp-2Ch]
  int v22; // [esp+20h] [ebp-28h]
  int v23; // [esp+24h] [ebp-24h]
  unsigned __int16 *v24; // [esp+28h] [ebp-20h]
  int v25; // [esp+2Ch] [ebp-1Ch]
  int v26; // [esp+30h] [ebp-18h]
  int v27; // [esp+38h] [ebp-10h]
  int v28; // [esp+40h] [ebp-8h]
  int v29; // [esp+44h] [ebp-4h]

  v3 = a1[5];
  v4 = a2;
  v5 = a1[2];
  v6 = a1[1];
  v22 = a1[3];
  v7 = a1[4];
  v8 = *a1;
  v9 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v29 = v6;
  v28 = v5;
  v27 = v7;
  v23 = v3;
  v26 = v8;
  if ( v8 <= v6 )
  {
    v18 = 8 * v8 + 4;
    do
    {
      if ( v5 <= v22 )
      {
        v10 = (unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 440) + 24) + 4 * v8) + 2 * (v7 + 32 * v5));
        v11 = v23;
        v12 = v22 - v5 + 1;
        v13 = 4 * v5 + 2;
        v24 = v10;
        v25 = v12;
        do
        {
          if ( v7 <= v11 )
          {
            v14 = 8 * v7 + 4;
            v15 = v11 - v7 + 1;
            do
            {
              v16 = *v10++;
              if ( v16 )
              {
                v19 += v16 * v18;
                v20 += v16 * v13;
                v9 += v16;
                v21 += v16 * v14;
                v7 = v27;
              }
              v14 += 8;
              --v15;
            }
            while ( v15 );
            v5 = v28;
            v11 = v23;
            v12 = v25;
          }
          v10 = v24 + 32;
          v13 += 4;
          --v12;
          v24 += 32;
          v25 = v12;
        }
        while ( v12 );
        v4 = a2;
        v6 = v29;
        v8 = v26;
      }
      v18 += 8;
      v26 = ++v8;
    }
    while ( v8 <= v6 );
  }
  *(_BYTE *)(a3 + **(_DWORD **)(v4 + 116)) = ((v9 >> 1) + v19) / v9;
  *(_BYTE *)(a3 + *(_DWORD *)(*(_DWORD *)(v4 + 116) + 4)) = ((v9 >> 1) + v20) / v9;
  result = ((v9 >> 1) + v21) / v9;
  *(_BYTE *)(a3 + *(_DWORD *)(*(_DWORD *)(v4 + 116) + 8)) = result;
  return result;
}
