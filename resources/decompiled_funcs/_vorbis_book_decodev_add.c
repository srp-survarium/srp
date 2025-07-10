int __cdecl vorbis_book_decodev_add(codebook *book, float *a, oggpack_buffer *b, int n)
{
  int v4; // esi
  int v5; // eax
  float *v6; // edx
  int i; // eax
  double v8; // st7
  double v9; // st7
  int v11; // eax
  float *v12; // ecx
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7

  if ( book->used_entries > 0 )
  {
    v4 = 0;
    if ( book->dim <= 8 )
    {
      if ( n > 0 )
      {
        while ( 1 )
        {
          v11 = decode_packed_entry_number(book, b);
          if ( v11 == -1 )
            return -1;
          v12 = &book->valuelist[v11 * book->dim];
          v13 = 0;
          switch ( book->dim )
          {
            case 1:
              goto $LN37_13;
            case 2:
              goto $LN36_22;
            case 3:
              goto $LN35_20;
            case 4:
              goto $LN34_17;
            case 5:
              goto $LN33_8;
            case 6:
              goto $LN32_18;
            case 7:
              goto $LN31_25;
            case 8:
              v13 = 1;
              v14 = *v12 + a[v4++];
              a[v4 - 1] = v14;
$LN31_25:
              v15 = v12[v13++];
              v16 = v15 + a[v4++];
              a[v4 - 1] = v16;
$LN32_18:
              v17 = v12[v13++];
              v18 = v17 + a[v4++];
              a[v4 - 1] = v18;
$LN33_8:
              v19 = v12[v13++];
              v20 = v19 + a[v4++];
              a[v4 - 1] = v20;
$LN34_17:
              v21 = v12[v13++];
              v22 = v21 + a[v4++];
              a[v4 - 1] = v22;
$LN35_20:
              v23 = v12[v13++];
              v24 = v23 + a[v4++];
              a[v4 - 1] = v24;
$LN36_22:
              v25 = v12[v13++];
              v26 = v25 + a[v4++];
              a[v4 - 1] = v26;
$LN37_13:
              ++v4;
              a[v4 - 1] = v12[v13] + a[v4 - 1];
              break;
            default:
              break;
          }
          if ( v4 >= n )
            return 0;
        }
      }
    }
    else if ( n > 0 )
    {
      while ( 1 )
      {
        v5 = decode_packed_entry_number(book, b);
        if ( v5 == -1 )
          break;
        v6 = &book->valuelist[v5 * book->dim];
        for ( i = 0; i < book->dim; a[v4 - 1] = v9 )
        {
          v8 = v6[i++];
          v9 = v8 + a[v4++];
        }
        if ( v4 >= n )
          return 0;
      }
      return -1;
    }
  }
  return 0;
}
