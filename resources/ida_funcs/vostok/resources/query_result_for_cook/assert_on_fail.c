BOOL __usercall vostok::resources::query_result_for_cook::assert_on_fail@<eax>(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 328);
  return !v2 || *(_DWORD *)(v2 + 76);
}
