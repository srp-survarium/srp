void __usercall vostok::render::backend::set_vb_instance_data(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  bool v2; // dl
  vostok::render::backend **v3; // eax

  v2 = *(vostok::render::backend **)(a2 + 400) != this || *(_DWORD *)(a2 + 7452) != 24 || *(_DWORD *)(a2 + 7456);
  *(_BYTE *)(a2 + 89) |= v2;
  *(_DWORD *)(a2 + 400) = this;
  *(_DWORD *)(a2 + 7452) = 24;
  v3 = (vostok::render::backend **)(a2 + 7456);
  *v3 = 0;
  if ( this )
    this = (vostok::render::backend *)this->vertex_small.m_position;
  *v3 = this;
}
