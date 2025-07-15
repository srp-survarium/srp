void __usercall vostok::render::effect_options_descriptor::effect_options_descriptor(
        vostok::render::effect_options_descriptor *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 8) = this + 1;
  *(_WORD *)(a2 + 16) = 3;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_WORD *)(a2 + 18) = 0;
  *(_WORD *)(a2 + 20) = 1024;
}


void __usercall vostok::render::effect_options_descriptor::effect_options_descriptor(
        vostok::render::effect_options_descriptor *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_WORD *)(a2 + 16) = 0;
  *(_WORD *)(a2 + 18) = 0;
  *(_WORD *)(a2 + 20) = 0;
}
