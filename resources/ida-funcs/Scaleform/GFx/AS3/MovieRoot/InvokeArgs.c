bool __thiscall Scaleform::GFx::AS3::MovieRoot::InvokeArgs(
        Scaleform::GFx::AS3::MovieRoot *this,
        __m128i *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        char *args)
{
  __m128i *v5; // ebp
  Scaleform::GFx::AS3::Value *v7; // edi
  char *v8; // eax
  Scaleform::GFx::AS3::ASVM *pObject; // edi
  bool HandleException; // al
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value *Data; // esi
  Scaleform::GFx::AS3::Value *v14; // esi
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> valArray; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Value resultVal; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+2Ch] [ebp-10h] BYREF

  v5 = pmethodName;
  memset(&valArray, 0, sizeof(valArray));
  Scaleform::GFx::AS3::MovieRoot::ParseValueArguments(this, &valArray, pmethodName->m128i_i8, pargFmt, args);
  v7 = valArray.Data.Size != 0 ? valArray.Data.Data : 0;
  _controlfp_s(0, (unsigned int *)&pargFmt, 0, 0);
  _controlfp_s(0, (unsigned int *)&args, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  resultVal.Flags = 0;
  resultVal.Bonus.pWeakProxy = 0;
  if ( this->pInvokeAliases )
  {
    v8 = (char *)Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(this, v5);
    args = v8;
    if ( v8 )
    {
      if ( (_S15 & 1) == 0 )
      {
        _S15 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
        v8 = args;
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        this->pAVM.pObject,
        (Scaleform::GFx::AS3::Value *)v8,
        &v,
        &resultVal,
        valArray.Data.Size,
        v7,
        0);
LABEL_10:
      pObject = this->pAVM.pObject;
      HandleException = pObject->HandleException;
      LOBYTE(args) = !HandleException;
      if ( HandleException )
      {
        pObject->HandleException = 0;
      }
      else if ( presult )
      {
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &resultVal, (Scaleform::GFx::ASStringNode *)presult);
      }
      if ( (resultVal.Flags & 0x1F) > 9 )
      {
        if ( (resultVal.Flags & 0x200) != 0 )
        {
          pWeakProxy = resultVal.Bonus.pWeakProxy;
          --resultVal.Bonus.pWeakProxy->RefCount;
          if ( !pWeakProxy->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          resultVal.Flags &= 0xFFFFFDE0;
          memset(&resultVal.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&resultVal);
        }
      }
      _controlfp_s(0, (unsigned int *)&pmethodName, (unsigned int)pargFmt, (unsigned int)&loc_30000);
      Data = valArray.Data.Data;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(valArray.Data.Data, valArray.Data.Size);
      if ( Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
      return (char)args;
    }
  }
  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, v5->m128i_i8) )
  {
    if ( (_S15 & 1) == 0 )
    {
      _S15 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      this->pAVM.pObject,
      &resolvedVal,
      &v,
      &resultVal,
      valArray.Data.Size,
      v7,
      0);
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
    goto LABEL_10;
  }
  Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
  Scaleform::GFx::AS3::Value::~Value(&resultVal);
  _controlfp_s(0, (unsigned int *)&args, (unsigned int)pargFmt, (unsigned int)&loc_30000);
  v14 = valArray.Data.Data;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(valArray.Data.Data, valArray.Data.Size);
  if ( v14 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
  return 0;
}
