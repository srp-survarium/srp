BOOL __usercall vostok::resources::fs_task::is_mount_task@<eax>(vostok::resources::fs_task *this@<ecx>, int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 12);
  return v2 > 2 && v2 < 8;
}
