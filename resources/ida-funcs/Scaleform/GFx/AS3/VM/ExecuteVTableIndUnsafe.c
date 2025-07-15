void __thiscall Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(
        Scaleform::GFx::AS3::VM *this,
        unsigned int ind,
        const Scaleform::GFx::AS3::Traits *tr,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v7; // ecx
  unsigned int Flags; // eax
  const Scaleform::GFx::AS3::Traits *pTraits; // edi
  Scaleform::GFx::AS3::Traits_vtbl *v10; // eax
  Scaleform::GFx::AS3::VMAbcFile *(__thiscall *GetFilePtr)(Scaleform::GFx::AS3::Traits *); // edx
  Scaleform::GFx::AS3::VMAbcFile *v12; // esi
  Scaleform::GFx::AS3::VTable *VT; // eax
  bool v14; // zf
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *v19; // ecx
  Scaleform::GFx::AS3::VM *v20; // ecx
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v22; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v25; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // edi
  Scaleform::GFx::AS3::Abc::File *pObject; // eax
  Scaleform::RefCountVImpl *v28; // esi
  Scaleform::GFx::AMP::ViewStats *(__thiscall *GetAdvanceStats)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::GFx::AMP::ViewStats *v30; // eax
  Scaleform::GFx::AMP::ViewStats *v31; // eax
  unsigned int Size; // esi
  Scaleform::ArrayPagedCC<Scaleform::GFx::AS3::CallFrame,6,64,329> *p_CallStack; // ebp
  unsigned int v34; // esi
  Scaleform::GFx::AS3::CallFrame *v35; // ecx
  Scaleform::GFx::AS3::Value::V1U v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // eax
  const char *v39; // ecx
  unsigned int v40; // ecx
  const Scaleform::GFx::AS3::VM::Error *v41; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v43; // ebp
  unsigned int SwfFileOffset; // [esp-14h] [ebp-B0h]
  Scaleform::StringDataPtr v45; // [esp-14h] [ebp-B0h]
  const __m128i *pData; // [esp-10h] [ebp-ACh]
  unsigned int v47; // [esp-Ch] [ebp-A8h]
  int v48; // [esp-Ch] [ebp-A8h]
  unsigned __int64 StartTicks; // [esp-8h] [ebp-A4h]
  int v50; // [esp-8h] [ebp-A4h]
  unsigned __int16 v51; // [esp-4h] [ebp-A0h]
  Scaleform::GFx::AS3::Abc::MiInd method_inda; // [esp+10h] [ebp-8Ch]
  int method_ind; // [esp+10h] [ebp-8Ch]
  Scaleform::GFx::AS3::Value result; // [esp+14h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::VM::Error v55; // [esp+24h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Value func; // [esp+2Ch] [ebp-70h] BYREF
  Scaleform::GFx::AS3::CallFrame other; // [esp+3Ch] [ebp-60h] BYREF

  v7 = &Scaleform::GFx::AS3::Traits::GetVT(tr)->VTMethods.Data.Data[ind];
  Flags = v7->Flags;
  _mm_prefetch((const char *)v7, 2);
  if ( (Flags & 0x1F) == 6 )
  {
    pTraits = v7->value.VS._2.pTraits;
    v10 = pTraits->__vftable;
    *(_QWORD *)&func.value.VNumber = __PAIR64__((unsigned int)tr, ind);
    method_inda.Ind = v7->value.VS._1.VInt;
    GetFilePtr = v10->GetFilePtr;
    func.Flags = 7;
    func.Bonus.pWeakProxy = 0;
    v12 = GetFilePtr(pTraits);
    method_ind = v12->File.pObject->Methods.Info.Data.Data[method_inda.Ind]->MethodBodyInfoInd;
    VT = Scaleform::GFx::AS3::Traits::GetVT(pTraits);
    v14 = this->CallStack.Size == 128;
    result.Flags = (unsigned int)&VT->Names.Data.Data[ind];
    if ( v14 )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result, eStackOverflowError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v15,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
      pWeakProxy = (Scaleform::GFx::ASStringNode *)result.Bonus.pWeakProxy;
      --result.Bonus.pWeakProxy[1].pObject;
      if ( !pWeakProxy->RefCount )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
        Scaleform::GFx::AS3::Value::~Value(&func);
        return;
      }
    }
    else
    {
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      VMRef = v12->VMRef;
      v55.Message.pNode = (Scaleform::GFx::ASStringNode *)HIDWORD(ProfileTicks);
      other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
      HIDWORD(ProfileTicks) = &VMRef->RegisterFile;
      other.pHeap = VMRef->MHeap;
      other.pSavedScope = &pTraits->InitScope;
      other.pScopeStack = &v12->VMRef->ScopeStack;
      v19 = *(Scaleform::GFx::ASStringNode **)result.Flags;
      other.pRegisterFile = (Scaleform::GFx::AS3::ValueRegisterFile *)HIDWORD(ProfileTicks);
      other.DiscardResult = 0;
      other.ACopy = 0;
      other.RegisteredFunction = 0;
      other.CP = 0;
      other.pFile = v12;
      other.MBIIndex.Ind = method_ind;
      other.OriginationTraits = pTraits;
      other.DefXMLNamespace.pObject = 0;
      other.Name.pObject = v19;
      if ( v19 )
        ++v19->RefCount;
      other.StartTicks = __PAIR64__((unsigned int)v55.Message.pNode, ProfileTicks);
      other.Invoker.value.VNumber = func.value.VNumber;
      v20 = v12->VMRef;
      pCurrent = v20->OpStack.pCurrent;
      v20 = (Scaleform::GFx::AS3::VM *)((char *)v20 + 40);
      other.PrevInitialStackPos = pCurrent;
      other.PrevReservedNum = *(_WORD *)&v20->Initialized;
      other.PrevFirstStackPos = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v20->__vftable + 1);
      v22 = v12->File.pObject->MethodBodies.Info.Data.Data[method_ind];
      v51 = LOWORD(v22->max_stack) + 1;
      other.CurrFileInd = 0;
      other.CurrLineNumber = 0;
      other.Invoker.Flags = 7;
      other.Invoker.Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v20, v51);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v22->local_reg_count);
      p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v12->VMRef->DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&other.DefXMLNamespace,
          *p_DefXMLNamespace);
        result.Flags = 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
          (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&result);
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &other,
        (int)v12->File.pObject->Methods.Info.Data.Data[v12->File.pObject->MethodBodies.Info.Data.Data[method_ind]->method_info_ind],
        _this,
        argc,
        argv);
      if ( this->HandleException )
      {
        other.ACopy = 1;
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
        Scaleform::GFx::AS3::Value::~Value(&func);
        return;
      }
      if ( this->GetAdvanceStats(this) )
      {
        Instance = Scaleform::AmpServer::GetInstance();
        if ( Instance->GetProfileLevel(Instance) >= Amp_Profile_Level_Medium )
        {
          v25 = Scaleform::AmpServer::GetInstance();
          if ( v25->IsProfiling(v25) )
          {
            pFile = other.pFile;
            pObject = other.pFile->File.pObject;
            v28 = (Scaleform::RefCountVImpl *)(pObject->FileHandle
                                             + (pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind]->method_info_ind << 16));
            if ( !other.RegisteredFunction )
            {
              pData = (const __m128i *)other.Name.pObject->pData;
              SwfFileOffset = pObject->SwfFileOffset;
              GetAdvanceStats = this->GetAdvanceStats;
              other.RegisteredFunction = 1;
              v30 = GetAdvanceStats(this);
              Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v30, v28, SwfFileOffset, pData, 0, 3u, 0);
            }
            StartTicks = other.StartTicks;
            v47 = pFile->File.pObject->SwfFileOffset;
            v31 = this->GetAdvanceStats(this);
            Scaleform::GFx::AMP::ViewStats::PushCallstack(v31, (unsigned int)v28, v47, StartTicks);
          }
        }
      }
      Size = this->CallStack.Size;
      p_CallStack = &this->CallStack;
      v34 = Size >> 6;
      if ( v34 >= p_CallStack->NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          p_CallStack,
          v34);
      v35 = &p_CallStack->Pages[v34][p_CallStack->Size & 0x3F];
      if ( v35 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v35, &other);
      ++p_CallStack->Size;
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
    }
    Scaleform::GFx::AS3::Value::~Value(&func);
  }
  else
  {
    v36 = v7->value.VS._1;
    _mm_prefetch((const char *)v36.VInt, 2);
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0;
    v37 = (*(_DWORD *)(v36.VInt + 16) >> 10) & 0xFFF;
    if ( v37 == 4095 || argc <= v37 && argc >= ((*(_DWORD *)(v36.VInt + 16) >> 7) & 7u) )
    {
      (*(void (__cdecl **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v36.VInt)(
        v36,
        this,
        _this,
        &result,
        argc,
        argv);
      if ( !this->HandleException )
      {
        v43 = ++this->OpStack.pCurrent;
        if ( v43 )
        {
          *v43 = result;
          result.Flags = 0;
        }
      }
    }
    else
    {
      v38 = *(_DWORD *)(v36.VInt + 16);
      v39 = *(const char **)(v36.VInt + 8);
      v50 = (v38 >> 10) & 0xFFF;
      v48 = (v38 >> 7) & 7;
      v45.pStr = v39;
      if ( v39 )
        v40 = strlen(v39);
      else
        v40 = 0;
      v45.Size = v40;
      Scaleform::GFx::AS3::VM::Error::Error(
        &v55,
        eWrongArgumentCountError,
        (Scaleform::String)this,
        v45,
        v48,
        v50,
        argc);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v41,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      pNode = v55.Message.pNode;
      --v55.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Scaleform::GFx::AS3::Value::~Value(&result);
  }
}
