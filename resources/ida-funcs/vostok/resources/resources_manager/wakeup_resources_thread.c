void __usercall vostok::resources::resources_manager::wakeup_resources_thread(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  SetEvent(*(HANDLE *)((char *)&dword_203D0 + a2));
}
