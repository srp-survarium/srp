char __thiscall Scaleform::GFx::AS2ValueObjectInterface::PopBack(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AS2::ArrayObject *v3; // esi
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  int v5; // ecx
  Scaleform::GFx::AS2::Environment *v6; // eax
  int Size; // ecx
  unsigned int v9; // eax

  if ( pdata )
    v3 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v3 = 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v5 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v6 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 124))(v5);
  Size = v3->Elements.Data.Size;
  if ( Size > 0 )
  {
    if ( pval )
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v6, v3->Elements.Data.Data[Size - 1], pval);
    v9 = v3->Elements.Data.Size;
    if ( v9 )
      Scaleform::GFx::AS2::ArrayObject::Resize(v3, v9 - 1);
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
