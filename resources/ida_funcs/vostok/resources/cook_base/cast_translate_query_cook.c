vostok::resources::translate_query_cook *__usercall vostok::resources::cook_base::cast_translate_query_cook@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_BYTE *)(a2 + 24) & 8) != 8 ? 0 : (vostok::resources::translate_query_cook *)a2;
}
