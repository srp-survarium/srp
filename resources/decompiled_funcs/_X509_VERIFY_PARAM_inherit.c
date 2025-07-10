int __cdecl X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM_st *dest, const X509_VERIFY_PARAM_st *src)
{
  int result; // eax
  unsigned int v3; // edx
  int v4; // esi
  int check_time_high; // edi

  if ( !src )
    return 1;
  v3 = dest->inh_flags | src->inh_flags;
  if ( (v3 & 0x10) != 0 )
    dest->inh_flags = 0;
  if ( (v3 & 8) != 0 )
    return 1;
  if ( (v3 & 2) != 0 )
  {
    v4 = 1;
    goto LABEL_11;
  }
  v4 = 0;
  if ( src->purpose && ((v3 & 1) != 0 || !dest->purpose) )
  {
LABEL_11:
    dest->purpose = src->purpose;
    if ( v4 )
      goto LABEL_15;
  }
  if ( !src->trust || (v3 & 1) == 0 && dest->trust )
  {
LABEL_16:
    if ( src->depth == -1 || (v3 & 1) == 0 && dest->depth != -1 )
      goto LABEL_20;
    goto LABEL_19;
  }
LABEL_15:
  dest->trust = src->trust;
  if ( !v4 )
    goto LABEL_16;
LABEL_19:
  dest->depth = src->depth;
  if ( v4 )
  {
LABEL_21:
    LODWORD(dest->check_time) = src->check_time;
    check_time_high = HIDWORD(src->check_time);
    dest->flags &= ~2u;
    HIDWORD(dest->check_time) = check_time_high;
    goto LABEL_22;
  }
LABEL_20:
  if ( (dest->flags & 2) == 0 )
    goto LABEL_21;
LABEL_22:
  if ( (v3 & 4) != 0 )
    dest->flags = 0;
  dest->flags |= src->flags;
  if ( !v4 && (!src->policies || (v3 & 1) == 0 && dest->policies) )
    return 1;
  result = X509_VERIFY_PARAM_set1_policies(dest, src->policies);
  if ( result )
    return 1;
  return result;
}
