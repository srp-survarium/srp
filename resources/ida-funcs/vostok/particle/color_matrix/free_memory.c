void __usercall vostok::particle::color_matrix::free_memory(
        vostok::particle::color_matrix *this@<ecx>,
        _DWORD *a2@<esi>)
{
  if ( a2[2] && a2[3] )
  {
    if ( *a2 )
      ((void (__thiscall *)(vostok::particle::color_matrix *, _DWORD, const char *, const char *, int))LODWORD(this->m_points.pointer[1].color.x))(
        this,
        *a2,
        "vostok::particle::color_matrix::free_memory",
        "c:\\survarium.deploy\\sources\\vostok\\particle\\sources\\color_matrix_inline.h",
        283);
    *a2 = 0;
    a2[2] = 0;
    a2[3] = 0;
  }
}
