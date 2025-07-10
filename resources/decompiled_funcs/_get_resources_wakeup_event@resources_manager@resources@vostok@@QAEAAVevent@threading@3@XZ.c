vostok::threading::event *__usercall vostok::resources::resources_manager::get_resources_wakeup_event@<eax>(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  return (vostok::threading::event *)((char *)&dword_203D0 + a2);
}
