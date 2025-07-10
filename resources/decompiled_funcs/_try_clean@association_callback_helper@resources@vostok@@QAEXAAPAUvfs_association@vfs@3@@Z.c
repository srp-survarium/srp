void __thiscall vostok::resources::association_callback_helper::try_clean(
        vostok::resources::association_callback_helper *this,
        vostok::vfs::vfs_association **association)
{
  _DWORD *v2; // eax
  unsigned int *v3; // eax

  v2 = *association;
  if ( ((int)(*association)[1].__vftable & 1) != 0 && v2 )
  {
    v3 = v2 + 55;
  }
  else if ( (v2[2] & 4) != 0 && v2 )
  {
    v3 = v2 + 52;
  }
  else
  {
    v3 = 0;
  }
  if ( *v3 <= this->reference_count )
  {
    *association = 0;
    this->cleaned = 1;
  }
}
