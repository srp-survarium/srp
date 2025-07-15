void __usercall vostok::resources::query_result::on_observed_resource_destroyed(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 692), 0xFFFFFFFF);
}
