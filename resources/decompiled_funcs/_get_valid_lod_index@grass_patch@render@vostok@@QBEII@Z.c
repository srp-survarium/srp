vostok::render::grass_patch *__usercall vostok::render::grass_patch::get_valid_lod_index@<eax>(
        vostok::render::grass_patch *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::grass_patch *result; // eax

  result = *(vostok::render::grass_patch **)(a2 + 16452);
  if ( result )
  {
    if ( this < result )
      return this;
    else
      return (vostok::render::grass_patch *)((char *)result - 1);
  }
  return result;
}
