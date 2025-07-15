void __cdecl Scaleform::GFx::AS2::ArrayObject::ArraySort(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // ebp
  int v4; // ebx
  bool v5; // cc
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::FunctionRef *v8; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::ArrayObject *v14; // eax
  Scaleform::GFx::AS2::ArrayObject *v15; // esi
  int v16; // ebp
  Scaleform::GFx::AS2::Value *v17; // edi
  unsigned int v18; // eax
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *v20; // ecx
  unsigned int v21; // eax
  Scaleform::GFx::AS2::LocalFrame *v22; // ecx
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned __int8 v25; // bl
  Scaleform::GFx::AS2::FunctionObject *v26; // ecx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::Environment *v28; // [esp-Ch] [ebp-48h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-48h]
  Scaleform::GFx::AS2::FunctionRefBase v30; // [esp+8h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::ArraySortFunctor v32; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::FnCall *v33; // [esp+40h] [ebp+4h]

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
  {
    p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&ThisPtr[-2].pProto;
    v33 = (Scaleform::GFx::AS2::FnCall *)&ThisPtr[-2].pProto;
  }
  else
  {
    v33 = 0;
    p_pProto = 0;
  }
  p_pProto->LengthValueOverriden = 0;
  v4 = 0;
  v5 = fn->NArgs < 1;
  memset(&v30, 0, 9);
  if ( !v5 )
  {
    Type = Scaleform::GFx::AS2::FnCall::Arg(fn, 0)->T.Type;
    if ( Type != 8 && Type != 11 )
    {
      Env = fn->Env;
      v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      goto LABEL_21;
    }
    v28 = fn->Env;
    v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v8 = Scaleform::GFx::AS2::Value::ToFunction(v7, &result, v28);
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&v30, v8);
    if ( (result.Flags & 2) == 0 )
    {
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        Function = result.Function;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    result.Function = 0;
    if ( (result.Flags & 1) == 0 )
    {
      if ( result.pLocalFrame )
      {
        v11 = result.pLocalFrame->RefCount;
        pLocalFrame = result.pLocalFrame;
        if ( (v11 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    if ( v30.Function && fn->NArgs >= 2 )
    {
      Env = fn->Env;
      v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
LABEL_21:
      v4 = Scaleform::GFx::AS2::Value::ToInt32(v13, Env);
    }
  }
  v14 = (Scaleform::GFx::AS2::ArrayObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                              fn->Env,
                                              fn->Env->StringContext.pContext->pGlobal.pObject,
                                              (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pASSupport,
                                              0,
                                              -1);
  v15 = v14;
  if ( v14 )
  {
    Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(v14, p_pProto);
    Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(
      &v32,
      &v15->Scaleform::GFx::AS2::ObjectInterface,
      v4,
      (const Scaleform::GFx::AS2::FunctionRef *)&v30,
      fn->Env,
      p_pProto->LogPtr);
    if ( !Scaleform::GFx::AS2::ArrayObject::Sort<Scaleform::GFx::AS2::ArraySortFunctor>(v15, &v32) )
      Scaleform::GFx::AS2::Environment::LogScriptError(fn->Env, "Array.sort - sorting failed, check your sort functor");
    if ( (v4 & 4) != 0 )
    {
      v16 = 1;
      if ( (int)v15->Elements.Data.Size > 1 )
      {
        while ( Scaleform::GFx::AS2::ArraySortFunctor::Compare(
                  &v32,
                  v15->Elements.Data.Data[v16 - 1],
                  v15->Elements.Data.Data[v16]) )
        {
          if ( ++v16 >= (signed int)v15->Elements.Data.Size )
            goto LABEL_29;
        }
        v17 = fn->Result;
        if ( v17->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v17);
        v17->T.Type = 4;
        v17->NV.Int32Value = 0;
        Scaleform::GFx::AS2::ArrayObject::DetachAll(v15);
        Scaleform::GFx::AS2::ArraySortFunctor::~ArraySortFunctor(&v32);
        v18 = v15->RefCount;
        if ( (v18 & 0x3FFFFFF) != 0 )
        {
          v15->RefCount = v18 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
        }
        Flags = v30.Flags;
        if ( (v30.Flags & 2) == 0 )
        {
          v20 = v30.Function;
          if ( v30.Function )
          {
            v21 = v30.Function->RefCount;
            if ( (v21 & 0x3FFFFFF) != 0 )
            {
              v30.Function->RefCount = v21 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
            }
          }
        }
        if ( (Flags & 1) == 0 )
        {
          v22 = v30.pLocalFrame;
          goto LABEL_43;
        }
        return;
      }
LABEL_29:
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)v33;
    }
    if ( (v4 & 8) != 0 )
    {
      Scaleform::GFx::AS2::ArrayObject::MakeDeepCopy(v15, fn->Env->StringContext.pContext->pHeap);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v15);
    }
    else
    {
      Scaleform::GFx::AS2::ArrayObject::ShallowCopyFrom(p_pProto, v15);
      Scaleform::GFx::AS2::ArrayObject::DetachAll(v15);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
    }
    Scaleform::GFx::AS2::ArraySortFunctor::~ArraySortFunctor(&v32);
    v24 = v15->RefCount;
    if ( (v24 & 0x3FFFFFF) != 0 )
    {
      v15->RefCount = v24 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
    }
  }
  v25 = v30.Flags;
  if ( (v30.Flags & 2) == 0 )
  {
    v26 = v30.Function;
    if ( v30.Function )
    {
      v27 = v30.Function->RefCount;
      if ( (v27 & 0x3FFFFFF) != 0 )
      {
        v30.Function->RefCount = v27 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
      }
    }
  }
  if ( (v25 & 1) == 0 )
  {
    v22 = v30.pLocalFrame;
LABEL_43:
    if ( v22 )
    {
      v23 = v22->RefCount;
      if ( (v23 & 0x3FFFFFF) != 0 )
      {
        v22->RefCount = v23 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
      }
    }
  }
}
