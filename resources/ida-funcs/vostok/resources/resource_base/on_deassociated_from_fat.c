void __thiscall vostok::resources::resource_base::on_deassociated_from_fat(vostok::resources::resource_base *this)
{
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *p_m_flags; // edx
  vostok::vfs::vfs_iterator *v2; // eax
  int v3; // eax
  _DWORD *v4; // eax
  vostok::vfs::vfs_iterator v5; // [esp-10h] [ebp-28h] BYREF
  int v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  p_m_flags = &this->m_flags;
  v2 = (unsigned __int8)((this->m_flags.m_flags & 1) - 1) == 0 ? (vostok::vfs::vfs_iterator *)this : 0;
  if ( v2 )
  {
    memset(&v5, 0, 12);
    v5.m_type = type_number;
    vostok::resources::managed_resource::late_set_fat_it((vostok::resources::managed_resource *)&v5, v2, v5);
  }
  else
  {
    v3 = -((unsigned __int8)((p_m_flags->m_flags & 4) - 4) != 0);
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v4 = (_DWORD *)((unsigned int)this & ~v3);
    v9 = 3;
    v4[40] = 0;
    v4[41] = v7;
    v4[42] = v8;
    v4[43] = v9;
  }
  _InterlockedOr(&p_m_flags->m_flags, 0x40u);
}
