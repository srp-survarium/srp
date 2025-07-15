char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetElement(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  Scaleform::GFx::AS3::Value *v7; // eax

  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    pval->pObjectInterface = 0;
  }
  pval->Type = VT_Undefined;
  if ( idx >= *((_DWORD *)pdata + 8) )
    return 0;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                       (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
                                       idx);
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, v7, (Scaleform::GFx::ASStringNode *)pval);
  return 1;
}
