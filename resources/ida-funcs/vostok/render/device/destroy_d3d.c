void __usercall vostok::render::device::destroy_d3d(vostok::render::device *this@<ecx>, int a2@<esi>)
{
  int v2; // eax

  log_ref_count<IDXGIAdapter>(*(IDXGIAdapter **)(a2 + 296));
  v2 = *(_DWORD *)(a2 + 296);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 296));
    *(_DWORD *)(a2 + 296) = 0;
  }
}
