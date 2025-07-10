void __usercall vostok::render::backend::reset_render_targets(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx
  bool v3; // zf
  _BYTE *v4; // ecx
  _DWORD *v5; // eax
  int v6; // esi

  v2 = *(_DWORD *)(a2 + 2184);
  v3 = *(_DWORD *)(a2 + 2140) == v2;
  *(_DWORD *)(a2 + 2140) = v2;
  *(_BYTE *)(a2 + 163) |= !v3;
  v4 = (_BYTE *)(a2 + 164);
  v5 = (_DWORD *)(a2 + 2144);
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
