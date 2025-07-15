void __thiscall Scaleform::GFx::AS3::CallFrame::CallFrame(
        Scaleform::GFx::AS3::CallFrame *this,
        const Scaleform::GFx::AS3::CallFrame *other)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int Flags; // eax

  this->DiscardResult = other->DiscardResult;
  this->ACopy = 1;
  this->ScopeStackBaseInd = other->ScopeStackBaseInd;
  this->CP = other->CP;
  this->pRegisterFile = other->pRegisterFile;
  this->pHeap = other->pHeap;
  this->pFile = other->pFile;
  this->MBIIndex.Ind = other->MBIIndex.Ind;
  this->pSavedScope = other->pSavedScope;
  this->OriginationTraits = other->OriginationTraits;
  this->pScopeStack = other->pScopeStack;
  this->PrevInitialStackPos = other->PrevInitialStackPos;
  pObject = other->DefXMLNamespace.pObject;
  this->DefXMLNamespace.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  this->PrevFirstStackPos = other->PrevFirstStackPos;
  this->Invoker = other->Invoker;
  Flags = other->Invoker.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      ++other->Invoker.Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&other->Invoker);
  }
}
