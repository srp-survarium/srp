void __usercall vostok::resources::resource_base::set_name_registry_entry(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 176) = this;
}
