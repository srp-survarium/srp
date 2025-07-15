void __thiscall Scaleform::GFx::AS2::MovieRoot::CreateArray(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue)
{
  Scaleform::GFx::AS2::Environment *v3; // esi
  Scaleform::GFx::AS2::Object *v4; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value value; // [esp+Ch] [ebp-10h] BYREF

  v3 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(char *))(*((_DWORD *)&this->pMovieImpl->pMainMovie->__vftable
                                                                           + this->pMovieImpl->pMainMovie->AvmObjOffset)
                                                                         + 124))(
                                             (char *)&this->pMovieImpl->pMainMovie->__vftable
                                           + 4 * this->pMovieImpl->pMainMovie->AvmObjOffset);
  v4 = Scaleform::GFx::AS2::Environment::OperatorNew(
         v3,
         v3->StringContext.pContext->pGlobal.pObject,
         (const Scaleform::GFx::ASString *)&v3->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
         0,
         -1);
  Scaleform::GFx::AS2::Value::Value(&value, v4);
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v3, &value, pvalue);
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
}
