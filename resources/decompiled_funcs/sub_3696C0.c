unsigned __int8 __cdecl sub_3696C0(int a1, unsigned __int8 *a2, unsigned __int8 *a3)
{
  unsigned __int8 result; // al
  int v4; // [esp+0h] [ebp-2Ch]
  int v5; // [esp+4h] [ebp-28h]
  int v6; // [esp+8h] [ebp-24h]
  int v7; // [esp+10h] [ebp-1Ch]
  int v8; // [esp+14h] [ebp-18h]
  int v9; // [esp+18h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *v11; // [esp+20h] [ebp-Ch]
  int v12; // [esp+24h] [ebp-8h]
  unsigned __int8 v13; // [esp+28h] [ebp-4h]
  unsigned __int8 *i; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v15; // [esp+3Ch] [ebp+10h]

  v11 = &a2[*(_DWORD *)(a1 + 4)];
  v12 = *a3;
  v15 = a3 + 1;
  v13 = v12 + *a2;
  *a2 = v13;
  result = (_BYTE)a2 + 1;
  for ( i = a2 + 1; i < v11; ++i )
  {
    v7 = *v15++;
    v10 = v7 - v12;
    v9 = v13 - v12;
    if ( v7 - v12 >= 0 )
      v6 = v7 - v12;
    else
      v6 = v12 - v7;
    v8 = v6;
    if ( v9 >= 0 )
      v5 = v13 - v12;
    else
      v5 = v12 - v13;
    if ( v9 + v10 >= 0 )
      v4 = v9 + v10;
    else
      v4 = -(v9 + v10);
    if ( v5 < v6 )
    {
      v8 = v5;
      v13 = v7;
    }
    if ( v4 < v8 )
      v13 = v12;
    v12 = v7;
    v13 += *i;
    result = v13;
    *i = v13;
  }
  return result;
}
