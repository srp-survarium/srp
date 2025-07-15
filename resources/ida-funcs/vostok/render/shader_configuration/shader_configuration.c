void __usercall vostok::render::shader_configuration::shader_configuration(
        vostok::render::shader_configuration *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 10) = *(_BYTE *)(a2 + 10) & 0xF1 | 8;
}
