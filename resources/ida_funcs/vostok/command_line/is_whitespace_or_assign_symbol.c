BOOL __usercall vostok::command_line::is_whitespace_or_assign_symbol@<eax>(unsigned __int8 value@<al>)
{
  int v1; // eax

  strchr(" \t=", value);
  return v1 != 0;
}
