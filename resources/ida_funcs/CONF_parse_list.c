int __cdecl CONF_parse_list(
        char *list_,
        unsigned __int8 sep,
        int nospc,
        int (__cdecl *list_cb)(const char *, int, void *),
        void *arg)
{
  char *v5; // edi
  int result; // eax
  unsigned __int8 v7; // al
  char *v8; // eax
  char *v9; // ebx
  char *v10; // esi
  int v11; // eax

  v5 = list_;
  if ( list_ )
  {
    while ( 1 )
    {
      if ( nospc )
      {
        v7 = *v5;
        if ( *v5 )
        {
          do
          {
            if ( !isspace(v7) )
              break;
            v7 = *++v5;
          }
          while ( v7 );
        }
      }
      strchr(v5, sep);
      v9 = v8;
      if ( v8 == v5 || !*v5 )
      {
        result = list_cb(0, 0, arg);
      }
      else
      {
        v10 = v8 ? v8 - 1 : &v5[strlen(v5) - 1];
        if ( nospc && isspace((unsigned __int8)*v10) )
        {
          do
            v11 = (unsigned __int8)*--v10;
          while ( isspace(v11) );
        }
        result = list_cb(v5, v10 - v5 + 1, arg);
      }
      if ( result <= 0 )
        break;
      if ( !v9 )
        return 1;
      v5 = v9 + 1;
    }
  }
  else
  {
    ERR_put_error(0xEu, 119, 115, ".\\crypto\\conf\\conf_mod.c", 588);
    return 0;
  }
  return result;
}
