bool __usercall vostok::strings::equal@<al>(const char *left@<eax>, const char *right@<ecx>)
{
  return strcmp(left, right) == 0;
}
