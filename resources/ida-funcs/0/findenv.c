int __usercall findenv@<eax>(const char *len@<edi>, char *name)
{
  char **i; // esi
  int v3; // eax
  char v4; // al

  for ( i = _environ; ; ++i )
  {
    if ( !*i )
      return -(i - _environ);
    _mbsnbicoll(len, (int)i, name, *i, (unsigned int)len);
    if ( !v3 )
    {
      v4 = (*i)[(_DWORD)len];
      if ( v4 == 61 || !v4 )
        break;
    }
  }
  return i - _environ;
}
