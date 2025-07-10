unsigned int *__cdecl png_do_write_swap_alpha(unsigned int *a1, _BYTE *a2)
{
  unsigned int *result; // eax
  char v3; // [esp+0h] [ebp-50h]
  char v4; // [esp+1h] [ebp-4Fh]
  unsigned int v5; // [esp+4h] [ebp-4Ch]
  char *v6; // [esp+8h] [ebp-48h]
  _BYTE *v7; // [esp+8h] [ebp-48h]
  char *v8; // [esp+Ch] [ebp-44h]
  char *v9; // [esp+Ch] [ebp-44h]
  unsigned int v10; // [esp+10h] [ebp-40h]
  char v11; // [esp+17h] [ebp-39h]
  unsigned int v12; // [esp+18h] [ebp-38h]
  _BYTE *v13; // [esp+1Ch] [ebp-34h]
  char *v14; // [esp+20h] [ebp-30h]
  _BYTE *v15; // [esp+20h] [ebp-30h]
  unsigned int v16; // [esp+24h] [ebp-2Ch]
  char v17; // [esp+28h] [ebp-28h]
  char v18; // [esp+29h] [ebp-27h]
  unsigned int v19; // [esp+2Ch] [ebp-24h]
  char *v20; // [esp+30h] [ebp-20h]
  _BYTE *v21; // [esp+30h] [ebp-20h]
  char *v22; // [esp+34h] [ebp-1Ch]
  char *v23; // [esp+34h] [ebp-1Ch]
  unsigned int v24; // [esp+38h] [ebp-18h]
  char v25; // [esp+3Fh] [ebp-11h]
  unsigned int v26; // [esp+40h] [ebp-10h]
  _BYTE *v27; // [esp+44h] [ebp-Ch]
  _BYTE *v28; // [esp+44h] [ebp-Ch]
  char *v29; // [esp+48h] [ebp-8h]
  _BYTE *v30; // [esp+48h] [ebp-8h]
  unsigned int v31; // [esp+4Ch] [ebp-4h]

  result = a1;
  if ( *((_BYTE *)a1 + 8) == 6 )
  {
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      v26 = *a1;
      v31 = 0;
      v27 = a2;
      v29 = a2;
      while ( 1 )
      {
        result = (unsigned int *)v31;
        if ( v31 >= v26 )
          break;
        v25 = *v29;
        v30 = v29 + 1;
        *v27 = *v30;
        v28 = v27 + 1;
        *v28++ = *++v30;
        *v28 = *++v30;
        v29 = v30 + 1;
        v28[1] = v25;
        v27 = v28 + 2;
        ++v31;
      }
    }
    else
    {
      v19 = *a1;
      v24 = 0;
      v20 = a2;
      v22 = a2;
      while ( 1 )
      {
        result = (unsigned int *)v24;
        if ( v24 >= v19 )
          break;
        v17 = *v22;
        v23 = v22 + 1;
        v18 = *v23++;
        *v20 = *v23;
        v21 = v20 + 1;
        *v21++ = *++v23;
        *v21++ = *++v23;
        *v21++ = *++v23;
        *v21++ = *++v23;
        *v21++ = *++v23;
        v22 = v23 + 1;
        *v21 = v17;
        v21[1] = v18;
        v20 = v21 + 2;
        ++v24;
      }
    }
  }
  else if ( *((_BYTE *)a1 + 8) == 4 )
  {
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      result = (unsigned int *)*a1;
      v12 = *a1;
      v16 = 0;
      v13 = a2;
      v14 = a2;
      while ( v16 < v12 )
      {
        v11 = *v14;
        v15 = v14 + 1;
        *v13 = *v15;
        v14 = v15 + 1;
        v13[1] = v11;
        v13 += 2;
        result = (unsigned int *)++v16;
      }
    }
    else
    {
      v5 = *a1;
      v10 = 0;
      v6 = a2;
      v8 = a2;
      while ( 1 )
      {
        result = (unsigned int *)v10;
        if ( v10 >= v5 )
          break;
        v3 = *v8;
        v9 = v8 + 1;
        v4 = *v9++;
        *v6 = *v9;
        v7 = v6 + 1;
        *v7++ = *++v9;
        v8 = v9 + 1;
        *v7 = v3;
        v7[1] = v4;
        v6 = v7 + 2;
        ++v10;
      }
    }
  }
  return result;
}
