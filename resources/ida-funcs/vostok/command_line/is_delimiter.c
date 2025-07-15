BOOL __usercall vostok::command_line::is_delimiter@<eax>(unsigned __int8 value@<al>, char *delimiters)
{
  int v2; // eax

  strchr(delimiters, value);
  return v2 != 0;
}
