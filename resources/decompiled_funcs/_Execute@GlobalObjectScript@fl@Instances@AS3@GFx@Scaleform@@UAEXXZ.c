void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::Execute(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::AS3::VMAbcFile *FirstOwnSlotNum; // edi
  Scaleform::GFx::AS3::VM::ErrorID v5; // eax
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::Value *v7; // ecx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::GFx::AS3::Value::V1U v12; // edx
  Scaleform::GFx::AS3::Value::V2U v13; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::VM *v15; // ecx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v16; // esi
  Scaleform::GFx::AS3::VM *v17; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v18; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *p_DefXMLNamespace; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-79h] BYREF
  Scaleform::GFx::AS3::Abc::MbiInd mbi_ind; // [esp+8h] [ebp-78h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> other; // [esp+Ch] [ebp-74h] BYREF
  Scaleform::GFx::AS3::VM::Error v23; // [esp+10h] [ebp-70h] BYREF
  Scaleform::GFx::AS3::Value v24; // [esp+18h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::Value v25; // [esp+28h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::CallFrame val; // [esp+38h] [ebp-48h] BYREF

  if ( !this->Initialized
    && Scaleform::GFx::AS3::Traits::SetupSlotValues(
         this->pTraits.pObject,
         &result,
         (Scaleform::GFx::AS3::VMAbcFile *)this->pTraits.pObject[1].FirstOwnSlotNum,
         (const Scaleform::GFx::AS3::Abc::HasTraits *)this->pTraits.pObject[1].Parent,
         this)->Result )
  {
    pObject = this->pTraits.pObject;
    pVM = pObject->pVM;
    FirstOwnSlotNum = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1].FirstOwnSlotNum;
    mbi_ind.Ind = FirstOwnSlotNum->File.pObject->Methods.Info.Data.Data[pObject[1].Parent->VArray.Data.Size]->MethodBodyInfoInd;
    Scaleform::GFx::AS3::Value::Value(&v25, this);
    v23.ID = v5;
    Scaleform::GFx::AS3::Value::Value(&v24, this);
    v7 = v6;
    if ( pVM->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v23, eStackOverflowError, pVM);
      Scaleform::GFx::AS3::VM::ThrowError(pVM, v8);
      pNode = v23.Message.pNode;
      --v23.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      VMRef = FirstOwnSlotNum->VMRef;
      val.DiscardResult = 1;
      val.ACopy = 0;
      val.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
      val.pRegisterFile = &VMRef->RegisterFile;
      val.CP = 0;
      MHeap = VMRef->MHeap;
      val.MBIIndex = mbi_ind;
      val.pScopeStack = &FirstOwnSlotNum->VMRef->ScopeStack;
      val.Invoker.Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
      v12 = v7->value.VS._1;
      val.pHeap = MHeap;
      val.Invoker.value.VS._1 = v12;
      v13.VObj = (Scaleform::GFx::AS3::Object *)v7->value.VS._2;
      val.pSavedScope = &pObject->InitScope;
      Flags = v7->Flags;
      val.Invoker.value.VS._2 = v13;
      val.pFile = FirstOwnSlotNum;
      val.OriginationTraits = pObject;
      val.DefXMLNamespace.pObject = 0;
      val.Invoker.Flags = Flags;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(v7);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v7);
      }
      v15 = FirstOwnSlotNum->VMRef;
      val.PrevInitialStackPos = v15->OpStack.pCurrent;
      val.PrevFirstStackPos = v15->OpStack.pStack;
      v16 = val.pFile->File.pObject->MethodBodies.Info.Data.Data[val.MBIIndex.Ind];
      Scaleform::GFx::AS3::ValueStack::Reserve(&v15->OpStack, LOWORD(v16->max_stack) + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v16->local_reg_count);
      v17 = val.pFile->VMRef;
      v18 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v17->DefXMLNamespace.pObject;
      p_DefXMLNamespace = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v17->DefXMLNamespace;
      if ( v18 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
          v18);
        other.pObject = 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(p_DefXMLNamespace, &other);
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &val,
        FirstOwnSlotNum->File.pObject->Methods.Info.Data.Data[FirstOwnSlotNum->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind]->method_info_ind],
        (const Scaleform::GFx::AS3::Value *)v23.ID,
        0,
        0);
      if ( pVM->HandleException )
        val.ACopy = 1;
      else
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
          &pVM->CallStack,
          &val);
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
    }
    if ( (v24.Flags & 0x1F) > 9 )
    {
      if ( (v24.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v24);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v24);
    }
    if ( (v25.Flags & 0x1F) > 9 )
    {
      if ( (v25.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v25);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v25);
    }
    if ( !this->pTraits.pObject->pVM->HandleException )
      this->Initialized = 1;
  }
}
