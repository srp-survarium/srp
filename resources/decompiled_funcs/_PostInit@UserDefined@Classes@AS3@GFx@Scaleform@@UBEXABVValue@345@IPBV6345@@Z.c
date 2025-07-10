void __thiscall Scaleform::GFx::AS3::Classes::UserDefined::PostInit(
        Scaleform::GFx::AS3::Classes::UserDefined *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::AS3::VM *pVM; // ebx
  bool v6; // zf
  const Scaleform::GFx::AS3::Traits *v7; // ecx
  Scaleform::GFx::AS3::VMAbcFile *pRCC; // esi
  Scaleform::GFx::AS3::VM::ErrorID MethodBodyInfoInd; // edx
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::AS3::VM *v13; // eax
  const Scaleform::GFx::AS3::Value *v14; // edi
  Scaleform::GFx::AS3::Value::V1U v15; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::Extra v17; // ecx
  Scaleform::GFx::AS3::Value::V2U v18; // ecx
  Scaleform::GFx::AS3::VM *v19; // ecx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v20; // ebp
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // ebp
  Scaleform::GFx::AS3::VM::Error v22; // [esp+Ch] [ebp-50h] BYREF
  Scaleform::GFx::AS3::CallFrame val; // [esp+14h] [ebp-48h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  v6 = pVM->CallStack.Size == 128;
  v7 = (const Scaleform::GFx::AS3::Traits *)pObject[1].__vftable;
  pRCC = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1]._pRCC;
  MethodBodyInfoInd = pRCC->File.pObject->Methods.Info.Data.Data[(int)pObject[1].pNext->Scaleform::GFx::AS3::Slots::pPrev]->MethodBodyInfoInd;
  v22.ID = MethodBodyInfoInd;
  if ( v6 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v22, eStackOverflowError, pVM);
    Scaleform::GFx::AS3::VM::ThrowError(pVM, v10);
    pNode = v22.Message.pNode;
    --v22.Message.pNode->RefCount;
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
    v13 = pRCC->VMRef;
    val.MBIIndex.Ind = MethodBodyInfoInd;
    val.pSavedScope = &v7->InitScope;
    val.DefXMLNamespace.pObject = 0;
    v14 = _this;
    v15 = _this->value.VS._1;
    val.pScopeStack = &v13->ScopeStack;
    Flags = _this->Flags;
    val.OriginationTraits = v7;
    v17.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)_this->Bonus;
    val.Invoker.value.VS._1 = v15;
    val.Invoker.Bonus = v17;
    v18.VObj = (Scaleform::GFx::AS3::Object *)_this->value.VS._2;
    val.pFile = pRCC;
    val.Invoker.Flags = Flags;
    val.Invoker.value.VS._2 = v18;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(_this);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(_this);
    }
    v19 = pRCC->VMRef;
    val.PrevInitialStackPos = v19->OpStack.pCurrent;
    val.PrevFirstStackPos = v19->OpStack.pStack;
    v20 = val.pFile->File.pObject->MethodBodies.Info.Data.Data[val.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(&v19->OpStack, LOWORD(v20->max_stack) + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v20->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&val.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
        *p_DefXMLNamespace);
      _this = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&_this);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &val,
      pRCC->File.pObject->Methods.Info.Data.Data[pRCC->File.pObject->MethodBodies.Info.Data.Data[v22.ID]->method_info_ind],
      v14,
      argc,
      argv);
    if ( pVM->HandleException )
      val.ACopy = 1;
    else
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
        &pVM->CallStack,
        &val);
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
  }
}
