char __thiscall Scaleform::GFx::AS2::ArrayObject::Sort<Scaleform::GFx::AS2::ArraySortFunctor>(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ArraySortFunctor *sf)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS2::ArraySortFunctor v4; // [esp-1Ch] [ebp-24h] BYREF
  Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> a; // [esp+0h] [ebp-8h] BYREF

  Size = this->Elements.Data.Size;
  if ( !Size )
    return 1;
  a.Data = this->Elements.Data.Data;
  a.Size = Size;
  Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(&v4, sf);
  return Scaleform::Alg::QuickSortSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortFunctor>(
           &a,
           v4);
}
