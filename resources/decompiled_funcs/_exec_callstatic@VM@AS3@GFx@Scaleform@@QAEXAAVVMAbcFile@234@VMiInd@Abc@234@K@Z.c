void __thiscall Scaleform::GFx::AS3::VM::exec_callstatic(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MiInd ind,
        unsigned int arg_count)
{
  int MethodBodyInfoInd; // ebp
  const Scaleform::GFx::AS3::Traits *v6; // edi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::MemoryHeap *MHeap; // edx
  Scaleform::GFx::AS3::VM *v11; // ecx
  Scaleform::GFx::AS3::Value *pStack; // eax
  Scaleform::GFx::AS3::Abc::File *pObject; // edx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v14; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  const Scaleform::GFx::AS3::Value *argv; // [esp+4h] [ebp-104h]
  Scaleform::GFx::AS3::VM::Error v17; // [esp+8h] [ebp-100h] BYREF
  Scaleform::GFx::AS3::CallFrame val; // [esp+10h] [ebp-F8h] BYREF
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+58h] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject = *(Scaleform::GFx::AS3::Value *)*(_DWORD *)args.OpStack;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( this->HandleException )
  {
    Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
  }
  else
  {
    MethodBodyInfoInd = file->File.pObject->Methods.Info.Data.Data[ind.Ind]->MethodBodyInfoInd;
    v6 = *(const Scaleform::GFx::AS3::Traits **)(args.ArgObject.value.VS._1.VInt + 20);
    if ( args.ArgNum > 8 )
      argv = args.CallArgs.Data.Data;
    else
      argv = args.FixedArr;
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    if ( this->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v17, eStackOverflowError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v7,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
      pNode = v17.Message.pNode;
      --v17.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      VMRef = file->VMRef;
      val.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
      val.pRegisterFile = &VMRef->RegisterFile;
      MHeap = VMRef->MHeap;
      val.CP = 0;
      val.DefXMLNamespace.pObject = 0;
      val.pScopeStack = &VMRef->ScopeStack;
      val.pHeap = MHeap;
      val.Invoker = v;
      val.pSavedScope = &v6->InitScope;
      val.OriginationTraits = v6;
      val.DiscardResult = 0;
      val.ACopy = 0;
      val.pFile = file;
      val.MBIIndex.Ind = MethodBodyInfoInd;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          ++v.Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&v);
      }
      v11 = file->VMRef;
      pStack = v11->OpStack.pStack;
      val.PrevInitialStackPos = v11->OpStack.pCurrent;
      pObject = file->File.pObject;
      val.PrevFirstStackPos = pStack;
      v14 = pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd];
      Scaleform::GFx::AS3::ValueStack::Reserve(&v11->OpStack, LOWORD(v14->max_stack) + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v14->local_reg_count);
      p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&file->VMRef->DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
          *p_DefXMLNamespace);
        v17.ID = 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
          (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v17);
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &val,
        (int)file->File.pObject->Methods.Info.Data.Data[file->File.pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd]->method_info_ind],
        &args.ArgObject,
        arg_count,
        argv);
      if ( this->HandleException )
        val.ACopy = 1;
      else
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
          &this->CallStack,
          &val);
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
    }
    Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
  }
}
