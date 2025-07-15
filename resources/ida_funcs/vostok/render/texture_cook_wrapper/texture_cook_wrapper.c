void __usercall vostok::render::texture_cook_wrapper::texture_cook_wrapper(
        vostok::render::texture_cook_wrapper *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = &vostok::resources::cook_base::`vftable';
  a2[1] = 0;
  a2[2] = 7;
  a2[3] = 1;
  a2[4] = -1;
  a2[5] = -4;
  a2[6] = 8;
  a2[7] = 0;
  *a2 = &vostok::render::texture_cook_wrapper::`vftable';
}
