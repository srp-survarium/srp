int __cdecl png_do_encode_alpha(int *a1, int a2, _DWORD *a3)
{
  int result; // eax
  __int16 v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+8h] [ebp-14h]
  int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h]
  _BYTE *v11; // [esp+28h] [ebp+Ch]
  unsigned __int8 *v12; // [esp+28h] [ebp+Ch]

  v10 = *a1;
  if ( (a1[2] & 4) == 0 )
    return png_warning((int)a3, "png_do_encode_alpha: unexpected call");
  if ( *((_BYTE *)a1 + 9) == 8 )
  {
    v9 = a3[98];
    if ( v9 )
    {
      v8 = (a1[2] & 2) != 0 ? 4 : 2;
      result = a2 + v8 - 1;
      v11 = (_BYTE *)result;
      while ( v10 )
      {
        result = v9;
        *v11 = *(_BYTE *)(v9 + (unsigned __int8)*v11);
        --v10;
        v11 += v8;
      }
      return result;
    }
    return png_warning((int)a3, "png_do_encode_alpha: unexpected call");
  }
  if ( *((_BYTE *)a1 + 9) != 16 )
    return png_warning((int)a3, "png_do_encode_alpha: unexpected call");
  v7 = a3[100];
  v6 = a3[93];
  if ( !v7 )
    return png_warning((int)a3, "png_do_encode_alpha: unexpected call");
  v5 = (a1[2] & 2) != 0 ? 8 : 4;
  result = a2 + v5 - 2;
  v12 = (unsigned __int8 *)result;
  while ( v10 )
  {
    v4 = *(_WORD *)(*(_DWORD *)(v7 + 4 * ((int)v12[1] >> v6)) + 2 * *v12);
    *v12 = HIBYTE(v4);
    result = (unsigned __int8)v4;
    v12[1] = v4;
    --v10;
    v12 += v5;
  }
  return result;
}
