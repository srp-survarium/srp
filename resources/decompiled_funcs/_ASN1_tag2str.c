const char *__cdecl ASN1_tag2str(unsigned int tag)
{
  unsigned int v1; // eax

  v1 = tag;
  if ( tag == 258 || tag == 266 )
    v1 = tag & 0xFFFFFEFF;
  if ( v1 > 0x1E )
    return "(unknown)";
  else
    return tag2str[v1];
}
