int __usercall sub_4887F0@<eax>(int a1@<eax>, int a2@<ecx>, int a3, int a4, int a5)
{
  int v5; // ebp
  int v6; // esi
  int v8; // ecx
  int v9; // ebx
  int *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // eax
  int v19; // ecx
  int v20; // ecx
  int v21; // esi
  int v22; // eax
  int v23; // edx
  int result; // eax
  int i; // ecx
  int v26; // [esp+10h] [ebp-428h]
  int v27; // [esp+14h] [ebp-424h]
  int v28; // [esp+1Ch] [ebp-41Ch]
  int v29; // [esp+24h] [ebp-414h]
  int v30; // [esp+30h] [ebp-408h]
  int v31; // [esp+34h] [ebp-404h]
  _DWORD v32[256]; // [esp+38h] [ebp-400h]

  v5 = a4;
  v6 = *(_DWORD *)(a1 + 112);
  v8 = a3;
  v9 = a2 + 28;
  v30 = v6;
  v27 = 0x7FFFFFFF;
  v26 = 0;
  if ( v6 > 0 )
  {
    v10 = *(int **)(a1 + 116);
    v31 = *v10;
    v29 = v10[1];
    v28 = v10[2];
    while ( 1 )
    {
      v11 = *(unsigned __int8 *)(v31 + v26);
      if ( v11 < v8 )
        break;
      v17 = v8 + 24;
      if ( v11 > v8 + 24 )
      {
        v12 = 2 * (v11 - v17) * 2 * (v11 - v17);
        goto LABEL_5;
      }
      v12 = 0;
      if ( v11 > (2 * a3 + 24) >> 1 )
        goto LABEL_5;
      v13 = v11 - v17;
LABEL_6:
      v14 = *(unsigned __int8 *)(v29 + v26);
      v15 = 2 * v13 * 2 * v13;
      if ( v14 < a2 )
      {
        v12 += 3 * (v14 - a2) * 3 * (v14 - a2);
        v5 = a4;
        v16 = v14 - v9;
        goto LABEL_15;
      }
      if ( v14 > v9 )
      {
        v12 += 3 * (v14 - v9) * 3 * (v14 - v9);
        v5 = a4;
LABEL_14:
        v16 = v14 - a2;
        goto LABEL_15;
      }
      if ( v14 > (a2 + 28 + a2) >> 1 )
        goto LABEL_14;
      v16 = v14 - v9;
LABEL_15:
      v18 = 3 * v16 * 3 * v16 + v15;
      v19 = *(unsigned __int8 *)(v28 + v26);
      if ( v19 >= v5 )
      {
        if ( v19 <= v5 + 24 )
        {
          if ( v19 <= (2 * a4 + 24) >> 1 )
          {
            v20 = v19 - (v5 + 24);
            goto LABEL_22;
          }
        }
        else
        {
          v12 += (v19 - (v5 + 24)) * (v19 - (v5 + 24));
          v5 = a4;
        }
        v20 = v19 - v5;
      }
      else
      {
        v12 += (v19 - v5) * (v19 - v5);
        v5 = a4;
        v20 = v19 - (a4 + 24);
      }
LABEL_22:
      v21 = v20 * v20;
      v8 = a3;
      v22 = v21 + v18;
      v32[v26] = v12;
      v23 = v27;
      if ( v22 < v27 )
      {
        v23 = v22;
        v27 = v22;
      }
      ++v26;
      v6 = v30;
      if ( v26 >= v30 )
        goto LABEL_29;
    }
    v12 = 2 * (v11 - v8) * 2 * (v11 - v8);
    v8 += 24;
LABEL_5:
    v13 = v11 - v8;
    goto LABEL_6;
  }
  v23 = 0x7FFFFFFF;
LABEL_29:
  result = 0;
  for ( i = 0; i < v6; ++i )
  {
    if ( v32[i] <= v23 )
    {
      *(_BYTE *)(result + a5) = i;
      ++result;
    }
  }
  return result;
}
