void __cdecl png_handle_cHRM(int a1, _DWORD *a2, unsigned int a3)
{
  _BYTE v3[32]; // [esp-20h] [ebp-1C4h] BYREF
  int v4; // [esp+8h] [ebp-19Ch]
  signed int v5; // [esp+Ch] [ebp-198h] BYREF
  signed int v6; // [esp+10h] [ebp-194h] BYREF
  signed int v7; // [esp+14h] [ebp-190h] BYREF
  _DWORD v8[8]; // [esp+18h] [ebp-18Ch] BYREF
  _BYTE v9[4]; // [esp+38h] [ebp-16Ch] BYREF
  int v10; // [esp+3Ch] [ebp-168h]
  int v11; // [esp+48h] [ebp-15Ch]
  int v12; // [esp+54h] [ebp-150h]
  _BYTE v13[260]; // [esp+5Ch] [ebp-148h] BYREF
  int v14; // [esp+160h] [ebp-44h]
  int v15; // [esp+164h] [ebp-40h]
  unsigned __int8 buf[4]; // [esp+168h] [ebp-3Ch] BYREF
  unsigned __int8 v17[4]; // [esp+16Ch] [ebp-38h] BYREF
  unsigned __int8 v18[4]; // [esp+170h] [ebp-34h] BYREF
  unsigned __int8 v19[4]; // [esp+174h] [ebp-30h] BYREF
  unsigned __int8 v20[4]; // [esp+178h] [ebp-2Ch] BYREF
  unsigned __int8 v21[4]; // [esp+17Ch] [ebp-28h] BYREF
  unsigned __int8 v22[4]; // [esp+180h] [ebp-24h] BYREF
  unsigned __int8 v23[4]; // [esp+184h] [ebp-20h] BYREF
  int v24; // [esp+18Ch] [ebp-18h]
  int v25; // [esp+190h] [ebp-14h]
  int v26; // [esp+194h] [ebp-10h]
  int v27; // [esp+198h] [ebp-Ch]
  int v28; // [esp+19Ch] [ebp-8h]
  int v29; // [esp+1A0h] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before cHRM");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid cHRM after IDAT");
    png_crc_finish(a1, a3);
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 108) & 2) != 0 )
      png_warning(a1, "Out of place cHRM chunk");
    if ( a2 && (a2[2] & 4) != 0 && (a2[2] & 0x800) == 0 )
    {
      png_warning(a1, "Duplicate cHRM chunk");
      png_crc_finish(a1, a3);
    }
    else if ( a3 == 32 )
    {
      png_crc_read((_DWORD *)a1, buf, 32);
      if ( !png_crc_finish(a1, 0) )
      {
        v29 = sub_471D20(0, buf);
        v28 = sub_471D20(0, v17);
        v24 = sub_471D20(0, v18);
        v26 = sub_471D20(0, v19);
        v14 = sub_471D20(0, v20);
        v25 = sub_471D20(0, v21);
        v27 = sub_471D20(0, v22);
        v15 = sub_471D20(0, v23);
        if ( v29 == -1 || v28 == -1 || v24 == -1 || v26 == -1 || v14 == -1 || v25 == -1 || v27 == -1 || v15 == -1 )
        {
          png_warning(a1, "Ignoring cHRM chunk with negative chromaticities");
        }
        else if ( a2 && (a2[2] & 0x800) != 0 )
        {
          if ( v29 < 30270
            || v29 > 32270
            || v28 < 31900
            || v28 > 33900
            || v24 < 63000
            || v24 > 65000
            || v26 < 32000
            || v26 > 34000
            || v14 < 29000
            || v14 > 31000
            || v25 < 59000
            || v25 > 61000
            || v27 < 14000
            || v27 > 16000
            || v15 < 5000
            || v15 > 7000 )
          {
            png_warning_parameter_signed((int)v13, 1, 5, v29);
            png_warning_parameter_signed((int)v13, 2, 5, v28);
            png_warning_parameter_signed((int)v13, 3, 5, v24);
            png_warning_parameter_signed((int)v13, 4, 5, v26);
            png_warning_parameter_signed((int)v13, 5, 5, v14);
            png_warning_parameter_signed((int)v13, 6, 5, v25);
            png_warning_parameter_signed((int)v13, 7, 5, v27);
            png_warning_parameter_signed((int)v13, 8, 5, v15);
            png_formatted_warning(
              a1,
              (int)v13,
              "Ignoring incorrect cHRM white(@1,@2) r(@3,@4)g(@5,@6)b(@7,@8) when sRGB is also present");
          }
        }
        else
        {
          if ( !*(_BYTE *)(a1 + 594) )
          {
            v8[0] = v24;
            v8[1] = v26;
            v8[2] = v14;
            v8[3] = v25;
            v8[4] = v27;
            v8[5] = v15;
            v8[6] = v29;
            v8[7] = v28;
            qmemcpy(v3, v8, sizeof(v3));
            if ( png_XYZ_from_xy_checked(a1, (int)v9) )
            {
              if ( !png_muldiv(&v5, v10, 0x8000, 100000)
                || (unsigned int)v5 > 0x8000
                || !png_muldiv(&v6, v11, 0x8000, 100000)
                || (unsigned int)v6 > 0x8000
                || !png_muldiv(&v7, v12, 0x8000, 100000)
                || (unsigned int)v7 > 0x8000
                || v7 + v6 + v5 > 32769 )
              {
                png_error(a1, (int)"internal error handling cHRM->XYZ");
              }
              v4 = 0;
              if ( v7 + v6 + v5 <= 0x8000 )
                v4 = v7 + v6 + v5 < 0x8000;
              else
                v4 = -1;
              if ( v4 )
              {
                if ( v6 < v5 || v6 < v7 )
                {
                  if ( v5 < v6 || v5 < v7 )
                    v7 += v4;
                  else
                    v5 += v4;
                }
                else
                {
                  v6 += v4;
                }
              }
              if ( v7 + v6 + v5 != 0x8000 )
                png_error(a1, (int)"internal error handling cHRM coefficients");
              *(_WORD *)(a1 + 596) = v5;
              *(_WORD *)(a1 + 598) = v6;
            }
          }
          png_set_cHRM_fixed(a1, a2, v29, v28, v24, v26, v14, v25, v27, v15);
        }
      }
    }
    else
    {
      png_warning(a1, "Incorrect cHRM chunk length");
      png_crc_finish(a1, a3);
    }
  }
}
