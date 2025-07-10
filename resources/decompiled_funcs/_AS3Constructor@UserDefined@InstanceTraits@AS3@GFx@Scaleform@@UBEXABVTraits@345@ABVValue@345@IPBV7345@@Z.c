void __thiscall Scaleform::GFx::AS3::InstanceTraits::UserDefined::AS3Constructor(
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *this,
        const Scaleform::GFx::AS3::Traits *ot,
        const Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pObject; // esi
  int method_info_ind; // ebx
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v9; // esi
  bool v10; // zf
  const Scaleform::GFx::AS3::Traits *v11; // ebp
  Scaleform::GFx::AS3::VM *v12; // ecx
  Scaleform::GFx::AS3::VMAbcFile *FirstOwnSlotNum; // esi
  Scaleform::GFx::AS3::VM *v14; // ebx
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::AS3::Value::Extra v19; // edx
  Scaleform::GFx::AS3::VM *v20; // eax
  Scaleform::GFx::AS3::Value::V2U v21; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::VM *v23; // ecx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v24; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  Scaleform::GFx::AS3::Abc::MbiInd mbi_ind; // [esp+10h] [ebp-50h] BYREF
  Scaleform::GFx::ASStringNode *v27; // [esp+14h] [ebp-4Ch]
  Scaleform::GFx::AS3::CallFrame val; // [esp+18h] [ebp-48h] BYREF

  pObject = this->Script.pObject;
  method_info_ind = this->class_info->inst_info.method_info_ind;
  if ( !pObject->Initialized )
  {
    pObject->Execute(this->Script.pObject);
    pVM = pObject->pTraits.pObject->pVM;
    if ( !pVM->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(pVM, 1u);
  }
  v9 = this->Script.pObject;
  v10 = !v9->Initialized;
  v11 = ot->pParent.pObject;
  mbi_ind.Ind = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v9->pTraits.pObject[1].FirstOwnSlotNum + 60) + 112)
                                      + 4 * method_info_ind)
                          + 8);
  if ( v10 )
  {
    v9->Execute(v9);
    v12 = v9->pTraits.pObject->pVM;
    if ( !v12->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v12, 1u);
  }
  FirstOwnSlotNum = (Scaleform::GFx::AS3::VMAbcFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum;
  v14 = this->pVM;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  if ( v14->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&mbi_ind, eStackOverflowError, v14);
    Scaleform::GFx::AS3::VM::ThrowError(v14, v16);
    v17 = v27;
    --v27->RefCount;
    if ( !v17->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  else
  {
    VMRef = FirstOwnSlotNum->VMRef;
    val.DiscardResult = 1;
    val.ACopy = 0;
    val.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    val.CP = 0;
    val.pRegisterFile = &VMRef->RegisterFile;
    val.pHeap = VMRef->MHeap;
    val.MBIIndex = mbi_ind;
    val.DefXMLNamespace.pObject = 0;
    v19.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)Undefined->Bonus;
    val.pSavedScope = &v11->InitScope;
    v20 = FirstOwnSlotNum->VMRef;
    val.Invoker.Bonus = v19;
    val.Invoker.value.VS._1.VInt = Undefined->value.VS._1.VInt;
    v21.VObj = (Scaleform::GFx::AS3::Object *)Undefined->value.VS._2;
    val.pScopeStack = &v20->ScopeStack;
    Flags = Undefined->Flags;
    val.Invoker.value.VS._2 = v21;
    val.pFile = FirstOwnSlotNum;
    val.OriginationTraits = v11;
    val.Invoker.Flags = Flags;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    }
    v23 = FirstOwnSlotNum->VMRef;
    val.PrevInitialStackPos = v23->OpStack.pCurrent;
    val.PrevFirstStackPos = v23->OpStack.pStack;
    v24 = val.pFile->File.pObject->MethodBodies.Info.Data.Data[val.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(&v23->OpStack, LOWORD(v24->max_stack) + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v24->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&val.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
        *p_DefXMLNamespace);
      ot = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&ot);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &val,
      FirstOwnSlotNum->File.pObject->Methods.Info.Data.Data[FirstOwnSlotNum->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind]->method_info_ind],
      _this,
      argc,
      argv);
    if ( v14->HandleException )
      val.ACopy = 1;
    else
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
        &v14->CallStack,
        &val);
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
  }
}
