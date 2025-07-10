void __usercall vostok::render::clouds::invalidate(vostok::render::clouds *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 2704) = -1;
  *(_DWORD *)(a2 + 2708) = -1;
}
