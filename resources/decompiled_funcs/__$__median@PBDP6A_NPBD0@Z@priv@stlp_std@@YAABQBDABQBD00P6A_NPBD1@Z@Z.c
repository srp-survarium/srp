const char *const *__usercall stlp_std::priv::__median<char const *,bool (__cdecl *)(char const *,char const *)>@<eax>(
        const char **__c@<edi>,
        bool (__cdecl *__comp)(const char *, const char *)@<esi>,
        const char **__a,
        const char **__b)
{
  const char *const *result; // eax
  bool v5; // zf

  if ( __comp(*__a, *__b) )
  {
    if ( !__comp(*__b, *__c) )
    {
      if ( __comp(*__a, *__c) )
        return __c;
      return __a;
    }
    return __b;
  }
  if ( __comp(*__a, *__c) )
    return __a;
  v5 = !__comp(*__b, *__c);
  result = __c;
  if ( v5 )
    return __b;
  return result;
}
