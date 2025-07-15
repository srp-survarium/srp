BOOL __usercall vostok::vfs::physical_folder_node<1>::set_is_scanned@<eax>(
        vostok::vfs::physical_folder_node<1> *this@<eax>,
        bool recursively@<cl>)
{
  unsigned int v2; // edx

  v2 = (recursively ? 2 : 0) | 1;
  return (v2 & _InterlockedOr(&this->m_folder_flags.m_flags, v2)) == 0;
}
