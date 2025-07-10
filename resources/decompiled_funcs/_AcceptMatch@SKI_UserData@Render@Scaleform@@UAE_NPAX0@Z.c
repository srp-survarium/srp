bool __thiscall Scaleform::Render::SKI_UserData::AcceptMatch(
        Scaleform::Render::SKI_UserData *this,
        _BYTE *d0,
        _BYTE *d1)
{
  if ( d0 != d1 )
    return 0;
  if ( !d0 )
    return 1;
  return (d0[20] & 4) == 0 || !d0[16];
}
