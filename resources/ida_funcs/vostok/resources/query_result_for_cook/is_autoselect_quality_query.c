bool __usercall vostok::resources::query_result_for_cook::is_autoselect_quality_query@<al>(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 688) & 0x10000000) == 0x10000000;
}
