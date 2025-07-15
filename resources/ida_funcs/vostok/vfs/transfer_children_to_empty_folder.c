void __cdecl vostok::vfs::transfer_children_to_empty_folder(
        vostok::vfs::base_folder_node<1> *dest_folder,
        vostok::vfs::base_folder_node<1> *source_folder)
{
  vostok::platform_pointer_selector<vostok::vfs::base_folder_node<1>,1>::helper *v2; // ecx
  vostok::vfs::base_folder_node<1> *v3; // [esp+1Ch] [ebp-24h] BYREF
  int v4; // [esp+20h] [ebp-20h]
  vostok::platform_pointer_selector<vostok::vfs::base_folder_node<1>,1>::helper *p_m_parent; // [esp+24h] [ebp-1Ch]
  vostok::vfs::base_folder_node<1> **v6; // [esp+28h] [ebp-18h]
  vostok::vfs::base_node<1> *pointer; // [esp+2Ch] [ebp-14h]
  vostok::vfs::base_node<1> *child; // [esp+3Ch] [ebp-4h]

  for ( child = source_folder->m_first_child.pointer; child; child = pointer )
  {
    v6 = &v3;
    v4 = 0;
    v3 = dest_folder;
    p_m_parent = &child->m_parent;
    v2 = &child->m_parent;
    child->m_parent.pointer = dest_folder;
    HIDWORD(v2->max_storage) = v4;
    pointer = child->m_next.pointer;
  }
  dest_folder->m_first_child.max_storage = (unsigned int)source_folder->m_first_child.pointer;
  source_folder->m_first_child.max_storage = 0;
}
