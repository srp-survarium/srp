void __usercall vostok::resources::resource_base::on_deassociated_from_fat(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<eax>)
{
  volatile int *v3; // edi
  vostok::vfs::vfs_iterator *v4; // esi
  vostok::vfs::vfs_iterator *v5; // esi
  vostok::vfs::vfs_iterator result; // [esp+8h] [ebp-20h] BYREF
  vostok::vfs::vfs_iterator v7; // [esp+18h] [ebp-10h] BYREF

  v3 = (volatile int *)(a2 + 8);
  if ( (*(_DWORD *)(a2 + 8) & 1) != 0 && a2 )
  {
    vostok::vfs::vfs_iterator::end(&result);
    v4 = (vostok::vfs::vfs_iterator *)(a2 + 160);
    if ( !vostok::vfs::vfs_iterator::operator==(&result, v4) )
    {
      *v4 = result;
      vostok::threading::interlocked_or(v3, 0x40u);
      return;
    }
  }
  else
  {
    v5 = (*v3 & 4) != 4 ? 0 : (vostok::vfs::vfs_iterator *)a2;
    vostok::vfs::vfs_iterator::end(&v7);
    v5[10] = v7;
  }
  vostok::threading::interlocked_or(v3, 0x40u);
}
