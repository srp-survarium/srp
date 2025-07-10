int __cdecl i2c_ASN1_BIT_STRING(asn1_string_st *a, unsigned __int8 **pp)
{
  int result; // eax
  signed int length; // edi
  int flags; // ebx
  unsigned __int8 *data; // ecx
  unsigned __int8 *v6; // eax
  unsigned __int8 v7; // al
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // esi

  if ( !a )
    return 0;
  length = a->length;
  if ( a->length <= 0 )
    goto LABEL_23;
  flags = a->flags;
  if ( (flags & 8) != 0 )
  {
    LOBYTE(flags) = flags & 7;
    goto LABEL_24;
  }
  data = a->data;
  v6 = &data[length - 1];
  do
  {
    if ( *v6 )
      break;
    --length;
    --v6;
  }
  while ( length > 0 );
  v7 = data[length - 1];
  if ( (v7 & 1) != 0 )
  {
LABEL_23:
    LOBYTE(flags) = 0;
  }
  else if ( (v7 & 2) != 0 )
  {
    LOBYTE(flags) = 1;
  }
  else if ( (v7 & 4) != 0 )
  {
    LOBYTE(flags) = 2;
  }
  else if ( (v7 & 8) != 0 )
  {
    LOBYTE(flags) = 3;
  }
  else if ( (v7 & 0x10) != 0 )
  {
    LOBYTE(flags) = 4;
  }
  else if ( (v7 & 0x20) != 0 )
  {
    LOBYTE(flags) = 5;
  }
  else if ( (v7 & 0x40) != 0 )
  {
    LOBYTE(flags) = 6;
  }
  else
  {
    flags = (char)(v7 & 0x80) != 0 ? 7 : 0;
  }
LABEL_24:
  result = length + 1;
  if ( pp )
  {
    v8 = *pp;
    *v8++ = flags;
    memcpy(v8, a->data, length);
    v9 = &v8[length];
    if ( length > 0 )
      *(v9 - 1) &= -1 << flags;
    result = length + 1;
    *pp = v9;
  }
  return result;
}
