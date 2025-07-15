void __usercall vostok::resources::query_result_for_cook::clear_user_data(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v2; // edi
  int v3; // esi

  v2 = (_DWORD *)(a2 + 264);
  v3 = *(_DWORD *)(a2 + 264);
  if ( v3 )
    vostok::variant<32>::destroy_previous_variable_if_needed((vostok::variant<32> *)this, v3);
  *v2 = 0;
}
