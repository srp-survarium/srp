void __usercall vostok::resources::resources_manager::cooker_thread_yield(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  vostok::threading::event::wait((vostok::threading::event *)this, (unsigned int)&dword_203E0 + a2);
}
