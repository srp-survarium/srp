unsigned int __usercall vostok::buffer_string::find@<eax>(
        vostok::buffer_string *this@<ecx>,
        unsigned __int8 **a2@<esi>)
{
  int v2; // eax

  strstr(*a2, (unsigned __int8 *)this);
  if ( v2 )
    return v2 - (_DWORD)*a2;
  else
    return -1;
}
