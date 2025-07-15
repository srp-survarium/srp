void __usercall vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  if ( this == *(vostok::resources::resources_manager **)((char *)&dword_203CC + a2) )
  {
    SetEvent(*(HANDLE *)((char *)&dword_203D0 + a2));
  }
  else if ( this == *(vostok::resources::resources_manager **)&byte_203D8[a2] )
  {
    SetEvent(*(HANDLE *)((char *)&dword_203E0 + a2));
  }
}
