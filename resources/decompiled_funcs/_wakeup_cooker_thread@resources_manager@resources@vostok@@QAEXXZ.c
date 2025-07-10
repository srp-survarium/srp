void __usercall vostok::resources::resources_manager::wakeup_cooker_thread(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  SetEvent(*(HANDLE *)((char *)&dword_203E0 + a2));
}
