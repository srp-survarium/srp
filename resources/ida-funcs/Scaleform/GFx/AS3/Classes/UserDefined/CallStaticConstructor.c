void __thiscall Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(
        Scaleform::GFx::AS3::Classes::UserDefined *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // edi
  Scaleform::GFx::AS3::VMAbcFile *pRCC; // ebp
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v5; // eax
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::Value *v7; // ecx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::AS3::Value::Extra v11; // edx
  Scaleform::GFx::AS3::VM *v12; // eax
  Scaleform::GFx::AS3::Value::V2U v13; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::VM *v15; // ecx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v16; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // esi
  int mbi_ind; // [esp+10h] [ebp-78h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> other; // [esp+14h] [ebp-74h] BYREF
  Scaleform::GFx::AS3::VM::Error v20; // [esp+18h] [ebp-70h] BYREF
  Scaleform::GFx::AS3::Value v21; // [esp+20h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::Value v22; // [esp+30h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::CallFrame val; // [esp+40h] [ebp-48h] BYREF

  pObject = this->pTraits.pObject;
  pRCC = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1]._pRCC;
  pVM = pObject->pVM;
  mbi_ind = pRCC->File.pObject->Methods.Info.Data.Data[pObject[1].pNext[2].RefCount]->MethodBodyInfoInd;
  Scaleform::GFx::AS3::Value::Value(&v22, this);
  v20.ID = v5;
  Scaleform::GFx::AS3::Value::Value(&v21, this);
  v7 = v6;
  if ( pVM->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eStackOverflowError, pVM);
    Scaleform::GFx::AS3::VM::ThrowError(pVM, v8);
    pNode = v20.Message.pNode;
    --v20.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    VMRef = pRCC->VMRef;
    val.DiscardResult = 1;
    val.ACopy = 0;
    val.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    val.CP = 0;
    val.pRegisterFile = &VMRef->RegisterFile;
    val.pHeap = VMRef->MHeap;
    val.MBIIndex.Ind = mbi_ind;
    val.DefXMLNamespace.pObject = 0;
    v11.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v7->Bonus;
    val.pSavedScope = &pObject->InitScope;
    v12 = pRCC->VMRef;
    val.Invoker.Bonus = v11;
    val.Invoker.value.VS._1.VInt = v7->value.VS._1.VInt;
    v13.VObj = (Scaleform::GFx::AS3::Object *)v7->value.VS._2;
    val.pScopeStack = &v12->ScopeStack;
    Flags = v7->Flags;
    val.Invoker.value.VS._2 = v13;
    val.pFile = pRCC;
    val.OriginationTraits = pObject;
    val.Invoker.Flags = Flags;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v7);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v7);
    }
    v15 = pRCC->VMRef;
    val.PrevInitialStackPos = v15->OpStack.pCurrent;
    val.PrevFirstStackPos = v15->OpStack.pStack;
    v16 = val.pFile->File.pObject->MethodBodies.Info.Data.Data[val.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(&v15->OpStack, LOWORD(v16->max_stack) + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v16->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&val.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
        *p_DefXMLNamespace);
      other.pObject = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        &other);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &val,
      pRCC->File.pObject->Methods.Info.Data.Data[pRCC->File.pObject->MethodBodies.Info.Data.Data[mbi_ind]->method_info_ind],
      (const Scaleform::GFx::AS3::Value *)v20.ID,
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
  if ( (v21.Flags & 0x1F) > 9 )
  {
    if ( (v21.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v21);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v21);
  }
  if ( (v22.Flags & 0x1F) > 9 )
  {
    if ( (v22.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v22);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
  }
}
