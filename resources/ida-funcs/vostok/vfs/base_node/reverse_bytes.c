void __usercall vostok::vfs::base_node<1>::reverse_bytes(vostok::vfs::base_node<1> *this@<ecx>, char *a2@<esi>)
{
  stlp_std::reverse<char *>(a2, a2 + 8);
  stlp_std::reverse<char *>(a2 + 8, a2 + 16);
  stlp_std::reverse<char *>(a2 + 16, a2 + 24);
  stlp_std::reverse<char *>(a2 + 24, a2 + 32);
  stlp_std::reverse<char *>(a2 + 32, a2 + 40);
  stlp_std::reverse<char *>(a2 + 40, a2 + 48);
  stlp_std::reverse<char *>(a2 + 48, a2 + 50);
}
