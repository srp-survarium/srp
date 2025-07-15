void __cdecl vostok::vfs::mount_helper_node<1>::create_inplace(
        vostok::vfs::mount_helper_node<1> *in_out_helper_node,
        vostok::memory::base_allocator *allocator,
        const char *name,
        unsigned int name_length,
        unsigned int mount_id)
{
  _DWORD *v5; // eax
  _DWORD v6[2]; // [esp+10h] [ebp-20h] BYREF
  _DWORD *v7; // [esp+18h] [ebp-18h]
  _DWORD *v8; // [esp+1Ch] [ebp-14h]
  _DWORD *v9; // [esp+20h] [ebp-10h]
  _DWORD *v10; // [esp+28h] [ebp-8h]
  vostok::vfs::base_node<1> *base; // [esp+2Ch] [ebp-4h]

  v10 = operator new(0x50u, in_out_helper_node);
  if ( v10 )
  {
    *v10 = allocator;
    v10[1] = mount_id;
    v7 = v10 + 2;
    v5 = v10 + 2;
    v10[2] = 0;
    v5[1] = 0;
    *v7 = 0;
    v8 = v7 + 2;
    v9 = v7 + 2;
    v7[2] = 0;
    *v8 = 0;
    vostok::vfs::base_node<1>::base_node<1>((vostok::vfs::base_node<1> *)(v7 + 4), 1u);
  }
  base = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::mount_helper_node,1>(in_out_helper_node);
  v6[1] = v6;
  v6[0] = 1025;
  base->m_flags = 1025;
  vostok::strings::copy(base->m_name, name_length + 1, name);
}
