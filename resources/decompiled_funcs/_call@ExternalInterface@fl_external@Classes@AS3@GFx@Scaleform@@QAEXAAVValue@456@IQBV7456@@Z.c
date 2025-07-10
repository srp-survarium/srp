void __thiscall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::call(
        Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::MovieImpl *v6; // edi
  unsigned int v7; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  bool v10; // zf
  void **v11; // eax
  Scaleform::GFx::Value *v12; // esi
  const Scaleform::GFx::AS3::Value *v13; // edi
  unsigned int v14; // ebx
  Scaleform::GFx::Value *v15; // eax
  Scaleform::GFx::AS3::Value *p_ExternalIntfRetVal; // esi
  Scaleform::GFx::AS3::Value *v17; // ecx
  Scaleform::GFx::ASStringNode *v18; // eax
  const char *pData; // eax
  Scaleform::GFx::Value *v20; // esi
  unsigned int v21; // edi
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::Value *pargArray; // [esp+18h] [ebp-104h]
  Scaleform::GFx::ASString methodName; // [esp+1Ch] [ebp-100h] BYREF
  Scaleform::GFx::AS3::CheckResult v25; // [esp+23h] [ebp-F9h] BYREF
  Scaleform::GFx::AS3::MovieRoot *proot; // [esp+24h] [ebp-F8h]
  Scaleform::GFx::MovieImpl *pmovie; // [esp+28h] [ebp-F4h]
  void *argArrayOnStack[60]; // [esp+2Ch] [ebp-F0h] BYREF

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
    if ( !argc )
      goto LABEL_10;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(argv, &v25, &methodName)->Result )
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
    if ( argc - 1 > 0xA )
      v11 = (void **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 24 * v7, 0);
    else
LABEL_10:
      v11 = argArrayOnStack;
    pargArray = (Scaleform::GFx::Value *)v11;
    if ( v7 )
    {
      v12 = (Scaleform::GFx::Value *)v11;
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
    v6->pExtIntfHandler.pObject->Callback(v6->pExtIntfHandler.pObject, v6, pData, pargArray, v7);
    Scaleform::GFx::AS3::Value::Assign(result, p_ExternalIntfRetVal);
    if ( v7 )
    {
      v20 = pargArray;
      v21 = v7;
      do
      {
        if ( (v20->Type & 0x40) != 0 )
        {
          ((void (__stdcall *)(Scaleform::GFx::Value *, int))v20->pObjectInterface->ObjectRelease)(
            v20,
            v20->mValue.IValue);
          v20->pObjectInterface = 0;
        }
        v20->Type = VT_Undefined;
        ++v20;
        --v21;
      }
      while ( v21 );
    }
    if ( v7 > 0xA )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pargArray);
    v22 = methodName.pNode;
    --methodName.pNode->RefCount;
    v9 = v22;
    v10 = v22->RefCount == 0;
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
