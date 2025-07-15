void __usercall vostok::fs_new::physical_path_iterator::physical_path_iterator(
        vostok::fs_new::physical_path_iterator *this@<eax>,
        const vostok::fs_new::physical_path_initializer *initializer@<edi>,
        vostok::fs_new::physical_path_info *a3@<ecx>)
{
  vostok::fs_new::physical_path_info::physical_path_info(a3, &this->device, initializer);
  this->search_handle = initializer->search_handle;
}
