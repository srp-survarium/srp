unsigned int __usercall wcstol@<eax>(unsigned int a1@<esi>, const wchar_t *nptr, wchar_t **endptr, unsigned int ibase)
{
  if ( __locale_changed )
    return wcstoxl(a1, 0, nptr, (const wchar_t **)endptr, ibase, 0);
  else
    return wcstoxl(a1, &__initiallocalestructinfo, nptr, (const wchar_t **)endptr, ibase, 0);
}
