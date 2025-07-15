bool __usercall vostok::render::res_effect::apply@<al>(vostok::render::res_effect *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 22048) = this;
  return vostok::render::res_effect::apply_pass(this, a2) != 0;
}
