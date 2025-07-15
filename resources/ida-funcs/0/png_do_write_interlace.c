unsigned int __cdecl png_do_write_interlace(unsigned int *a1, _BYTE *a2, int a3)
{
  unsigned int result; // eax
  unsigned int v4; // [esp+0h] [ebp-70h]
  char v5; // [esp+4h] [ebp-6Ch]
  int count; // [esp+8h] [ebp-68h]
  unsigned int v7; // [esp+Ch] [ebp-64h]
  unsigned __int8 *dst; // [esp+10h] [ebp-60h]
  const __m128i *src; // [esp+14h] [ebp-5Ch]
  unsigned int m; // [esp+18h] [ebp-58h]
  int v11; // [esp+1Ch] [ebp-54h]
  int v12; // [esp+20h] [ebp-50h]
  unsigned int v13; // [esp+24h] [ebp-4Ch]
  _BYTE *v14; // [esp+28h] [ebp-48h]
  unsigned int k; // [esp+30h] [ebp-40h]
  int v16; // [esp+38h] [ebp-38h]
  int v17; // [esp+3Ch] [ebp-34h]
  unsigned int v18; // [esp+40h] [ebp-30h]
  _BYTE *v19; // [esp+44h] [ebp-2Ch]
  unsigned int j; // [esp+4Ch] [ebp-24h]
  int v21; // [esp+54h] [ebp-1Ch]
  int v22; // [esp+58h] [ebp-18h]
  unsigned int v23; // [esp+5Ch] [ebp-14h]
  _BYTE *v24; // [esp+60h] [ebp-10h]
  unsigned int i; // [esp+68h] [ebp-8h]

  if ( a3 < 6 )
  {
    v5 = *((_BYTE *)a1 + 11);
    switch ( v5 )
    {
      case 1:
        v23 = *a1;
        v24 = a2;
        v22 = 0;
        v21 = 7;
        for ( i = (unsigned __int8)byte_6F4228[a3]; i < v23; i += (unsigned __int8)byte_6F4230[a3] )
        {
          v22 |= (((int)(unsigned __int8)a2[i >> 3] >> (7 - (i & 7))) & 1) << v21;
          if ( v21 )
          {
            --v21;
          }
          else
          {
            v21 = 7;
            *v24++ = v22;
            v22 = 0;
          }
        }
        if ( v21 != 7 )
          *v24 = v22;
        break;
      case 2:
        v18 = *a1;
        v19 = a2;
        v16 = 6;
        v17 = 0;
        for ( j = (unsigned __int8)byte_6F4228[a3]; j < v18; j += (unsigned __int8)byte_6F4230[a3] )
        {
          v17 |= (((int)(unsigned __int8)a2[j >> 2] >> (2 * (3 - (j & 3)))) & 3) << v16;
          if ( v16 )
          {
            v16 -= 2;
          }
          else
          {
            v16 = 6;
            *v19++ = v17;
            v17 = 0;
          }
        }
        if ( v16 != 6 )
          *v19 = v17;
        break;
      case 4:
        v13 = *a1;
        v14 = a2;
        v11 = 4;
        v12 = 0;
        for ( k = (unsigned __int8)byte_6F4228[a3]; k < v13; k += (unsigned __int8)byte_6F4230[a3] )
        {
          v12 |= (((int)(unsigned __int8)a2[k >> 1] >> (4 * (1 - (k & 1)))) & 0xF) << v11;
          if ( v11 )
          {
            v11 -= 4;
          }
          else
          {
            v11 = 4;
            *v14++ = v12;
            v12 = 0;
          }
        }
        if ( v11 != 4 )
          *v14 = v12;
        break;
      default:
        v7 = *a1;
        dst = a2;
        count = (int)*((unsigned __int8 *)a1 + 11) >> 3;
        for ( m = (unsigned __int8)byte_6F4228[a3]; m < v7; m += (unsigned __int8)byte_6F4230[a3] )
        {
          src = (const __m128i *)&a2[count * m];
          if ( dst != (unsigned __int8 *)src )
            memcpy((int)dst, src, count);
          dst += count;
        }
        break;
    }
    *a1 = (*a1 + (unsigned __int8)byte_6F4230[a3] - 1 - (unsigned __int8)byte_6F4228[a3])
        / (unsigned __int8)byte_6F4230[a3];
    if ( *((unsigned __int8 *)a1 + 11) < 8u )
      v4 = (*a1 * *((unsigned __int8 *)a1 + 11) + 7) >> 3;
    else
      v4 = *a1 * (*((unsigned __int8 *)a1 + 11) >> 3);
    result = v4;
    a1[1] = v4;
  }
  return result;
}
