void __thiscall Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *pinterface)
{
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v5; // eax
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *v6; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v8; // esi
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v11; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // ecx
  unsigned int RefCount; // eax
  unsigned int v14; // eax
  Scaleform::GFx::AS2::Value v15; // [esp+Ch] [ebp-10h] BYREF

  if ( this->pInterfaces || pinterface )
  {
    pContext = psc->pContext;
    v8 = pinterface->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
    v15.T.Type = 0;
    if ( v8->GetMemberRaw(
           &pinterface->Scaleform::GFx::AS2::ObjectInterface,
           psc,
           (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
           &v15) )
    {
      v9 = Scaleform::GFx::AS2::Value::ToObject(&v15, 0);
      v10 = v9;
      if ( v9 )
        v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
      v11 = &this->pInterfaces->Data.Data[index];
      if ( v9 )
        v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
      pObject = v11->pObject;
      if ( v11->pObject )
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
        }
      }
      v11->pObject = (Scaleform::GFx::AS2::Object *)v10;
      if ( v10 )
      {
        v14 = v10->RefCount;
        if ( (v14 & 0x3FFFFFF) != 0 )
        {
          v10->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
        }
      }
    }
    if ( v15.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
  }
  else
  {
    v5 = (Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)psc->pContext->pHeap->Alloc(psc->pContext->pHeap, 12, 0);
    v6 = (Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *)v5;
    if ( v5 )
    {
      Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>(
        v5,
        index);
      this->pInterfaces = v6;
    }
    else
    {
      this->pInterfaces = 0;
    }
  }
}
