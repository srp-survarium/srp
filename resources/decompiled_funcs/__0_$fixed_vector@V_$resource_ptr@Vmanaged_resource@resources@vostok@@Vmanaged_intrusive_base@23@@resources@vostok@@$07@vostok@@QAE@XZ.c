void __usercall vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8>(
        vostok::fixed_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,8> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = a2 + 2;
  a2[1] = a2 + 2;
}
