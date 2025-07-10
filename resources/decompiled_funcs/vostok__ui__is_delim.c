BOOL __usercall vostok::ui::is_delim@<eax>(unsigned __int8 ch@<al>)
{
  return ch == 32
      || ch == 9
      || ch == 13
      || ch == 10
      || ch == 44
      || ch == 46
      || ch == 58
      || ch == 33
      || ch == 40
      || ch == 41
      || ch == 45
      || ch == 43
      || ch == 42;
}
