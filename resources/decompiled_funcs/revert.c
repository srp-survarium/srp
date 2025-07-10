vostok::animation::comparison_result_enum __usercall revert@<eax>(
        vostok::animation::comparison_result_enum result@<eax>)
{
  if ( result == more )
    return 1;
  if ( result == less )
    return 2;
  return result;
}
