void __usercall vostok::resources::unmanaged_resource::constructor_impl(
        vostok::resources::unmanaged_resource *this@<ecx>,
        int a2@<esi>)
{
  vostok::vfs::vfs_iterator *v2; // eax
  __int64 v3; // xmm0_8
  vostok::vfs::vfs_iterator result; // [esp+8h] [ebp-14h] BYREF

  *(_DWORD *)(a2 + 232) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  v2 = vostok::vfs::vfs_iterator::end(&result);
  *(_QWORD *)(a2 + 160) = *(_QWORD *)&v2->m_hashset;
  v3 = *(_QWORD *)&v2->m_link_target;
  *(_BYTE *)(a2 + 260) = 0;
  *(_DWORD *)(a2 + 236) = 0;
  *(_DWORD *)(a2 + 240) = 0;
  *(_DWORD *)(a2 + 244) = 0;
  *(_DWORD *)(a2 + 248) = 0;
  *(_QWORD *)(a2 + 168) = v3;
}
