// local variable allocation has failed, the output may be wrong!
void __thiscall Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        Scaleform::GFx::AS3::CallFrame *this,
        int mi,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  char v5; // bl
  Scaleform::GFx::AS3::Value *p_callee; // ecx
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // eax
  Scaleform::GFx::AS3::Value::V1U v9; // eax
  Scaleform::GFx::AS3::Value *pRF; // ecx
  int v11; // ebp
  const Scaleform::GFx::AS3::Abc::MethodInfo *v12; // ecx
  unsigned int v13; // edi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::GFx::AS3::Abc::Multiname *v17; // edi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v18; // ebp
  const char *v19; // eax
  unsigned int v20; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass_vtbl *v21; // edi
  Scaleform::GFx::AS3::Value *DetailValue; // eax
  const char *pData; // eax
  unsigned int v24; // eax
  Scaleform::GFx::AS3::WeakProxy *v25; // eax
  unsigned __int8 Flags; // cl
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ebx
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // ebx
  const Scaleform::GFx::AS3::VM::Error *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  const Scaleform::GFx::AS3::VM::Error *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v38; // zf
  Scaleform::GFx::AS3::VMAbcFile *v39; // ecx
  Scaleform::GFx::ASStringNode *VMRef; // edi
  Scaleform::GFx::AS3::Value *v41; // eax
  const Scaleform::GFx::AS3::VM::Error *v42; // eax
  Scaleform::GFx::ASStringNode *Size; // eax
  Scaleform::GFx::ASStringNode *v44; // eax
  const char *v45; // eax
  unsigned int v46; // eax
  const Scaleform::GFx::AS3::VM::Error *v47; // eax
  Scaleform::GFx::ASStringNode *v48; // eax
  Scaleform::GFx::AS3::Value *v49; // ecx
  void *v50; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v51; // edi
  Scaleform::GFx::AS3::VM *v52; // edx
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v54; // eax
  const Scaleform::GFx::AS3::Abc::MethodInfo *v55; // eax
  Scaleform::GFx::AS3::Value *v56; // ecx
  int v57; // ebp
  void *v58; // eax
  const char *v59; // ebx
  Scaleform::ArrayDefaultPolicy *v60; // ebp
  int v61; // edi
  unsigned int v62; // eax
  Scaleform::GFx::AS3::Value::V1U v63; // eax
  Scaleform::GFx::AS3::Value::V1U v64; // ecx
  void *v65; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v67; // ecx
  Scaleform::GFx::ASStringNode *v68; // esi
  Scaleform::GFx::ASStringNode *v69; // eax
  Scaleform::StringDataPtr v70; // [esp-14h] [ebp-70h]
  Scaleform::StringDataPtr v71; // [esp-8h] [ebp-64h]
  Scaleform::StringDataPtr v72; // [esp-8h] [ebp-64h]
  Scaleform::GFx::AS3::Value *v73; // [esp-4h] [ebp-60h]
  bool v74; // [esp+13h] [ebp-49h]
  int v75; // [esp+14h] [ebp-48h]
  const Scaleform::GFx::AS3::Value *arg2; // [esp+18h] [ebp-44h]
  int arg2_4; // [esp+1Ch] [ebp-40h]
  unsigned int param_count; // [esp+20h] [ebp-3Ch]
  unsigned int first_opt_param_num; // [esp+24h] [ebp-38h] BYREF
  Scaleform::GFx::ASStringNode *v80; // [esp+28h] [ebp-34h]
  Scaleform::StringDataPtr avail_regn; // [esp+2Ch] [ebp-30h] OVERLAPPED BYREF
  Scaleform::GFx::AS3::Value::V1U v82; // [esp+34h] [ebp-28h]
  Scaleform::GFx::AS3::Value::V1U v83; // [esp+38h] [ebp-24h]
  Scaleform::GFx::AS3::Value callee; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+4Ch] [ebp-10h] BYREF

  v5 = 0;
  p_callee = _this;
  avail_regn.pStr = 0;
  if ( (_this->Flags & 0x1F) == 0 || (_this->Flags & 0x1F) - 12 <= 3 && !_this->value.VS._1.VInt )
  {
    pSavedScope = this->pSavedScope;
    v5 = 1;
    if ( pSavedScope->Data.Size )
    {
      v9 = pSavedScope->Data.Data->value.VS._1;
    }
    else
    {
      pRF = this->pRegisterFile->pRF;
      if ( (pRF->Flags & 0x1F) - 12 > 3 )
        v9.VInt = 0;
      else
        v9 = pRF->value.VS._1;
    }
    callee.Flags = 12;
    callee.Bonus.pWeakProxy = 0;
    callee.value.VS._1 = v9;
    if ( v9.VInt )
      *(_DWORD *)(v9.VInt + 16) = (*(_DWORD *)(v9.VInt + 16) + 1) & 0x8FBFFFFF;
    p_callee = &callee;
  }
  Scaleform::GFx::AS3::Value::Assign(this->pRegisterFile->pRF, p_callee);
  v11 = 1;
  arg2_4 = 1;
  if ( (v5 & 1) != 0 )
    Scaleform::GFx::AS3::Value::~Value(&callee);
  v12 = (const Scaleform::GFx::AS3::Abc::MethodInfo *)mi;
  v13 = *(_DWORD *)(mi + 16);
  v14 = v13 - *(_DWORD *)(mi + 28);
  v15 = 0;
  param_count = v13;
  first_opt_param_num = v14;
  if ( v13 )
  {
    avail_regn.pStr = (const char *)16;
    v75 = -8 * v14;
    arg2 = argv;
    while ( 1 )
    {
      pFile = this->pFile;
      v17 = &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[*(_DWORD *)(*(_DWORD *)(mi + 12) + 4 * v15)];
      v18 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(pFile->VMRef, pFile, v17);
      if ( !v18 )
      {
        Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
          &this->pFile->File.pObject->Const_Pool.ConstStr.Data.Data[v17->NameIndex],
          &avail_regn);
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&first_opt_param_num,
          eClassNotFoundError,
          (Scaleform::String)this->pFile->VMRef,
          avail_regn);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this->pFile->VMRef,
          v32,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v33 = v80;
        --v80->RefCount;
        if ( !v33->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v33);
        return;
      }
      if ( (_S15 & 1) == 0 )
      {
        _S15 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      callee = v;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          ++v.Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&v);
      }
      if ( v15 >= argc )
      {
        if ( (*(_BYTE *)mi & 8) != 0 && v15 >= first_opt_param_num )
        {
          v21 = v18->__vftable;
          DetailValue = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(
                          this->pFile,
                          &result,
                          (Scaleform::GFx::ASStringNode *)(v75 + *(_DWORD *)(mi + 24)));
          v74 = !v21->Coerce(v18, DetailValue, &callee);
          Scaleform::GFx::AS3::Value::~Value(&result);
          if ( v74 )
          {
            pData = v18->GetName(v18, (Scaleform::GFx::ASString *)&argv)->pNode->pData;
            v72.pStr = pData;
            if ( pData )
              v24 = strlen(pData);
            else
              v24 = 0;
            v72.Size = v24;
            v39 = this->pFile;
            VMRef = (Scaleform::GFx::ASStringNode *)v39->VMRef;
            v41 = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(
                    v39,
                    &result,
                    (Scaleform::GFx::ASStringNode *)(*(_DWORD *)(mi + 24) + 8 * (v15 - first_opt_param_num)));
            Scaleform::GFx::AS3::VM::Error::Error(
              (Scaleform::GFx::AS3::VM::Error *)&avail_regn,
              (Scaleform::GFx::AS3::VM_vtbl *)0x40A,
              VMRef,
              v41,
              v72);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              this->pFile->VMRef,
              v42,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
            Size = (Scaleform::GFx::ASStringNode *)avail_regn.Size;
            --*(_DWORD *)(avail_regn.Size + 12);
            if ( !Size->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(Size);
            Scaleform::GFx::AS3::Value::~Value(&result);
            v44 = (Scaleform::GFx::ASStringNode *)argv;
            --argv->value.VS._2.VObj;
            if ( !v44->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v44);
LABEL_59:
            Scaleform::GFx::AS3::Value::~Value(&callee);
            return;
          }
        }
        else if ( v18 != this->pFile->VMRef->TraitsClassClass.pObject )
        {
          v45 = this->Name.pObject->pData;
          v70.pStr = v45;
          if ( v45 )
            v46 = strlen(v45);
          else
            v46 = 0;
          v70.Size = v46;
          Scaleform::GFx::AS3::VM::Error::Error(
            (Scaleform::GFx::AS3::VM::Error *)&avail_regn,
            eWrongArgumentCountError,
            (Scaleform::String)this->pFile->VMRef,
            v70,
            first_opt_param_num,
            param_count,
            argc);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            this->pFile->VMRef,
            v47,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
          v48 = (Scaleform::GFx::ASStringNode *)avail_regn.Size;
          --*(_DWORD *)(avail_regn.Size + 12);
          if ( !v48->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v48);
          goto LABEL_59;
        }
      }
      else if ( !v18->Coerce(v18, arg2, &callee) )
      {
        v19 = v18->GetName(v18, (Scaleform::GFx::ASString *)&mi)->pNode->pData;
        v71.pStr = v19;
        if ( v19 )
          v20 = strlen(v19);
        else
          v20 = 0;
        v71.Size = v20;
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&avail_regn,
          (Scaleform::GFx::AS3::VM_vtbl *)0x40A,
          (Scaleform::GFx::ASStringNode *)this->pFile->VMRef,
          &argv[v15],
          v71);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          this->pFile->VMRef,
          v34,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v35 = (Scaleform::GFx::ASStringNode *)avail_regn.Size;
        --*(_DWORD *)(avail_regn.Size + 12);
        if ( !v35->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
        v36 = (Scaleform::GFx::ASStringNode *)mi;
        --*(_DWORD *)(mi + 12);
        if ( !v36->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        if ( (callee.Flags & 0x1F) <= 9 )
          return;
        if ( (callee.Flags & 0x200) == 0 )
          goto LABEL_107;
        pWeakProxy = callee.Bonus.pWeakProxy;
        --callee.Bonus.pWeakProxy->RefCount;
        v38 = pWeakProxy->RefCount == 0;
LABEL_105:
        if ( v38 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return;
      }
      Scaleform::GFx::AS3::Value::Assign(
        (Scaleform::GFx::AS3::Value *)&avail_regn.pStr[(unsigned int)this->pRegisterFile->pRF],
        &callee);
      ++arg2_4;
      avail_regn.pStr += 16;
      if ( (callee.Flags & 0x1F) > 9 )
      {
        if ( (callee.Flags & 0x200) != 0 )
        {
          v25 = callee.Bonus.pWeakProxy;
          --callee.Bonus.pWeakProxy->RefCount;
          if ( !v25->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
          callee.Flags &= 0xFFFFFDE0;
          memset(&callee.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
        }
      }
      v75 += 8;
      ++arg2;
      if ( ++v15 >= param_count )
      {
        v12 = (const Scaleform::GFx::AS3::Abc::MethodInfo *)mi;
        v13 = param_count;
        v11 = arg2_4;
        break;
      }
    }
  }
  Flags = v12->Flags;
  if ( (Flags & 4) != 0 )
  {
    pObject = this->pFile->VMRef->TraitsArray.pObject->ITraits.pObject;
    pVM = pObject->pVM;
    mi = 337;
    v29 = (Scaleform::GFx::AS3::Instances::fl::Array *)pVM->MHeap->Alloc(
                                                         pVM->MHeap,
                                                         pObject->MemSize,
                                                         (const Scaleform::AllocInfo *)&mi);
    if ( v29 )
    {
      Scaleform::GFx::AS3::Instances::fl::Array::Array(v29, pObject);
      v31 = v30;
    }
    else
    {
      v31 = 0;
    }
    v49 = &this->pRegisterFile->pRF[v11];
    callee.Bonus.pWeakProxy = 0;
    callee.Flags = 12;
    *(_QWORD *)&callee.value.VNumber = __PAIR64__(avail_regn.Size, v31);
    Scaleform::GFx::AS3::Value::Assign(v49, &callee);
    if ( (callee.Flags & 0x1F) > 9 )
    {
      if ( (callee.Flags & 0x200) != 0 )
      {
        v50 = callee.Bonus.pWeakProxy;
        v38 = callee.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v38 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v50);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
      }
    }
    if ( argc > v13 )
      Scaleform::GFx::AS3::Impl::SparseArray::Append(
        (Scaleform::GFx::AS3::Impl::SparseArray *)(v31 + 32),
        argc - v13,
        &argv[v13]);
  }
  else if ( (Flags & 1) != 0 )
  {
    v51 = this->pFile->VMRef->TraitsArray.pObject->ITraits.pObject;
    v52 = v51->pVM;
    MemSize = v51->MemSize;
    mi = 337;
    v54 = (Scaleform::GFx::AS3::Instances::fl::Array *)v52->MHeap->Alloc(
                                                         v52->MHeap,
                                                         MemSize,
                                                         (const Scaleform::AllocInfo *)&mi);
    if ( v54 )
      Scaleform::GFx::AS3::Instances::fl::Array::Array(v54, v51);
    else
      v55 = 0;
    mi = (int)v55;
    *(_QWORD *)&callee.value.VNumber = __PAIR64__(avail_regn.Size, (unsigned int)v55);
    v56 = &this->pRegisterFile->pRF[v11];
    callee.Bonus.pWeakProxy = 0;
    callee.Flags = 12;
    Scaleform::GFx::AS3::Value::Assign(v56, &callee);
    v57 = v11 + 1;
    if ( (callee.Flags & 0x1F) > 9 )
    {
      if ( (callee.Flags & 0x200) != 0 )
      {
        v58 = callee.Bonus.pWeakProxy;
        v38 = callee.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v38 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v58);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
      }
    }
    v59 = 0;
    avail_regn.pStr = (const char *)(v57 - 2);
    if ( argc )
    {
      v60 = (Scaleform::ArrayDefaultPolicy *)(mi + 32);
      v61 = 0;
      do
      {
        if ( v59 >= avail_regn.pStr )
          v73 = &argv[v61];
        else
          v73 = &this->pRegisterFile->pRF[v61 + 1];
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)v60, v73);
        ++v59;
        ++v61;
      }
      while ( (unsigned int)v59 < argc );
    }
    v62 = this->Invoker.Flags & 0x1F;
    callee.Flags = 0;
    callee.Bonus.pWeakProxy = 0;
    if ( v62 == 7 )
    {
      v63 = _this->value.VS._1;
      v64 = this->Invoker.value.VS._1;
      avail_regn.Size = 0;
      v83 = v63;
      v82 = v64;
      if ( v63.VInt )
        *(_DWORD *)(v63.VInt + 16) = (*(_DWORD *)(v63.VInt + 16) + 1) & 0x8FBFFFFF;
      avail_regn.pStr = (const char *)17;
      Scaleform::GFx::AS3::Value::Assign(&callee, (const Scaleform::GFx::AS3::Value *)&avail_regn);
      if ( ((int)avail_regn.pStr & 0x1F) > 9u )
      {
        if ( ((int)avail_regn.pStr & 0x200) != 0 )
        {
          v65 = (void *)avail_regn.Size;
          v38 = (*(_DWORD *)avail_regn.Size)-- == 1;
          if ( v38 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v65);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&avail_regn);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(&callee, &this->Invoker);
    }
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        this->pFile->VMRef->StringManagerRef->pStringManager,
                        "callee",
                        6u,
                        0);
    v67 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)mi;
    v68 = ConstStringNode;
    ++ConstStringNode->RefCount;
    first_opt_param_num = (unsigned int)&avail_regn;
    avail_regn.pStr = 0;
    avail_regn.Size = (unsigned int)ConstStringNode;
    ++ConstStringNode->RefCount;
    v80 = (Scaleform::GFx::ASStringNode *)&callee;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
      v67 + 6,
      &v67[6],
      (const Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef *)&first_opt_param_num);
    v69 = (Scaleform::GFx::ASStringNode *)avail_regn.Size;
    --*(_DWORD *)(avail_regn.Size + 12);
    if ( !v69->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v69);
    v38 = v68->RefCount-- == 1;
    if ( v38 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v68);
    if ( (callee.Flags & 0x1F) > 9 )
    {
      if ( (callee.Flags & 0x200) != 0 )
      {
        pWeakProxy = callee.Bonus.pWeakProxy;
        --callee.Bonus.pWeakProxy->RefCount;
        v38 = pWeakProxy->RefCount == 0;
        goto LABEL_105;
      }
LABEL_107:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
    }
  }
}
