void __usercall vostok::render::backend::set_ib(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  bool v2; // dl
  vostok::render::backend **v3; // eax

  v2 = *(vostok::render::backend **)(a2 + 408) != this || *(_DWORD *)(a2 + 7468);
  *(_BYTE *)(a2 + 91) |= v2;
  *(_DWORD *)(a2 + 408) = this;
  v3 = (vostok::render::backend **)(a2 + 7468);
  *v3 = 0;
  if ( this )
    this = (vostok::render::backend *)this->vertex_small.m_position;
  *v3 = this;
}
