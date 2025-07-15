int Scaleform::GFx::AS3::MovieRoot::Invoke(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, pargFmt);
  return ((int (__thiscall *)(Scaleform::GFx::AS3::MovieRoot *, const char *, Scaleform::GFx::Value *, const char *, char *))this->InvokeArgs)(
           this,
           pmethodName,
           presult,
           pargFmt,
           va);
}


bool __thiscall Scaleform::GFx::AS3::MovieRoot::Invoke(
        Scaleform::GFx::AS3::MovieRoot *this,
        char *pmethodName,
        Scaleform::GFx::Value *presult,
        Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  unsigned int v5; // ebx
  Scaleform::GFx::AS3::Value *v7; // esi
  Scaleform::GFx::AS3::Value *v9; // eax
  Scaleform::GFx::AS3::Value *v10; // esi
  void *pWeakProxy; // eax
  bool v12; // zf
  Scaleform::GFx::AS3::ASVM *pObject; // ecx
  bool HandleException; // al
  bool v15; // bl
  Scaleform::GFx::AS3::Value *v16; // esi
  unsigned int v17; // edi
  Scaleform::GFx::AS3::WeakProxy *v18; // eax
  Scaleform::GFx::AS3::WeakProxy *v19; // eax
  Scaleform::GFx::ASStringNode *VStr; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // eax
  unsigned int RefCount; // edx
  bool retVal; // [esp+Fh] [ebp-145h]
  Scaleform::GFx::AS3::Value *pargArray; // [esp+10h] [ebp-144h]
  Scaleform::GFx::AS3::Value resultVal; // [esp+14h] [ebp-140h] BYREF
  unsigned int _CurrentState; // [esp+24h] [ebp-130h] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+28h] [ebp-12Ch] BYREF
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+2Ch] [ebp-128h] BYREF
  void *argArrayOnStack[70]; // [esp+3Ch] [ebp-118h] BYREF

  v5 = numArgs;
  retVal = 1;
  if ( numArgs <= 0xA )
    pargArray = (Scaleform::GFx::AS3::Value *)argArrayOnStack;
  else
    pargArray = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                16 * numArgs,
                                                0);
  if ( numArgs )
  {
    v7 = pargArray;
    do
    {
      v9 = 0;
      if ( v7 )
      {
        v7->Flags = 0;
        v7->Bonus.pWeakProxy = 0;
        v9 = v7;
      }
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, (Scaleform::GFx::ASStringNode *)pargs++, v9);
      ++v7;
      --v5;
    }
    while ( v5 );
    v5 = numArgs;
  }
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  resultVal.Flags = 0;
  resultVal.Bonus.pWeakProxy = 0;
  if ( this->pInvokeAliases )
  {
    v10 = Scaleform::GFx::AS3::MovieRoot::ResolveInvokeAlias(this, pmethodName);
    if ( v10 )
    {
      if ( (_S10_0 & 1) == 0 )
      {
        _S10_0 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pAVM.pObject, v10, &v, &resultVal, v5, pargArray, 0);
LABEL_26:
      pObject = this->pAVM.pObject;
      HandleException = pObject->HandleException;
      v15 = !HandleException;
      retVal = !HandleException;
      if ( HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(pObject);
      if ( v15 && presult )
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &resultVal, (Scaleform::GFx::ASStringNode *)presult);
      v5 = numArgs;
      goto LABEL_32;
    }
  }
  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, pmethodName) )
  {
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pAVM.pObject, &resolvedVal, &v, &resultVal, v5, pargArray, 0);
  }
  else
  {
    retVal = 0;
  }
  if ( (resolvedVal.Flags & 0x1F) > 9 )
  {
    if ( (resolvedVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = resolvedVal.Bonus.pWeakProxy;
      v12 = resolvedVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resolvedVal);
    }
  }
  if ( retVal )
    goto LABEL_26;
LABEL_32:
  if ( v5 )
  {
    v16 = pargArray;
    v17 = v5;
    do
    {
      if ( (v16->Flags & 0x1F) > 9 )
      {
        if ( (v16->Flags & 0x200) != 0 )
        {
          v18 = v16->Bonus.pWeakProxy;
          v12 = v18->RefCount-- == 1;
          if ( v12 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
          v16->Flags &= 0xFFFFFDE0;
          v16->Bonus.pWeakProxy = 0;
          v16->value.VS._1.VInt = 0;
          v16->value.VS._2.VObj = 0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v16);
        }
      }
      ++v16;
      --v17;
    }
    while ( v17 );
  }
  if ( v5 > 0x46 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pargArray);
  if ( (resultVal.Flags & 0x1F) > 9 )
  {
    if ( (resultVal.Flags & 0x200) != 0 )
    {
      v19 = resultVal.Bonus.pWeakProxy;
      --resultVal.Bonus.pWeakProxy->RefCount;
      if ( !v19->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
      resultVal.Flags &= 0xFFFFFDE0;
      memset(&resultVal.Bonus, 0, 12);
    }
    else
    {
      switch ( resultVal.Flags & 0x1F )
      {
        case 0xA:
          VStr = resultVal.value.VS._1.VStr;
          --*(_DWORD *)(resultVal.value.VS._1.VInt + 12);
          if ( !VStr->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          VObj = resultVal.value.VS._1.VObj;
          if ( !resultVal.value.VS._1.VBool )
            goto LABEL_55;
          --resultVal.value.VS._1.VInt;
          break;
        case 0x10:
        case 0x11:
          VObj = resultVal.value.VS._2.VObj;
          if ( ((int)resultVal.value.VS._2.VObj & 1) != 0 )
          {
            --resultVal.value.VS._2.VObj;
          }
          else
          {
LABEL_55:
            if ( VObj )
            {
              RefCount = VObj->RefCount;
              if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
              {
                VObj->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }
  _controlfp_s(&_CurrentState, dpg.fpc, 0x30000u);
  return retVal;
}
