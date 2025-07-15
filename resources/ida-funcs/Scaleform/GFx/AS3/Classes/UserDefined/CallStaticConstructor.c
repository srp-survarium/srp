void __thiscall Scaleform::GFx::AS3::Classes::UserDefined::CallStaticConstructor(
        Scaleform::GFx::AS3::Classes::UserDefined *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // edi
  Scaleform::GFx::AS3::VMAbcFile *pRCC; // ebp
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v5; // eax
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::Value *v7; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::GFx::AS3::Value::Extra v13; // ecx
  Scaleform::GFx::AS3::Value::V2U v15; // ecx
  Scaleform::GFx::AS3::VM *v16; // ecx
  unsigned __int16 NumOfReservedElem; // dx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v18; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // esi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v21; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::RefCountVImpl *v23; // esi
  Scaleform::GFx::AMP::ViewStats *v24; // eax
  Scaleform::GFx::AMP::ViewStats *v25; // eax
  unsigned int Size; // esi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *p_CallStack; // ebx
  unsigned int v28; // esi
  Scaleform::GFx::AS3::CallFrame *v29; // ecx
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  unsigned int SwfFileOffset; // [esp-14h] [ebp-C4h]
  const __m128i *pData; // [esp-10h] [ebp-C0h]
  unsigned int v34; // [esp-Ch] [ebp-BCh]
  unsigned __int64 StartTicks; // [esp-8h] [ebp-B8h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> other; // [esp+10h] [ebp-A0h] BYREF
  Scaleform::GFx::ASStringNode *v37; // [esp+14h] [ebp-9Ch] BYREF
  Scaleform::GFx::AS3::Abc::MbiInd mbi_ind; // [esp+18h] [ebp-98h]
  Scaleform::GFx::ASStringNode *v39; // [esp+1Ch] [ebp-94h] BYREF
  Scaleform::GFx::AS3::VM::Error v40; // [esp+20h] [ebp-90h] BYREF
  Scaleform::GFx::AS3::CallFrame v41; // [esp+28h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::Value v42; // [esp+88h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value v43; // [esp+98h] [ebp-18h] BYREF
  unsigned int v44; // [esp+ACh] [ebp-4h]

  mbi_ind.Ind = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this->pTraits.pObject[1].pRCCRaw + 60) + 120)
                                      + 4 * this->pTraits.pObject[1].pNext[2].RefCount)
                          + 8);
  this->pTraits.pObject->GetName(this->pTraits.pObject, (Scaleform::GFx::ASString *)&v37);
  pObject = this->pTraits.pObject;
  pRCC = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1]._pRCC;
  pVM = pObject->pVM;
  other.pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)Scaleform::GFx::ASString::operator+(
                                                                           (Scaleform::GFx::ASString *)&v37,
                                                                           (Scaleform::GFx::ASString *)&v39,
                                                                           (const __m128i *)" class constructor");
  Scaleform::GFx::AS3::Value::Value(&v43, this);
  v40.ID = v5;
  Scaleform::GFx::AS3::Value::Value(&v42, this);
  v7 = v6;
  if ( pVM->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v40, eStackOverflowError, pVM);
    Scaleform::GFx::AS3::VM::ThrowError(pVM, v8);
    pNode = v40.Message.pNode;
    --v40.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    VMRef = pRCC->VMRef;
    v44 = HIDWORD(ProfileTicks);
    v41.DiscardResult = 1;
    v41.ACopy = 0;
    v41.RegisteredFunction = 0;
    v41.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    v41.pRegisterFile = &VMRef->RegisterFile;
    v41.CP = 0;
    v41.pHeap = VMRef->MHeap;
    v41.MBIIndex = mbi_ind;
    HIDWORD(ProfileTicks) = &pRCC->VMRef->ScopeStack;
    v41.pSavedScope = &pObject->InitScope;
    v12 = (Scaleform::GFx::ASStringNode *)other.pObject->__vftable;
    v41.pScopeStack = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)HIDWORD(ProfileTicks);
    v41.pFile = pRCC;
    v41.OriginationTraits = pObject;
    v41.DefXMLNamespace.pObject = 0;
    v41.Name.pObject = v12;
    if ( v12 )
      ++v12->RefCount;
    v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v7->Bonus;
    v41.CurrFileInd = 0;
    v41.CurrLineNumber = 0;
    HIDWORD(ProfileTicks) = v7->value.VS._1.VInt;
    v41.StartTicks = __PAIR64__(v44, ProfileTicks);
    LODWORD(ProfileTicks) = v7->Flags;
    v41.Invoker.value.VS._1.VInt = HIDWORD(ProfileTicks);
    v41.Invoker.Bonus = v13;
    v15.VObj = (Scaleform::GFx::AS3::Object *)v7->value.VS._2;
    v41.Invoker.Flags = ProfileTicks;
    v41.Invoker.value.VS._2 = v15;
    if ( (ProfileTicks & 0x1F) > 9 )
    {
      if ( (ProfileTicks & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v7);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v7);
    }
    v16 = pRCC->VMRef;
    v41.PrevInitialStackPos = v16->OpStack.pCurrent;
    NumOfReservedElem = v16->OpStack.NumOfReservedElem;
    v16 = (Scaleform::GFx::AS3::VM *)((char *)v16 + 40);
    v41.PrevReservedNum = NumOfReservedElem;
    v41.PrevFirstStackPos = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v16->__vftable + 1);
    v18 = v41.pFile->File.pObject->MethodBodies.Info.Data.Data[v41.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v16, LOWORD(v18->max_stack) + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(v41.pRegisterFile, v18->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v41.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&v41.DefXMLNamespace,
        *p_DefXMLNamespace);
      other.pObject = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        &other);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &v41,
      pRCC->File.pObject->Methods.Info.Data.Data[pRCC->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind]->method_info_ind],
      (const Scaleform::GFx::AS3::Value *)v40.ID,
      0,
      0);
    if ( pVM->HandleException )
    {
      v41.ACopy = 1;
    }
    else
    {
      if ( pVM->GetAdvanceStats(pVM) )
      {
        Instance = Scaleform::AmpServer::GetInstance();
        if ( Instance->GetProfileLevel(Instance) >= Amp_Profile_Level_Medium )
        {
          v21 = Scaleform::AmpServer::GetInstance();
          if ( v21->IsProfiling(v21) )
          {
            pFile = v41.pFile;
            v23 = (Scaleform::RefCountVImpl *)(v41.pFile->File.pObject->FileHandle
                                             + (v41.pFile->File.pObject->MethodBodies.Info.Data.Data[v41.MBIIndex.Ind]->method_info_ind << 16));
            if ( !v41.RegisteredFunction )
            {
              v41.RegisteredFunction = 1;
              pData = (const __m128i *)v41.Name.pObject->pData;
              SwfFileOffset = v41.pFile->File.pObject->SwfFileOffset;
              v24 = pVM->GetAdvanceStats(pVM);
              Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v24, v23, SwfFileOffset, pData, 0, 3u, 0);
              pFile = v41.pFile;
            }
            StartTicks = v41.StartTicks;
            v34 = pFile->File.pObject->SwfFileOffset;
            v25 = pVM->GetAdvanceStats(pVM);
            Scaleform::GFx::AMP::ViewStats::PushCallstack(v25, (unsigned int)v23, v34, StartTicks);
          }
        }
      }
      Size = pVM->CallStack.Size;
      p_CallStack = &pVM->CallStack;
      v28 = Size >> 6;
      if ( v28 >= p_CallStack->NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          p_CallStack,
          v28);
      v29 = &p_CallStack->Pages[v28][p_CallStack->Size & 0x3F];
      if ( v29 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v29, &v41);
      ++p_CallStack->Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&v41);
  }
  if ( (v42.Flags & 0x1F) > 9 )
  {
    if ( (v42.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v42);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v42);
  }
  if ( (v43.Flags & 0x1F) > 9 )
  {
    if ( (v43.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v43);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v43);
  }
  v30 = v39;
  --v39->RefCount;
  if ( !v30->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  v31 = v37;
  --v37->RefCount;
  if ( !v31->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
}
