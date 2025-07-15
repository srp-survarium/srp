void __thiscall Scaleform::GFx::MovieImpl::ClearIndirectTransformPairs(Scaleform::GFx::MovieImpl *this)
{
  int v2; // edi
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // esi
  Scaleform::Render::ContextImpl::Entry *pObject; // ecx
  Scaleform::GFx::MovieImpl::IndirectTransPair *v5; // esi
  bool v6; // zf
  Scaleform::RefCountNTSImpl *v7; // ecx
  Scaleform::RefCountNTSImpl *v8; // ecx
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *p_IndirectTransformPairs; // esi
  unsigned int Size; // [esp+Ch] [ebp-4h]

  if ( this->IndirectTransformPairs.Data.Size )
  {
    v2 = 0;
    Size = this->IndirectTransformPairs.Data.Size;
    do
    {
      Data = this->IndirectTransformPairs.Data.Data;
      pObject = Data[v2].TransformParent.pObject;
      v5 = &Data[v2];
      if ( pObject )
      {
        v6 = pObject->RefCount-- == 1;
        if ( v6 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
      }
      v5->TransformParent.pObject = 0;
      v7 = v5->Obj.pObject;
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      v5->Obj.pObject = 0;
      v8 = v5->OriginalParent.pObject;
      if ( v8 )
        Scaleform::RefCountNTSImpl::Release(v8);
      ++v2;
      v6 = Size-- == 1;
      v5->OriginalParent.pObject = 0;
      v5->OrigParentDepth = 0;
    }
    while ( !v6 );
  }
  p_IndirectTransformPairs = &this->IndirectTransformPairs;
  if ( !this->IndirectTransformPairs.Data.Size )
  {
    if ( !this->IndirectTransformPairs.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SocketThreadMgr::EventInfo,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->IndirectTransformPairs,
        &this->IndirectTransformPairs,
        0);
    goto LABEL_18;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::MovieImpl::IndirectTransPair>::DestructArray(
    p_IndirectTransformPairs->Data.Data,
    this->IndirectTransformPairs.Data.Size);
  if ( (this->IndirectTransformPairs.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_18:
    this->IndirectTransformPairs.Data.Size = 0;
    return;
  }
  if ( p_IndirectTransformPairs->Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_IndirectTransformPairs->Data.Data);
    p_IndirectTransformPairs->Data.Data = 0;
  }
  this->IndirectTransformPairs.Data.Policy.Capacity = 0;
  this->IndirectTransformPairs.Data.Size = 0;
}
