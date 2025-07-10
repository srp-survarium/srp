unsigned int __usercall vostok::math::align_up<unsigned int>@<eax>(
        unsigned int value@<ecx>,
        unsigned int align_on@<esi>)
{
  if ( value % align_on )
    return align_on + value - value % align_on;
  return value;
}
