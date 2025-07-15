void __usercall vostok::resources::resources_manager::wakeup_resources_thread(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  SetEvent(*(HANDLE *)((char *)&loc_203D7 + a2 + 1));
}
