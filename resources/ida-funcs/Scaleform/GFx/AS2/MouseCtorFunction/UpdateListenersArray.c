void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::ArrayObject *v6; // edi
  Scaleform::GFx::AS2::ArrayObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ArrayObject *v9; // ecx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value v11; // [esp+Ch] [ebp+0h] BYREF

  pContext = psc->pContext;
  v11.T.Type = 0;
  if ( this->GetMemberRaw(
         &this->Scaleform::GFx::AS2::ObjectInterface,
         psc,
         (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl,
         &v11) )
  {
    v5 = Scaleform::GFx::AS2::Value::ToObject(&v11, penv);
    v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
    if ( v5 && v5->GetObjectType(&v5->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
    {
      v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
      pObject = this->pListenersArray.pObject;
      if ( pObject )
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
        }
      }
      this->pListenersArray.pObject = v6;
    }
    else
    {
      v9 = this->pListenersArray.pObject;
      if ( v9 )
      {
        v10 = v9->RefCount;
        if ( (v10 & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      this->pListenersArray.pObject = 0;
    }
  }
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
}
