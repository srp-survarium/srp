void __usercall vostok::render::backend::on_device_destroy(vostok::render::backend *this@<ecx>, int a2@<esi>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 116);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 116));
    *(_DWORD *)(a2 + 116) = 0;
  }
  *(_DWORD *)(a2 + 116) = 0;
}
