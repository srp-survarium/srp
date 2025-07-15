void __usercall vostok::resources::query_result::on_file_operation_end(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::query_result *v2; // [esp-8h] [ebp-8h]

  vostok::resources::query_result::set_is_unmovable_if_needed(*(vostok::resources::managed_resource **)(a2 + 648), 0);
  vostok::resources::query_result::set_is_unmovable_if_needed(*(vostok::resources::managed_resource **)(a2 + 216), 0);
  vostok::resources::query_result::set_is_unmovable_if_needed(*(vostok::resources::managed_resource **)(a2 + 644), 0);
  if ( (*(_DWORD *)(a2 + 704) & 2) != 0 )
    vostok::resources::query_result::on_load_operation_end(v2, a2);
  else
    vostok::resources::query_result::on_save_operation_end(v2, (void **)a2);
}
