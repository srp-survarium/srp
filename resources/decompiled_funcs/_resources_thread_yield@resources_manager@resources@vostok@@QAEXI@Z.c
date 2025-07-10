void __usercall vostok::resources::resources_manager::resources_thread_yield(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  vostok::threading::event::wait(
    (vostok::threading::event *)this,
    (vostok::threading::event *)((char *)&dword_203D0 + a2),
    0x12Cu);
}
