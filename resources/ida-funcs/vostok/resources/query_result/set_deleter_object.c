void __userpurge vostok::resources::query_result::set_deleter_object(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::resources::unmanaged_resource *resource)
{
  vostok::resources::cook_base *cook; // eax
  unsigned int thread_id; // eax
  vostok::resources::cook_base *v5; // edx
  vostok::resources::cook_base *v6; // [esp-4h] [ebp-4h]

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  thread_id = vostok::resources::cook_base::allocate_thread_id(v6, (int)cook);
  if ( thread_id == -5 )
    thread_id = *(_DWORD *)(a2 + 716);
  vostok::resources::unmanaged_resource::set_deleter_object(resource, v5, thread_id);
}
