void __thiscall Scaleform::GFx::AS3::Instances::Function::Execute(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool discard_result)
{
  unsigned int v6; // ecx
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // ebp
  Scaleform::GFx::AS3::VMAbcFile *Parent; // edi
  const Scaleform::GFx::AS3::Traits *v10; // ecx
  bool v11; // zf
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_StoredScopeStack; // ecx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v18; // ecx
  Scaleform::GFx::AS3::VM *v19; // ecx
  unsigned __int16 NumOfReservedElem; // dx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v21; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // esi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v24; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::RefCountVImpl *v26; // esi
  Scaleform::GFx::AMP::ViewStats *v27; // eax
  Scaleform::GFx::AMP::ViewStats *v28; // eax
  unsigned int Size; // esi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *p_CallStack; // ebp
  unsigned int v31; // esi
  Scaleform::GFx::AS3::CallFrame *v32; // ecx
  unsigned int SwfFileOffset; // [esp-14h] [ebp-ACh]
  const __m128i *pData; // [esp-10h] [ebp-A8h]
  unsigned int v35; // [esp-Ch] [ebp-A4h]
  unsigned __int64 StartTicks; // [esp-8h] [ebp-A0h]
  const Scaleform::GFx::AS3::Traits *otr; // [esp+10h] [ebp-88h] BYREF
  Scaleform::GFx::ASStringNode *v38; // [esp+14h] [ebp-84h]
  Scaleform::GFx::AS3::Abc::MbiInd mbi_ind; // [esp+18h] [ebp-80h]
  Scaleform::GFx::AS3::Value *p_This; // [esp+1Ch] [ebp-7Ch]
  Scaleform::GFx::AS3::Value v41; // [esp+20h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::CallFrame other; // [esp+30h] [ebp-68h] BYREF
  unsigned int v43; // [esp+94h] [ebp-4h]

  v6 = this->This.Flags & 0x1F;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  if ( v6 && (v6 - 12 > 3 || this->This.value.VS._1.VInt) )
    p_This = (Scaleform::GFx::AS3::Value *)&this->This;
  else
    p_This = _this;
  Parent = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1].Parent;
  v10 = (const Scaleform::GFx::AS3::Traits *)pObject[1].VArray.Data.Data->Value.File.pObject;
  mbi_ind.Ind = Parent->File.pObject->Methods.Info.Data.Data[pObject[1].FirstOwnSlotNum]->MethodBodyInfoInd;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v11 = pVM->CallStack.Size == 128;
  otr = v10;
  v41.Flags = 14;
  v41.Bonus.pWeakProxy = 0;
  v41.value.VS._1.VInt = (int)this;
  if ( v11 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&otr, eStackOverflowError, pVM);
    Scaleform::GFx::AS3::VM::ThrowError(pVM, v12);
    v13 = v38;
    --v38->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  else
  {
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    other.DiscardResult = discard_result;
    VMRef = Parent->VMRef;
    v43 = HIDWORD(ProfileTicks);
    other.ACopy = 0;
    other.RegisteredFunction = 0;
    other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    other.pRegisterFile = &VMRef->RegisterFile;
    other.CP = 0;
    other.pHeap = VMRef->MHeap;
    p_StoredScopeStack = &this->StoredScopeStack;
    pNode = this->Name.pNode;
    other.pSavedScope = p_StoredScopeStack;
    v18 = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)Parent->VMRef;
    other.MBIIndex = mbi_ind;
    other.pFile = Parent;
    other.OriginationTraits = otr;
    other.pScopeStack = v18 + 5;
    other.DefXMLNamespace.pObject = 0;
    other.Name.pObject = pNode;
    if ( pNode )
      ++pNode->RefCount;
    other.StartTicks = __PAIR64__(v43, ProfileTicks);
    other.Invoker = v41;
    other.CurrFileInd = 0;
    other.CurrLineNumber = 0;
    if ( (v41.Flags & 0x1F) > 9 )
    {
      if ( (v41.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(&v41);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(&v41);
    }
    v19 = Parent->VMRef;
    other.PrevInitialStackPos = v19->OpStack.pCurrent;
    NumOfReservedElem = v19->OpStack.NumOfReservedElem;
    v19 = (Scaleform::GFx::AS3::VM *)((char *)v19 + 40);
    other.PrevReservedNum = NumOfReservedElem;
    other.PrevFirstStackPos = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v19->__vftable + 1);
    v21 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v19, LOWORD(v21->max_stack) + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v21->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&other.DefXMLNamespace,
        *p_DefXMLNamespace);
      otr = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&otr);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      Parent->File.pObject->Methods.Info.Data.Data[Parent->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind]->method_info_ind],
      p_This,
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
          v24 = Scaleform::AmpServer::GetInstance();
          if ( v24->IsProfiling(v24) )
          {
            pFile = other.pFile;
            v26 = (Scaleform::RefCountVImpl *)(other.pFile->File.pObject->FileHandle
                                             + (other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind]->method_info_ind << 16));
            if ( !other.RegisteredFunction )
            {
              other.RegisteredFunction = 1;
              pData = (const __m128i *)other.Name.pObject->pData;
              SwfFileOffset = other.pFile->File.pObject->SwfFileOffset;
              v27 = pVM->GetAdvanceStats(pVM);
              Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v27, v26, SwfFileOffset, pData, 0, 3u, 0);
              pFile = other.pFile;
            }
            StartTicks = other.StartTicks;
            v35 = pFile->File.pObject->SwfFileOffset;
            v28 = pVM->GetAdvanceStats(pVM);
            Scaleform::GFx::AMP::ViewStats::PushCallstack(v28, (unsigned int)v26, v35, StartTicks);
          }
        }
      }
      Size = pVM->CallStack.Size;
      p_CallStack = &pVM->CallStack;
      v31 = Size >> 6;
      if ( v31 >= p_CallStack->NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          p_CallStack,
          v31);
      v32 = &p_CallStack->Pages[v31][p_CallStack->Size & 0x3F];
      if ( v32 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v32, &other);
      ++p_CallStack->Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
  if ( (v41.Flags & 0x1F) > 9 )
  {
    if ( (v41.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v41);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v41);
  }
}
