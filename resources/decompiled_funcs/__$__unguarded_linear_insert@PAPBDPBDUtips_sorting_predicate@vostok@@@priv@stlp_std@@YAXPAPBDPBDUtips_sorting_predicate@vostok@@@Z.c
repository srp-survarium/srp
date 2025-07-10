void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__last,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  const char **v3; // ebp
  const char **v4; // esi
  int v5; // eax
  int v6; // edi
  int v7; // eax
  unsigned __int8 *v8; // ebp
  int v9; // eax
  int v10; // edi
  int v11; // eax
  unsigned __int8 *__lastb; // [esp+14h] [ebp+4h]
  const char **__lasta; // [esp+14h] [ebp+4h]

  v3 = __last;
  v4 = __last - 1;
  __lastb = (unsigned __int8 *)*(__last - 1);
  strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
  v6 = v5;
  strstr(__lastb, (unsigned __int8 *)__comp.editor_str);
  if ( v6 - (int)__val < v7 - (int)__lastb )
  {
    while ( 1 )
    {
      __lasta = v4;
      *v3 = *v4;
      v8 = (unsigned __int8 *)*--v4;
      strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
      v10 = v9;
      strstr(v8, (unsigned __int8 *)__comp.editor_str);
      if ( v10 - (int)__val >= v11 - (int)v8 )
        break;
      v3 = __lasta;
    }
    *__lasta = __val;
  }
  else
  {
    *v3 = __val;
  }
}
