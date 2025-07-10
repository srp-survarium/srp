void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getCodeFileNames(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  unsigned int v4; // edi
  unsigned int AllLoadedAbcFiles; // ebp
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // ebx
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // ecx
  unsigned int RefCount; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> destArr; // [esp+10h] [ebp-24h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v12; // [esp+14h] [ebp-20h] BYREF
  Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> srcArr; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+24h] [ebp-10h] BYREF

  pObject = this->pTraits.pObject;
  v4 = 0;
  memset(&srcArr, 0, sizeof(srcArr));
  AllLoadedAbcFiles = Scaleform::GFx::AS3::VM::GetAllLoadedAbcFiles(pObject->pVM, &srcArr);
  pV = Scaleform::GFx::AS3::VM::MakeArray(this->pTraits.pObject->pVM, &v12)->pV;
  if ( AllLoadedAbcFiles )
  {
    do
    {
      destArr.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                       this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                                                                       (char *)((srcArr.Data.Data[v4].pObject->File.pObject->Source.HeapTypeBits
                                                                               & 0xFFFFFFFC)
                                                                              + 8));
      ++destArr.pObject->pPrev;
      Scaleform::GFx::AS3::Value::Value(&v, (const Scaleform::GFx::ASString *)&destArr);
      v7 = (Scaleform::GFx::ASStringNode *)destArr.pObject;
      --destArr.pObject->pPrev;
      if ( !v7->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&pV->SA, &v);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
      ++v4;
    }
    while ( v4 < AllLoadedAbcFiles );
  }
  if ( &destArr != result )
  {
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    v8 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v8 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v8 - 1);
      }
      else
      {
        RefCount = v8->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v8->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
        }
      }
    }
    result->pObject = pV;
  }
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) == 0 )
    {
      v10 = pV->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v10) != 0 )
      {
        pV->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    srcArr.Data.Data,
    srcArr.Data.Size);
  if ( srcArr.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, srcArr.Data.Data);
}
