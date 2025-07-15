vostok::vfs::base_node<1> *__usercall vostok::vfs::base_node<1>::get_first_child@<eax>(
        vostok::vfs::base_node<1> *this@<ecx>,
        int a2@<eax>)
{
  if ( (*(_BYTE *)(a2 + 48) & 1) != 0 )
    return vostok::vfs::cast_folder<1>((vostok::vfs::base_node<1> *)a2)->m_first_child.pointer;
  else
    return 0;
}
