void __usercall vostok::render::light::set_attenuation_power(
        vostok::render::light *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>)
{
  *(_DWORD *)(a2 + 220) = a3;
}
