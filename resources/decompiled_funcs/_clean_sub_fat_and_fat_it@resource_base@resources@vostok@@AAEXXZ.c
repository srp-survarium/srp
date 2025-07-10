void __usercall vostok::resources::resource_base::clean_sub_fat_and_fat_it(
        vostok::resources::resource_base *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v2; // ecx
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v3; // ecx
  vostok::vfs::vfs_iterator result; // [esp+8h] [ebp-24h] BYREF
  vostok::vfs::vfs_iterator v5; // [esp+18h] [ebp-14h] BYREF

  if ( (*(_DWORD *)(a2 + 8) & 1) != 0 && a2 )
  {
    vostok::vfs::vfs_iterator::end(&result);
    if ( !vostok::vfs::vfs_iterator::operator==(&result, (const vostok::vfs::vfs_iterator *)(a2 + 160)) )
      *(vostok::vfs::vfs_iterator *)(a2 + 160) = result;
    vostok::resources::child_resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>::set_zero(
      v2,
      (vostok::resources::unmanaged_resource **)(a2 + 228));
  }
  else if ( (*(_DWORD *)(a2 + 8) & 4) != 0 && a2 )
  {
    vostok::vfs::vfs_iterator::end(&v5);
    *(vostok::vfs::vfs_iterator *)(a2 + 160) = v5;
    vostok::resources::child_resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>::set_zero(
      v3,
      (vostok::resources::unmanaged_resource **)(a2 + 216));
  }
}
