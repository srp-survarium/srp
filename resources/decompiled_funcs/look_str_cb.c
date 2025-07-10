void __cdecl look_str_cb(int nid, stack_st_ENGINE *sk, engine_st *def, void *arg)
{
  unsigned int v4; // ebx
  char *v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // [esp+0h] [ebp-4h] BYREF

  if ( !*((_DWORD *)arg + 1) )
  {
    v4 = 0;
    if ( sk_num(&sk->stack) > 0 )
    {
      while ( 1 )
      {
        v5 = sk_value(&sk->stack, v4);
        (*((void (__cdecl **)(char *, int *, _DWORD, int))v5 + 12))(v5, &v8, 0, nid);
        if ( strlen(*(const char **)(v8 + 12)) == *((_DWORD *)arg + 3) )
        {
          _strnicmp(v4, (const char *)arg, *(char **)(v8 + 12), *((char **)arg + 2), *((_DWORD *)arg + 3));
          if ( !v6 )
            break;
        }
        if ( (int)++v4 >= sk_num(&sk->stack) )
          return;
      }
      v7 = v8;
      *(_DWORD *)arg = v5;
      *((_DWORD *)arg + 1) = v7;
    }
  }
}
