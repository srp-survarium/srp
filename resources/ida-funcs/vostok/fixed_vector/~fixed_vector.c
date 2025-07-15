void __usercall vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::~fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
        vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *this@<ecx>,
        int a2@<edi>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v2; // esi

  v2 = *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)a2;
  if ( *(_DWORD *)a2 == *(_DWORD *)(a2 + 4) )
  {
    *(_DWORD *)(a2 + 4) = v2;
  }
  else
  {
    do
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v2++);
    while ( v2 != *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)(a2 + 4) );
    *(_DWORD *)(a2 + 4) = *(_DWORD *)a2;
  }
}
