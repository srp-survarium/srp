void __usercall vostok::vfs::base_node<1>::reverse_bytes_for_final_class(
        vostok::vfs::base_node<1> *this@<ecx>,
        char *a2@<eax>)
{
  char *v2; // esi
  char *v3; // ebx
  __int16 v4; // ax
  char *v5; // esi
  vostok::vfs::base_node<1> *v6; // ecx
  char *v7; // esi
  vostok::vfs::archive_file_node_base<1> *v8; // ecx
  char *v9; // ecx
  char *v10; // edi
  char *v11; // esi
  vostok::vfs::archive_file_node_base<1> *v12; // ecx
  char *v13; // ecx
  char *v14; // edi
  char *v15; // esi
  vostok::vfs::archive_file_node_base<1> *v16; // ecx
  char *v17; // esi
  vostok::vfs::archive_file_node_base<1> *v18; // ecx

  v2 = a2;
  v3 = a2 + 48;
  stlp_std::reverse<char *>(a2 + 48, a2 + 50);
  v4 = *(_WORD *)v3;
  if ( (*(_WORD *)v3 & 0x1000) == 0x1000 )
  {
    v5 = v2 - 16;
LABEL_3:
    stlp_std::reverse<char *>(v5, v5 + 8);
    stlp_std::reverse<char *>(v5 + 8, v5 + 12);
    v2 = v5 + 16;
    goto LABEL_22;
  }
  if ( (v4 & 0x100) == 0x100 || (v4 & 0x200) == 0x200 )
  {
    stlp_std::reverse<char *>(v2 - 8, v2);
    goto LABEL_22;
  }
  if ( (v4 & 1) != 0 )
  {
    v5 = (char *)vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)v2);
    goto LABEL_3;
  }
  if ( (v4 & 0x40) != 0 )
  {
    if ( (v4 & 0x10) != 0 )
    {
      v7 = (char *)vostok::vfs::node_cast<vostok::vfs::archive_inline_compressed_file_node,vostok::vfs::base_node,1>((vostok::vfs::base_node<1> *)v2);
      vostok::vfs::archive_file_node_base<1>::reverse_bytes(v8, v7);
      if ( v7 )
        v9 = v7 + 24;
      else
        v9 = 0;
      v10 = v9 + 8;
      stlp_std::reverse<char *>(v9, v9 + 8);
      stlp_std::reverse<char *>(v10, v10 + 4);
      stlp_std::reverse<char *>(v7 + 40, v7 + 44);
      v2 = v7 + 48;
    }
    else
    {
      v11 = (char *)vostok::vfs::node_cast<vostok::vfs::archive_inline_file_node,vostok::vfs::base_node,1>((vostok::vfs::base_node<1> *)v2);
      vostok::vfs::archive_file_node_base<1>::reverse_bytes(v12, v11);
      if ( v11 )
        v13 = v11 + 24;
      else
        v13 = 0;
      v14 = v13 + 8;
      stlp_std::reverse<char *>(v13, v13 + 8);
      stlp_std::reverse<char *>(v14, v14 + 4);
      v2 = v11 + 40;
    }
  }
  else if ( (v4 & 0x10) != 0 )
  {
    v15 = (char *)vostok::vfs::node_cast<vostok::vfs::archive_compressed_file_node,vostok::vfs::base_node,1>((vostok::vfs::base_node<1> *)v2);
    vostok::vfs::archive_file_node_base<1>::reverse_bytes(v16, v15);
    stlp_std::reverse<char *>(v15 + 24, v15 + 28);
    v2 = v15 + 32;
  }
  else
  {
    v17 = (char *)vostok::vfs::node_cast<vostok::vfs::archive_file_node,vostok::vfs::base_node,1>((vostok::vfs::base_node<1> *)v2);
    vostok::vfs::archive_file_node_base<1>::reverse_bytes(v18, v17);
    v2 = v17 + 24;
  }
LABEL_22:
  vostok::vfs::base_node<1>::reverse_bytes(v6, v2);
  stlp_std::reverse<char *>(v3, v3 + 2);
}
