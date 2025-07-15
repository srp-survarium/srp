void __thiscall Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *func,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool result_on_stack)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::V1U v9; // ecx
  Scaleform::GFx::AS3::Value::V1U v10; // edi
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  void (__thiscall *v13)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *); // edx
  bool v14; // zf
  Scaleform::GFx::AS3::Value *v15; // esi
  Scaleform::GFx::AS3::Value::V1U v16; // edi
  unsigned int v17; // ecx
  unsigned int v18; // eax
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::Object *VObj; // ecx
  Scaleform::GFx::AS3::Value::V1U v22; // ebx
  unsigned int v23; // edx
  unsigned int v24; // eax
  const Scaleform::GFx::AS3::VM::Error *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::AS3::Value *v27; // esi
  Scaleform::GFx::AS3::Value *v28; // ecx
  unsigned int v29; // edx
  const Scaleform::GFx::AS3::Traits *pTraits; // ebp
  Scaleform::GFx::AS3::VMAbcFile *v31; // ebx
  int MethodBodyInfoInd; // edx
  const Scaleform::GFx::AS3::VM::Error *v33; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::AS3::ValueRegisterFile *p_RegisterFile; // ecx
  Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::GFx::AS3::VM *v38; // eax
  Scaleform::GFx::AS3::Value::V2U v39; // ecx
  unsigned int v40; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // ebp
  Scaleform::GFx::AS3::ValueStack *v42; // ecx
  Scaleform::GFx::AS3::Value *pCurrentPage; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v44; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **p_DefXMLNamespace; // edi
  Scaleform::GFx::AS3::Value::V1U v46; // ecx
  unsigned int v47; // edx
  unsigned int v48; // eax
  Scaleform::GFx::AS3::Value *v49; // esi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v51; // ebx
  Scaleform::GFx::AS3::Object *v52; // eax
  const Scaleform::GFx::AS3::Traits *v53; // ebp
  Scaleform::GFx::AS3::Traits_vtbl *v54; // eax
  Scaleform::GFx::AS3::VMAbcFile *v55; // ebx
  int v56; // edx
  const Scaleform::GFx::AS3::VM::Error *v57; // eax
  Scaleform::GFx::ASStringNode *v58; // eax
  Scaleform::GFx::AS3::VM *v59; // eax
  Scaleform::GFx::AS3::ValueRegisterFile *v60; // ecx
  Scaleform::MemoryHeap *v61; // eax
  Scaleform::GFx::AS3::VM *v62; // eax
  Scaleform::GFx::AS3::Value::V2U v63; // ecx
  unsigned int v64; // eax
  Scaleform::GFx::AS3::WeakProxy *v65; // ebp
  Scaleform::GFx::AS3::ValueStack *v66; // ecx
  Scaleform::GFx::AS3::Value *v67; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v68; // edi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **v69; // edi
  unsigned int v70; // ecx
  unsigned int v71; // eax
  const Scaleform::GFx::AS3::VM::Error *v72; // eax
  Scaleform::GFx::AS3::Value::V1U v73; // [esp+8h] [ebp-74h]
  int v74; // [esp+8h] [ebp-74h]
  int v75; // [esp+8h] [ebp-74h]
  Scaleform::GFx::AS3::VM::Error v76; // [esp+Ch] [ebp-70h] BYREF
  Scaleform::GFx::AS3::VM::Error v77; // [esp+14h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::VM::Error v78; // [esp+1Ch] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value v79; // [esp+24h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::CallFrame val; // [esp+34h] [ebp-48h] BYREF

  _mm_prefetch((const char *)_this, 2);
  Flags = func->Flags;
  _mm_prefetch((const char *)func, 2);
  switch ( Flags & 0x1F )
  {
    case 5u:
      v16 = func->value.VS._1;
      v17 = *(_DWORD *)(v16.VInt + 16);
      _mm_prefetch((const char *)v16.VInt, 2);
      v18 = (v17 >> 10) & 0xFFF;
      if ( v18 != 4095 && (argc > v18 || argc < ((v17 >> 7) & 7)) )
        goto LABEL_15;
      (*(void (__cdecl **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))v16.VInt)(
        v16,
        this,
        _this,
        result,
        argc,
        argv);
      if ( result_on_stack && !this->HandleException )
      {
        v14 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
        pCurrent = this->OpStack.pCurrent;
        if ( !v14 )
        {
          *pCurrent = *result;
          result->Flags = 0;
        }
      }
      return;
    case 7u:
      v28 = &Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)func->value.VS._2.VObj)->VTMethods.Data.Data[func->value.VS._1.VInt];
      v29 = v28->Flags;
      _mm_prefetch((const char *)v28, 2);
      if ( (v29 & 0x1F) == 6 )
      {
        pTraits = v28->value.VS._2.pTraits;
        v73 = v28->value.VS._1;
        v31 = pTraits->GetFilePtr(pTraits);
        MethodBodyInfoInd = v31->File.pObject->Methods.Info.Data.Data[v73.VInt]->MethodBodyInfoInd;
        v74 = MethodBodyInfoInd;
        if ( this->CallStack.Size == 128 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v76, eStackOverflowError, this);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this,
            v33,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
          pNode = v76.Message.pNode;
          --v76.Message.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
        else
        {
          VMRef = v31->VMRef;
          val.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
          p_RegisterFile = &VMRef->RegisterFile;
          MHeap = VMRef->MHeap;
          val.pRegisterFile = p_RegisterFile;
          val.pHeap = MHeap;
          v38 = v31->VMRef;
          val.pSavedScope = &pTraits->InitScope;
          val.Invoker.value.VS._1.VInt = func->value.VS._1.VInt;
          v39.VObj = (Scaleform::GFx::AS3::Object *)func->value.VS._2;
          val.pScopeStack = &v38->ScopeStack;
          v40 = func->Flags;
          val.Invoker.value.VS._2 = v39;
          val.OriginationTraits = pTraits;
          pWeakProxy = func->Bonus.pWeakProxy;
          val.DiscardResult = 0;
          val.ACopy = 0;
          val.CP = 0;
          val.pFile = v31;
          val.MBIIndex.Ind = MethodBodyInfoInd;
          val.DefXMLNamespace.pObject = 0;
          val.Invoker.Flags = v40;
          val.Invoker.Bonus.pWeakProxy = pWeakProxy;
          if ( (v40 & 0x1F) > 9 )
          {
            if ( (v40 & 0x200) != 0 )
            {
              ++pWeakProxy->RefCount;
            }
            else
            {
              Scaleform::GFx::AS3::Value::AddRefInternal(func);
              MethodBodyInfoInd = v74;
            }
          }
          v42 = (Scaleform::GFx::AS3::ValueStack *)v31->VMRef;
          pCurrentPage = (Scaleform::GFx::AS3::Value *)v42[2].pCurrentPage;
          v42 = (Scaleform::GFx::AS3::ValueStack *)((char *)v42 + 40);
          val.PrevInitialStackPos = pCurrentPage;
          val.PrevFirstStackPos = v42->pStack;
          v44 = v31->File.pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd];
          Scaleform::GFx::AS3::ValueStack::Reserve(v42, LOWORD(v44->max_stack) + 1);
          Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v44->local_reg_count);
          p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v31->VMRef->DefXMLNamespace;
          if ( *p_DefXMLNamespace )
          {
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
              *p_DefXMLNamespace);
            v76.ID = 0;
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)p_DefXMLNamespace,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v76);
          }
          Scaleform::GFx::AS3::CallFrame::SetupRegisters(
            &val,
            (int)v31->File.pObject->Methods.Info.Data.Data[v31->File.pObject->MethodBodies.Info.Data.Data[v74]->method_info_ind],
            _this,
            argc,
            argv);
          if ( this->HandleException )
            val.ACopy = 1;
          else
            Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
              &this->CallStack,
              &val);
          Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
        }
        if ( !result_on_stack )
          Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(this, result);
      }
      else
      {
        v46 = v28->value.VS._1;
        v47 = *(_DWORD *)(v46.VInt + 16);
        _mm_prefetch((const char *)v46.VInt, 2);
        v48 = (v47 >> 10) & 0xFFF;
        if ( v48 != 4095 && (argc > v48 || argc < ((v47 >> 7) & 7)) )
        {
LABEL_15:
          Scaleform::GFx::AS3::VM::Error::Error(&v76, eWrongArgumentCountError, this);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this,
            v19,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
          v12 = v76.Message.pNode;
          goto LABEL_79;
        }
        (*(void (__cdecl **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))v46.VInt)(
          v46,
          this,
          _this,
          result,
          argc,
          argv);
        if ( result_on_stack && !this->HandleException )
        {
          v14 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v49 = this->OpStack.pCurrent;
          if ( !v14 )
          {
            *v49 = *result;
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
        Scaleform::GFx::AS3::VM::Error::Error(&v77, eCallOfNonFunctionError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v11,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v12 = v77.Message.pNode;
        goto LABEL_79;
      }
      v13 = *(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))(*(_DWORD *)v10.VInt + 28);
      goto LABEL_8;
    case 0xEu:
      v9 = func->value.VS._1;
      if ( result_on_stack )
        (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *, _DWORD))(*(_DWORD *)v9.VInt + 72))(
          v9,
          _this,
          argc,
          argv,
          0);
      else
        (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))(*(_DWORD *)v9.VInt + 68))(
          v9,
          _this,
          result,
          argc,
          argv);
      return;
    case 0xFu:
      v10 = func->value.VS._1;
      v13 = *(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))(*(_DWORD *)v10.VInt + 68);
LABEL_8:
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v13)(
        (Scaleform::GFx::AS3::Value::V1U)v10.VInt,
        _this,
        result,
        argc,
        argv);
      if ( !this->HandleException && result_on_stack )
      {
        v14 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
        v15 = this->OpStack.pCurrent;
        if ( !v14 )
        {
          *v15 = *result;
          result->Flags = 0;
        }
      }
      return;
    case 0x10u:
      VObj = func->value.VS._2.VObj;
      v22 = func->value.VS._1;
      _mm_prefetch((const char *)v22.VInt, 2);
      Scaleform::GFx::AS3::Value::Value(&v79, VObj);
      v23 = argc;
      v24 = (*(_DWORD *)(v22.VInt + 16) >> 10) & 0xFFF;
      if ( v24 != 4095 && (argc > v24 || argc < ((*(_DWORD *)(v22.VInt + 16) >> 7) & 7u)) )
        goto LABEL_24;
      goto LABEL_26;
    case 0x11u:
      if ( (Flags & 0x800) != 0 )
        pObject = (Scaleform::GFx::AS3::Traits *)func->value.VS._2.VObj->pTraits.pObject->pParent.pObject;
      else
        pObject = func->value.VS._2.VObj->pTraits.pObject;
      v51 = &Scaleform::GFx::AS3::Traits::GetVT(pObject)->VTMethods.Data.Data[func->value.VS._1.VInt];
      v52 = func->value.VS._2.VObj;
      _mm_prefetch((const char *)v51, 2);
      Scaleform::GFx::AS3::Value::Value(&v79, v52);
      if ( (v51->Flags & 0x1F) != 6 )
      {
        v22 = v51->value.VS._1;
        v70 = *(_DWORD *)(v22.VInt + 16);
        _mm_prefetch((const char *)v22.VInt, 2);
        v23 = argc;
        v71 = (v70 >> 10) & 0xFFF;
        if ( v71 == 4095 || argc <= v71 && argc >= ((v70 >> 7) & 7) )
        {
LABEL_26:
          (*(void (__cdecl **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *))v22.VInt)(
            v22,
            this,
            &v79,
            result,
            v23,
            argv);
          if ( result_on_stack && !this->HandleException )
          {
            v14 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v27 = this->OpStack.pCurrent;
            if ( !v14 )
            {
              *v27 = *result;
              result->Flags = 0;
            }
          }
        }
        else
        {
LABEL_24:
          Scaleform::GFx::AS3::VM::Error::Error(&v76, eWrongArgumentCountError, this);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this,
            v25,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
          v26 = v76.Message.pNode;
          --v76.Message.pNode->RefCount;
          if ( !v26->RefCount )
          {
            Scaleform::GFx::ASStringNode::ReleaseNode(v26);
            Scaleform::GFx::AS3::Value::~Value(&v79);
            return;
          }
        }
        goto LABEL_30;
      }
      v53 = v51->value.VS._2.pTraits;
      v54 = v53->__vftable;
      v76.ID = v51->value.VS._1.VInt;
      v55 = v54->GetFilePtr(v53);
      v56 = v55->File.pObject->Methods.Info.Data.Data[v76.ID]->MethodBodyInfoInd;
      v75 = v56;
      if ( this->CallStack.Size == 128 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v76, eStackOverflowError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this,
          v57,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ErrorTI);
        v58 = v76.Message.pNode;
        --v76.Message.pNode->RefCount;
        if ( !v58->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v58);
      }
      else
      {
        v59 = v55->VMRef;
        val.ScopeStackBaseInd = v59->ScopeStack.Data.Size;
        v60 = &v59->RegisterFile;
        v61 = v59->MHeap;
        val.pRegisterFile = v60;
        val.pHeap = v61;
        v62 = v55->VMRef;
        val.pSavedScope = &v53->InitScope;
        val.Invoker.value.VS._1.VInt = func->value.VS._1.VInt;
        v63.VObj = (Scaleform::GFx::AS3::Object *)func->value.VS._2;
        val.pScopeStack = &v62->ScopeStack;
        v64 = func->Flags;
        val.Invoker.value.VS._2 = v63;
        val.OriginationTraits = v53;
        v65 = func->Bonus.pWeakProxy;
        val.DiscardResult = 0;
        val.ACopy = 0;
        val.CP = 0;
        val.pFile = v55;
        val.MBIIndex.Ind = v56;
        val.DefXMLNamespace.pObject = 0;
        val.Invoker.Flags = v64;
        val.Invoker.Bonus.pWeakProxy = v65;
        if ( (v64 & 0x1F) > 9 )
        {
          if ( (v64 & 0x200) != 0 )
          {
            ++v65->RefCount;
          }
          else
          {
            Scaleform::GFx::AS3::Value::AddRefInternal(func);
            v56 = v75;
          }
        }
        v66 = (Scaleform::GFx::AS3::ValueStack *)v55->VMRef;
        v67 = (Scaleform::GFx::AS3::Value *)v66[2].pCurrentPage;
        v66 = (Scaleform::GFx::AS3::ValueStack *)((char *)v66 + 40);
        val.PrevInitialStackPos = v67;
        val.PrevFirstStackPos = v66->pStack;
        v68 = v55->File.pObject->MethodBodies.Info.Data.Data[v56];
        Scaleform::GFx::AS3::ValueStack::Reserve(v66, LOWORD(v68->max_stack) + 1);
        Scaleform::GFx::AS3::ValueRegisterFile::Reserve(val.pRegisterFile, v68->local_reg_count);
        v69 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&v55->VMRef->DefXMLNamespace;
        if ( *v69 )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&val.DefXMLNamespace,
            *v69);
          v76.ID = 0;
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)v69,
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&v76);
        }
        Scaleform::GFx::AS3::CallFrame::SetupRegisters(
          &val,
          (int)v55->File.pObject->Methods.Info.Data.Data[v55->File.pObject->MethodBodies.Info.Data.Data[v75]->method_info_ind],
          &v79,
          argc,
          argv);
        if ( this->HandleException )
          val.ACopy = 1;
        else
          Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::PushBack(
            &this->CallStack,
            &val);
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&val);
      }
      if ( result_on_stack )
      {
LABEL_30:
        Scaleform::GFx::AS3::Value::~Value(&v79);
        return;
      }
      Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(this, result);
      Scaleform::GFx::AS3::Value::~Value(&v79);
      return;
    default:
      Scaleform::GFx::AS3::VM::Error::Error(&v78, eCallOfNonFunctionError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v72,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      v12 = v78.Message.pNode;
LABEL_79:
      if ( !--v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      return;
  }
}
