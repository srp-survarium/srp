BOOL __usercall ASN1_GENERALIZEDTIME_print@<eax>(int a1@<ebx>, bio_st *bp, const asn1_string_st *tm)
{
  int length; // edx
  char *data; // eax
  int v5; // esi
  int v6; // edi
  char v7; // cl
  int v8; // esi
  int v9; // ebp
  char v10; // cl
  char v11; // bl
  _BYTE *v12; // eax
  _BYTE *v13; // ecx
  char *v14; // eax
  const char *v15; // eax
  const char *v17; // [esp+Ch] [ebp-18h]
  BOOL v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]
  int v23; // [esp+2Ch] [ebp+8h]

  length = tm->length;
  data = (char *)tm->data;
  v5 = 0;
  v6 = 0;
  v19 = 0;
  v17 = 0;
  if ( tm->length >= 12 )
  {
    v18 = data[length - 1] == 90;
    while ( 1 )
    {
      v7 = data[v5];
      if ( v7 > 57 || v7 < 48 )
        break;
      if ( ++v5 >= 12 )
      {
        v8 = data[5];
        v23 = data[3] + 10 * (data[2] + 10 * (data[1] + 10 * *data)) - 53328;
        v9 = v8 + 10 * data[4] - 528;
        if ( (unsigned int)(v8 + 10 * data[4] - 529) > 0xB )
          break;
        v22 = data[7] + 10 * data[6] - 528;
        v21 = data[9] + 10 * data[8] - 528;
        v20 = data[11] + 10 * data[10] - 528;
        if ( length >= 14 )
        {
          v10 = data[12];
          if ( v10 >= 48 && v10 <= 57 )
          {
            v11 = data[13];
            if ( v11 >= 48 && v11 <= 57 )
            {
              v19 = v11 + 10 * v10 - 528;
              if ( length >= 15 )
              {
                v12 = data + 14;
                if ( *v12 == 46 )
                {
                  v17 = v12;
                  v6 = 1;
                  if ( length > 15 )
                  {
                    v13 = v12;
                    v14 = v12 + 1;
                    do
                    {
                      if ( *v14 < 48 )
                        break;
                      if ( *v14 > 57 )
                        break;
                      ++v14;
                      ++v6;
                    }
                    while ( (int)&v14[14 - (_DWORD)v13] < length );
                  }
                }
              }
            }
          }
        }
        v15 = " GMT";
        if ( !v18 )
          v15 = uri;
        return BIO_printf(
                 bp,
                 "%s %2d %02d:%02d:%02d%.*s %d%s",
                 (const char *)(&ext_nids)[v9],
                 v22,
                 v21,
                 v20,
                 v19,
                 v6,
                 v17,
                 v23,
                 v15) > 0;
      }
    }
  }
  BIO_write(a1, bp, "Bad time value", 14);
  return 0;
}
