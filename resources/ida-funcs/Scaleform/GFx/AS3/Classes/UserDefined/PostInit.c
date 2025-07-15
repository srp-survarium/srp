void __thiscall Scaleform::GFx::AS3::Classes::UserDefined::PostInit(
        Scaleform::GFx::AS3::Classes::UserDefined *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  const Scaleform::GFx::AS3::Traits *v6; // ebp
  Scaleform::GFx::AS3::Traits *v7; // eax
  Scaleform::GFx::AS3::VMAbcFile *pRCC; // esi
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::ASString *v10; // ebx
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  Scaleform::MemoryHeap *MHeap; // ecx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *v16; // ecx
  Scaleform::GFx::AS3::Value::Extra v17; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::V2U v19; // ecx
  Scaleform::GFx::AS3::VM *v20; // ecx
  unsigned __int16 NumOfReservedElem; // dx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v22; // ebp
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // ebp
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v25; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::RefCountVImpl *v27; // esi
  Scaleform::GFx::AMP::ViewStats *v28; // eax
  Scaleform::GFx::AMP::ViewStats *v29; // eax
  unsigned int Size; // esi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *p_CallStack; // edi
  unsigned int v32; // esi
  Scaleform::GFx::AS3::CallFrame *v33; // ecx
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  unsigned int SwfFileOffset; // [esp-14h] [ebp-98h]
  const __m128i *pData; // [esp-10h] [ebp-94h]
  unsigned int v38; // [esp-Ch] [ebp-90h]
  unsigned __int64 StartTicks; // [esp-8h] [ebp-8Ch]
  int mbi_ind; // [esp+10h] [ebp-74h]
  Scaleform::GFx::ASStringNode *v41; // [esp+14h] [ebp-70h] BYREF
  Scaleform::GFx::AS3::VM::Error v42; // [esp+18h] [ebp-6Ch] BYREF
  Scaleform::GFx::ASStringNode *v43; // [esp+20h] [ebp-64h] BYREF
  Scaleform::GFx::AS3::CallFrame other; // [esp+24h] [ebp-60h] BYREF

  mbi_ind = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this->pTraits.pObject[1].pRCCRaw + 60) + 120)
                                  + 4 * (int)this->pTraits.pObject[1].pNext->Scaleform::GFx::AS3::Slots::pPrev)
                      + 8);
  pObject = this->pTraits.pObject;
  v6 = (const Scaleform::GFx::AS3::Traits *)pObject[1].__vftable;
  ((void (__stdcall *)(Scaleform::GFx::ASStringNode **))pObject->GetName)(&v41);
  v7 = this->pTraits.pObject;
  pRCC = (Scaleform::GFx::AS3::VMAbcFile *)v7[1]._pRCC;
  pVM = v7->pVM;
  v10 = Scaleform::GFx::ASString::operator+(
          (Scaleform::GFx::ASString *)&v41,
          (Scaleform::GFx::ASString *)&v43,
          (const __m128i *)" instance constructor");
  if ( pVM->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v42, eStackOverflowError, pVM);
    Scaleform::GFx::AS3::VM::ThrowError(pVM, v11);
    pNode = v42.Message.pNode;
    --v42.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    VMRef = pRCC->VMRef;
    v42.Message.pNode = (Scaleform::GFx::ASStringNode *)HIDWORD(ProfileTicks);
    other.DiscardResult = 1;
    other.ACopy = 0;
    other.RegisteredFunction = 0;
    other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    other.pRegisterFile = &VMRef->RegisterFile;
    other.CP = 0;
    MHeap = VMRef->MHeap;
    other.MBIIndex.Ind = mbi_ind;
    HIDWORD(ProfileTicks) = pRCC->VMRef;
    other.pHeap = MHeap;
    other.pSavedScope = &v6->InitScope;
    v16 = v10->pNode;
    other.pScopeStack = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)(HIDWORD(ProfileTicks) + 80);
    other.pFile = pRCC;
    other.OriginationTraits = v6;
    other.DefXMLNamespace.pObject = 0;
    other.Name.pObject = v16;
    if ( v16 )
      ++v16->RefCount;
    v17.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)_this->Bonus;
    other.StartTicks = __PAIR64__((unsigned int)v42.Message.pNode, ProfileTicks);
    other.CurrFileInd = 0;
    other.CurrLineNumber = 0;
    Flags = _this->Flags;
    other.Invoker.value.VS._1.VInt = _this->value.VS._1.VInt;
    other.Invoker.Bonus = v17;
    v19.VObj = (Scaleform::GFx::AS3::Object *)_this->value.VS._2;
    other.Invoker.Flags = Flags;
    other.Invoker.value.VS._2 = v19;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(_this);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(_this);
    }
    v20 = pRCC->VMRef;
    other.PrevInitialStackPos = v20->OpStack.pCurrent;
    NumOfReservedElem = v20->OpStack.NumOfReservedElem;
    v20 = (Scaleform::GFx::AS3::VM *)((char *)v20 + 40);
    other.PrevReservedNum = NumOfReservedElem;
    other.PrevFirstStackPos = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v20->__vftable + 1);
    v22 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v20, LOWORD(v22->max_stack) + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v22->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&other.DefXMLNamespace,
        *p_DefXMLNamespace);
      v42.ID = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v42);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      pRCC->File.pObject->Methods.Info.Data.Data[pRCC->File.pObject->MethodBodies.Info.Data.Data[mbi_ind]->method_info_ind],
      _this,
      argc,
      argv);
    if ( pVM->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      if ( pVM->GetAdvanceStats(pVM) )
      {
        Instance = Scaleform::AmpServer::GetInstance();
        if ( Instance->GetProfileLevel(Instance) >= Amp_Profile_Level_Medium )
        {
          v25 = Scaleform::AmpServer::GetInstance();
          if ( v25->IsProfiling(v25) )
          {
            pFile = other.pFile;
            v27 = (Scaleform::RefCountVImpl *)(other.pFile->File.pObject->FileHandle
                                             + (other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind]->method_info_ind << 16));
            if ( !other.RegisteredFunction )
            {
              other.RegisteredFunction = 1;
              pData = (const __m128i *)other.Name.pObject->pData;
              SwfFileOffset = other.pFile->File.pObject->SwfFileOffset;
              v28 = pVM->GetAdvanceStats(pVM);
              Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v28, v27, SwfFileOffset, pData, 0, 3u, 0);
              pFile = other.pFile;
            }
            StartTicks = other.StartTicks;
            v38 = pFile->File.pObject->SwfFileOffset;
            v29 = pVM->GetAdvanceStats(pVM);
            Scaleform::GFx::AMP::ViewStats::PushCallstack(v29, (unsigned int)v27, v38, StartTicks);
          }
        }
      }
      Size = pVM->CallStack.Size;
      p_CallStack = &pVM->CallStack;
      v32 = Size >> 6;
      if ( v32 >= p_CallStack->NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          p_CallStack,
          v32);
      v33 = &p_CallStack->Pages[v32][p_CallStack->Size & 0x3F];
      if ( v33 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v33, &other);
      ++p_CallStack->Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
  v34 = v43;
  --v43->RefCount;
  if ( !v34->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  v35 = v41;
  --v41->RefCount;
  if ( !v35->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
}
