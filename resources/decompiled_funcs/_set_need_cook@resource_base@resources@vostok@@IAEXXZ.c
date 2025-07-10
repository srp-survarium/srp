void __usercall vostok::resources::resource_base::set_need_cook(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>)
{
  vostok::threading::interlocked_or((volatile int *)(a2 + 8), 0x10u);
}
