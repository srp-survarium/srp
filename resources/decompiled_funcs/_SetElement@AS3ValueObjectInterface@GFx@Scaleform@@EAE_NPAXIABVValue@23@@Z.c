char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetElement(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::ASStringNode *value)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value asval; // [esp+0h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  asval.Flags = 0;
  asval.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, value, &asval);
  Scaleform::GFx::AS3::Impl::SparseArray::Set((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32), idx, &asval);
  if ( (asval.Flags & 0x1F) > 9 )
  {
    if ( (asval.Flags & 0x200) != 0 )
    {
      pWeakProxy = asval.Bonus.pWeakProxy;
      --asval.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return 1;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
    }
  }
  return 1;
}
