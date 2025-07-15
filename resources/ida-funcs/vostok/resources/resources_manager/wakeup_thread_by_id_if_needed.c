void __userpurge vostok::resources::resources_manager::wakeup_thread_by_id_if_needed(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resources_manager *thread_id)
{
  vostok::resources::resources_manager *v3; // ecx

  v3 = *(vostok::resources::resources_manager **)((char *)&loc_203D3 + a2 + 1);
  if ( thread_id == v3 )
  {
    vostok::resources::resources_manager::wakeup_resources_thread(v3, a2);
  }
  else if ( thread_id == *(vostok::resources::resources_manager **)((char *)&loc_203DF + a2 + 1) )
  {
    SetEvent(*(HANDLE *)((char *)&loc_203E8 + a2));
  }
}
