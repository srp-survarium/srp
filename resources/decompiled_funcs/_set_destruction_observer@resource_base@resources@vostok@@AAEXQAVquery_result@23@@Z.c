void __usercall vostok::resources::resource_base::set_destruction_observer(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 188) = this;
}
