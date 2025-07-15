void __usercall vostok::render::backend::reset_render_targets(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  bool v3; // zf
  _BYTE *v4; // ecx
  _DWORD *v5; // eax
  int v6; // esi

  v2 = *(_DWORD *)(a2 + 7436);
  v3 = *(_DWORD *)(a2 + 7368) == v2;
  *(_DWORD *)(a2 + 7368) = v2;
  *(_BYTE *)(a2 + 113) |= !v3;
  v4 = (_BYTE *)(a2 + 114);
  v5 = (_DWORD *)(a2 + 7372);
  v6 = 3;
  do
  {
    *v4 |= *v5 != 0;
    *v5++ = 0;
    ++v4;
    --v6;
  }
  while ( v6 );
}
