void __usercall vostok::resources::resource_quality::set_target_satisfaction(
        vostok::resources::resource_quality *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>)
{
  *(_DWORD *)(a2 + 116) = a3;
}
