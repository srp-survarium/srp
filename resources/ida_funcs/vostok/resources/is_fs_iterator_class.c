BOOL __usercall vostok::resources::is_fs_iterator_class@<eax>(const vostok::resources::class_id_enum class_id@<eax>)
{
  return class_id == fs_iterator_class || class_id == fs_iterator_recursive_class;
}
