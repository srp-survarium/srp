void __thiscall vostok::vfs::physical_file_node<1>::set_is_mounted(
        vostok::vfs::physical_file_node<1> *this,
        bool is_mounted)
{
  _DWORD v2[3]; // [esp+4h] [ebp-20h] BYREF
  _DWORD v3[5]; // [esp+10h] [ebp-14h] BYREF

  if ( is_mounted )
  {
    v3[2] = v3;
    v3[0] = 4;
    v3[1] = 4;
    _InterlockedOr(&this->m_file_flags.m_flags, 4u);
  }
  else
  {
    v2[2] = v2;
    v2[0] = 4;
    v2[1] = 4;
    _InterlockedAnd(&this->m_file_flags.m_flags, 0xFFFFFFFB);
  }
}
