unsigned int __usercall strtol@<eax>(unsigned int a1@<ebx>, const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed )
    return strtoxl(a1, 0, nptr, (const char **)endptr, ibase, 0);
  else
    return strtoxl(a1, &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, 0);
}
