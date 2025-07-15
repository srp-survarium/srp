void __thiscall vostok::resources::resource_base::clean_sub_fat_and_fat_it(vostok::resources::resource_base *this)
{
  vostok::vfs::vfs_iterator *v1; // eax
  vostok::resources::resource_base *v2; // eax
  vostok::resources::vfs_sub_fat_resource *v3; // edx
  vostok::resources::managed_resource *v4; // ecx
  vostok::resources::resource_base *v5; // eax
  vostok::vfs::vfs_iterator v6; // [esp-10h] [ebp-28h] BYREF
  vostok::vfs::base_node<1> *v7; // [esp+Ch] [ebp-Ch]
  vostok::vfs::base_node<1> *v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v1 = (unsigned __int8)((this->m_flags.m_flags & 1) - 1) == 0 ? (vostok::vfs::vfs_iterator *)this : 0;
  if ( v1 )
  {
    memset(&v6, 0, 12);
    v6.m_type = type_number;
    vostok::resources::managed_resource::late_set_fat_it((vostok::resources::managed_resource *)&v6, v1, v6);
    vostok::resources::managed_resource::set_sub_fat_resource(v4, v2, v3);
  }
  else
  {
    v5 = (unsigned __int8)((this->m_flags.m_flags & 4) - 4) == 0 ? this : 0;
    if ( v5 )
    {
      v7 = 0;
      v8 = 0;
      v9 = 3;
      v5->m_fat_it.m_hashset = 0;
      v5->m_fat_it.m_node = v7;
      v5->m_fat_it.m_link_target = v8;
      v5->m_fat_it.m_type = v9;
      vostok::resources::unmanaged_resource::set_sub_fat_resource(
        (vostok::resources::unmanaged_resource *)this,
        (int)v5,
        0);
    }
  }
}
