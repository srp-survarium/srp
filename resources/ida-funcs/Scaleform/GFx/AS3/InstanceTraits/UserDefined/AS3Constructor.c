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
  int v10; // ecx
  const Scaleform::GFx::AS3::Traits *v11; // ebx
  Scaleform::GFx::AS3::VM *v12; // ecx
  Scaleform::GFx::AS3::VMAbcFile *FirstOwnSlotNum; // esi
  Scaleform::GFx::AS3::VM *v14; // ebp
  Scaleform::GFx::ASString *v15; // eax
  Scaleform::GFx::AS3::Value *Undefined; // edi
  const Scaleform::GFx::AS3::VM::Error *v17; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *v21; // ecx
  Scaleform::GFx::AS3::Value::Extra v22; // ecx
  Scaleform::GFx::AS3::Value::V2U v24; // ecx
  Scaleform::GFx::AS3::VM *v25; // ecx
  unsigned __int16 NumOfReservedElem; // dx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v27; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v30; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::RefCountVImpl *v32; // esi
  Scaleform::GFx::AMP::ViewStats *v33; // eax
  Scaleform::GFx::AMP::ViewStats *v34; // eax
  unsigned int Size; // esi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *p_CallStack; // ebp
  unsigned int v37; // esi
  Scaleform::GFx::AS3::CallFrame *v38; // ecx
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  unsigned int SwfFileOffset; // [esp-14h] [ebp-A0h]
  const __m128i *pData; // [esp-10h] [ebp-9Ch]
  unsigned int v43; // [esp-Ch] [ebp-98h]
  unsigned __int64 StartTicks; // [esp-8h] [ebp-94h]
  int mbi_ind; // [esp+10h] [ebp-7Ch]
  Scaleform::GFx::AS3::VM::Error v46; // [esp+14h] [ebp-78h] BYREF
  Scaleform::GFx::ASStringNode *v47; // [esp+1Ch] [ebp-70h] BYREF
  Scaleform::GFx::ASStringNode *v48; // [esp+20h] [ebp-6Ch] BYREF
  unsigned int v49; // [esp+28h] [ebp-64h]
  Scaleform::GFx::AS3::CallFrame other; // [esp+2Ch] [ebp-60h] BYREF

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
  v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v9->pTraits.pObject[1].FirstOwnSlotNum + 60) + 120)
                              + 4 * method_info_ind)
                  + 8);
  v11 = ot->pParent.pObject;
  mbi_ind = v10;
  if ( !v9->Initialized )
  {
    v9->Execute(v9);
    v12 = v9->pTraits.pObject->pVM;
    if ( !v12->HandleException )
      Scaleform::GFx::AS3::VM::ExecuteCode(v12, 1u);
  }
  FirstOwnSlotNum = (Scaleform::GFx::AS3::VMAbcFile *)this->Script.pObject->pTraits.pObject[1].FirstOwnSlotNum;
  v14 = this->pVM;
  v15 = this->GetName(this, &v48);
  v46.ID = (Scaleform::GFx::AS3::VM::ErrorID)Scaleform::GFx::ASString::operator+(
                                               v15,
                                               (Scaleform::GFx::ASString *)&v47,
                                               (const __m128i *)" instance constructor");
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  if ( v14->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v46, eStackOverflowError, v14);
    Scaleform::GFx::AS3::VM::ThrowError(v14, v17);
    pNode = v46.Message.pNode;
    --v46.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    VMRef = FirstOwnSlotNum->VMRef;
    v49 = HIDWORD(ProfileTicks);
    other.DiscardResult = 1;
    other.ACopy = 0;
    other.RegisteredFunction = 0;
    other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    other.pRegisterFile = &VMRef->RegisterFile;
    other.CP = 0;
    other.pHeap = VMRef->MHeap;
    other.MBIIndex.Ind = mbi_ind;
    HIDWORD(ProfileTicks) = &FirstOwnSlotNum->VMRef->ScopeStack;
    other.pSavedScope = &v11->InitScope;
    v21 = *(Scaleform::GFx::ASStringNode **)v46.ID;
    other.pScopeStack = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)HIDWORD(ProfileTicks);
    other.pFile = FirstOwnSlotNum;
    other.OriginationTraits = v11;
    other.DefXMLNamespace.pObject = 0;
    other.Name.pObject = v21;
    if ( v21 )
      ++v21->RefCount;
    v22.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)Undefined->Bonus;
    other.CurrFileInd = 0;
    other.CurrLineNumber = 0;
    HIDWORD(ProfileTicks) = Undefined->value.VS._1.VInt;
    other.StartTicks = __PAIR64__(v49, ProfileTicks);
    LODWORD(ProfileTicks) = Undefined->Flags;
    other.Invoker.value.VS._1.VInt = HIDWORD(ProfileTicks);
    other.Invoker.Bonus = v22;
    v24.VObj = (Scaleform::GFx::AS3::Object *)Undefined->value.VS._2;
    other.Invoker.Flags = ProfileTicks;
    other.Invoker.value.VS._2 = v24;
    if ( (ProfileTicks & 0x1F) > 9 )
    {
      if ( (ProfileTicks & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    }
    v25 = FirstOwnSlotNum->VMRef;
    other.PrevInitialStackPos = v25->OpStack.pCurrent;
    NumOfReservedElem = v25->OpStack.NumOfReservedElem;
    v25 = (Scaleform::GFx::AS3::VM *)((char *)v25 + 40);
    other.PrevReservedNum = NumOfReservedElem;
    other.PrevFirstStackPos = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v25->__vftable + 1);
    v27 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v25, LOWORD(v27->max_stack) + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v27->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&other.DefXMLNamespace,
        *p_DefXMLNamespace);
      v46.ID = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v46);
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      FirstOwnSlotNum->File.pObject->Methods.Info.Data.Data[FirstOwnSlotNum->File.pObject->MethodBodies.Info.Data.Data[mbi_ind]->method_info_ind],
      _this,
      argc,
      argv);
    if ( v14->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      if ( v14->GetAdvanceStats(v14) )
      {
        Instance = Scaleform::AmpServer::GetInstance();
        if ( Instance->GetProfileLevel(Instance) >= Amp_Profile_Level_Medium )
        {
          v30 = Scaleform::AmpServer::GetInstance();
          if ( v30->IsProfiling(v30) )
          {
            pFile = other.pFile;
            v32 = (Scaleform::RefCountVImpl *)(other.pFile->File.pObject->FileHandle
                                             + (other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind]->method_info_ind << 16));
            if ( !other.RegisteredFunction )
            {
              other.RegisteredFunction = 1;
              pData = (const __m128i *)other.Name.pObject->pData;
              SwfFileOffset = other.pFile->File.pObject->SwfFileOffset;
              v33 = v14->GetAdvanceStats(v14);
              Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v33, v32, SwfFileOffset, pData, 0, 3u, 0);
              pFile = other.pFile;
            }
            StartTicks = other.StartTicks;
            v43 = pFile->File.pObject->SwfFileOffset;
            v34 = v14->GetAdvanceStats(v14);
            Scaleform::GFx::AMP::ViewStats::PushCallstack(v34, (unsigned int)v32, v43, StartTicks);
          }
        }
      }
      Size = v14->CallStack.Size;
      p_CallStack = &v14->CallStack;
      v37 = Size >> 6;
      if ( v37 >= p_CallStack->NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          p_CallStack,
          v37);
      v38 = &p_CallStack->Pages[v37][p_CallStack->Size & 0x3F];
      if ( v38 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v38, &other);
      ++p_CallStack->Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
  v39 = v47;
  --v47->RefCount;
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  v40 = v48;
  --v48->RefCount;
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
}
