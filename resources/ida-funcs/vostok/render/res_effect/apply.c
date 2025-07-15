BOOL __usercall vostok::render::res_effect::apply@<eax>(vostok::render::res_effect *this@<ecx>, _DWORD *a2@<eax>)
{
  BOOL result; // eax

  result = 0;
  if ( (unsigned int)this < (a2[71] - a2[70]) >> 2 )
  {
    a2[69] = this;
    if ( vostok::render::res_effect::apply_pass(this, (unsigned int)this) )
      return 1;
  }
  return result;
}
