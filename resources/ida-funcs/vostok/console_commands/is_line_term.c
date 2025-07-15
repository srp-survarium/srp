BOOL __usercall vostok::console_commands::is_line_term@<eax>(char a@<al>)
{
  return a == 13 || a == 10;
}
