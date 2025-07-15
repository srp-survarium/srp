unsigned __int64 __usercall _strtoui64@<edx:eax>(int a1@<esi>, const char *nptr, const char **endptr, int ibase)
{
  if ( __locale_changed )
    return strtoxq(a1, 0, nptr, endptr, ibase, 1);
  else
    return strtoxq(a1, &__initiallocalestructinfo, nptr, endptr, ibase, 1);
}
