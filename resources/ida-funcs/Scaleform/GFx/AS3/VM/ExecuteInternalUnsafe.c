void __thiscall Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *func,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool result_on_stack)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::V1U v9; // ecx
  Scaleform::GFx::AS3::Value::V1U v10; // ecx
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v13; // zf
  Scaleform::GFx::AS3::Value *v14; // esi
  Scaleform::GFx::AS3::Value::V1U v15; // edi
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // eax
  const char *v19; // edi
  unsigned int v20; // edi
  const Scaleform::GFx::AS3::VM::Error *v21; // eax
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::Value *v23; // esi
  Scaleform::GFx::AS3::Value::V1U v24; // ebx
  Scaleform::GFx::AS3::Object *VObj; // edi
  unsigned int v26; // eax
  unsigned int v27; // eax
  const char *v28; // ebx
  unsigned int v29; // ebx
  const Scaleform::GFx::AS3::VM::Error *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::ASStringNode *v32; // ecx
  Scaleform::GFx::AS3::Value *v33; // esi
  Scaleform::GFx::AS3::VTable *VT; // eax
  int v35; // ecx
  int v36; // edx
  const Scaleform::GFx::AS3::Traits *v37; // ebx
  Scaleform::GFx::AS3::Traits_vtbl *v38; // edx
  Scaleform::GFx::AS3::VMAbcFile *v39; // ebp
  Scaleform::GFx::AS3::VTable *v40; // eax
  const Scaleform::GFx::AS3::VM::Error *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  Scaleform::GFx::ASStringNode *v44; // ecx
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // ecx
  Scaleform::GFx::AS3::VM *v48; // ecx
  unsigned __int16 NumOfReservedElem; // dx
  Scaleform::GFx::AS3::Value *v50; // eax
  Scaleform::GFx::AS3::Value *v51; // eax
  Scaleform::GFx::AS3::Abc::File *pObject; // edx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v53; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v56; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // ebx
  Scaleform::GFx::AS3::Abc::File *v58; // eax
  Scaleform::RefCountVImpl *v59; // edi
  Scaleform::GFx::AMP::ViewStats *(__thiscall *GetAdvanceStats)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::GFx::AMP::ViewStats *v61; // eax
  Scaleform::GFx::AMP::ViewStats *v62; // eax
  unsigned int v63; // ebx
  Scaleform::GFx::AS3::CallFrame *v64; // ecx
  int v65; // ecx
  unsigned int v66; // edx
  unsigned int v67; // eax
  unsigned int v68; // eax
  const char *v69; // ecx
  unsigned int v70; // ecx
  const Scaleform::GFx::AS3::VM::Error *v71; // eax
  Scaleform::GFx::AS3::Value *v72; // esi
  Scaleform::GFx::AS3::Value::V2U v73; // eax
  Scaleform::GFx::AS3::Traits *v74; // ecx
  Scaleform::GFx::AS3::VTable *v75; // eax
  __int32 v76; // ebp
  Scaleform::GFx::AS3::Object *v77; // eax
  const Scaleform::GFx::AS3::Traits *v78; // ebx
  Scaleform::GFx::AS3::Traits_vtbl *v79; // edx
  Scaleform::GFx::AS3::VMAbcFile *v80; // ebp
  Scaleform::GFx::AS3::VTable *v81; // eax
  const Scaleform::GFx::AS3::VM::Error *v82; // eax
  Scaleform::GFx::ASStringNode *v83; // eax
  Scaleform::GFx::AS3::VM *v84; // ecx
  Scaleform::GFx::ASStringNode *v85; // ecx
  unsigned __int64 v86; // rax
  Scaleform::GFx::AS3::WeakProxy *v88; // ecx
  Scaleform::GFx::AS3::VM *v89; // ecx
  unsigned __int16 v90; // dx
  Scaleform::GFx::AS3::Value *v91; // eax
  int v92; // ebx
  Scaleform::GFx::AS3::Value *v93; // eax
  Scaleform::GFx::AS3::Abc::File *v94; // edx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v95; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **v96; // edi
  Scaleform::AmpServer *v97; // eax
  Scaleform::AmpServer *v98; // eax
  Scaleform::GFx::AS3::VMAbcFile *v99; // ebx
  Scaleform::GFx::AS3::Abc::File *v100; // eax
  Scaleform::RefCountVImpl *v101; // edi
  Scaleform::GFx::AMP::ViewStats *(__thiscall *v102)(Scaleform::GFx::AS3::VM *); // eax
  Scaleform::GFx::AMP::ViewStats *v103; // eax
  Scaleform::GFx::AMP::ViewStats *v104; // eax
  unsigned int v105; // ebx
  Scaleform::GFx::AS3::CallFrame *v106; // ecx
  int v107; // ebp
  unsigned int v108; // ecx
  unsigned int v109; // eax
  unsigned int v110; // eax
  const char *v111; // ebp
  unsigned int v112; // ebp
  const Scaleform::GFx::AS3::VM::Error *v113; // eax
  Scaleform::GFx::ASStringNode *v114; // eax
  Scaleform::GFx::AS3::Value *v115; // esi
  const Scaleform::GFx::AS3::VM::Error *v116; // eax
  Scaleform::StringDataPtr v117; // [esp-1Ch] [ebp-B8h]
  Scaleform::StringDataPtr v118; // [esp-1Ch] [ebp-B8h]
  unsigned int SwfFileOffset; // [esp-1Ch] [ebp-B8h]
  Scaleform::StringDataPtr v120; // [esp-1Ch] [ebp-B8h]
  unsigned int v121; // [esp-1Ch] [ebp-B8h]
  Scaleform::StringDataPtr v122; // [esp-1Ch] [ebp-B8h]
  const __m128i *pData; // [esp-18h] [ebp-B4h]
  const __m128i *v124; // [esp-18h] [ebp-B4h]
  unsigned int v125; // [esp-14h] [ebp-B0h]
  unsigned int v126; // [esp-14h] [ebp-B0h]
  unsigned __int64 StartTicks; // [esp-10h] [ebp-ACh]
  unsigned __int64 v128; // [esp-10h] [ebp-ACh]
  Scaleform::GFx::AS3::VM::Error v129; // [esp+8h] [ebp-94h] BYREF
  int MethodBodyInfoInd; // [esp+10h] [ebp-8Ch]
  int ind; // [esp+14h] [ebp-88h] BYREF
  unsigned int v132; // [esp+18h] [ebp-84h]
  Scaleform::GFx::AS3::CallFrame other; // [esp+1Ch] [ebp-80h] BYREF
  Scaleform::GFx::AS3::Value v134; // [esp+7Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v135; // [esp+8Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VM::Error v136; // [esp+94h] [ebp-8h] BYREF

  _mm_prefetch((const char *)_this, 2);
  Flags = func->Flags;
  _mm_prefetch((const char *)func, 2);
  switch ( Flags & 0x1F )
  {
    case 5u:
      v15 = func->value.VS._1;
      v16 = *(_DWORD *)(v15.VInt + 16);
      _mm_prefetch((const char *)v15.VInt, 2);
      v17 = (v16 >> 10) & 0xFFF;
      if ( v17 != 4095 && (argc > v17 || argc < ((v16 >> 7) & 7)) )
      {
        v18 = *(_DWORD *)(v15.VInt + 16);
        v19 = *(const char **)(v15.VInt + 8);
        v117.pStr = v19;
        if ( v19 )
          v20 = strlen(v19);
        else
          v20 = 0;
        v117.Size = v20;
        Scaleform::GFx::AS3::VM::Error::Error(
          &v129,
          eWrongArgumentCountError,
          (Scaleform::String)this,
          v117,
          (v18 >> 7) & 7,
          (v18 >> 10) & 0xFFF,
          argc);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v21,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        pNode = v129.Message.pNode;
        goto LABEL_123;
      }
      (*(void (__cdecl **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v15.VInt)(
        v15,
        this,
        _this,
        result,
        argc,
        argv);
      if ( result_on_stack && !this->HandleException )
      {
        v13 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
        pCurrent = this->OpStack.pCurrent;
        if ( !v13 )
        {
          *pCurrent = *result;
          result->Flags = 0;
        }
      }
      return;
    case 7u:
      VT = Scaleform::GFx::AS3::Traits::GetVT(func->value.VS._2.pTraits);
      ind = func->value.VS._1.VInt;
      v35 = (int)&VT->VTMethods.Data.Data[ind];
      v36 = *(_DWORD *)v35;
      _mm_prefetch((const char *)v35, 2);
      if ( (v36 & 0x1F) == 6 )
      {
        v37 = *(const Scaleform::GFx::AS3::Traits **)(v35 + 12);
        v38 = v37->__vftable;
        MethodBodyInfoInd = *(_DWORD *)(v35 + 8);
        v39 = v38->GetFilePtr(v37);
        MethodBodyInfoInd = v39->File.pObject->Methods.Info.Data.Data[MethodBodyInfoInd]->MethodBodyInfoInd;
        v40 = Scaleform::GFx::AS3::Traits::GetVT(v37);
        v13 = this->CallStack.Size == 128;
        ind = (int)&v40->Names.Data.Data[ind];
        if ( v13 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v129, eStackOverflowError, this);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this,
            v41,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
          v42 = v129.Message.pNode;
          --v129.Message.pNode->RefCount;
          if ( !v42->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v42);
        }
        else
        {
          ProfileTicks = Scaleform::Timer::GetProfileTicks();
          VMRef = v39->VMRef;
          v129.Message.pNode = (Scaleform::GFx::ASStringNode *)HIDWORD(ProfileTicks);
          other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
          other.pHeap = VMRef->MHeap;
          other.pRegisterFile = &VMRef->RegisterFile;
          other.pSavedScope = &v37->InitScope;
          v44 = *(Scaleform::GFx::ASStringNode **)ind;
          other.MBIIndex.Ind = MethodBodyInfoInd;
          HIDWORD(ProfileTicks) = &v39->VMRef->ScopeStack;
          other.DiscardResult = 0;
          other.ACopy = 0;
          other.RegisteredFunction = 0;
          other.CP = 0;
          other.pFile = v39;
          other.OriginationTraits = v37;
          other.pScopeStack = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)HIDWORD(ProfileTicks);
          other.DefXMLNamespace.pObject = 0;
          other.Name.pObject = v44;
          if ( v44 )
            ++v44->RefCount;
          other.Invoker.value.VS._1.VInt = func->value.VS._1.VInt;
          HIDWORD(ProfileTicks) = func->value.VS._2.VObj;
          other.StartTicks = __PAIR64__((unsigned int)v129.Message.pNode, ProfileTicks);
          LODWORD(ProfileTicks) = func->Flags;
          other.Invoker.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)HIDWORD(ProfileTicks);
          other.CurrFileInd = 0;
          other.CurrLineNumber = 0;
          pWeakProxy = func->Bonus.pWeakProxy;
          other.Invoker.Flags = ProfileTicks;
          other.Invoker.Bonus.pWeakProxy = pWeakProxy;
          if ( (ProfileTicks & 0x1F) > 9 )
          {
            if ( (ProfileTicks & 0x200) != 0 )
              ++pWeakProxy->RefCount;
            else
              Scaleform::GFx::AS3::Value::AddRefInternal(func);
          }
          v48 = v39->VMRef;
          NumOfReservedElem = v48->OpStack.NumOfReservedElem;
          v50 = v48->OpStack.pCurrent;
          v48 = (Scaleform::GFx::AS3::VM *)((char *)v48 + 40);
          other.PrevInitialStackPos = v50;
          v51 = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v48->__vftable + 1);
          other.PrevReservedNum = NumOfReservedElem;
          pObject = v39->File.pObject;
          other.PrevFirstStackPos = v51;
          v53 = pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd];
          Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v48, LOWORD(v53->max_stack) + 1);
          Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v53->local_reg_count);
          p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v39->VMRef->DefXMLNamespace;
          if ( *p_DefXMLNamespace )
          {
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&other.DefXMLNamespace,
              *p_DefXMLNamespace);
            ind = 0;
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&ind);
          }
          Scaleform::GFx::AS3::CallFrame::SetupRegisters(
            &other,
            (int)v39->File.pObject->Methods.Info.Data.Data[v39->File.pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd]->method_info_ind],
            _this,
            argc,
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
                v56 = Scaleform::AmpServer::GetInstance();
                if ( v56->IsProfiling(v56) )
                {
                  pFile = other.pFile;
                  v58 = other.pFile->File.pObject;
                  v59 = (Scaleform::RefCountVImpl *)(v58->FileHandle
                                                   + (v58->MethodBodies.Info.Data.Data[other.MBIIndex.Ind]->method_info_ind << 16));
                  if ( !other.RegisteredFunction )
                  {
                    pData = (const __m128i *)other.Name.pObject->pData;
                    SwfFileOffset = v58->SwfFileOffset;
                    GetAdvanceStats = this->GetAdvanceStats;
                    other.RegisteredFunction = 1;
                    v61 = GetAdvanceStats(this);
                    Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v61, v59, SwfFileOffset, pData, 0, 3u, 0);
                  }
                  StartTicks = other.StartTicks;
                  v125 = pFile->File.pObject->SwfFileOffset;
                  v62 = this->GetAdvanceStats(this);
                  Scaleform::GFx::AMP::ViewStats::PushCallstack(v62, (unsigned int)v59, v125, StartTicks);
                }
              }
            }
            v63 = this->CallStack.Size >> 6;
            if ( v63 >= this->CallStack.NumPages )
              Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
                &this->CallStack,
                this->CallStack.Size >> 6);
            v64 = &this->CallStack.Pages[v63][this->CallStack.Size & 0x3F];
            if ( v64 )
              Scaleform::GFx::AS3::CallFrame::CallFrame(v64, &other);
            ++this->CallStack.Size;
          }
          Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
        }
        if ( !result_on_stack )
          Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(this, result);
      }
      else
      {
        v65 = *(_DWORD *)(v35 + 8);
        v66 = *(_DWORD *)(v65 + 16);
        _mm_prefetch((const char *)v65, 2);
        v67 = (v66 >> 10) & 0xFFF;
        if ( v67 != 4095 && (argc > v67 || argc < ((v66 >> 7) & 7)) )
        {
          v68 = *(_DWORD *)(v65 + 16);
          v69 = *(const char **)(v65 + 8);
          v120.pStr = v69;
          if ( v69 )
            v70 = strlen(v69);
          else
            v70 = 0;
          v120.Size = v70;
          Scaleform::GFx::AS3::VM::Error::Error(
            &v129,
            eWrongArgumentCountError,
            (Scaleform::String)this,
            v120,
            (v68 >> 7) & 7,
            (v68 >> 10) & 0xFFF,
            argc);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this,
            v71,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
          pNode = v129.Message.pNode;
          goto LABEL_123;
        }
        (*(void (__cdecl **)(int, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v65)(
          v65,
          this,
          _this,
          result,
          argc,
          argv);
        if ( result_on_stack && !this->HandleException )
        {
          v13 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v72 = this->OpStack.pCurrent;
          if ( !v13 )
          {
            *v72 = *result;
            result->Flags = 0;
          }
        }
      }
      return;
    case 0xCu:
    case 0xDu:
      v10 = func->value.VS._1;
      if ( !v10.VInt )
      {
        Scaleform::GFx::AS3::VM::Error::Error(
          &v135,
          (Scaleform::GFx::AS3::VM_vtbl *)0x3EE,
          (Scaleform::GFx::ASStringNode *)this,
          func);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v11,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        pNode = v135.Message.pNode;
        goto LABEL_123;
      }
      (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v10.VInt + 40))(
        v10,
        _this,
        result,
        argc,
        argv);
      if ( !this->HandleException && result_on_stack )
      {
        v13 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
        v14 = this->OpStack.pCurrent;
        if ( !v13 )
        {
          *v14 = *result;
          result->Flags = 0;
        }
      }
      return;
    case 0xEu:
      v9 = func->value.VS._1;
      if ( result_on_stack )
        (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *, _DWORD))(*(_DWORD *)v9.VInt + 84))(
          v9,
          _this,
          argc,
          argv,
          0);
      else
        (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v9.VInt + 80))(
          v9,
          _this,
          result,
          argc,
          argv);
      return;
    case 0xFu:
      (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))(*(_DWORD *)func->value.VS._1.VInt + 80))(
        func->value.VS._1,
        _this,
        result,
        argc,
        argv);
      if ( !this->HandleException && result_on_stack )
      {
        v13 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
        v23 = this->OpStack.pCurrent;
        if ( !v13 )
        {
          *v23 = *result;
          result->Flags = 0;
        }
      }
      return;
    case 0x10u:
      v24 = func->value.VS._1;
      VObj = func->value.VS._2.VObj;
      _mm_prefetch((const char *)v24.VInt, 2);
      Scaleform::GFx::AS3::Value::Value(&v134, VObj);
      v26 = (*(_DWORD *)(v24.VInt + 16) >> 10) & 0xFFF;
      if ( v26 == 4095 || argc <= v26 && argc >= ((*(_DWORD *)(v24.VInt + 16) >> 7) & 7u) )
      {
        (*(void (__cdecl **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v24.VInt)(
          v24,
          this,
          &v134,
          result,
          argc,
          argv);
        if ( result_on_stack && !this->HandleException )
        {
          v13 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v33 = this->OpStack.pCurrent;
          if ( !v13 )
          {
            *v33 = *result;
            result->Flags = 0;
          }
        }
        goto LABEL_38;
      }
      v27 = *(_DWORD *)(v24.VInt + 16);
      v28 = *(const char **)(v24.VInt + 8);
      v118.pStr = v28;
      if ( v28 )
        v29 = strlen(v28);
      else
        v29 = 0;
      v118.Size = v29;
      Scaleform::GFx::AS3::VM::Error::Error(
        &v129,
        eWrongArgumentCountError,
        (Scaleform::String)this,
        v118,
        (v27 >> 7) & 7,
        (v27 >> 10) & 0xFFF,
        argc);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v30,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v31 = v129.Message.pNode;
      --v129.Message.pNode->RefCount;
      v32 = v31;
      if ( v31->RefCount )
        goto LABEL_38;
      goto LABEL_33;
    case 0x11u:
      v73.VObj = (Scaleform::GFx::AS3::Object *)func->value.VS._2;
      if ( (func->Flags & 0x800) != 0 )
        v74 = v73.VObj->pTraits.pObject->pParent.pObject;
      else
        v74 = v73.VObj->pTraits.pObject;
      v75 = Scaleform::GFx::AS3::Traits::GetVT(v74);
      v129.ID = func->value.VS._1.VInt;
      v76 = (__int32)&v75->VTMethods.Data.Data[v129.ID];
      v77 = func->value.VS._2.VObj;
      _mm_prefetch((const char *)v76, 2);
      Scaleform::GFx::AS3::Value::Value(&v134, v77);
      if ( (*(_BYTE *)v76 & 0x1F) != 6 )
      {
        v107 = *(_DWORD *)(v76 + 8);
        v108 = *(_DWORD *)(v107 + 16);
        _mm_prefetch((const char *)v107, 2);
        v109 = (v108 >> 10) & 0xFFF;
        if ( v109 == 4095 || argc <= v109 && argc >= ((v108 >> 7) & 7) )
        {
          (*(void (__cdecl **)(int, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v107)(
            v107,
            this,
            &v134,
            result,
            argc,
            argv);
          if ( result_on_stack && !this->HandleException )
          {
            v13 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v115 = this->OpStack.pCurrent;
            if ( !v13 )
            {
              *v115 = *result;
              result->Flags = 0;
            }
          }
        }
        else
        {
          v110 = *(_DWORD *)(v107 + 16);
          v111 = *(const char **)(v107 + 8);
          v122.pStr = v111;
          if ( v111 )
            v112 = strlen(v111);
          else
            v112 = 0;
          v122.Size = v112;
          Scaleform::GFx::AS3::VM::Error::Error(
            &v129,
            eWrongArgumentCountError,
            (Scaleform::String)this,
            v122,
            (v110 >> 7) & 7,
            (v110 >> 10) & 0xFFF,
            argc);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this,
            v113,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
          v114 = v129.Message.pNode;
          --v129.Message.pNode->RefCount;
          v32 = v114;
          if ( !v114->RefCount )
          {
LABEL_33:
            Scaleform::GFx::ASStringNode::ReleaseNode(v32);
            Scaleform::GFx::AS3::Value::~Value(&v134);
            return;
          }
        }
        goto LABEL_38;
      }
      v78 = *(const Scaleform::GFx::AS3::Traits **)(v76 + 12);
      v79 = v78->__vftable;
      ind = *(_DWORD *)(v76 + 8);
      v80 = v79->GetFilePtr(v78);
      MethodBodyInfoInd = v80->File.pObject->Methods.Info.Data.Data[ind]->MethodBodyInfoInd;
      v81 = Scaleform::GFx::AS3::Traits::GetVT(v78);
      v13 = this->CallStack.Size == 128;
      v129.ID = (Scaleform::GFx::AS3::VM::ErrorID)&v81->Names.Data.Data[v129.ID];
      if ( v13 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v129, eStackOverflowError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v82,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
        v83 = v129.Message.pNode;
        --v129.Message.pNode->RefCount;
        if ( !v83->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v83);
      }
      else
      {
        v86 = Scaleform::Timer::GetProfileTicks();
        v84 = v80->VMRef;
        v132 = HIDWORD(v86);
        other.ScopeStackBaseInd = v84->ScopeStack.Data.Size;
        other.pHeap = v84->MHeap;
        other.pRegisterFile = &v84->RegisterFile;
        other.pSavedScope = &v78->InitScope;
        v85 = *(Scaleform::GFx::ASStringNode **)v129.ID;
        other.MBIIndex.Ind = MethodBodyInfoInd;
        HIDWORD(v86) = &v80->VMRef->ScopeStack;
        other.DiscardResult = 0;
        other.ACopy = 0;
        other.RegisteredFunction = 0;
        other.CP = 0;
        other.pFile = v80;
        other.OriginationTraits = v78;
        other.pScopeStack = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)HIDWORD(v86);
        other.DefXMLNamespace.pObject = 0;
        other.Name.pObject = v85;
        if ( v85 )
          ++v85->RefCount;
        other.Invoker.value.VS._1.VInt = func->value.VS._1.VInt;
        HIDWORD(v86) = func->value.VS._2.VObj;
        other.StartTicks = __PAIR64__(v132, v86);
        LODWORD(v86) = func->Flags;
        other.Invoker.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)HIDWORD(v86);
        other.CurrFileInd = 0;
        other.CurrLineNumber = 0;
        v88 = func->Bonus.pWeakProxy;
        other.Invoker.Flags = v86;
        other.Invoker.Bonus.pWeakProxy = v88;
        if ( (v86 & 0x1F) > 9 )
        {
          if ( (v86 & 0x200) != 0 )
            ++v88->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(func);
        }
        v89 = v80->VMRef;
        v90 = v89->OpStack.NumOfReservedElem;
        v91 = v89->OpStack.pCurrent;
        v92 = MethodBodyInfoInd;
        v89 = (Scaleform::GFx::AS3::VM *)((char *)v89 + 40);
        other.PrevInitialStackPos = v91;
        v93 = (Scaleform::GFx::AS3::Value *)*((_DWORD *)&v89->__vftable + 1);
        other.PrevReservedNum = v90;
        v94 = v80->File.pObject;
        other.PrevFirstStackPos = v93;
        v95 = v94->MethodBodies.Info.Data.Data[MethodBodyInfoInd];
        Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v89, LOWORD(v95->max_stack) + 1);
        Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v95->local_reg_count);
        v96 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v80->VMRef->DefXMLNamespace;
        if ( *v96 )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&other.DefXMLNamespace,
            *v96);
          v129.ID = 0;
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)v96,
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v129);
        }
        Scaleform::GFx::AS3::CallFrame::SetupRegisters(
          &other,
          (int)v80->File.pObject->Methods.Info.Data.Data[v80->File.pObject->MethodBodies.Info.Data.Data[v92]->method_info_ind],
          &v134,
          argc,
          argv);
        if ( this->HandleException )
        {
          other.ACopy = 1;
        }
        else
        {
          if ( this->GetAdvanceStats(this) )
          {
            v97 = Scaleform::AmpServer::GetInstance();
            if ( v97->GetProfileLevel(v97) >= Amp_Profile_Level_Medium )
            {
              v98 = Scaleform::AmpServer::GetInstance();
              if ( v98->IsProfiling(v98) )
              {
                v99 = other.pFile;
                v100 = other.pFile->File.pObject;
                v101 = (Scaleform::RefCountVImpl *)(v100->FileHandle
                                                  + (v100->MethodBodies.Info.Data.Data[other.MBIIndex.Ind]->method_info_ind << 16));
                if ( !other.RegisteredFunction )
                {
                  v124 = (const __m128i *)other.Name.pObject->pData;
                  v121 = v100->SwfFileOffset;
                  v102 = this->GetAdvanceStats;
                  other.RegisteredFunction = 1;
                  v103 = v102(this);
                  Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(v103, v101, v121, v124, 0, 3u, 0);
                }
                v128 = other.StartTicks;
                v126 = v99->File.pObject->SwfFileOffset;
                v104 = this->GetAdvanceStats(this);
                Scaleform::GFx::AMP::ViewStats::PushCallstack(v104, (unsigned int)v101, v126, v128);
              }
            }
          }
          v105 = this->CallStack.Size >> 6;
          if ( v105 >= this->CallStack.NumPages )
            Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
              &this->CallStack,
              this->CallStack.Size >> 6);
          v106 = &this->CallStack.Pages[v105][this->CallStack.Size & 0x3F];
          if ( v106 )
            Scaleform::GFx::AS3::CallFrame::CallFrame(v106, &other);
          ++this->CallStack.Size;
        }
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
      }
      if ( result_on_stack )
      {
LABEL_38:
        Scaleform::GFx::AS3::Value::~Value(&v134);
        return;
      }
      Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(this, result);
      Scaleform::GFx::AS3::Value::~Value(&v134);
      return;
    default:
      Scaleform::GFx::AS3::VM::Error::Error(
        &v136,
        (Scaleform::GFx::AS3::VM_vtbl *)0x3EE,
        (Scaleform::GFx::ASStringNode *)this,
        func);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v116,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v136.Message.pNode;
LABEL_123:
      if ( !--pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
  }
}
