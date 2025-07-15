int __usercall asn1_str2tag@<eax>(const char *tagstr@<ebx>, unsigned int len@<ecx>)
{
  unsigned int v2; // edi
  const tag_name_st *v3; // eax
  unsigned int v4; // esi

  v2 = len;
  if ( len == -1 )
    v2 = strlen(tagstr);
  v3 = tnst;
  tntmp = tnst;
  v4 = 0;
  while ( v2 != v3->len )
  {
LABEL_7:
    ++v4;
    tntmp = ++v3;
    if ( v4 >= 0x31 )
      return -1;
  }
  if ( strncmp(v3->strnam, tagstr, v2) )
  {
    v3 = tntmp;
    goto LABEL_7;
  }
  return tntmp->tag;
}
