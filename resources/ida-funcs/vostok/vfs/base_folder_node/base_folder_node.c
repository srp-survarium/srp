void __usercall vostok::vfs::base_folder_node<1>::base_folder_node<1>(
        vostok::vfs::base_folder_node<1> *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  vostok::vfs::base_node<1>::base_node<1>((vostok::vfs::base_node<1> *)(a2 + 16), 1u);
}
