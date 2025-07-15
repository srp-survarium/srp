unsigned int __usercall vostok::resources::query_result::allocate_thread_id@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::cook_base *cook; // eax
  unsigned int result; // eax
  vostok::resources::cook_base *v4; // [esp-8h] [ebp-8h]

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  result = vostok::resources::cook_base::allocate_thread_id(v4, (int)cook);
  if ( result == -5 )
    return *(_DWORD *)(a2 + 716);
  return result;
}
