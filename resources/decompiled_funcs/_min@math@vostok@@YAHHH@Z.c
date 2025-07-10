int __usercall vostok::math::min@<eax>(int left@<eax>, int right@<ecx>)
{
  return right + (left < right ? left - right : 0);
}
