const char **__cdecl stlp_std::priv::__median<char const *,vostok::tips_sorting_predicate>(
        const char **__a,
        char **__b,
        char **__c,
        vostok::tips_sorting_predicate __comp)
{
  unsigned __int8 *v4; // ebx
  char *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  char *v10; // edi
  char *v11; // ebx
  int v12; // eax
  int v13; // esi
  int v14; // eax
  const char **result; // eax
  char **v16; // esi
  bool v17; // al
  unsigned __int8 *v18; // ebx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  bool v22; // zf

  v4 = (unsigned __int8 *)*__a;
  v5 = *__b;
  strstr((unsigned __int8 *)*__a, (unsigned __int8 *)__comp.editor_str);
  v7 = v6;
  strstr((unsigned __int8 *)v5, (unsigned __int8 *)__comp.editor_str);
  v9 = v8 - (_DWORD)v5;
  v10 = *__c;
  if ( v7 - (int)v4 >= v9 )
  {
    v18 = (unsigned __int8 *)*__a;
    strstr((unsigned __int8 *)*__a, (unsigned __int8 *)__comp.editor_str);
    v20 = v19;
    strstr((unsigned __int8 *)v10, (unsigned __int8 *)__comp.editor_str);
    if ( v20 - (int)v18 < v21 - (int)v10 )
      return __a;
    v16 = __b;
    v17 = vostok::tips_sorting_predicate::operator()(*__c, &__comp, *__b);
  }
  else
  {
    v11 = *__b;
    strstr((unsigned __int8 *)*__b, (unsigned __int8 *)__comp.editor_str);
    v13 = v12;
    strstr((unsigned __int8 *)v10, (unsigned __int8 *)__comp.editor_str);
    if ( v13 - (int)v11 < v14 - (int)v10 )
      return (const char **)__b;
    v16 = (char **)__a;
    v17 = vostok::tips_sorting_predicate::operator()(*__c, &__comp, (char *)*__a);
  }
  v22 = !v17;
  result = (const char **)__c;
  if ( v22 )
    return (const char **)v16;
  return result;
}
