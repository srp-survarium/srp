unsigned int __userpurge vostok::buffer_string::find@<eax>(
        vostok::buffer_string *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        char *s,
        unsigned int offs)
{
  int v4; // eax

  strstr(*a2, (unsigned __int8 *)s);
  if ( v4 )
    return v4 - (_DWORD)*a2;
  else
    return -1;
}
