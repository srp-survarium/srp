void __thiscall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::call(
        Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::MovieImpl *v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  bool v10; // zf
  Scaleform::GFx::Value *v11; // eax
  Scaleform::GFx::Value *v12; // esi
  const Scaleform::GFx::AS3::Value *v13; // edi
  unsigned int v14; // ebx
  Scaleform::GFx::Value *v15; // eax
  Scaleform::GFx::AS3::Value *p_ExternalIntfRetVal; // esi
  Scaleform::GFx::AS3::Value *v17; // ecx
  Scaleform::GFx::ASStringNode *v18; // eax
  const char *pData; // eax
  Scaleform::GFx::Value *v20; // edi
  Scaleform::GFx::Value *v21; // esi
  unsigned int v22; // edi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASString methodName; // [esp+24h] [ebp-118h] BYREF
  Scaleform::GFx::ASString fullMethodName; // [esp+28h] [ebp-114h] BYREF
  Scaleform::GFx::Value *pargArray; // [esp+2Ch] [ebp-110h]
  Scaleform::GFx::AS3::CheckResult v31; // [esp+33h] [ebp-109h] BYREF
  Scaleform::GFx::AS3::MovieRoot *proot; // [esp+34h] [ebp-108h]
  Scaleform::GFx::MovieImpl *pmovie; // [esp+38h] [ebp-104h]
  Scaleform::AmpFunctionTimer _amp_timer_; // [esp+3Ch] [ebp-100h] BYREF
  void *argArrayOnStack[60]; // [esp+4Ch] [ebp-F0h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v6 = (Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v10 = v6->pExtIntfHandler.pObject == 0;
  proot = (Scaleform::GFx::AS3::MovieRoot *)pVM[1].__vftable;
  pmovie = v6;
  if ( !v10 )
  {
    methodName.pNode = pVM->StringManagerRef->Builtins[0].pNode;
    ++methodName.pNode->RefCount;
    v7 = 0;
    if ( argc )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2String(argv, &v31, &methodName)->Result )
      {
        pNode = methodName.pNode;
        --methodName.pNode->RefCount;
        v9 = pNode;
        v10 = pNode->RefCount == 0;
LABEL_5:
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        return;
      }
      v7 = argc - 1;
    }
    fullMethodName.pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[0].pNode;
    ++fullMethodName.pNode->RefCount;
    Scaleform::GFx::ASString::operator=(&fullMethodName, (Scaleform::GFx::ASStringNode *)"ExternalInterface::call(");
    Scaleform::GFx::ASString::Append(&fullMethodName, (Scaleform::GFx::ASStringNode *)&methodName);
    Scaleform::GFx::ASString::Append(&fullMethodName, (const __m128i *)")", (Scaleform::GFx::ASStringNode *)1);
    Scaleform::AmpFunctionTimer::AmpFunctionTimer(
      &_amp_timer_,
      v6->AdvanceStats.pObject,
      fullMethodName.pNode->pData,
      Amp_Profile_Level_Medium,
      Amp_Native_Function_Id_Invalid);
    if ( v7 <= 0xA )
      v11 = (Scaleform::GFx::Value *)argArrayOnStack;
    else
      v11 = (Scaleform::GFx::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                       Scaleform::Memory::pGlobalHeap,
                                       this,
                                       24 * v7,
                                       0);
    pargArray = v11;
    if ( v7 )
    {
      v12 = v11;
      v13 = argv + 1;
      v14 = v7;
      do
      {
        v15 = 0;
        if ( v12 )
        {
          v12->pObjectInterface = 0;
          v12->Type = VT_Undefined;
          v15 = v12;
        }
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(proot, v13++, v15);
        ++v12;
        --v14;
      }
      while ( v14 );
      v6 = pmovie;
    }
    p_ExternalIntfRetVal = &proot->ExternalIntfRetVal;
    if ( (proot->ExternalIntfRetVal.Flags & 0x1F) > 9 )
    {
      v17 = &proot->ExternalIntfRetVal;
      if ( (proot->ExternalIntfRetVal.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v17);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v17);
    }
    v18 = methodName.pNode;
    p_ExternalIntfRetVal->Flags &= 0xFFFFFFE0;
    if ( v18->Size )
      pData = v18->pData;
    else
      pData = 0;
    v20 = pargArray;
    v6->pExtIntfHandler.pObject->Callback(v6->pExtIntfHandler.pObject, v6, pData, pargArray, v7);
    Scaleform::GFx::AS3::Value::Assign(result, p_ExternalIntfRetVal);
    if ( v7 )
    {
      v21 = v20;
      v22 = v7;
      do
      {
        if ( (v21->Type & 0x40) != 0 )
        {
          ((void (__stdcall *)(Scaleform::GFx::Value *, int))v21->pObjectInterface->ObjectRelease)(
            v21,
            v21->mValue.IValue);
          v21->pObjectInterface = 0;
        }
        v21->Type = VT_Undefined;
        ++v21;
        --v22;
      }
      while ( v22 );
    }
    if ( v7 > 0xA )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pargArray);
    Stats = _amp_timer_.Stats;
    if ( _amp_timer_.Stats )
    {
      p_NativePopCallstack = &_amp_timer_.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_.StartTicks),
        (ProfileTicks - _amp_timer_.StartTicks) >> 32);
    }
    v26 = fullMethodName.pNode;
    --fullMethodName.pNode->RefCount;
    if ( !v26->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    v27 = methodName.pNode;
    --methodName.pNode->RefCount;
    v9 = v27;
    v10 = v27->RefCount == 0;
    goto LABEL_5;
  }
  pVM->UI->Output(pVM->UI, Output_Warning, "Warning: ExternalInterface.call - handler is not installed.\n");
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      result->Flags &= 0xFFFFFFE0;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  result->Flags &= 0xFFFFFFE0;
}
