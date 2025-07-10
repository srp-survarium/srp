int __cdecl png_do_write_invert_alpha(unsigned int *a1, _BYTE *a2)
{
  int result; // eax
  unsigned int v3; // [esp+0h] [ebp-40h]
  _BYTE *v4; // [esp+8h] [ebp-38h]
  _BYTE *v5; // [esp+8h] [ebp-38h]
  unsigned int v6; // [esp+Ch] [ebp-34h]
  unsigned int v7; // [esp+10h] [ebp-30h]
  _BYTE *v8; // [esp+14h] [ebp-2Ch]
  _BYTE *v9; // [esp+18h] [ebp-28h]
  _BYTE *v10; // [esp+18h] [ebp-28h]
  unsigned int v11; // [esp+1Ch] [ebp-24h]
  unsigned int v12; // [esp+20h] [ebp-20h]
  _BYTE *v13; // [esp+28h] [ebp-18h]
  _BYTE *v14; // [esp+28h] [ebp-18h]
  unsigned int v15; // [esp+2Ch] [ebp-14h]
  _BYTE *v16; // [esp+30h] [ebp-10h]
  _BYTE *i; // [esp+38h] [ebp-8h]
  _BYTE *v18; // [esp+3Ch] [ebp-4h]

  if ( *((_BYTE *)a1 + 8) == 6 )
  {
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      v16 = (_BYTE *)*a1;
      v18 = 0;
      for ( i = a2; ; i += 4 )
      {
        result = (int)v18;
        if ( v18 >= v16 )
          break;
        i[3] = -1 - i[3];
        ++v18;
      }
    }
    else
    {
      v12 = *a1;
      v15 = 0;
      result = (int)a2;
      v13 = a2;
      while ( v15 < v12 )
      {
        v14 = v13 + 6;
        *v14 = -1 - *v14;
        v14[1] = -1 - v14[1];
        result = (int)(v14 + 2);
        v13 = v14 + 2;
        ++v15;
      }
    }
  }
  else
  {
    result = *((unsigned __int8 *)a1 + 8);
    if ( result == 4 )
    {
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        v7 = *a1;
        v11 = 0;
        v8 = a2;
        result = (int)a2;
        v9 = a2;
        while ( v11 < v7 )
        {
          *v8 = *v9;
          v10 = v9 + 1;
          v8[1] = -1 - *v10;
          result = (int)(v8 + 2);
          v8 += 2;
          v9 = v10 + 1;
          ++v11;
        }
      }
      else
      {
        result = *a1;
        v3 = *a1;
        v6 = 0;
        v4 = a2;
        while ( v6 < v3 )
        {
          v5 = v4 + 2;
          *v5 = -1 - *v5;
          v5[1] = -1 - v5[1];
          v4 = v5 + 2;
          result = ++v6;
        }
      }
    }
  }
  return result;
}
