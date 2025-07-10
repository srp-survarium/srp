void __usercall vostok::resources::managed_resource::set_creation_source(
        vostok::resources::managed_resource *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 192) = this;
}
