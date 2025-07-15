void __usercall vostok::render::state_descriptor::set_cull_mode(
        vostok::render::state_descriptor *this@<ecx>,
        int a2@<eax>)
{
  bool v2; // zf

  v2 = *(_DWORD *)(a2 + 4) == (_DWORD)this;
  *(_DWORD *)(a2 + 4) = this;
  *(_BYTE *)(a2 + 360) |= !v2;
}
