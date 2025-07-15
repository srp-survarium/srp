void __usercall vostok::resources::query_result::send_to_create_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  if ( vostok::resources::cook_base::does_create_resource(*(vostok::resources::class_id_enum *)(a2 + 132)) )
  {
    vostok::resources::resources_manager::add_resource_to_create((vostok::resources::query_result *)a2);
  }
  else
  {
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 648),
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 216));
    v2 = *(_DWORD *)(a2 + 216);
    *(_DWORD *)(a2 + 256) = 0;
    *(_DWORD *)(a2 + 260) = 3;
    *(_DWORD *)(a2 + 712) = *(_DWORD *)(v2 + 92);
    vostok::resources::query_result::on_create_resource_end((vostok::resources::query_result *)a2);
  }
}
