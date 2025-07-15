BOOL __usercall vostok::resources::query_result::is_translate_query@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  return vostok::resources::cook_base::find_translate_query_cook(*(vostok::resources::class_id_enum *)(a2 + 132)) != 0;
}
