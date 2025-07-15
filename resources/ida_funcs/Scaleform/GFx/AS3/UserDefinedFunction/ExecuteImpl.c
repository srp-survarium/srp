void __thiscall Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(
        Scaleform::GFx::AS3::UserDefinedFunction *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::UserDefinedFunction *v5; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::MovieRoot *v7; // ecx
  unsigned int Size; // edi
  Scaleform::GFx::Value *Data; // ebp
  Scaleform::GFx::Value *v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // esi
  int v13; // eax
  void *v14; // esi
  Scaleform::GFx::FunctionHandler *v15; // ecx
  char Type; // al
  Scaleform::ArrayCPP<Scaleform::GFx::Value,2,Scaleform::ArrayDefaultPolicy> args; // [esp+18h] [ebp-84h] BYREF
  Scaleform::GFx::AS3::Value *value; // [esp+24h] [ebp-78h]
  Scaleform::GFx::AS3::MovieRoot *pmovieRoot; // [esp+28h] [ebp-74h]
  Scaleform::GFx::Value thisVal; // [esp+2Ch] [ebp-70h] BYREF
  unsigned int v21; // [esp+44h] [ebp-58h]
  Scaleform::GFx::Value arg; // [esp+48h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::ASVM *vm; // [esp+60h] [ebp-3Ch]
  Scaleform::GFx::AS3::UserDefinedFunction *v24; // [esp+64h] [ebp-38h]
  Scaleform::GFx::Value retVal; // [esp+68h] [ebp-34h] BYREF
  Scaleform::GFx::FunctionHandler::Params params; // [esp+80h] [ebp-1Ch] BYREF

  v5 = this;
  pObject = this->pTraits.pObject;
  thisVal.pObjectInterface = 0;
  thisVal.Type = VT_Undefined;
  retVal.pObjectInterface = 0;
  retVal.Type = VT_Undefined;
  vm = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  v7 = vm->pMovieRoot;
  v24 = v5;
  memset(&args, 0, sizeof(args));
  pmovieRoot = v7;
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v7, _this, (Scaleform::GFx::ASStringNode *)&thisVal);
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &args.Data,
    &args,
    1u);
  Size = args.Data.Size;
  Data = args.Data.Data;
  v10 = &args.Data.Data[args.Data.Size - 1];
  if ( &args.Data.Data[args.Data.Size] != (Scaleform::GFx::Value *)24 )
  {
    v10->pObjectInterface = 0;
    v10->Type = thisVal.Type;
    v10->mValue.NValue = thisVal.mValue.NValue;
    v10->DataAux = thisVal.DataAux;
    if ( (thisVal.Type & 0x40) != 0 )
    {
      v10->pObjectInterface = thisVal.pObjectInterface;
      thisVal.pObjectInterface->ObjectAddRef(thisVal.pObjectInterface, v10, (void *)v10->mValue.IValue);
    }
  }
  v11 = argc;
  if ( argc )
  {
    value = argv;
    v21 = argc;
    while ( 1 )
    {
      arg.pObjectInterface = 0;
      arg.Type = VT_Undefined;
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pmovieRoot, value, (Scaleform::GFx::ASStringNode *)&arg);
      v12 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v12 < args.Data.Policy.Capacity )
          goto LABEL_12;
        Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &args.Data,
          &args,
          v12 + (v12 >> 2));
      }
      else
      {
        Scaleform::ConstructorCPP<Scaleform::GFx::Value>::DestructArray(&Data[v12], 0xFFFFFFFF);
        if ( v12 >= args.Data.Policy.Capacity >> 1 )
          goto LABEL_12;
        Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &args.Data,
          &args,
          v12);
      }
      Data = args.Data.Data;
LABEL_12:
      v13 = (int)&Data[v12 - 1];
      ++Size;
      args.Data.Size = v12;
      if ( &Data[v12] != (Scaleform::GFx::Value *)24 )
      {
        *(_DWORD *)v13 = 0;
        *(_DWORD *)(v13 + 4) = arg.Type;
        *(long double *)(v13 + 8) = arg.mValue.NValue;
        *(_DWORD *)(v13 + 16) = arg.DataAux;
        if ( (arg.Type & 0x40) != 0 )
        {
          v14 = *(void **)(v13 + 8);
          *(_DWORD *)v13 = arg.pObjectInterface;
          arg.pObjectInterface->ObjectAddRef(arg.pObjectInterface, (Scaleform::GFx::Value *)v13, v14);
        }
      }
      if ( (arg.Type & 0x40) != 0 )
        arg.pObjectInterface->ObjectRelease(arg.pObjectInterface, &arg, (void *)arg.mValue.IValue);
      ++value;
      if ( !--v21 )
      {
        v5 = v24;
        v11 = argc;
        break;
      }
    }
  }
  params.pMovie = vm->pMovieRoot->pMovieImpl;
  params.pRetVal = &retVal;
  params.pThis = &thisVal;
  if ( v11 )
    params.pArgs = Data + 1;
  else
    params.pArgs = 0;
  params.pUserData = v5->pUserData;
  v15 = v5->pContext.pObject;
  params.ArgCount = Size - 1;
  params.pArgsWithThisRef = Data;
  v15->Call(v15, &params);
  Type = retVal.Type;
  if ( (retVal.Type & 0x8F) != 0 )
  {
    Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pmovieRoot, (Scaleform::GFx::ASStringNode *)&retVal, result);
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
  thisVal.Type = VT_Undefined;
  Scaleform::ConstructorCPP<Scaleform::GFx::Value>::DestructArray(Data, Size);
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
