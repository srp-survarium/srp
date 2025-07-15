void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist )
  {
    strlen((unsigned __int8 *)s);
    memmove((unsigned __int8 *)&s[dist], (unsigned __int8 *)s, v3 + 1);
  }
}
