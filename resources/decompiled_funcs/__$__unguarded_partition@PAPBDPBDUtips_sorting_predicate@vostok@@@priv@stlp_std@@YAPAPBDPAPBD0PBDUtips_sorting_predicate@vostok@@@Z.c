const char **__usercall stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::tips_sorting_predicate>@<eax>(
        char *__pivot@<esi>,
        const char **__first,
        const char **__last,
        vostok::tips_sorting_predicate __comp)
{
  int v6; // eax
  int v7; // edi
  int v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // eax
  int v11; // edi
  int v12; // eax
  unsigned __int8 *v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  unsigned __int8 *v17; // ecx
  int v18; // eax
  int v19; // edi
  int v20; // eax
  const char *v21; // eax
  const char **__lasta; // [esp+14h] [ebp+8h]
  const char **__lastb; // [esp+14h] [ebp+8h]
  unsigned __int8 *__lastc; // [esp+14h] [ebp+8h]
  unsigned __int8 *__lastd; // [esp+14h] [ebp+8h]

  while ( 1 )
  {
    __lasta = (const char **)*__first;
    strstr((unsigned __int8 *)*__first, (unsigned __int8 *)__comp.editor_str);
    v7 = v6;
    strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
    if ( v7 - (int)__lasta < v8 - (int)__pivot )
    {
      do
      {
        v9 = (unsigned __int8 *)__first[1];
        ++__first;
        __lastb = (const char **)v9;
        strstr(v9, (unsigned __int8 *)__comp.editor_str);
        v11 = v10;
        strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
      }
      while ( v11 - (int)__lastb < v12 - (int)__pivot );
    }
    v13 = (unsigned __int8 *)*--__last;
    __lastc = v13;
    strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
    v15 = v14;
    strstr(__lastc, (unsigned __int8 *)__comp.editor_str);
    if ( v15 - (int)__pivot < v16 - (int)__lastc )
    {
      do
      {
        v17 = (unsigned __int8 *)*--__last;
        __lastd = v17;
        strstr((unsigned __int8 *)__pivot, (unsigned __int8 *)__comp.editor_str);
        v19 = v18;
        strstr(__lastd, (unsigned __int8 *)__comp.editor_str);
      }
      while ( v19 - (int)__pivot < v20 - (int)__lastd );
    }
    if ( __first >= __last )
      break;
    v21 = *__first;
    *__first = *__last;
    *__last = v21;
    ++__first;
  }
  return __first;
}
