void __usercall vostok::vfs::archive_file_node_base<1>::reverse_bytes(
        vostok::vfs::archive_file_node_base<1> *this@<ecx>,
        char *a2@<esi>)
{
  stlp_std::reverse<char *>(a2, a2 + 4);
  stlp_std::reverse<char *>(a2 + 8, a2 + 16);
  stlp_std::reverse<char *>(a2 + 16, a2 + 20);
}
