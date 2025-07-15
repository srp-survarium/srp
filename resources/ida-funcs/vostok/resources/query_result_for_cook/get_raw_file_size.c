unsigned int __usercall vostok::resources::query_result_for_cook::get_raw_file_size@<eax>(
        vostok::resources::query_result_for_cook *this@<ecx>,
        _DWORD *a2@<eax>)
{
  vostok::vfs::base_node<1> *v2; // ecx

  if ( !a2[41] )
    return a2[53];
  v2 = (vostok::vfs::base_node<1> *)a2[42];
  if ( !v2 )
    v2 = (vostok::vfs::base_node<1> *)a2[41];
  return vostok::vfs::get_file_size<1>(v2);
}
