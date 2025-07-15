unsigned int __cdecl png_check_keyword(int a1, LPCSTR lpString, void **a3)
{
  _BYTE v4[260]; // [esp+0h] [ebp-120h] BYREF
  int v5; // [esp+108h] [ebp-18h]
  _BYTE *v6; // [esp+10Ch] [ebp-14h]
  LPCSTR v7; // [esp+110h] [ebp-10h]
  unsigned int v8; // [esp+114h] [ebp-Ch]
  _BYTE *v9; // [esp+118h] [ebp-8h]
  int v10; // [esp+11Ch] [ebp-4h]

  v10 = 0;
  *a3 = 0;
  if ( lpString && (v8 = lstrlenA(lpString)) != 0 )
  {
    *a3 = (void *)png_malloc_warn(a1, v8 + 2);
    if ( *a3 )
    {
      v7 = lpString;
      v6 = *a3;
      while ( *v7 )
      {
        if ( *(unsigned __int8 *)v7 >= 0x20u && (*(unsigned __int8 *)v7 <= 0x7Eu || *(unsigned __int8 *)v7 >= 0xA1u) )
        {
          *v6 = *v7;
        }
        else
        {
          png_warning_parameter_unsigned((int)v4, 1, 4, *(unsigned __int8 *)v7);
          png_formatted_warning(a1, (int)v4, "invalid keyword character 0x@1");
          *v6 = 32;
        }
        ++v7;
        ++v6;
      }
      *v6 = 0;
      v9 = (char *)*a3 + v8 - 1;
      if ( *v9 == 32 )
      {
        png_warning(a1, "trailing spaces removed from keyword");
        while ( *v9 == 32 )
        {
          *v9-- = 0;
          --v8;
        }
      }
      v9 = *a3;
      if ( *v9 == 32 )
      {
        png_warning(a1, "leading spaces removed from keyword");
        while ( *v9 == 32 )
        {
          ++v9;
          --v8;
        }
      }
      v5 = 0;
      v6 = *a3;
      while ( *v9 )
      {
        if ( *v9 != 32 || v5 )
        {
          if ( *v9 == 32 )
          {
            --v8;
            v10 = 1;
          }
          else
          {
            *v6++ = *v9;
            v5 = 0;
          }
        }
        else
        {
          *v6++ = *v9;
          v5 = 1;
        }
        ++v9;
      }
      *v6 = 0;
      if ( v10 )
        png_warning(a1, "extra interior spaces removed from keyword");
      if ( !v8 )
      {
        png_free(a1, *a3);
        png_warning(a1, "Zero length keyword");
      }
      if ( v8 > 0x4F )
      {
        png_warning(a1, "keyword length must be 1 - 79 characters");
        *((_BYTE *)*a3 + 79) = 0;
        return 79;
      }
      return v8;
    }
    else
    {
      png_warning(a1, "Out of memory while procesing keyword");
      return 0;
    }
  }
  else
  {
    png_warning(a1, "zero length keyword");
    return 0;
  }
}
