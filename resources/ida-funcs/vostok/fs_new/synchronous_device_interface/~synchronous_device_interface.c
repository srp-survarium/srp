void __usercall vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(
        vostok::fs_new::synchronous_device_interface *this@<ecx>,
        int *a2@<eax>)
{
  int v2; // eax

  v2 = *a2;
  if ( v2 )
  {
    *(_DWORD *)(*(_DWORD *)(v2 + 32) + 180) = -1;
    SetEvent(*(HANDLE *)(v2 + 48));
  }
}
