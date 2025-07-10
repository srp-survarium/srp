int __usercall conf_value_cmp@<eax>(const CONF_VALUE *a@<edi>, const CONF_VALUE *b@<esi>)
{
  int result; // eax
  char *name; // eax
  char *v4; // ecx
  bool v5; // cf
  unsigned __int8 v6; // dl

  if ( a->section == b->section || (result = strcmp(a->section, b->section)) == 0 )
  {
    name = a->name;
    if ( name && (v4 = b->name) != 0 )
    {
      while ( 1 )
      {
        v5 = (unsigned __int8)*name < (unsigned __int8)*v4;
        if ( *name != *v4 )
          break;
        if ( !*name )
          return 0;
        v6 = name[1];
        v5 = v6 < (unsigned __int8)v4[1];
        if ( v6 != v4[1] )
          break;
        name += 2;
        v4 += 2;
        if ( !v6 )
          return 0;
      }
      return -v5 - (v5 - 1);
    }
    else if ( name == b->name )
    {
      return 0;
    }
    else
    {
      return 2 * (name != 0) - 1;
    }
  }
  return result;
}
