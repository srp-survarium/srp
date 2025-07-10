void __thiscall Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Environment *Env; // esi
  unsigned int Size; // edi
  Scaleform::GFx::Value *v5; // eax
  int v6; // ecx
  bool v7; // cc
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Environment *v9; // ecx
  int v10; // esi
  unsigned int v11; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // ecx
  Scaleform::GFx::AS2::Value *v13; // edx
  unsigned int v14; // esi
  Scaleform::GFx::Value *v15; // eax
  const char **pStringManaged; // esi
  Scaleform::GFx::FunctionHandler *pObject; // ecx
  char Type; // al
  Scaleform::GFx::Value *Data; // esi
  Scaleform::ArrayCPP<Scaleform::GFx::Value,2,Scaleform::ArrayDefaultPolicy> args; // [esp+2Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::AS2::Environment *penv; // [esp+38h] [ebp-80h]
  int i; // [esp+3Ch] [ebp-7Ch]
  Scaleform::GFx::Value thisVal; // [esp+40h] [ebp-78h] BYREF
  Scaleform::GFx::Value arg; // [esp+58h] [ebp-60h] BYREF
  Scaleform::GFx::Value retVal; // [esp+70h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v26; // [esp+88h] [ebp-30h]
  Scaleform::GFx::AS2::Value thisAS; // [esp+8Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::FunctionHandler::Params params; // [esp+9Ch] [ebp-1Ch] BYREF

  ThisPtr = fn->ThisPtr;
  Env = fn->Env;
  v26 = this;
  penv = Env;
  memset(&args, 0, sizeof(args));
  thisVal.pObjectInterface = 0;
  thisVal.Type = VT_Undefined;
  retVal.pObjectInterface = 0;
  retVal.Type = VT_Undefined;
  thisAS.T.Type = 0;
  if ( ThisPtr )
  {
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&thisAS, ThisPtr);
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(&thisAS);
    thisAS.T.Type = 1;
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
    (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    Env,
    &thisAS,
    &thisVal);
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &args.Data,
    &args,
    1u);
  Size = args.Data.Size;
  v5 = &args.Data.Data[args.Data.Size - 1];
  if ( &args.Data.Data[args.Data.Size] != (Scaleform::GFx::Value *)24 )
  {
    v5->pObjectInterface = 0;
    v5->Type = thisVal.Type;
    v5->mValue.NValue = thisVal.mValue.NValue;
    v5->DataAux = thisVal.DataAux;
    if ( (thisVal.Type & 0x40) != 0 )
    {
      v5->pObjectInterface = thisVal.pObjectInterface;
      thisVal.pObjectInterface->ObjectAddRef(thisVal.pObjectInterface, v5, (void *)v5->mValue.IValue);
    }
  }
  v6 = 0;
  v7 = fn->NArgs <= 0;
  i = 0;
  if ( !v7 )
  {
    do
    {
      v8 = fn->FirstArgBottomIndex - v6;
      v9 = fn->Env;
      arg.pObjectInterface = 0;
      arg.Type = VT_Undefined;
      v10 = (char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart;
      v11 = v9->Stack.Pages.Data.Size;
      p_Stack = &v9->Stack;
      v13 = 0;
      if ( v8 <= 32 * (v11 - 1) + (v10 >> 4) )
        v13 = &p_Stack->Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
        (Scaleform::GFx::AS2::MovieRoot *)penv->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
        penv,
        v13,
        &arg);
      v14 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v14 >= args.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &args.Data,
            &args,
            v14 + (v14 >> 2));
      }
      else
      {
        Scaleform::ConstructorCPP<Scaleform::GFx::Value>::DestructArray(&args.Data.Data[v14], 0xFFFFFFFF);
        if ( v14 < args.Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &args.Data,
            &args,
            v14);
      }
      v15 = &args.Data.Data[v14 - 1];
      ++Size;
      args.Data.Size = v14;
      if ( &args.Data.Data[v14] != (Scaleform::GFx::Value *)24 )
      {
        v15->pObjectInterface = 0;
        v15->Type = arg.Type;
        v15->mValue.NValue = arg.mValue.NValue;
        v15->DataAux = arg.DataAux;
        if ( (arg.Type & 0x40) != 0 )
        {
          pStringManaged = v15->mValue.pStringManaged;
          v15->pObjectInterface = arg.pObjectInterface;
          arg.pObjectInterface->ObjectAddRef(arg.pObjectInterface, v15, pStringManaged);
        }
      }
      if ( (arg.Type & 0x40) != 0 )
        arg.pObjectInterface->ObjectRelease(arg.pObjectInterface, &arg, (void *)arg.mValue.IValue);
      v6 = i + 1;
      v7 = ++i < fn->NArgs;
    }
    while ( v7 );
    Env = penv;
  }
  v7 = fn->NArgs <= 0;
  params.pMovie = Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject->pMovieImpl;
  params.pRetVal = &retVal;
  params.pThis = &thisVal;
  if ( v7 )
    params.pArgs = 0;
  else
    params.pArgs = args.Data.Data + 1;
  params.ArgCount = Size - 1;
  params.pUserData = v26->pUserData;
  pObject = v26->pContext.pObject;
  params.pArgsWithThisRef = args.Data.Data;
  pObject->Call(pObject, &params);
  Type = retVal.Type;
  if ( (retVal.Type & 0x8F) != 0 )
  {
    Scaleform::GFx::AS2::MovieRoot::Value2ASValue(
      (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      &retVal,
      fn->Result);
    Type = retVal.Type;
  }
  if ( thisAS.T.Type >= 5u )
  {
    Scaleform::GFx::AS2::Value::DropRefs(&thisAS);
    Type = retVal.Type;
  }
  if ( (Type & 0x40) != 0 )
  {
    retVal.pObjectInterface->ObjectRelease(retVal.pObjectInterface, &retVal, (void *)retVal.mValue.IValue);
    retVal.pObjectInterface = 0;
  }
  retVal.Type = VT_Undefined;
  if ( (thisVal.Type & 0x40) != 0 )
  {
    thisVal.pObjectInterface->ObjectRelease(thisVal.pObjectInterface, &thisVal, (void *)thisVal.mValue.IValue);
    thisVal.pObjectInterface = 0;
  }
  Data = args.Data.Data;
  thisVal.Type = VT_Undefined;
  Scaleform::ConstructorCPP<Scaleform::GFx::Value>::DestructArray(args.Data.Data, Size);
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
