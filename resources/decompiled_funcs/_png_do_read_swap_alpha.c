unsigned int __cdecl png_do_read_swap_alpha(unsigned int *a1, int a2)
{
  unsigned int result; // eax
  char v3; // [esp+0h] [ebp-44h]
  char v4; // [esp+1h] [ebp-43h]
  char *v5; // [esp+4h] [ebp-40h]
  char *v6; // [esp+4h] [ebp-40h]
  char *v7; // [esp+8h] [ebp-3Ch]
  char *v8; // [esp+8h] [ebp-3Ch]
  unsigned int m; // [esp+Ch] [ebp-38h]
  char v10; // [esp+13h] [ebp-31h]
  char *v11; // [esp+14h] [ebp-30h]
  char *v12; // [esp+14h] [ebp-30h]
  char *v13; // [esp+18h] [ebp-2Ch]
  char *v14; // [esp+18h] [ebp-2Ch]
  unsigned int k; // [esp+1Ch] [ebp-28h]
  char v16; // [esp+20h] [ebp-24h]
  char v17; // [esp+21h] [ebp-23h]
  char *v18; // [esp+24h] [ebp-20h]
  char *v19; // [esp+24h] [ebp-20h]
  char *v20; // [esp+28h] [ebp-1Ch]
  char *v21; // [esp+28h] [ebp-1Ch]
  unsigned int j; // [esp+2Ch] [ebp-18h]
  char v23; // [esp+33h] [ebp-11h]
  char *v24; // [esp+34h] [ebp-10h]
  char *v25; // [esp+34h] [ebp-10h]
  char *v26; // [esp+38h] [ebp-Ch]
  char *v27; // [esp+38h] [ebp-Ch]
  unsigned int i; // [esp+3Ch] [ebp-8h]
  unsigned int v29; // [esp+40h] [ebp-4h]

  v29 = *a1;
  result = *((unsigned __int8 *)a1 + 8);
  if ( result == 6 )
  {
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      result = (unsigned int)a1;
      v26 = (char *)(a1[1] + a2);
      v24 = v26;
      for ( i = 0; i < v29; ++i )
      {
        v27 = v26 - 1;
        v23 = *v27--;
        v25 = v24 - 1;
        *v25 = *v27--;
        *--v25 = *v27;
        v26 = v27 - 1;
        *--v25 = *v26;
        v24 = v25 - 1;
        *v24 = v23;
        result = i + 1;
      }
    }
    else
    {
      v20 = (char *)(a1[1] + a2);
      v18 = v20;
      for ( j = 0; ; ++j )
      {
        result = j;
        if ( j >= v29 )
          break;
        v21 = v20 - 1;
        v16 = *v21--;
        v17 = *v21--;
        v19 = v18 - 1;
        *v19 = *v21--;
        *--v19 = *v21--;
        *--v19 = *v21--;
        *--v19 = *v21--;
        *--v19 = *v21;
        v20 = v21 - 1;
        *--v19 = *v20;
        *--v19 = v16;
        v18 = v19 - 1;
        *v18 = v17;
      }
    }
  }
  else if ( *((_BYTE *)a1 + 8) == 4 )
  {
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      v13 = (char *)(a1[1] + a2);
      v11 = v13;
      for ( k = 0; ; ++k )
      {
        result = k;
        if ( k >= v29 )
          break;
        v14 = v13 - 1;
        v10 = *v14;
        v13 = v14 - 1;
        v12 = v11 - 1;
        *v12 = *v13;
        v11 = v12 - 1;
        *v11 = v10;
      }
    }
    else
    {
      result = (unsigned int)a1;
      v7 = (char *)(a1[1] + a2);
      v5 = v7;
      for ( m = 0; m < v29; ++m )
      {
        v8 = v7 - 1;
        v3 = *v8--;
        v4 = *v8--;
        v6 = v5 - 1;
        *v6 = *v8;
        v7 = v8 - 1;
        *--v6 = *v7;
        *--v6 = v3;
        v5 = v6 - 1;
        *v5 = v4;
        result = m + 1;
      }
    }
  }
  return result;
}
