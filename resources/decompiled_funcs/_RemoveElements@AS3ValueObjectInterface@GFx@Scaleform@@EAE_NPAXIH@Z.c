char __thiscall Scaleform::GFx::AS3ValueObjectInterface::RemoveElements(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        int count)
{
  unsigned int v4; // eax
  unsigned int v6; // edx
  unsigned int v7; // eax

  v4 = *((_DWORD *)pdata + 8);
  if ( idx >= v4 )
    return 0;
  v6 = count;
  if ( count < 0 )
    v6 = v4 - idx;
  v7 = v4 - idx;
  if ( v7 >= v6 )
    v7 = v6;
  Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(
    (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
    idx,
    v7,
    0);
  return 1;
}
