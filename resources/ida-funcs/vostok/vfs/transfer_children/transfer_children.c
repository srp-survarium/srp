void __thiscall vostok::vfs::transfer_children::transfer_children(
        vostok::vfs::transfer_children *this,
        vostok::vfs::vfs_hashset *hashset,
        const vostok::fs_new::virtual_path_string *path,
        unsigned int hash,
        vostok::vfs::base_node<1> *dest_start,
        vostok::vfs::base_node<1> *source_folder)
{
  vostok::fs_new::virtual_path_string *p_m_path; // ebx
  vostok::vfs::base_node<1> *v8; // ecx
  vostok::vfs::base_folder_node<1> *v9; // eax
  vostok::vfs::base_node<1> *first_child; // eax
  unsigned int v11; // esi
  vostok::buffer_string *v12; // ecx
  char *v13; // eax
  vostok::vfs::base_folder_node<1> *m_source_folder; // eax
  int max_storage_high; // edx
  vostok::vfs::base_node<1> *v16; // [esp+10h] [ebp-120h]
  int v17; // [esp+14h] [ebp-11Ch]
  vostok::fixed_string<260> *pointer; // [esp+18h] [ebp-118h]
  vostok::buffer_string v19; // [esp+1Ch] [ebp-114h] BYREF
  char v20; // [esp+12Ch] [ebp-4h]

  this->m_hashset = hashset;
  this->m_new_source_nodes.m_size = 0;
  this->m_new_source_nodes.m_first.max_storage = 0;
  this->m_new_source_nodes.m_last.max_storage = 0;
  this->m_dest_start = dest_start;
  this->m_hash = hash;
  p_m_path = &this->m_path;
  vostok::fixed_string<260>::fixed_string<260>(&this->m_path.m_string, &path->m_string);
  p_m_path->m_separator = 47;
  if ( source_folder )
    v9 = vostok::vfs::cast_folder<1>(source_folder);
  else
    v9 = 0;
  this->m_source_folder = v9;
  v17 = p_m_path->m_string.m_end - p_m_path->m_string.m_begin;
  first_child = vostok::vfs::base_node<1>::get_first_child(v8, (int)source_folder);
  v16 = first_child;
  if ( first_child )
  {
    while ( 1 )
    {
      pointer = (vostok::fixed_string<260> *)first_child->m_next.pointer;
      vostok::fixed_string<260>::fixed_string<260>(pointer, &v19, first_child->m_name);
      v20 = 47;
      v11 = vostok::fs_new::path_crc32(v19.m_begin, v19.m_end - v19.m_begin, hash);
      vostok::buffer_string::appendf(
        (int)p_m_path,
        v12,
        (vostok::buffer_string *)&stru_7FCCD0,
        (const char *)0x2F,
        v16->m_name);
      vostok::vfs::transfer_children::transfer_child(this, v16, p_m_path, v11);
      v13 = &p_m_path->m_string.m_begin[v17];
      p_m_path->m_string.m_end = v13;
      *v13 = 0;
      v16 = (vostok::vfs::base_node<1> *)pointer;
      if ( !pointer )
        break;
      first_child = (vostok::vfs::base_node<1> *)pointer;
    }
  }
  m_source_folder = this->m_source_folder;
  max_storage_high = HIDWORD(this->m_new_source_nodes.m_first.max_storage);
  m_source_folder->m_first_child.pointer = this->m_new_source_nodes.m_first.pointer;
  HIDWORD(m_source_folder->m_first_child.max_storage) = max_storage_high;
}
