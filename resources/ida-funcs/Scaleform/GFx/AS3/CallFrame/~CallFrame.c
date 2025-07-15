void __thiscall Scaleform::GFx::AS3::CallFrame::~CallFrame(Scaleform::GFx::AS3::CallFrame *this)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebx
  unsigned int RefCount; // eax
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> other; // [esp+4h] [ebp-4h] BYREF

  if ( this->pRegisterFile && this->pScopeStack && this->ACopy )
  {
    Scaleform::GFx::AS3::ValueStack::ReleaseReserved(&this->pFile->VMRef->OpStack, this->PrevFirstStackPos);
    Scaleform::GFx::AS3::ValueRegisterFile::ReleaseReserved(
      this->pRegisterFile,
      this->pFile->File.pObject->MethodBodies.Info.Data.Data[this->MBIIndex.Ind]->local_reg_count);
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->pScopeStack->Data,
      this->ScopeStackBaseInd);
    pObject = this->DefXMLNamespace.pObject;
    other.pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->pFile->VMRef->DefXMLNamespace,
      &other);
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) == 0 )
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
  Flags = this->Invoker.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Invoker.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->Invoker.Flags &= 0xFFFFFDE0;
      this->Invoker.Bonus.pWeakProxy = 0;
      this->Invoker.value.VS._1.VInt = 0;
      this->Invoker.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->Invoker);
    }
  }
  v7 = this->DefXMLNamespace.pObject;
  if ( v7 )
  {
    if ( ((unsigned __int8)v7 & 1) != 0 )
    {
      this->DefXMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v7 - 1);
    }
    else
    {
      v8 = v7->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v8) != 0 )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
      }
    }
  }
}
