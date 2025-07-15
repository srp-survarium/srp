void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::Execute(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *this)
{
  bool v2; // zf
  unsigned int v3; // ebp
  Scaleform::GFx::AS3::Traits *pObject; // esi
  Scaleform::GFx::AS3::VMAbcFile *FirstOwnSlotNum; // edi
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::ASString *v7; // eax
  Scaleform::GFx::AS3::Object *v8; // ebp
  Scaleform::GFx::AS3::VM::ErrorID v9; // eax
  Scaleform::GFx::AS3::Value *v10; // eax
  Scaleform::GFx::AS3::Value *v11; // ebp
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *v16; // ecx
  Scaleform::GFx::AS3::Value::Extra v17; // ecx
  Scaleform::GFx::AS3::Value::V2U v19; // ecx
  Scaleform::GFx::AS3::VM *v20; // ecx
  unsigned __int16 NumOfReservedElem; // dx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v22; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // esi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v25; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::RefCountVImpl *v27; // esi
  Scaleform::GFx::AMP::ViewStats *v28; // eax
  Scaleform::GFx::AMP::ViewStats *v29; // eax
  unsigned int Size; // esi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *p_CallStack; // ebx
  unsigned int v32; // esi
  Scaleform::GFx::AS3::CallFrame *v33; // ecx
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  void *v36; // esi
  unsigned int SwfFileOffset; // [esp-20h] [ebp-3DCh]
  const __m128i *pData; // [esp-1Ch] [ebp-3D8h]
  unsigned int v39; // [esp-18h] [ebp-3D4h]
  unsigned __int64 StartTicks; // [esp-14h] [ebp-3D0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> other; // [esp+4h] [ebp-3B8h] BYREF
  Scaleform::String v42; // [esp+8h] [ebp-3B4h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [esp+Fh] [ebp-3ADh] BYREF
  Scaleform::GFx::AS3::Abc::MbiInd mbi_ind; // [esp+10h] [ebp-3ACh]
  Scaleform::GFx::AS3::Object *v; // [esp+14h] [ebp-3A8h]
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+18h] [ebp-3A4h] BYREF
  Scaleform::GFx::AS3::VM::Error v47; // [esp+1Ch] [ebp-3A0h] BYREF
  Scaleform::GFx::ASStringNode *v48; // [esp+24h] [ebp-398h] BYREF
  Scaleform::GFx::AS3::CallFrame v49; // [esp+28h] [ebp-394h] BYREF
  Scaleform::GFx::AS3::Value v50; // [esp+88h] [ebp-334h] BYREF
  Scaleform::GFx::AS3::Value v51; // [esp+98h] [ebp-324h] BYREF
  Scaleform::MsgFormat::Sink r; // [esp+A8h] [ebp-314h] BYREF
  unsigned int v53; // [esp+B8h] [ebp-304h]
  Scaleform::MsgFormat v54; // [esp+BCh] [ebp-300h] BYREF

  v2 = !this->Initialized;
  v = this;
  if ( v2
    && Scaleform::GFx::AS3::Traits::SetupSlotValues(
         this->pTraits.pObject,
         &result,
         (Scaleform::GFx::AS3::VMAbcFile *)this->pTraits.pObject[1].FirstOwnSlotNum,
         (const Scaleform::GFx::AS3::Abc::HasTraits *)this->pTraits.pObject[1].Parent,
         this)->Result )
  {
    mbi_ind.Ind = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this->pTraits.pObject[1].FirstOwnSlotNum + 60) + 120)
                                        + 4 * this->pTraits.pObject[1].Parent->VArray.Data.Size)
                            + 8);
    other.pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)mbi_ind.Ind;
    Scaleform::String::String(&v42);
    r.Type = tStr;
    r.SinkData.pStr = &v42;
    Scaleform::MsgFormat::MsgFormat(&v54, &r);
    Scaleform::MsgFormat::Parse(&v54, "{0}");
    Scaleform::MsgFormat::FormatD1<int>(&v54, (int *)&other);
    Scaleform::MsgFormat::FinishFormatD(&v54);
    Scaleform::MsgFormat::~MsgFormat(&v54);
    v3 = v42.HeapTypeBits & 0xFFFFFFFC;
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                        (char *)name,
                        strlen(name),
                        0);
    ++ConstStringNode->RefCount;
    pObject = this->pTraits.pObject;
    FirstOwnSlotNum = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1].FirstOwnSlotNum;
    pVM = pObject->pVM;
    v7 = Scaleform::GFx::ASString::operator+(
           (Scaleform::GFx::ASString *)&ConstStringNode,
           (Scaleform::GFx::ASString *)&v48,
           (const __m128i *)(v3 + 8));
    v8 = v;
    other.pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)v7;
    Scaleform::GFx::AS3::Value::Value(&v51, v);
    v47.ID = v9;
    Scaleform::GFx::AS3::Value::Value(&v50, v8);
    v11 = v10;
    if ( pVM->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v47, eStackOverflowError, pVM);
      Scaleform::GFx::AS3::VM::ThrowError(pVM, v12);
      pNode = v47.Message.pNode;
      --v47.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      VMRef = FirstOwnSlotNum->VMRef;
      v53 = HIDWORD(ProfileTicks);
      v49.DiscardResult = 1;
      v49.ACopy = 0;
      v49.RegisteredFunction = 0;
      v49.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
      v49.pRegisterFile = &VMRef->RegisterFile;
      v49.CP = 0;
      v49.pHeap = VMRef->MHeap;
      v49.MBIIndex = mbi_ind;
      HIDWORD(ProfileTicks) = &FirstOwnSlotNum->VMRef->ScopeStack;
      v49.pSavedScope = &pObject->InitScope;
      v16 = (Scaleform::GFx::ASStringNode *)other.pObject->__vftable;
      v49.pScopeStack = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)HIDWORD(ProfileTicks);
      v49.pFile = FirstOwnSlotNum;
      v49.OriginationTraits = pObject;
      v49.DefXMLNamespace.pObject = 0;
      v49.Name.pObject = v16;
      if ( v16 )
        ++v16->RefCount;
      v17.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v11->Bonus;
      v49.CurrFileInd = 0;
      v49.CurrLineNumber = 0;
      HIDWORD(ProfileTicks) = v11->value.VS._1.VInt;
      v49.StartTicks = __PAIR64__(v53, ProfileTicks);
      LODWORD(ProfileTicks) = v11->Flags;
      v49.Invoker.value.VS._1.VInt = HIDWORD(ProfileTicks);
      v49.Invoker.Bonus = v17;
      v19.VObj = (Scaleform::GFx::AS3::Object *)v11->value.VS._2;
      v49.Invoker.Flags = ProfileTicks;
      v49.Invoker.value.VS._2 = v19;
      if ( (ProfileTicks & 0x1F) > 9 )
      {
        if ( (ProfileTicks & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(v11);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v11);
      }
      v20 = FirstOwnSlotNum->VMRef;
      v49.PrevInitialStackPos = v20->OpStack.pCurrent;
      NumOfReservedElem = v20->OpStack.NumOfReservedElem;
      v20 = (Scaleform::GFx::AS3::VM *)((char *)v20 + 40);
      v49.PrevReservedNum = NumOfReservedElem;
      v49.PrevFirstStackPos = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v20->__vftable + 1);
      v22 = v49.pFile->File.pObject->MethodBodies.Info.Data.Data[v49.MBIIndex.Ind];
      Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v20, LOWORD(v22->max_stack) + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(v49.pRegisterFile, v22->local_reg_count);
      p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v49.pFile->VMRef->DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&v49.DefXMLNamespace,
          *p_DefXMLNamespace);
        other.pObject = 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
          &other);
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &v49,
        FirstOwnSlotNum->File.pObject->Methods.Info.Data.Data[FirstOwnSlotNum->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind]->method_info_ind],
        (const Scaleform::GFx::AS3::Value *)v47.ID,
        0,
        0);
      if ( pVM->HandleException )
      {
        v49.ACopy = 1;
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
              pFile = v49.pFile;
              v27 = (Scaleform::RefCountVImpl *)(v49.pFile->File.pObject->FileHandle
                                               + (v49.pFile->File.pObject->MethodBodies.Info.Data.Data[v49.MBIIndex.Ind]->method_info_ind << 16));
              if ( !v49.RegisteredFunction )
              {
                v49.RegisteredFunction = 1;
                pData = (const __m128i *)v49.Name.pObject->pData;
                SwfFileOffset = v49.pFile->File.pObject->SwfFileOffset;
                v28 = pVM->GetAdvanceStats(pVM);
                Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v28, v27, SwfFileOffset, pData, 0, 3u, 0);
                pFile = v49.pFile;
              }
              StartTicks = v49.StartTicks;
              v39 = pFile->File.pObject->SwfFileOffset;
              v29 = pVM->GetAdvanceStats(pVM);
              Scaleform::GFx::AMP::ViewStats::PushCallstack(v29, (unsigned int)v27, v39, StartTicks);
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
          Scaleform::GFx::AS3::CallFrame::CallFrame(v33, &v49);
        ++p_CallStack->Size;
      }
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&v49);
    }
    if ( (v50.Flags & 0x1F) > 9 )
    {
      if ( (v50.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v50);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v50);
    }
    if ( (v51.Flags & 0x1F) > 9 )
    {
      if ( (v51.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
    }
    v34 = v48;
    --v48->RefCount;
    if ( !v34->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    v35 = ConstStringNode;
    --ConstStringNode->RefCount;
    if ( !v35->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v35);
    v36 = (void *)(v42.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v42.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v36);
    if ( !v->pTraits.pObject->pVM->HandleException )
      LOBYTE(v[1].__vftable) = 1;
  }
}
