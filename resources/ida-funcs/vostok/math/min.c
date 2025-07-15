int __usercall vostok::math::min@<eax>(int left@<eax>, int right@<ecx>)
{
  return right + (left < right ? left - right : 0);
}


unsigned int __fastcall vostok::math::min(unsigned int left, unsigned int right)
{
  return right + (left < right ? left - right : 0);
}


void __cdecl vostok::math::min()
{
  ;
}


unsigned __int64 __cdecl vostok::math::min(unsigned __int64 left, unsigned __int64 right)
{
  return right + (left < right ? left - right : 0);
}
