BOOL __usercall vostok::resources::query_result::ready_to_retry_action_that_caused_out_of_memory@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  return *(_BYTE *)(a2 + 708) && !*(_DWORD *)(a2 + 692);
}
