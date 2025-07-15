void __usercall vostok::render::res_texture::set_name(vostok::render::res_texture *this@<ecx>, int a2@<eax>)
{
  vostok::render::res_texture *v3; // eax
  vostok::buffer_string *v4; // esi

  v3 = *(vostok::render::res_texture **)(a2 + 144);
  v4 = (vostok::buffer_string *)(a2 + 144);
  if ( v3 != this )
  {
    v4->m_end = (char *)v3;
    LOBYTE(v3->__vftable) = 0;
    vostok::buffer_string::operator+=(v4, (const char *)this);
  }
}
