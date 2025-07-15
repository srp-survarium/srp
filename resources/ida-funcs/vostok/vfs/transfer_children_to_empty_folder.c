void __usercall vostok::vfs::transfer_children_to_empty_folder(
        vostok::vfs::base_folder_node<1> *dest_folder@<edx>,
        vostok::vfs::base_folder_node<1> *source_folder@<eax>)
{
  vostok::vfs::base_node<1> *i; // ecx

  for ( i = source_folder->m_first_child.pointer; i; i = i->m_next.pointer )
  {
    i->m_parent.pointer = dest_folder;
    HIDWORD(i->m_parent.max_storage) = 0;
  }
  dest_folder->m_first_child.max_storage = (unsigned int)source_folder->m_first_child.pointer;
  source_folder->m_first_child.max_storage = 0;
}
