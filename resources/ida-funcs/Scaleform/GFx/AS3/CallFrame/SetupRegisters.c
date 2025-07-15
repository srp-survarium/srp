void __thiscall Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        Scaleform::GFx::AS3::CallFrame *this,
        int mi,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  char v5; // bl
  Scaleform::GFx::AS3::Value *p_callee; // ecx
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // eax
  Scaleform::GFx::AS3::Value::V1U v9; // eax
  Scaleform::GFx::AS3::Value *pRF; // ecx
  int v11; // ebp
  const Scaleform::GFx::AS3::Abc::MethodInfo *v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // eax
  const Scaleform::GFx::AS3::Abc::MethodInfo *v15; // ebx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v16; // ebp
  Scaleform::GFx::AS3::VM *v17; // esi
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v21; // zf
  unsigned __int8 (__thiscall **p_Coerce)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *); // esi
  Scaleform::GFx::AS3::Value *DetailValue; // eax
  bool v24; // bl
  Scaleform::GFx::AS3::VM *v25; // esi
  const Scaleform::GFx::AS3::VM::Error *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::GFx::AS3::WeakProxy *v29; // eax
  unsigned __int8 Flags; // cl
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // ebx
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::AS3::VM *v39; // esi
  const Scaleform::GFx::AS3::VM::Error *v40; // eax
  Scaleform::GFx::ASStringNode *v41; // eax
  Scaleform::GFx::AS3::Value *v42; // ecx
  void *v43; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v44; // esi
  Scaleform::GFx::AS3::VM *v45; // edx
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v47; // eax
  const Scaleform::GFx::AS3::Abc::MethodInfo *v48; // eax
  Scaleform::GFx::AS3::Value *v49; // ecx
  int v50; // ebp
  void *v51; // eax
  unsigned int v52; // ebx
  Scaleform::ArrayDefaultPolicy *v53; // ebp
  int v54; // esi
  unsigned int v55; // eax
  Scaleform::GFx::AS3::Value::V1U v56; // eax
  Scaleform::GFx::AS3::Value::V1U v57; // ecx
  Scaleform::GFx::ASStringNode *v58; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v60; // ecx
  Scaleform::GFx::ASStringNode *v61; // esi
  Scaleform::GFx::ASStringNode *v62; // eax
  unsigned int i; // [esp+10h] [ebp-4Ch]
  int v64; // [esp+14h] [ebp-48h]
  const Scaleform::GFx::AS3::Value *v65; // [esp+18h] [ebp-44h]
  int reg; // [esp+1Ch] [ebp-40h]
  int v67; // [esp+20h] [ebp-3Ch]
  unsigned int param_count[2]; // [esp+24h] [ebp-38h] BYREF
  unsigned int avail_regn; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::GFx::ASStringNode *v70; // [esp+30h] [ebp-2Ch]
  Scaleform::GFx::AS3::Value::V1U v71; // [esp+34h] [ebp-28h]
  Scaleform::GFx::AS3::Value::V1U v72; // [esp+38h] [ebp-24h]
  Scaleform::GFx::AS3::Value callee; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+4Ch] [ebp-10h] BYREF

  v5 = 0;
  p_callee = _this;
  avail_regn = 0;
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
  reg = 1;
  if ( (v5 & 1) != 0 )
    Scaleform::GFx::AS3::Value::~Value(&callee);
  v12 = (const Scaleform::GFx::AS3::Abc::MethodInfo *)mi;
  v13 = *(_DWORD *)(mi + 16);
  v14 = v13 - *(_DWORD *)(mi + 28);
  param_count[0] = v13;
  avail_regn = v14;
  i = 0;
  if ( v13 )
  {
    v67 = 1;
    v64 = -1 * v14;
    v65 = argv;
    while ( 1 )
    {
      v15 = (const Scaleform::GFx::AS3::Abc::MethodInfo *)mi;
      v16 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
              this->pFile->VMRef,
              this->pFile,
              &this->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[*(_DWORD *)(*(_DWORD *)(mi + 12) + 4 * i)]);
      if ( !v16 )
      {
        VMRef = this->pFile->VMRef;
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&avail_regn, eClassNotFoundError, VMRef);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          VMRef,
          v37,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v38 = v70;
        --v70->RefCount;
        if ( !v38->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v38);
        return;
      }
      if ( (_S10_0 & 1) == 0 )
      {
        _S10_0 |= 1u;
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
      if ( i >= argc )
      {
        if ( (v15->Flags & 8) != 0 && i >= avail_regn )
        {
          p_Coerce = (unsigned __int8 (__thiscall **)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&v16->Coerce;
          DetailValue = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(
                          this->pFile,
                          &result,
                          (Scaleform::GFx::ASStringNode *)&v15->OptionalParams.Data.Data[v64]);
          v24 = (*p_Coerce)(v16, DetailValue, &callee) == 0;
          Scaleform::GFx::AS3::Value::~Value(&result);
          if ( v24 )
          {
            v25 = this->pFile->VMRef;
            Scaleform::GFx::AS3::VM::Error::Error(
              (Scaleform::GFx::AS3::VM::Error *)&avail_regn,
              eCheckTypeFailedError,
              v25);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              v25,
              v26,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
            v27 = v70;
            --v70->RefCount;
            if ( !v27->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v27);
LABEL_35:
            Scaleform::GFx::AS3::Value::~Value(&callee);
            return;
          }
        }
        else
        {
          pFile = this->pFile;
          if ( v16 != pFile->VMRef->TraitsClassClass.pObject )
          {
            v39 = pFile->VMRef;
            Scaleform::GFx::AS3::VM::Error::Error(
              (Scaleform::GFx::AS3::VM::Error *)&avail_regn,
              eWrongArgumentCountError,
              v39);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              v39,
              v40,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ArgumentErrorTI);
            v41 = v70;
            --v70->RefCount;
            if ( !v41->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v41);
            goto LABEL_35;
          }
        }
      }
      else if ( !v16->Coerce(v16, v65, &callee) )
      {
        v17 = this->pFile->VMRef;
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&avail_regn, eCheckTypeFailedError, v17);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v17,
          v18,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v19 = v70;
        --v70->RefCount;
        if ( !v19->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        if ( (callee.Flags & 0x1F) <= 9 )
          return;
        if ( (callee.Flags & 0x200) == 0 )
          goto LABEL_94;
        pWeakProxy = callee.Bonus.pWeakProxy;
        --callee.Bonus.pWeakProxy->RefCount;
        v21 = pWeakProxy->RefCount == 0;
LABEL_92:
        if ( v21 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return;
      }
      Scaleform::GFx::AS3::Value::Assign(&this->pRegisterFile->pRF[v67], &callee);
      ++reg;
      ++v67;
      if ( (callee.Flags & 0x1F) > 9 )
      {
        if ( (callee.Flags & 0x200) != 0 )
        {
          v29 = callee.Bonus.pWeakProxy;
          --callee.Bonus.pWeakProxy->RefCount;
          if ( !v29->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v29);
          callee.Flags &= 0xFFFFFDE0;
          memset(&callee.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
        }
      }
      ++v64;
      ++v65;
      if ( ++i >= param_count[0] )
      {
        v12 = (const Scaleform::GFx::AS3::Abc::MethodInfo *)mi;
        v13 = param_count[0];
        v11 = reg;
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
    v33 = (Scaleform::GFx::AS3::Instances::fl::Array *)pVM->MHeap->Alloc(
                                                         pVM->MHeap,
                                                         pObject->MemSize,
                                                         (const Scaleform::AllocInfo *)&mi);
    if ( v33 )
    {
      Scaleform::GFx::AS3::Instances::fl::Array::Array(v33, pObject);
      v35 = v34;
    }
    else
    {
      v35 = 0;
    }
    v42 = &this->pRegisterFile->pRF[v11];
    callee.Bonus.pWeakProxy = 0;
    callee.Flags = 12;
    *(_QWORD *)&callee.value.VNumber = __PAIR64__((unsigned int)v70, v35);
    Scaleform::GFx::AS3::Value::Assign(v42, &callee);
    if ( (callee.Flags & 0x1F) > 9 )
    {
      if ( (callee.Flags & 0x200) != 0 )
      {
        v43 = callee.Bonus.pWeakProxy;
        v21 = callee.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v43);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
      }
    }
    if ( argc > v13 )
      Scaleform::GFx::AS3::Impl::SparseArray::Append(
        (Scaleform::GFx::AS3::Impl::SparseArray *)(v35 + 32),
        argc - v13,
        (Scaleform::GFx::AS3::Value *)&argv[v13]);
  }
  else if ( (Flags & 1) != 0 )
  {
    v44 = this->pFile->VMRef->TraitsArray.pObject->ITraits.pObject;
    v45 = v44->pVM;
    MemSize = v44->MemSize;
    mi = 337;
    v47 = (Scaleform::GFx::AS3::Instances::fl::Array *)v45->MHeap->Alloc(
                                                         v45->MHeap,
                                                         MemSize,
                                                         (const Scaleform::AllocInfo *)&mi);
    if ( v47 )
      Scaleform::GFx::AS3::Instances::fl::Array::Array(v47, v44);
    else
      v48 = 0;
    mi = (int)v48;
    *(_QWORD *)&callee.value.VNumber = __PAIR64__((unsigned int)v70, (unsigned int)v48);
    v49 = &this->pRegisterFile->pRF[v11];
    callee.Bonus.pWeakProxy = 0;
    callee.Flags = 12;
    Scaleform::GFx::AS3::Value::Assign(v49, &callee);
    v50 = v11 + 1;
    if ( (callee.Flags & 0x1F) > 9 )
    {
      if ( (callee.Flags & 0x200) != 0 )
      {
        v51 = callee.Bonus.pWeakProxy;
        v21 = callee.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v51);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
      }
    }
    v52 = 0;
    avail_regn = v50 - 2;
    if ( argc )
    {
      v53 = (Scaleform::ArrayDefaultPolicy *)(mi + 32);
      v54 = 0;
      do
      {
        if ( v52 >= avail_regn )
          Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
            (Scaleform::GFx::AS3::Impl::SparseArray *)v53,
            (Scaleform::GFx::AS3::Value *)&argv[v54]);
        else
          Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
            (Scaleform::GFx::AS3::Impl::SparseArray *)v53,
            &this->pRegisterFile->pRF[v54 + 1]);
        ++v52;
        ++v54;
      }
      while ( v52 < argc );
    }
    v55 = this->Invoker.Flags & 0x1F;
    callee.Flags = 0;
    callee.Bonus.pWeakProxy = 0;
    if ( v55 == 7 )
    {
      v56 = _this->value.VS._1;
      v57 = this->Invoker.value.VS._1;
      v70 = 0;
      v72 = v56;
      v71 = v57;
      if ( v56.VInt )
        *(_DWORD *)(v56.VInt + 16) = (*(_DWORD *)(v56.VInt + 16) + 1) & 0x8FBFFFFF;
      avail_regn = 17;
      Scaleform::GFx::AS3::Value::Assign(&callee, (const Scaleform::GFx::AS3::Value *)&avail_regn);
      if ( (avail_regn & 0x1F) > 9 )
      {
        if ( (avail_regn & 0x200) != 0 )
        {
          v58 = v70;
          v21 = v70->pData-- == (const char *)1;
          if ( v21 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v58);
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
    v60 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)mi;
    v61 = ConstStringNode;
    ++ConstStringNode->RefCount;
    param_count[0] = (unsigned int)&avail_regn;
    avail_regn = 0;
    v70 = ConstStringNode;
    ++ConstStringNode->RefCount;
    param_count[1] = (unsigned int)&callee;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
      v60 + 6,
      &v60[6],
      (const Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef *)param_count);
    v62 = v70;
    --v70->RefCount;
    if ( !v62->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v62);
    v21 = v61->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v61);
    if ( (callee.Flags & 0x1F) > 9 )
    {
      if ( (callee.Flags & 0x200) != 0 )
      {
        pWeakProxy = callee.Bonus.pWeakProxy;
        --callee.Bonus.pWeakProxy->RefCount;
        v21 = pWeakProxy->RefCount == 0;
        goto LABEL_92;
      }
LABEL_94:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&callee);
    }
  }
}
