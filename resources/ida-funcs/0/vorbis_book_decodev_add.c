int __cdecl vorbis_book_decodev_add(codebook *book, float *a, oggpack_buffer *b, int n)
{
  int v4; // esi
  int v5; // edi
  int v6; // eax
  float *v7; // edx
  int i; // ecx
  float *v9; // eax
  float v10; // xmm0_4
  int v12; // eax
  float *v13; // ecx
  int v14; // eax

  v4 = 0;
  if ( book->used_entries > 0 )
  {
    if ( book->dim <= 8 )
    {
      if ( n > 0 )
      {
        while ( 1 )
        {
          v12 = decode_packed_entry_number(book, b);
          if ( v12 == -1 )
            return -1;
          v13 = &book->valuelist[v12 * book->dim];
          v14 = 0;
          switch ( book->dim )
          {
            case 1:
              goto $LN2;
            case 2:
              goto $LN3;
            case 3:
              goto $LN4;
            case 4:
              goto $LN5_0;
            case 5:
              goto $LN6_0;
            case 6:
              goto $LN7_0;
            case 7:
              goto $LN8_1;
            case 8:
              a[v4] = *v13 + a[v4];
              v14 = 1;
              ++v4;
$LN8_1:
              a[v4] = v13[v14++] + a[v4];
              ++v4;
$LN7_0:
              a[v4] = v13[v14++] + a[v4];
              ++v4;
$LN6_0:
              a[v4] = v13[v14++] + a[v4];
              ++v4;
$LN5_0:
              a[v4] = v13[v14++] + a[v4];
              ++v4;
$LN4:
              a[v4] = v13[v14++] + a[v4];
              ++v4;
$LN3:
              a[v4] = v13[v14++] + a[v4];
              ++v4;
$LN2:
              a[v4] = v13[v14] + a[v4];
              ++v4;
              break;
            default:
              break;
          }
          if ( v4 >= n )
            return 0;
        }
      }
    }
    else
    {
      v5 = 0;
      if ( n > 0 )
      {
        while ( 1 )
        {
          v6 = decode_packed_entry_number(book, b);
          if ( v6 == -1 )
            break;
          v7 = &book->valuelist[v6 * book->dim];
          for ( i = 0; i < book->dim; ++v5 )
          {
            v9 = &a[v5];
            v10 = v7[i++] + *v9;
            *v9 = v10;
          }
          if ( v5 >= n )
            return 0;
        }
        return -1;
      }
    }
  }
  return 0;
}
