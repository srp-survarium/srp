BOOL __usercall vostok::resources::query_result_for_cook::is_helper_query_for_mount@<eax>(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 688) & 0x8000000) == 0x8000000;
}
