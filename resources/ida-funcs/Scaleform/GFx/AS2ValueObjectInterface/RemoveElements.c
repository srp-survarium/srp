char __thiscall Scaleform::GFx::AS2ValueObjectInterface::RemoveElements(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        int count)
{
  Scaleform::GFx::AS2::ArrayObject *v4; // ecx
  unsigned int Size; // eax
  unsigned int v7; // edx
  unsigned int v8; // eax

  if ( pdata )
    v4 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v4 = 0;
  Size = v4->Elements.Data.Size;
  if ( idx >= Size )
    return 0;
  v7 = count;
  if ( count < 0 )
    v7 = Size - idx;
  v8 = Size - idx;
  if ( v8 >= v7 )
    v8 = v7;
  Scaleform::GFx::AS2::ArrayObject::RemoveElements(v4, idx, v8);
  return 1;
}
