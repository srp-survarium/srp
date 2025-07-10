void __thiscall Scaleform::GFx::AS3::Classes::fl_net::SharedObject::getLocal(
        Scaleform::GFx::AS3::Classes::fl_net::SharedObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result,
        Scaleform::GFx::ASStringNode *name,
        const Scaleform::GFx::ASString *localPath,
        bool secure)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edi
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> > *p_SharedObjects; // ebp
  int v8; // eax
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *v9; // edi
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *v10; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  void (__thiscall *v13)(Scaleform::GFx::AS3::VM *); // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *pV; // ebx
  char *v15; // esi
  int (__thiscall *v16)(char *, int); // eax
  Scaleform::RefCountVImpl *v17; // edi
  Scaleform::RefCountVImpl *v18; // eax
  Scaleform::RefCountVImpl *v19; // esi
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *pObject; // ecx
  unsigned int RefCount; // eax
  void *v22; // esi
  void *v23; // esi
  unsigned int v24; // eax
  unsigned int v25; // edx
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *v26; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString strFullPath; // [esp+18h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> pthis; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::String strLocalPath; // [esp+20h] [ebp-2Ch] BYREF
  Scaleform::String strName; // [esp+24h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> pdataObj; // [esp+28h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::ASSharedObjectLoader loader; // [esp+2Ch] [ebp-20h] BYREF

  strFullPath.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                        this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                        (char *)localPath->pNode->pData);
  ++strFullPath.pNode->RefCount;
  Scaleform::GFx::ASString::Append(&strFullPath, (char *)&stru_95963C.m_max_end, (Scaleform::GFx::ASStringNode *)1);
  Scaleform::GFx::ASString::Append(&strFullPath, name);
  pTable = this->SharedObjects.mHash.pTable;
  p_SharedObjects = &this->SharedObjects;
  if ( pTable )
  {
    v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
           &this->SharedObjects.mHash,
           &strFullPath,
           strFullPath.pNode->HashFlags & pTable->SizeMask);
    if ( v8 >= 0 )
    {
      v9 = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)(&pTable[1].SizeMask
                                                                                                  + 3 * v8);
      if ( v9 )
      {
        if ( v9 != (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)-4 )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(result, v9 + 1);
          goto LABEL_41;
        }
      }
    }
  }
  pthis.pObject = Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject::MakeInstance(
                    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *)&pdataObj,
                    (Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject *)this->pTraits.pObject[1].__vftable)->pV;
  if ( Scaleform::GFx::AS3::Instances::fl_net::SharedObject::SetNameAndLocalPath(
         pthis.pObject,
         (Scaleform::GFx::ASString *)name,
         localPath) )
  {
    pVM = this->pTraits.pObject->pVM;
    v13 = pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
    pV = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::VM::MakeObject(
                                                                    pVM,
                                                                    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *)&pdataObj)->pV;
    loader.pVM = pVM;
    memset(&loader.ObjectStack, 0, 13);
    v15 = (char *)v13 + 8;
    loader.RefCount = 1;
    loader.__vftable = (Scaleform::GFx::AS3::ASSharedObjectLoader_vtbl *)&Scaleform::GFx::AS3::ASSharedObjectLoader::`vftable';
    loader.pData = pV;
    v16 = *(int (__thiscall **)(char *, int))(*((_DWORD *)v13 + 2) + 12);
    pdataObj.pObject = pV;
    v17 = (Scaleform::RefCountVImpl *)v16((char *)v13 + 8, 32);
    v18 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(char *, int))(*(_DWORD *)v15 + 12))(v15, 9);
    v19 = v18;
    if ( v18 )
      Scaleform::RefCountImpl::Release(v18);
    Scaleform::String::String(&strName, *(char **)name->pData);
    Scaleform::String::String(&strLocalPath, (char *)localPath->pNode->pData);
    if ( v17
      && ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *, Scaleform::GFx::AS3::ASSharedObjectLoader *, Scaleform::RefCountVImpl *))v17->AddRef)(
           v17,
           &strName,
           &strLocalPath,
           &loader,
           v19) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&pthis.pObject->DataObj,
        pV);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        result,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pthis);
      Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Add(
        p_SharedObjects,
        &strFullPath,
        &pthis);
      Scaleform::String::~String(&strLocalPath);
      Scaleform::String::~String(&strName);
      Scaleform::RefCountImpl::Release(v17);
      Scaleform::GFx::AS3::ASSharedObjectLoader::~ASSharedObjectLoader(&loader);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pdataObj);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pthis);
      goto LABEL_41;
    }
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      result->pObject = 0;
    }
    v22 = (void *)(strLocalPath.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((strLocalPath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
    v23 = (void *)(strName.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((strName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
    if ( v17 )
      Scaleform::RefCountImpl::Release(v17);
    if ( loader.ObjectStack.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, loader.ObjectStack.Data.Data);
    Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&loader);
    if ( pV )
    {
      if ( ((unsigned __int8)pV & 1) == 0 )
      {
        v24 = pV->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v24) != 0 )
        {
          pV->RefCount = v24 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
        }
      }
    }
  }
  else
  {
    v10 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)((char *)v10 - 1);
        result->pObject = 0;
      }
      else
      {
        v11 = v10->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v11) != 0 )
        {
          v10->RefCount = v11 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
        result->pObject = 0;
      }
    }
  }
  if ( pthis.pObject )
  {
    if ( ((int)pthis.pObject & 1) != 0 )
    {
      --pthis.pObject;
    }
    else
    {
      v25 = pthis.pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v25) != 0 )
      {
        v26 = pthis.pObject;
        pthis.pObject->RefCount = v25 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
      }
    }
  }
LABEL_41:
  pNode = strFullPath.pNode;
  --strFullPath.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
