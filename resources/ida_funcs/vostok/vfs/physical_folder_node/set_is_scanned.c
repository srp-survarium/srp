BOOL __thiscall vostok::vfs::physical_folder_node<1>::set_is_scanned(
        vostok::vfs::physical_folder_node<1> *this,
        bool recursively)
{
  signed __int32 v3; // [esp+4h] [ebp-1Ch]
  _DWORD v4[4]; // [esp+Ch] [ebp-14h] BYREF
  unsigned int flags_to_set; // [esp+1Ch] [ebp-4h]

  flags_to_set = (recursively ? 2 : 0) | 1;
  v4[2] = v4;
  v4[0] = flags_to_set;
  v4[1] = flags_to_set;
  v3 = _InterlockedOr(&this->m_folder_flags.m_flags, flags_to_set);
  return (flags_to_set & v3) == 0;
}
