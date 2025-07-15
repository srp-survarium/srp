void __thiscall Scaleform::GFx::AS3::Instances::Function::Execute(
        Scaleform::GFx::AS3::Instances::Function *this,
        const Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> discard_result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VMAbcFile *Parent; // esi
  int MethodBodyInfoInd; // ebp
  const Scaleform::GFx::AS3::Traits *v8; // edi
  bool v9; // zf
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::GFx::AS3::VM *v14; // ecx
  Scaleform::GFx::AS3::VM *v15; // ecx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v16; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-64h]
  Scaleform::GFx::AS3::VM::Error v19; // [esp+14h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value v20; // [esp+1Ch] [ebp-58h] BYREF
  Scaleform::GFx::AS3::CallFrame val; // [esp+2Ch] [ebp-48h] BYREF

  pObject = this->pTraits.pObject;
  vm = pObject->pVM;
  if ( (this->This.Flags & 0x1F) != 0 && ((this->This.Flags & 0x1F) - 12 > 3 || this->This.value.VS._1.VInt) )
    _this = &this->This;
  Parent = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1].Parent;
  MethodBodyInfoInd = Parent->File.pObject->Methods.Info.Data.Data[pObject[1].FirstOwnSlotNum]->MethodBodyInfoInd;
  v8 = (const Scaleform::GFx::AS3::Traits *)pObject[1].VArray.Data.Data->Value.File.pObject;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v9 = vm->CallStack.Size == 128;
  v20.Flags = 14;
  v20.Bonus.pWeakProxy = 0;
  v20.value.VS._1.VInt = (int)this;
  if ( v9 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v19, eStackOverflowError, vm);
    Scaleform::GFx::AS3::VM::ThrowError(vm, v10);
    pNode = v19.Message.pNode;
    --v19.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    val.DiscardResult = (bool)discard_result.pObject;
    VMRef = Parent->VMRef;
    val.ACopy = 0;
    val.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    val.pRegisterFile = &VMRef->RegisterFile;
    val.CP = 0;
    MHeap = VMRef->MHeap;
    val.pSavedScope = &this->StoredScopeStack;
    v14 = Parent->VMRef;
    val.pHeap = MHeap;
    val.pScopeStack = &v14->ScopeStack;
    val.pFile = Parent;
    val.MBIIndex.Ind = MethodBodyInfoInd;
    val.OriginationTraits = v8;
    val.DefXMLNamespace.pObject = 0;
    val.Invoker.Flags = 14;
    val.Invoker.Bonus.pWeakProxy = 0;
    val.Invoker.value.VNumber = v20.value.VNumber;
    Scaleform::GFx::AS3::Value::AddRefInternal(&v20);
    v15 = Parent->VMRef;
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
      discard_result.pObject = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        &discard_result);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &val,
      Parent->File.pObject->Methods.Info.Data.Data[Parent->File.pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd]->method_info_ind],
      _this,
      argc,
      argv);
    if ( vm->HandleException )
      val.ACopy = 1;
    else
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
        &vm->CallStack,
        &val);
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
  }
  if ( (v20.Flags & 0x1F) > 9 )
  {
    if ( (v20.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v20);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
  }
}
