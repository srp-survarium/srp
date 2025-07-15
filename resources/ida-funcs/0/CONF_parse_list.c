int __usercall CONF_parse_list@<eax>(
        int a1@<ebx>,
        char *list_,
        unsigned __int8 sep,
        int nospc,
        int (__cdecl *list_cb)(const char *, int, void *),
        void *arg)
{
  char *v6; // edi
  int result; // eax
  unsigned __int8 v8; // al
  char *v9; // eax
  char *v10; // ebx
  char *v11; // esi
  int v12; // eax

  v6 = list_;
  if ( list_ )
  {
    while ( 1 )
    {
      if ( nospc )
      {
        v8 = *v6;
        if ( *v6 )
        {
          do
          {
            if ( !isspace(v8) )
              break;
            v8 = *++v6;
          }
          while ( v8 );
        }
      }
      strchr(v6, sep);
      v10 = v9;
      if ( v9 == v6 || !*v6 )
      {
        result = list_cb(0, 0, arg);
      }
      else
      {
        v11 = v9 ? v9 - 1 : &v6[strlen(v6) - 1];
        if ( nospc && isspace((unsigned __int8)*v11) )
        {
          do
            v12 = (unsigned __int8)*--v11;
          while ( isspace(v12) );
        }
        result = list_cb(v6, v11 - v6 + 1, arg);
      }
      if ( result <= 0 )
        break;
      if ( !v10 )
        return 1;
      v6 = v10 + 1;
    }
  }
  else
  {
    ERR_put_error(a1, 0xEu, 119, 115, ".\\crypto\\conf\\conf_mod.c", 588);
    return 0;
  }
  return result;
}
