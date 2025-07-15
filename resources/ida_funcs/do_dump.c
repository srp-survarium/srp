int __fastcall do_dump(asn1_string_st *str, void *arg, __int16 lflags, int (__cdecl *io_ch)(void *, const void *, int))
{
  int (__cdecl *v4)(void *, const void *, int); // ebp
  int v8; // eax
  int v9; // ebx
  int (__cdecl *v10)(void *, const void *, int); // esi
  int v11; // edi
  asn1_type_st a; // [esp+Ch] [ebp-8h] BYREF

  v4 = io_ch;
  if ( !io_ch(arg, "#", 1) )
    return -1;
  if ( (lflags & 0x200) != 0 )
  {
    a.type = str->type;
    a.value.boolean = (int)str;
    v9 = i2d_ASN1_TYPE(&a, 0);
    v10 = (int (__cdecl *)(void *, const void *, int))CRYPTO_malloc(v9, ".\\crypto\\asn1\\a_strex.c", 281);
    if ( v10
      && (io_ch = v10,
          i2d_ASN1_TYPE(&a, (unsigned __int8 **)&io_ch),
          v11 = do_hex_dump(arg, (unsigned __int8 *)v10, v4, v9),
          CRYPTO_free(v10),
          v11 >= 0) )
    {
      return v11 + 1;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    v8 = do_hex_dump(arg, str->data, v4, str->length);
    if ( v8 < 0 )
      return -1;
    return v8 + 1;
  }
}
