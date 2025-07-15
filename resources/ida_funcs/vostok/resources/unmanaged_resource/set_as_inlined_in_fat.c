void __usercall vostok::resources::unmanaged_resource::set_as_inlined_in_fat(
        vostok::resources::unmanaged_resource *this@<ecx>,
        int a2@<eax>)
{
  *(_BYTE *)(a2 + 260) = 1;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 208), 1u);
}
