unsigned int *__cdecl png_do_read_invert_alpha(unsigned int *a1, int a2)
{
  unsigned int *result; // eax
  unsigned int *v3; // [esp+0h] [ebp-34h]
  _BYTE *v4; // [esp+0h] [ebp-34h]
  unsigned int *v5; // [esp+4h] [ebp-30h]
  _BYTE *v6; // [esp+4h] [ebp-30h]
  unsigned int m; // [esp+8h] [ebp-2Ch]
  _BYTE *v8; // [esp+Ch] [ebp-28h]
  _BYTE *v9; // [esp+Ch] [ebp-28h]
  _BYTE *v10; // [esp+10h] [ebp-24h]
  _BYTE *v11; // [esp+10h] [ebp-24h]
  unsigned int k; // [esp+14h] [ebp-20h]
  unsigned int *v13; // [esp+18h] [ebp-1Ch]
  _BYTE *v14; // [esp+18h] [ebp-1Ch]
  unsigned int *v15; // [esp+1Ch] [ebp-18h]
  _BYTE *v16; // [esp+1Ch] [ebp-18h]
  unsigned int j; // [esp+20h] [ebp-14h]
  _BYTE *v18; // [esp+24h] [ebp-10h]
  _BYTE *v19; // [esp+28h] [ebp-Ch]
  _BYTE *v20; // [esp+28h] [ebp-Ch]
  unsigned int i; // [esp+2Ch] [ebp-8h]
  unsigned int v22; // [esp+30h] [ebp-4h]

  v22 = *a1;
  if ( *((_BYTE *)a1 + 8) == 6 )
  {
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      result = a1;
      v19 = (_BYTE *)(a1[1] + a2);
      v18 = v19;
      for ( i = 0; i < v22; ++i )
      {
        v20 = v19 - 1;
        *(v18 - 1) = -1 - *v20;
        v19 = v20 - 3;
        v18 = v19;
        result = (unsigned int *)(i + 1);
      }
    }
    else
    {
      v15 = (unsigned int *)(a1[1] + a2);
      result = v15;
      v13 = v15;
      for ( j = 0; j < v22; ++j )
      {
        v16 = (char *)v15 - 1;
        v14 = (char *)v13 - 1;
        *v14 = -1 - *v16--;
        *(v14 - 1) = -1 - *v16;
        result = (unsigned int *)(v16 - 6);
        v15 = (unsigned int *)(v16 - 6);
        v13 = v15;
      }
    }
  }
  else
  {
    result = (unsigned int *)*((unsigned __int8 *)a1 + 8);
    if ( result == (unsigned int *)4 )
    {
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        result = a1;
        v10 = (_BYTE *)(a1[1] + a2);
        v8 = v10;
        for ( k = 0; k < v22; ++k )
        {
          v11 = v10 - 1;
          v9 = v8 - 1;
          *v9 = -1 - *v11;
          v10 = v11 - 1;
          v8 = v9 - 1;
          *v8 = *v10;
          result = (unsigned int *)(k + 1);
        }
      }
      else
      {
        v5 = (unsigned int *)(a1[1] + a2);
        result = v5;
        v3 = v5;
        for ( m = 0; m < v22; ++m )
        {
          v6 = (char *)v5 - 1;
          v4 = (char *)v3 - 1;
          *v4 = -1 - *v6--;
          *(v4 - 1) = -1 - *v6;
          result = (unsigned int *)(v6 - 2);
          v5 = (unsigned int *)(v6 - 2);
          v3 = v5;
        }
      }
    }
  }
  return result;
}
