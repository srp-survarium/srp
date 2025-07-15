BOOL __usercall vostok::resources::resources_manager::resources_thread_can_exit@<eax>(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<eax>)
{
  return vostok::resources::resources_manager::thread_can_exit(this, a2)
      && !*(_DWORD *)((char *)&loc_2053C + (_DWORD)a2);
}
