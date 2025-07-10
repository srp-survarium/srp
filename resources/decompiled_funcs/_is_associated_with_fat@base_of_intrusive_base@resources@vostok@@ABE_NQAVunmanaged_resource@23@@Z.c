bool __usercall vostok::resources::base_of_intrusive_base::is_associated_with_fat@<al>(
        vostok::resources::unmanaged_resource *const object@<esi>,
        vostok::resources::base_of_intrusive_base *this)
{
  vostok::vfs::vfs_iterator v3; // [esp-14h] [ebp-28h] BYREF
  vostok::resources::resource_base *v4; // [esp-4h] [ebp-18h]
  vostok::vfs::vfs_iterator fat_it; // [esp+0h] [ebp-14h] BYREF

  vostok::vfs::vfs_iterator::vfs_iterator(&fat_it, &object->m_fat_it);
  v4 = object;
  vostok::vfs::vfs_iterator::vfs_iterator(&v3, &fat_it);
  return vostok::resources::is_associated_with(v3, v4);
}
