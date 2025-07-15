void __usercall vostok::fs_new::physical_path_initializer::physical_path_initializer(
        vostok::fs_new::physical_path_initializer *this@<ecx>,
        _DWORD *a2@<edi>)
{
  *a2 = -1;
  a2[1] = -1;
  a2[2] = 0;
  vostok::fs_new::physical_path_info_data::physical_path_info_data(
    (vostok::fs_new::physical_path_info_data *)this,
    (int)(a2 + 4));
  a2[78] = 0;
}
