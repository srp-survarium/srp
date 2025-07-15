void __usercall vostok::fs_new::asynchronous_device_interface::~asynchronous_device_interface(
        vostok::fs_new::asynchronous_device_interface *this@<ecx>,
        int a2@<esi>)
{
  CloseHandle(*(HANDLE *)(a2 + 184));
  TlsFree(*(_DWORD *)(a2 + 168));
  TlsFree(*(_DWORD *)(a2 + 172));
  TlsFree(*(_DWORD *)(a2 + 80));
  TlsFree(*(_DWORD *)(a2 + 84));
}
