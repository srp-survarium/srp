void __thiscall Scaleform::GFx::AS3::VM::exec_callstatic(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MiInd ind,
        unsigned int arg_count)
{
  int MethodBodyInfoInd; // ebx
  const Scaleform::GFx::AS3::Traits *v6; // ebp
  Scaleform::GFx::ASString *v7; // eax
  bool v8; // zf
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::AS3::VM *v14; // ecx
  unsigned __int16 NumOfReservedElem; // ax
  Scaleform::GFx::AS3::Value *pCurrent; // edx
  Scaleform::GFx::AS3::Value *v17; // edx
  Scaleform::GFx::AS3::Abc::File *pObject; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v19; // ebp
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // ebp
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v22; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // ebx
  Scaleform::GFx::AS3::Abc::File *v24; // eax
  Scaleform::RefCountVImpl *v25; // esi
  Scaleform::GFx::AMP::ViewStats *(__thiscall *GetAdvanceStats)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::GFx::AMP::ViewStats *v27; // eax
  Scaleform::GFx::AMP::ViewStats *v28; // eax
  Scaleform::ArrayPagedCC<Scaleform::GFx::AS3::CallFrame,6,64,329> *p_CallStack; // esi
  unsigned int v30; // edi
  Scaleform::GFx::AS3::CallFrame *v31; // ecx
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  unsigned int SwfFileOffset; // [esp-20h] [ebp-150h]
  const __m128i *pData; // [esp-1Ch] [ebp-14Ch]
  unsigned int v36; // [esp-18h] [ebp-148h]
  unsigned __int64 StartTicks; // [esp-14h] [ebp-144h]
  Scaleform::GFx::ASStringNode *v38; // [esp+4h] [ebp-12Ch] BYREF
  Scaleform::GFx::AS3::Value *argv; // [esp+8h] [ebp-128h]
  Scaleform::GFx::AS3::VM::Error v40; // [esp+Ch] [ebp-124h] BYREF
  Scaleform::GFx::ASStringNode *v41; // [esp+14h] [ebp-11Ch] BYREF
  Scaleform::GFx::AS3::CallFrame other; // [esp+18h] [ebp-118h] BYREF
  unsigned int v43; // [esp+7Ch] [ebp-B4h]
  Scaleform::GFx::AS3::ReadArgsObject args; // [esp+80h] [ebp-B0h] BYREF

  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&args, this, arg_count);
  args.ArgObject.Flags = args.OpStack->pCurrent->Flags;
  args.ArgObject.Bonus.pWeakProxy = args.OpStack->pCurrent->Bonus.pWeakProxy;
  args.ArgObject.value.VNumber = args.OpStack->pCurrent->value.VNumber;
  --args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, &args.ArgObject);
  if ( !this->HandleException )
  {
    MethodBodyInfoInd = file->File.pObject->Methods.Info.Data.Data[ind.Ind]->MethodBodyInfoInd;
    v6 = *(const Scaleform::GFx::AS3::Traits **)(args.ArgObject.value.VS._1.VInt + 20);
    v6->GetName(v6, (Scaleform::GFx::ASString *)&v38);
    if ( args.ArgNum > 8 )
      argv = args.CallArgs.Data.Data;
    else
      argv = args.FixedArr;
    if ( (_S15 & 1) == 0 )
    {
      _S15 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v7 = Scaleform::GFx::ASString::operator+(
           (Scaleform::GFx::ASString *)&v38,
           (Scaleform::GFx::ASString *)&v41,
           (const __m128i *)" callstatic");
    v8 = this->CallStack.Size == 128;
    v40.ID = (Scaleform::GFx::AS3::VM::ErrorID)v7;
    if ( v8 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v40, eStackOverflowError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v9,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
      pNode = v40.Message.pNode;
      --v40.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      VMRef = file->VMRef;
      v43 = HIDWORD(ProfileTicks);
      other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
      other.pRegisterFile = &VMRef->RegisterFile;
      other.pHeap = VMRef->MHeap;
      other.pScopeStack = &VMRef->ScopeStack;
      v13 = *(Scaleform::GFx::ASStringNode **)v40.ID;
      other.pSavedScope = &v6->InitScope;
      other.DiscardResult = 0;
      other.ACopy = 0;
      other.RegisteredFunction = 0;
      other.CP = 0;
      other.pFile = file;
      other.MBIIndex.Ind = MethodBodyInfoInd;
      other.OriginationTraits = v6;
      other.DefXMLNamespace.pObject = 0;
      other.Name.pObject = v13;
      if ( v13 )
        ++v13->RefCount;
      other.StartTicks = __PAIR64__(v43, ProfileTicks);
      other.CurrFileInd = 0;
      other.CurrLineNumber = 0;
      other.Invoker = v;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          ++v.Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&v);
      }
      v14 = file->VMRef;
      NumOfReservedElem = v14->OpStack.NumOfReservedElem;
      pCurrent = v14->OpStack.pCurrent;
      v14 = (Scaleform::GFx::AS3::VM *)((char *)v14 + 40);
      other.PrevInitialStackPos = pCurrent;
      v17 = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v14->__vftable + 1);
      other.PrevReservedNum = NumOfReservedElem;
      pObject = file->File.pObject;
      other.PrevFirstStackPos = v17;
      v19 = pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd];
      Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v14, LOWORD(v19->max_stack) + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v19->local_reg_count);
      p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&file->VMRef->DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&other.DefXMLNamespace,
          *p_DefXMLNamespace);
        v40.ID = 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
          (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v40);
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &other,
        (int)file->File.pObject->Methods.Info.Data.Data[file->File.pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd]->method_info_ind],
        &args.ArgObject,
        arg_count,
        argv);
      if ( this->HandleException )
      {
        other.ACopy = 1;
      }
      else
      {
        if ( this->GetAdvanceStats(this) )
        {
          Instance = Scaleform::AmpServer::GetInstance();
          if ( Instance->GetProfileLevel(Instance) >= Amp_Profile_Level_Medium )
          {
            v22 = Scaleform::AmpServer::GetInstance();
            if ( v22->IsProfiling(v22) )
            {
              pFile = other.pFile;
              v24 = other.pFile->File.pObject;
              v25 = (Scaleform::RefCountVImpl *)(v24->FileHandle
                                               + (v24->MethodBodies.Info.Data.Data[other.MBIIndex.Ind]->method_info_ind << 16));
              if ( !other.RegisteredFunction )
              {
                pData = (const __m128i *)other.Name.pObject->pData;
                SwfFileOffset = v24->SwfFileOffset;
                GetAdvanceStats = this->GetAdvanceStats;
                other.RegisteredFunction = 1;
                v27 = GetAdvanceStats(this);
                Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v27, v25, SwfFileOffset, pData, 0, 3u, 0);
              }
              StartTicks = other.StartTicks;
              v36 = pFile->File.pObject->SwfFileOffset;
              v28 = this->GetAdvanceStats(this);
              Scaleform::GFx::AMP::ViewStats::PushCallstack(v28, (unsigned int)v25, v36, StartTicks);
            }
          }
        }
        p_CallStack = &this->CallStack;
        v30 = this->CallStack.Size >> 6;
        if ( v30 >= p_CallStack->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
            p_CallStack,
            v30);
        v31 = &p_CallStack->Pages[v30][p_CallStack->Size & 0x3F];
        if ( v31 )
          Scaleform::GFx::AS3::CallFrame::CallFrame(v31, &other);
        ++p_CallStack->Size;
      }
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
    }
    v32 = v41;
    --v41->RefCount;
    if ( !v32->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v32);
    v33 = v38;
    --v38->RefCount;
    if ( !v33->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  }
  Scaleform::GFx::AS3::ReadArgsObject::~ReadArgsObject(&args);
}
