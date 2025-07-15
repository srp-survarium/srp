void __usercall vostok::render::grass_world::remove_trample(vostok::render::grass_world *this@<ecx>, int a2@<eax>)
{
  int v2; // esi
  int i; // edi

  v2 = *(_DWORD *)(a2 + 300);
  for ( i = *(_DWORD *)(a2 + 304); v2 != i; v2 += 4 )
    vostok::render::grass_patch::remove_trample((vostok::render::grass_patch *)this);
}
