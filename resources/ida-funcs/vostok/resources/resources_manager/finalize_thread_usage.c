void __usercall vostok::resources::resources_manager::finalize_thread_usage(
        vostok::resources::resources_manager *this@<ecx>,
        bool call_from_main_thread@<al>)
{
  vostok::resources::resources_manager::wait_and_dispatch_callbacks(this, (bool)this, call_from_main_thread);
}
