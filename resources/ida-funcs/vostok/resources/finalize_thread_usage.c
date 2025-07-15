void __cdecl vostok::resources::finalize_thread_usage(bool calling_from_main_thread)
{
  vostok::resources::resources_manager *v1; // ecx

  vostok::resources::resources_manager::wait_and_dispatch_callbacks(v1, calling_from_main_thread, 1);
}
