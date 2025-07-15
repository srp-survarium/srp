char __userpurge vostok::render::effect_constant_storage::is_equal@<al>(
        const unsigned int *a_ptr@<ecx>,
        const unsigned int *b_ptr@<edx>,
        vostok::render::effect_constant_storage *this,
        const unsigned int num_comparision)
{
  unsigned int v4; // eax

  v4 = 0;
  if ( !this )
    return 1;
  while ( *a_ptr == *b_ptr )
  {
    ++v4;
    ++a_ptr;
    ++b_ptr;
    if ( v4 >= (unsigned int)this )
      return 1;
  }
  return 0;
}
