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
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+2Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::AS2::Environment *penv; // [esp+38h] [ebp-80h]
  int v22; // [esp+3Ch] [ebp-7Ch]
  Scaleform::GFx::Value pdestVal; // [esp+40h] [ebp-78h] BYREF
  Scaleform::GFx::Value v24; // [esp+58h] [ebp-60h] BYREF
  Scaleform::GFx::Value gfxVal; // [esp+70h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::UserDefinedFunctionObject *v26; // [esp+88h] [ebp-30h]
  Scaleform::GFx::AS2::Value value; // [esp+8Ch] [ebp-2Ch] BYREF
  _DWORD v28[4]; // [esp+9Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::Value *v29; // [esp+ACh] [ebp-Ch]
  unsigned int v30; // [esp+B0h] [ebp-8h]
  void *pUserData; // [esp+B4h] [ebp-4h]

  ThisPtr = fn->ThisPtr;
  Env = fn->Env;
  v26 = this;
  penv = Env;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  pdestVal.pObjectInterface = 0;
  pdestVal.Type = VT_Undefined;
  gfxVal.pObjectInterface = 0;
  gfxVal.Type = VT_Undefined;
  value.T.Type = 0;
  if ( ThisPtr )
  {
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&value, ThisPtr);
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(&value);
    value.T.Type = 1;
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
    (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
    Env,
    &value,
    &pdestVal);
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    1u);
  Size = pheapAddr.Size;
  v5 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( &pheapAddr.Data[pheapAddr.Size] != (Scaleform::GFx::Value *)24 )
  {
    v5->pObjectInterface = 0;
    v5->Type = pdestVal.Type;
    v5->mValue.NValue = pdestVal.mValue.NValue;
    v5->DataAux = pdestVal.DataAux;
    if ( (pdestVal.Type & 0x40) != 0 )
    {
      v5->pObjectInterface = pdestVal.pObjectInterface;
      pdestVal.pObjectInterface->ObjectAddRef(pdestVal.pObjectInterface, v5, (void *)v5->mValue.IValue);
    }
  }
  v6 = 0;
  v7 = fn->NArgs <= 0;
  v22 = 0;
  if ( !v7 )
  {
    do
    {
      v8 = fn->FirstArgBottomIndex - v6;
      v9 = fn->Env;
      v24.pObjectInterface = 0;
      v24.Type = VT_Undefined;
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
        &v24);
      v14 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v14 >= pheapAddr.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v14 + (v14 >> 2));
      }
      else
      {
        Scaleform::ConstructorCPP<Scaleform::GFx::Value>::DestructArray(&pheapAddr.Data[v14], 0xFFFFFFFF);
        if ( v14 < pheapAddr.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v14);
      }
      v15 = &pheapAddr.Data[v14 - 1];
      ++Size;
      pheapAddr.Size = v14;
      if ( &pheapAddr.Data[v14] != (Scaleform::GFx::Value *)24 )
      {
        v15->pObjectInterface = 0;
        v15->Type = v24.Type;
        v15->mValue.NValue = v24.mValue.NValue;
        v15->DataAux = v24.DataAux;
        if ( (v24.Type & 0x40) != 0 )
        {
          pStringManaged = v15->mValue.pStringManaged;
          v15->pObjectInterface = v24.pObjectInterface;
          v24.pObjectInterface->ObjectAddRef(v24.pObjectInterface, v15, pStringManaged);
        }
      }
      if ( (v24.Type & 0x40) != 0 )
        v24.pObjectInterface->ObjectRelease(v24.pObjectInterface, &v24, (void *)v24.mValue.IValue);
      v6 = v22 + 1;
      v7 = ++v22 < fn->NArgs;
    }
    while ( v7 );
    Env = penv;
  }
  v7 = fn->NArgs <= 0;
  v28[1] = Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject->pMovieImpl;
  v28[0] = &gfxVal;
  v28[2] = &pdestVal;
  if ( v7 )
    v29 = 0;
  else
    v29 = pheapAddr.Data + 1;
  v30 = Size - 1;
  pUserData = v26->pUserData;
  pObject = v26->pContext.pObject;
  v28[3] = pheapAddr.Data;
  pObject->Call(pObject, (const Scaleform::GFx::FunctionHandler::Params *)v28);
  Type = gfxVal.Type;
  if ( (gfxVal.Type & 0x8F) != 0 )
  {
    Scaleform::GFx::AS2::MovieRoot::Value2ASValue(
      (Scaleform::GFx::AS2::MovieRoot *)Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      &gfxVal,
      fn->Result);
    Type = gfxVal.Type;
  }
  if ( value.T.Type >= 5u )
  {
    Scaleform::GFx::AS2::Value::DropRefs(&value);
    Type = gfxVal.Type;
  }
  if ( (Type & 0x40) != 0 )
  {
    gfxVal.pObjectInterface->ObjectRelease(gfxVal.pObjectInterface, &gfxVal, (void *)gfxVal.mValue.IValue);
    gfxVal.pObjectInterface = 0;
  }
  gfxVal.Type = VT_Undefined;
  if ( (pdestVal.Type & 0x40) != 0 )
  {
    pdestVal.pObjectInterface->ObjectRelease(pdestVal.pObjectInterface, &pdestVal, (void *)pdestVal.mValue.IValue);
    pdestVal.pObjectInterface = 0;
  }
  Data = pheapAddr.Data;
  pdestVal.Type = VT_Undefined;
  Scaleform::ConstructorCPP<Scaleform::GFx::Value>::DestructArray(pheapAddr.Data, Size);
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
