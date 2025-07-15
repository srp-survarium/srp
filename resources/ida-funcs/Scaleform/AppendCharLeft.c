char *__usercall Scaleform::AppendCharLeft@<eax>(char *value_ptr@<eax>, unsigned int ucs_char@<edi>, char *buff)
{
  char *v3; // esi
  int pindex; // [esp+4h] [ebp-4h] BYREF

  v3 = value_ptr;
  if ( ucs_char )
  {
    v3 = &value_ptr[-Scaleform::UTF8Util::GetEncodeCharSize(ucs_char)];
    if ( buff > v3 )
      return 0;
    pindex = 0;
    Scaleform::UTF8Util::EncodeChar(v3, &pindex, ucs_char);
  }
  return v3;
}
