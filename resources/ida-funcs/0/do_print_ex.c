int __usercall do_print_ex@<eax>(
        int (__cdecl *io_ch)(void *, const void *, int)@<edi>,
        __int16 lflags@<cx>,
        void *arg,
        asn1_string_st *str)
{
  asn1_string_st *v5; // ebp
  unsigned int type; // eax
  const char *v7; // eax
  int v8; // esi
  int v9; // esi
  int v10; // eax
  int v12; // eax
  int v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+Ch] [ebp-Ch]
  unsigned __int8 v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h]

  v5 = str;
  v15 = lflags & 0xF;
  type = str->type;
  LOBYTE(str) = 0;
  v16 = type;
  v13 = 0;
  if ( (lflags & 0x40) != 0 )
  {
    v7 = ASN1_tag2str(type);
    v8 = strlen(v7);
    if ( !io_ch(arg, v7, v8) || !io_ch(arg, ":", 1) )
      return -1;
    type = v16;
    v13 = v8 + 1;
  }
  if ( (lflags & 0x80u) != 0 )
    goto LABEL_10;
  if ( (lflags & 0x20) != 0 )
    goto LABEL_13;
  if ( type - 1 > 0x1D || (v9 = tag2nbyte[type], v9 == -1) )
  {
    if ( (lflags & 0x100) != 0 )
    {
LABEL_10:
      v10 = do_dump(v5, arg, lflags, io_ch);
      if ( v10 >= 0 )
        return v13 + v10;
      return -1;
    }
LABEL_13:
    v9 = 1;
  }
  if ( (lflags & 0x10) != 0 )
  {
    if ( v9 )
      LOBYTE(v9) = v9 | 8;
    else
      LOBYTE(v9) = 1;
  }
  v12 = do_buf((char *)&str, io_ch, v5->data, v5->length, v9, v15, 0);
  if ( v12 < 0 )
    return -1;
  v14 = v12 + v13;
  if ( (_BYTE)str )
    v14 += 2;
  if ( arg
    && ((_BYTE)str && !io_ch(arg, "\"", 1)
     || do_buf(0, io_ch, v5->data, v5->length, v9, v15, arg) < 0
     || (_BYTE)str && !io_ch(arg, "\"", 1)) )
  {
    return -1;
  }
  return v14;
}
