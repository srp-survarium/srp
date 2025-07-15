void __cdecl Scaleform::GFx::AS2::ArrayObject::ArraySortOn(const Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Value **p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy> *v7; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx
  volatile int RefCount; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy> *v10; // esi
  Scaleform::GFx::AS2::Value *v11; // edi
  Scaleform::GFx::ASStringNode *v12; // ecx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // eax
  bool v15; // cc
  Scaleform::GFx::AS2::Value *v16; // eax
  Scaleform::GFx::AS2::Object *v17; // eax
  Scaleform::GFx::AS2::Object *v18; // esi
  signed int i; // ebp
  Scaleform::GFx::AS2::Value *v20; // ecx
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::Value *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // ecx
  signed int j; // ebp
  unsigned int v25; // esi
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::Value *v28; // ecx
  Scaleform::GFx::AS2::Object *v29; // eax
  Scaleform::GFx::AS2::Object *v30; // ebp
  signed int v31; // esi
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // ebx
  Scaleform::GFx::AS2::Value *v33; // ecx
  Scaleform::GFx::AS2::Environment *v34; // edx
  unsigned int v35; // eax
  Scaleform::GFx::AS2::Value *v36; // ecx
  signed int v37; // eax
  Scaleform::GFx::AS3::Instances::fl::Object **v38; // edx
  Scaleform::GFx::AS2::ArrayObject *v39; // eax
  Scaleform::GFx::AS2::ArrayObject *v40; // esi
  Scaleform::GFx::AS2::ArrayObject *v41; // ebx
  unsigned int Size; // eax
  unsigned int v43; // ebp
  int v44; // ebp
  Scaleform::GFx::AS2::Value *Result; // edi
  unsigned int v46; // edx
  Scaleform::GFx::AS2::ArraySortFunctor *v47; // edi
  unsigned int v48; // eax
  Scaleform::GFx::ASStringNode *v49; // ecx
  void **p_Data; // ebx
  Scaleform::GFx::ASStringNode *v51; // ecx
  unsigned int v52; // eax
  int v53; // esi
  unsigned int v54; // edi
  Scaleform::GFx::ASStringNode *v55; // ecx
  void **v56; // ebp
  Scaleform::GFx::AS2::ArraySortFunctor *v57; // edi
  unsigned int v58; // eax
  Scaleform::GFx::ASStringNode *v59; // ecx
  Scaleform::GFx::ASStringNode *v60; // ecx
  unsigned int v61; // eax
  int v62; // esi
  unsigned int v63; // edi
  Scaleform::GFx::ASStringNode *v64; // ecx
  Scaleform::GFx::AS2::ArraySortOnFunctor v65; // [esp-1Ch] [ebp-84h] BYREF
  int v66; // [esp+10h] [ebp-58h]
  Scaleform::GFx::ASString v67; // [esp+14h] [ebp-54h] BYREF
  Scaleform::GFx::ASString val; // [esp+18h] [ebp-50h] BYREF
  Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *> ao; // [esp+1Ch] [ebp-4Ch] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+24h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::ArraySortOnFunctor __that; // [esp+30h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::ArraySortOnFunctor v72; // [esp+4Ch] [ebp-1Ch] BYREF
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *v73; // [esp+6Ch] [ebp+4h]

  v2 = 0;
  if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Array )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
    return;
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    p_pProto = (Scaleform::GFx::AS2::Value **)&ThisPtr[-2].pProto;
  else
    p_pProto = 0;
  pHeap = fn->Env->StringContext.pContext->pHeap;
  Alloc = pHeap->Alloc;
  ao.Data = p_pProto;
  v7 = (Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy> *)Alloc(pHeap, 16u, 0);
  if ( v7 )
  {
    pObject = fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
    v7->Data = 0;
    v7->Size = 0;
    v7->Policy.Capacity = 0;
    RefCount = pObject[8].RefCount;
    v7[1].Data = (Scaleform::GFx::ASString *)RefCount;
    ++*(_DWORD *)(RefCount + 12);
    v10 = v7;
    v73 = (Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *)v7;
  }
  else
  {
    v10 = 0;
    v73 = 0;
  }
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  v66 = 0;
  if ( fn->NArgs )
  {
    *((_BYTE *)p_pProto + 76) = 0;
    v14 = *(Scaleform::GFx::ASStringNode **)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[17].AVMVersion;
    ++v14->RefCount;
    v15 = fn->NArgs < 1;
    v67.pNode = v14;
    if ( !v15 )
    {
      v65.FunctorArray.Data.Policy.Capacity = (unsigned int)fn->Env;
      v16 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v17 = Scaleform::GFx::AS2::Value::ToObject(
              v16,
              (Scaleform::GFx::AS2::Environment *)v65.FunctorArray.Data.Policy.Capacity);
      v18 = v17;
      if ( v17 && v17->GetObjectType(&v17->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
      {
        for ( i = 0; i < (signed int)v18[1].RootIndex; ++i )
        {
          v20 = (Scaleform::GFx::AS2::Value *)(&v18[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[i];
          if ( v20 )
          {
            Scaleform::GFx::AS2::Value::ToStringImpl(v20, &val, fn->Env, -1, 0);
            Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v73,
              &val);
            pNode = val.pNode;
            v13 = val.pNode->RefCount-- == 1;
            if ( v13 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
          else
          {
            Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              v73,
              &v67);
          }
        }
      }
      else
      {
        v65.FunctorArray.Data.Data = (Scaleform::GFx::AS2::ArraySortFunctor *)fn->Env;
        v22 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(
          v22,
          &val,
          (Scaleform::GFx::AS2::Environment *)v65.FunctorArray.Data.Data,
          -1,
          0);
        Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v73,
          &val);
        v23 = val.pNode;
        v13 = val.pNode->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      }
    }
    for ( j = 0; j < (signed int)v73->Data.Size; ++j )
    {
      v25 = v2 + 1;
      if ( v2 + 1 >= v2 )
      {
        if ( v25 >= pheapAddr.Policy.Capacity )
        {
          v65.FunctorArray.Data.Policy.Capacity = v25 + (v25 >> 2);
          v65.FunctorArray.Data.Size = (unsigned int)&pheapAddr;
          goto LABEL_33;
        }
      }
      else if ( v25 < pheapAddr.Policy.Capacity >> 1 )
      {
        v65.FunctorArray.Data.Policy.Capacity = v2 + 1;
        v65.FunctorArray.Data.Size = (unsigned int)&pheapAddr;
LABEL_33:
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          (const void *)v65.FunctorArray.Data.Size,
          v65.FunctorArray.Data.Policy.Capacity);
      }
      ++v2;
      pheapAddr.Size = v25;
      if ( &pheapAddr.Data[v25] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
        pheapAddr.Data[v25 - 1] = 0;
    }
    if ( fn->NArgs >= 2 )
    {
      Env = fn->Env;
      v27 = fn->FirstArgBottomIndex - 1;
      v28 = 0;
      if ( v27 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
        v28 = &Env->Stack.Pages.Data.Data[v27 >> 5]->Values[v27 & 0x1F];
      v29 = Scaleform::GFx::AS2::Value::ToObject(v28, fn->Env);
      v30 = v29;
      if ( v29 && v29->GetObjectType(&v29->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
      {
        v31 = 0;
        if ( (int)v30[1].RootIndex > 0 )
        {
          Data = pheapAddr.Data;
          do
          {
            if ( v31 >= (signed int)v73->Data.Size )
              break;
            v33 = (Scaleform::GFx::AS2::Value *)(&v30[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[v31];
            if ( v33 )
              Data[v31] = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS2::Value::ToInt32(
                                                                          v33,
                                                                          fn->Env);
            ++v31;
          }
          while ( v31 < (signed int)v30[1].RootIndex );
        }
      }
      else
      {
        v34 = fn->Env;
        v35 = fn->FirstArgBottomIndex - 1;
        v36 = 0;
        if ( v35 <= 32 * (v34->Stack.Pages.Data.Size - 1) + v34->Stack.pCurrent - v34->Stack.pPageStart )
          v36 = &v34->Stack.Pages.Data.Data[v35 >> 5]->Values[v35 & 0x1F];
        v66 = Scaleform::GFx::AS2::Value::ToInt32(v36, fn->Env);
        v37 = 0;
        if ( (int)v73->Data.Size > 0 )
        {
          v38 = pheapAddr.Data;
          do
            v38[v37++] = (Scaleform::GFx::AS3::Instances::fl::Object *)v66;
          while ( v37 < (signed int)v73->Data.Size );
        }
      }
    }
    v39 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                fn->Env,
                                                fn->Env->StringContext.pContext->pGlobal.pObject,
                                                (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                                0,
                                                -1);
    v40 = v39;
    if ( v39 )
    {
      v41 = (Scaleform::GFx::AS2::ArrayObject *)ao.Data;
      Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(v39, (const Scaleform::GFx::AS2::ArrayObject *)ao.Data);
      Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(
        &__that,
        &v40->Scaleform::GFx::AS2::ObjectInterface,
        v73,
        (const Scaleform::Array<int,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
        fn->Env,
        v41->LogPtr);
      Size = v40->Elements.Data.Size;
      if ( Size )
      {
        ao.Data = v40->Elements.Data.Data;
        v43 = Size;
        ao.Size = Size;
        Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(&v72, &__that);
        Scaleform::GFx::AS2::ArraySortOnFunctor::ArraySortOnFunctor(&v65, &v72);
        Scaleform::Alg::QuickSortSlicedSafe<Scaleform::Alg::ArrayAdaptor<Scaleform::GFx::AS2::Value *>,Scaleform::GFx::AS2::ArraySortOnFunctor>(
          &ao,
          0,
          v43,
          v65);
        Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
          v72.FunctorArray.Data.Data,
          v72.FunctorArray.Data.Size);
        if ( v72.FunctorArray.Data.Data )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v72.FunctorArray.Data.Data);
      }
      if ( (v66 & 4) != 0 )
      {
        v44 = 1;
        if ( (int)v40->Elements.Data.Size > 1 )
        {
          while ( Scaleform::GFx::AS2::ArraySortOnFunctor::Compare(
                    &__that,
                    v40->Elements.Data.Data[v44 - 1],
                    v40->Elements.Data.Data[v44]) )
          {
            if ( ++v44 >= (signed int)v40->Elements.Data.Size )
              goto LABEL_62;
          }
          Result = fn->Result;
          if ( Result->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(Result);
          v46 = __that.FunctorArray.Data.Size;
          Result->T.Type = 4;
          Result->NV.Int32Value = 0;
          v47 = __that.FunctorArray.Data.Data;
          Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
            __that.FunctorArray.Data.Data,
            v46);
          if ( v47 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v47);
          v48 = v40->RefCount;
          if ( (v48 & 0x3FFFFFF) != 0 )
          {
            v40->RefCount = v48 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v40);
          }
          v49 = v67.pNode;
          v13 = v67.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v49);
          if ( pheapAddr.Data )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
          p_Data = (void **)&v73->Data.Data;
          v51 = v73->Data.DefaultValue.pNode;
          v13 = v51->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v51);
          v52 = v73->Data.Size;
          v53 = (int)&v73->Data.Data[v52 - 1];
          if ( v52 )
          {
            v54 = v73->Data.Size;
            do
            {
              v55 = *(Scaleform::GFx::ASStringNode **)v53;
              v13 = (*(_DWORD *)(*(_DWORD *)v53 + 12))-- == 1;
              if ( v13 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v55);
              v53 -= 4;
              --v54;
            }
            while ( v54 );
          }
          goto LABEL_105;
        }
      }
LABEL_62:
      if ( (v66 & 8) != 0 )
      {
        Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(v40, fn->Env->StringContext.pContext->pHeap);
        v65.FunctorArray.Data.Policy.Capacity = (unsigned int)v40;
      }
      else
      {
        Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(v41, v40);
        v56 = (void **)&v40->Elements.Data.Data;
        if ( v40->Elements.Data.Size )
        {
          if ( (v40->Elements.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
          {
            if ( *v56 )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v56);
              *v56 = 0;
            }
            v40->Elements.Data.Policy.Capacity = 0;
          }
        }
        else if ( !v40->Elements.Data.Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v40->Elements,
            &v40->Elements,
            0);
        }
        v40->Elements.Data.Size = 0;
        v65.FunctorArray.Data.Policy.Capacity = (unsigned int)v41;
      }
      Scaleform::GFx::AS2::Value::SetAsObject(
        fn->Result,
        (Scaleform::GFx::AS2::Object *)v65.FunctorArray.Data.Policy.Capacity);
      v57 = __that.FunctorArray.Data.Data;
      Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
        __that.FunctorArray.Data.Data,
        __that.FunctorArray.Data.Size);
      if ( v57 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v57);
      v58 = v40->RefCount;
      if ( (v58 & 0x3FFFFFF) != 0 )
      {
        v40->RefCount = v58 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v40);
      }
    }
    v59 = v67.pNode;
    v13 = v67.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v59);
    if ( pheapAddr.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
    p_Data = (void **)&v73->Data.Data;
    v60 = v73->Data.DefaultValue.pNode;
    v13 = v60->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v60);
    v61 = v73->Data.Size;
    v62 = (int)&v73->Data.Data[v61 - 1];
    if ( v61 )
    {
      v63 = v73->Data.Size;
      do
      {
        v64 = *(Scaleform::GFx::ASStringNode **)v62;
        v13 = (*(_DWORD *)(*(_DWORD *)v62 + 12))-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v64);
        v62 -= 4;
        --v63;
      }
      while ( v63 );
    }
LABEL_105:
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *p_Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Data);
    return;
  }
  v11 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v11);
  v11->T.Type = 0;
  if ( v10 )
  {
    v12 = (Scaleform::GFx::ASStringNode *)v10[1].Data;
    v13 = v12->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(v10);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
  }
}
