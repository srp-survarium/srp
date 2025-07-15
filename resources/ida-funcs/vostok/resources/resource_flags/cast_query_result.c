vostok::resources::query_result *__usercall vostok::resources::resource_flags::cast_query_result@<eax>(
        vostok::resources::resource_flags *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 8) & 2) != 2 ? 0 : (vostok::resources::query_result *)a2;
}


const vostok::resources::query_result *__usercall vostok::resources::resource_flags::cast_query_result@<eax>(
        vostok::resources::resource_flags *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 8) & 2) != 2 ? 0 : (const vostok::resources::query_result *)a2;
}
