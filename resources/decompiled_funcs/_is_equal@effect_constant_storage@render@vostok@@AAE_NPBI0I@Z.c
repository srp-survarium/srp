char __usercall vostok::render::effect_constant_storage::is_equal@<al>(
        const unsigned int *a_ptr@<ecx>,
        const unsigned int *b_ptr@<edx>,
        unsigned int num_comparision@<esi>,
        vostok::render::effect_constant_storage *this)
{
  unsigned int v4; // eax

  v4 = 0;
  if ( !num_comparision )
    return 1;
  while ( *a_ptr == *b_ptr )
  {
    ++v4;
    ++a_ptr;
    ++b_ptr;
    if ( v4 >= num_comparision )
      return 1;
  }
  return 0;
}
