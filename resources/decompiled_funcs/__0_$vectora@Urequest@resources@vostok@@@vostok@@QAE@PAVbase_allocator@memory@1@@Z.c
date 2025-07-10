void __usercall vostok::vectora<vostok::resources::request>::vectora<vostok::resources::request>(
        vostok::vectora<vostok::resources::request> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  int f; // edx

  f = (int)survarium::g_allocator.f_.f_;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = f;
  a2[3] = 0;
}
