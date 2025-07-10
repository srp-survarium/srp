void __usercall vostok::resources::resource_base::set_in_grm_observed_list(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>)
{
  vostok::threading::interlocked_or((volatile int *)(a2 + 8), 0x20u);
}
