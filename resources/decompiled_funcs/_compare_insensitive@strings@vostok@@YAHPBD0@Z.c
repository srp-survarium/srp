int __usercall vostok::strings::compare_insensitive@<eax>(const char *left@<ecx>, const char *right@<eax>)
{
  return _stricmp(left, right);
}
