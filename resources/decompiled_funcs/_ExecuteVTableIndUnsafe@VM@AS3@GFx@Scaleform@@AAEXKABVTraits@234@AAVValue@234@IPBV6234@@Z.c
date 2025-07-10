void __thiscall Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(
        Scaleform::GFx::AS3::VM *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Traits *tr,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::Traits *v6; // edi
  Scaleform::GFx::AS3::Value *v8; // ecx
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::Traits *pTraits; // edi
  Scaleform::GFx::AS3::VMAbcFile *(__thiscall *GetFilePtr)(Scaleform::GFx::AS3::Traits *); // eax
  Scaleform::GFx::AS3::Value::V1U v12; // ebp
  Scaleform::GFx::AS3::VMAbcFile *v13; // esi
  Scaleform::GFx::AS3::Abc::File *pObject; // edx
  int MethodBodyInfoInd; // ebp
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v18; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo **Data; // edx
  Scaleform::GFx::AS3::ValueRegisterFile *p_RegisterFile; // ecx
  Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::GFx::AS3::VM *v23; // ecx
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value *v25; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v26; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  Scaleform::GFx::AS3::Value::V1U v28; // ecx
  unsigned int v29; // eax
  const Scaleform::GFx::AS3::VM::Error *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::AS3::Value *v32; // esi
  unsigned __int16 v33; // [esp-8h] [ebp-78h]
  Scaleform::GFx::AS3::VM::Error v35; // [esp+10h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+18h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::CallFrame val; // [esp+28h] [ebp-48h] BYREF

  v6 = tr;
  v8 = &Scaleform::GFx::AS3::Traits::GetVT(tr)->VTMethods.Data.Data[ind];
  Flags = v8->Flags;
  _mm_prefetch((const char *)v8, 2);
  if ( (Flags & 0x1F) == 6 )
  {
    result.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v6;
    pTraits = v8->value.VS._2.pTraits;
    result.value.VS._1.VInt = ind;
    GetFilePtr = pTraits->GetFilePtr;
    v12 = v8->value.VS._1;
    result.Flags = 7;
    result.Bonus.pWeakProxy = 0;
    v13 = GetFilePtr((Scaleform::GFx::AS3::Traits *)pTraits);
    pObject = v13->File.pObject;
    MethodBodyInfoInd = pObject->Methods.Info.Data.Data[v12.VInt]->MethodBodyInfoInd;
    if ( this->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v35, eStackOverflowError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v16,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
      pNode = v35.Message.pNode;
      --v35.Message.pNode->RefCount;
      v18 = pNode;
      if ( !pNode->RefCount )
      {
LABEL_4:
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        Scaleform::GFx::AS3::Value::~Value(&result);
        return;
      }
    }
    else
    {
      VMRef = v13->VMRef;
      Data = pObject->MethodBodies.Info.Data.Data;
      val.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
      p_RegisterFile = &VMRef->RegisterFile;
      MHeap = VMRef->MHeap;
      val.pRegisterFile = p_RegisterFile;
      val.pHeap = MHeap;
      val.pSavedScope = &pTraits->InitScope;
      v23 = v13->VMRef;
      val.pScopeStack = &v23->ScopeStack;
      val.Invoker.value.VNumber = result.value.VNumber;
      pCurrent = v23->OpStack.pCurrent;
      v23 = (Scaleform::GFx::AS3::VM *)((char *)v23 + 40);
      val.PrevInitialStackPos = pCurrent;
      v25 = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v23->__vftable + 1);
      val.OriginationTraits = pTraits;
      v26 = Data[MethodBodyInfoInd];
      val.PrevFirstStackPos = v25;
      v33 = LOWORD(v26->max_stack) + 1;
      val.DiscardResult = 0;
      val.ACopy = 0;
      val.CP = 0;
      val.pFile = v13;
      val.MBIIndex.Ind = MethodBodyInfoInd;
      val.DefXMLNamespace.pObject = 0;
      val.Invoker.Flags = 7;
      val.Invoker.Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v23, v33);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v26->local_reg_count);
      p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v13->VMRef->DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
          *p_DefXMLNamespace);
        tr = 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
          (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&tr);
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &val,
        (int)v13->File.pObject->Methods.Info.Data.Data[v13->File.pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd]->method_info_ind],
        _this,
        argc,
        argv);
      if ( this->HandleException )
      {
        val.ACopy = 1;
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
        Scaleform::GFx::AS3::Value::~Value(&result);
        return;
      }
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
        &this->CallStack,
        &val);
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
    }
  }
  else
  {
    v28 = v8->value.VS._1;
    _mm_prefetch((const char *)v28.VInt, 2);
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0;
    v29 = (*(_DWORD *)(v28.VInt + 16) >> 10) & 0xFFF;
    if ( v29 == 4095 || argc <= v29 && argc >= ((*(_DWORD *)(v28.VInt + 16) >> 7) & 7u) )
    {
      (*(void (__cdecl **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))v28.VInt)(
        v28,
        this,
        _this,
        &result,
        argc,
        argv);
      if ( !this->HandleException )
      {
        v32 = ++this->OpStack.pCurrent;
        if ( v32 )
        {
          *v32 = result;
          result.Flags = 0;
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v35, eWrongArgumentCountError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v30,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v31 = v35.Message.pNode;
      --v35.Message.pNode->RefCount;
      v18 = v31;
      if ( !v31->RefCount )
        goto LABEL_4;
    }
  }
  Scaleform::GFx::AS3::Value::~Value(&result);
}
