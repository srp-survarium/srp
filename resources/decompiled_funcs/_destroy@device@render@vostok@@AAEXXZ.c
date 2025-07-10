void __usercall vostok::render::device::destroy(vostok::render::device *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 304) + 440))(*(_DWORD *)(a2 + 304));
  log_ref_count<ID3D11Device>(*(ID3D11Device **)(a2 + 300), "* destroy: device");
  v2 = *(_DWORD *)(a2 + 300);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 300));
    *(_DWORD *)(a2 + 300) = 0;
  }
  log_ref_count<IDXGIAdapter>(*(IDXGIAdapter **)(a2 + 296));
  v3 = *(_DWORD *)(a2 + 296);
  if ( v3 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(a2 + 296));
    *(_DWORD *)(a2 + 296) = 0;
  }
}
