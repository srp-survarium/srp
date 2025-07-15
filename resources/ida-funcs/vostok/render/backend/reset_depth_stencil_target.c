void __usercall vostok::render::backend::reset_depth_stencil_target(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  bool v3; // zf

  v2 = *(_DWORD *)(a2 + 7440);
  v3 = *(_DWORD *)(a2 + 7384) == v2;
  *(_DWORD *)(a2 + 7384) = v2;
  *(_BYTE *)(a2 + 117) |= !v3;
}
