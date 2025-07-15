void __usercall vostok::resources::query_result_for_cook::set_error_type(
        vostok::resources::query_result_for_cook *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 256) = this;
}
