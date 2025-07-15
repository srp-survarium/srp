void __userpurge vostok::render::scene::update_light(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        long double a3@<esi:edi>,
        unsigned int id,
        vostok::render::light_props *props)
{
  _DWORD *v5; // eax
  int v6; // eax

  v5 = *(_DWORD **)((char *)&dword_8B9660 + a2);
  HIDWORD(a3) = *v5;
  v6 = (v5[1] - *v5) >> 3;
  while ( v6 > 0 )
  {
    LODWORD(a3) = HIDWORD(a3) + 8 * (v6 >> 1);
    if ( *(_DWORD *)(LODWORD(a3) + 4) >= id )
    {
      v6 >>= 1;
    }
    else
    {
      HIDWORD(a3) = LODWORD(a3) + 8;
      v6 += -1 - (v6 >> 1);
    }
  }
  vostok::render::fill_light(a3, *(vostok::render::light **)HIDWORD(a3), props);
}
