void __usercall vostok::resources::query_result::on_decompressing_end(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  if ( *(_DWORD *)(a2 + 256) )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 0xFFFFFFFF) )
      vostok::resources::query_result::end_query_might_destroy_this_impl(0, (vostok::resources::query_result *)a2);
  }
  else
  {
    vostok::resources::query_result::prepare_final_resource(this, (vostok::resources::query_result *)a2);
  }
}
