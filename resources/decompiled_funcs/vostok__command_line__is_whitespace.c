BOOL __usercall vostok::command_line::is_whitespace@<eax>(unsigned __int8 value@<al>)
{
  int v1; // eax

  strchr(" \t", value);
  return v1 != 0;
}
