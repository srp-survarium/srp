void __userpurge vostok::resources::resources_manager::change_count_of_pending_mount_operations(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>,
        int change)
{
  volatile signed __int32 *v3; // eax

  v3 = (volatile signed __int32 *)((char *)&loc_201B0 + a2);
  if ( change == 1 )
    _InterlockedExchangeAdd(v3, 1u);
  else
    _InterlockedExchangeAdd(v3, 0xFFFFFFFF);
}
