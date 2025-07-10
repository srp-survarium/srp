unsigned int __thiscall Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(
        Scaleform::GFx::MovieImpl *this,
        unsigned int focusGroupIndex)
{
  unsigned int result; // eax
  int v3; // edx
  unsigned __int8 *v4; // ecx
  int v5; // edi
  int v6; // edx
  int v7; // edx
  int v8; // edx

  result = 0;
  v3 = 1;
  v4 = &this->FocusGroupIndexes[1];
  v5 = 4;
  do
  {
    if ( *(v4 - 1) == focusGroupIndex )
      result |= v3;
    v6 = 2 * v3;
    if ( *v4 == focusGroupIndex )
      result |= v6;
    v7 = 2 * v6;
    if ( v4[1] == focusGroupIndex )
      result |= v7;
    v8 = 2 * v7;
    if ( v4[2] == focusGroupIndex )
      result |= v8;
    v3 = 2 * v8;
    v4 += 4;
    --v5;
  }
  while ( v5 );
  return result;
}
