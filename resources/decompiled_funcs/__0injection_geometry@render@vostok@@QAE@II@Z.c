void __usercall vostok::render::injection_geometry::injection_geometry(
        vostok::render::injection_geometry *this@<ecx>,
        _DWORD *a2@<esi>)
{
  *a2 = 0;
  a2[1] = 0;
  a2[4] = 0;
  a2[5] = 0;
  a2[3] = 8;
  vostok::render::injection_geometry::prepare(this, (int)a2);
}
