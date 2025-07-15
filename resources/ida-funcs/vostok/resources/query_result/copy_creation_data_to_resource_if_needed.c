char __usercall vostok::resources::query_result::copy_creation_data_to_resource_if_needed@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result::copy_data_to_resource(
    *(vostok::resources::query_result **)(a2 + 212),
    a2,
    *(vostok::const_buffer *)(a2 + 208));
  return 1;
}
