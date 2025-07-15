char __thiscall Scaleform::GFx::AS3ValueObjectInterface::PopBack(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // ebx
  int v4; // edi
  Scaleform::GFx::AS3::Value *v6; // eax

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v4 = *((_DWORD *)pdata + 8);
  if ( v4 > 0 )
  {
    if ( pval )
    {
      v6 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                           (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
                                           v4 - 1);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, v6, (Scaleform::GFx::ASStringNode *)pval);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32), v4 - 1);
    return 1;
  }
  else
  {
    if ( pval )
    {
      if ( (pval->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
          pval,
          pval->mValue.IValue);
        pval->pObjectInterface = 0;
      }
      pval->Type = VT_Undefined;
    }
    return 0;
  }
}
