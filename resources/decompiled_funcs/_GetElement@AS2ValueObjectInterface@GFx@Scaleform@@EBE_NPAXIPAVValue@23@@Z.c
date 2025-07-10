char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetElement(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::Value *pval)
{
  char *v5; // esi
  Scaleform::GFx::AS2::Value *v7; // ebx
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  Scaleform::GFx::AS2::Environment *v9; // eax

  if ( pdata )
    v5 = pdata - 16;
  else
    v5 = 0;
  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    pval->pObjectInterface = 0;
  }
  pval->Type = VT_Undefined;
  if ( idx >= *((_DWORD *)v5 + 15) )
    return 0;
  v7 = *(Scaleform::GFx::AS2::Value **)(*((_DWORD *)v5 + 14) + 4 * idx);
  if ( !v7 )
    return 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->pMovieImpl->pMainMovie->__vftable
                                                                        + pObject->pMovieImpl->pMainMovie->AvmObjOffset)
                                                                      + 124))(
                                             (int)pObject->pMovieImpl->pMainMovie
                                           + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset);
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v9, v7, pval);
  return 1;
}
