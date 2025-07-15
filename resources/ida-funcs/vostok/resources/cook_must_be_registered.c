BOOL __usercall vostok::resources::cook_must_be_registered@<eax>(const vostok::resources::class_id_enum class_id@<eax>)
{
  return class_id != raw_data_class
      && class_id != raw_data_class_no_reuse
      && class_id != fs_iterator_class
      && class_id != fs_iterator_recursive_class;
}
