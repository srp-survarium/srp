void __usercall vostok::render::backend::reset_depth_stencil_target(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx
  bool v3; // zf

  v2 = *(_DWORD *)(a2 + 2188);
  v3 = *(_DWORD *)(a2 + 2156) == v2;
  *(_DWORD *)(a2 + 2156) = v2;
  *(_BYTE *)(a2 + 167) |= !v3;
}
