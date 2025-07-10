void __usercall vostok::resources::mount_by_config_helper::~mount_by_config_helper(
        vostok::resources::mount_by_config_helper *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  void (__cdecl *v4)(int, int, int); // eax

  v2 = a2[82];
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 28), 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(
      (vostok::resources::intrusive_fs_task_unmount_base *)this,
      (vostok::resources::fs_task_unmount *)a2[82]);
  v3 = *a2;
  if ( *a2 )
  {
    if ( (v3 & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(int, int, int))(v3 & 0xFFFFFFFE);
      if ( v4 )
        v4((int)(a2 + 2), (int)(a2 + 2), 2);
    }
    *a2 = 0;
  }
}
