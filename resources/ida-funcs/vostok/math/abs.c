int __usercall vostok::math::abs@<eax>(int value@<eax>)
{
  return (value >> 31) ^ ((value >> 31) + value);
}


void __cdecl vostok::math::abs()
{
  ;
}
