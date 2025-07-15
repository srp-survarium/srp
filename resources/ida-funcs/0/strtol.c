unsigned int __usercall strtol@<eax>(int a1@<ebx>, const char *nptr, const char **endptr, int ibase)
{
  if ( __locale_changed )
    return strtoxl(a1, 0, nptr, endptr, ibase, 0);
  else
    return strtoxl(a1, &__initiallocalestructinfo, nptr, endptr, ibase, 0);
}
