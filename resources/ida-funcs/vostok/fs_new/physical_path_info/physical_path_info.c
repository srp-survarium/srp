void __userpurge vostok::fs_new::physical_path_info::physical_path_info(
        vostok::fs_new::physical_path_info *this@<ecx>,
        vostok::fs_new::device_file_system_interface **a2@<esi>,
        const vostok::fs_new::physical_path_initializer *initializer)
{
  *a2 = initializer->device;
  vostok::fs_new::physical_path_info_data::physical_path_info_data(
    (vostok::fs_new::physical_path_info_data *)this,
    (int)(a2 + 2),
    &initializer->data);
  a2[76] = (vostok::fs_new::device_file_system_interface *)initializer->parent;
}


void __usercall vostok::fs_new::physical_path_info::physical_path_info(
        vostok::fs_new::physical_path_info *this@<ecx>,
        _DWORD *a2@<edi>)
{
  *a2 = 0;
  vostok::fs_new::physical_path_info_data::physical_path_info_data(
    (vostok::fs_new::physical_path_info_data *)this,
    (int)(a2 + 2));
  a2[76] = 0;
}
