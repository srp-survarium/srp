const char **__usercall stlp_std::priv::__median<char const *,vostok::render::shader_macros_dort_predicate>@<eax>(
        const char **__b@<eax>,
        const char **__a,
        const char **__c)
{
  if ( strcmp(*__a, *__b) < 0 )
  {
    if ( strcmp(*__b, *__c) < 0 )
      return __b;
    if ( strcmp(*__a, *__c) >= 0 )
      return __a;
    return __c;
  }
  if ( strcmp(*__a, *__c) < 0 )
    return __a;
  if ( strcmp(*__b, *__c) < 0 )
    return __c;
  return __b;
}
