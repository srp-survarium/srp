BOOL __cdecl ASN1_GENERALIZEDTIME_print(bio_st *bp, const asn1_string_st *tm)
{
  int length; // edx
  char *data; // eax
  int v4; // esi
  int v5; // edi
  char v6; // cl
  int v7; // esi
  int v8; // ebp
  char v9; // cl
  char v10; // bl
  _BYTE *v11; // eax
  _BYTE *v12; // ecx
  char *v13; // eax
  const char *v14; // eax
  const char *v16; // [esp+Ch] [ebp-18h]
  BOOL v17; // [esp+10h] [ebp-14h]
  int v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+18h] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-8h]
  int v21; // [esp+20h] [ebp-4h]
  int v22; // [esp+2Ch] [ebp+8h]

  length = tm->length;
  data = (char *)tm->data;
  v4 = 0;
  v5 = 0;
  v18 = 0;
  v16 = 0;
  if ( tm->length >= 12 )
  {
    v17 = data[length - 1] == 90;
    while ( 1 )
    {
      v6 = data[v4];
      if ( v6 > 57 || v6 < 48 )
        break;
      if ( ++v4 >= 12 )
      {
        v7 = data[5];
        v22 = data[3] + 10 * (data[2] + 10 * (data[1] + 10 * *data)) - 53328;
        v8 = v7 + 10 * data[4] - 528;
        if ( (unsigned int)(v7 + 10 * data[4] - 529) > 0xB )
          break;
        v21 = data[7] + 10 * data[6] - 528;
        v20 = data[9] + 10 * data[8] - 528;
        v19 = data[11] + 10 * data[10] - 528;
        if ( length >= 14 )
        {
          v9 = data[12];
          if ( v9 >= 48 && v9 <= 57 )
          {
            v10 = data[13];
            if ( v10 >= 48 && v10 <= 57 )
            {
              v18 = v10 + 10 * v9 - 528;
              if ( length >= 15 )
              {
                v11 = data + 14;
                if ( *v11 == 46 )
                {
                  v16 = v11;
                  v5 = 1;
                  if ( length > 15 )
                  {
                    v12 = v11;
                    v13 = v11 + 1;
                    do
                    {
                      if ( *v13 < 48 )
                        break;
                      if ( *v13 > 57 )
                        break;
                      ++v13;
                      ++v5;
                    }
                    while ( (int)&v13[14 - (_DWORD)v12] < length );
                  }
                }
              }
            }
          }
        }
        v14 = " GMT";
        if ( !v17 )
          v14 = (const char *)&buf;
        return (int)BIO_printf(
                      bp,
                      "%s %2d %02d:%02d:%02d%.*s %d%s",
                      (const char *)(&ext_nids)[v8],
                      v21,
                      v20,
                      v19,
                      v18,
                      v5,
                      v16,
                      v22,
                      v14) > 0;
      }
    }
  }
  BIO_write(bp, "Bad time value", 14);
  return 0;
}
