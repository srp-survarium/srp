bool __usercall compare_parts@<al>(const char *s1@<eax>, const char *s2@<ecx>)
{
  char v3; // dl
  char v4; // al
  char v5; // cl

  while ( 1 )
  {
    v3 = *s1;
    if ( !*s1 || v3 == 58 )
      break;
    v4 = *s2;
    if ( !*s2 || v4 == 58 )
      return 0;
    if ( v3 != v4 )
      return *s1 < *s2;
    ++s1;
    ++s2;
  }
  v5 = *s2;
  return v5 && v5 != 58;
}
