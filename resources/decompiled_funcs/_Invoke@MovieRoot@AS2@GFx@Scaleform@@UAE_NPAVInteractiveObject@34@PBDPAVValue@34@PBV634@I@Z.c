char __thiscall Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *thisCont,
        char *pmethodName,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  Scaleform::GFx::InteractiveObject *v6; // esi
  Scaleform::GFx::AS2::MovieRoot *v7; // ebx
  Scaleform::RefCountNTSImpl **v8; // edi
  Scaleform::GFx::InteractiveObject *v9; // eax
  int v10; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_RefCount; // esi
  const Scaleform::GFx::Value *v12; // ebx
  char *v13; // ebp
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v14; // eax
  char v15; // bl
  Scaleform::RefCountNTSImpl *v16; // esi
  Scaleform::GFx::AS2::Environment *v17; // esi
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value resultVal; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value asval; // [esp+20h] [ebp-10h] BYREF

  v6 = thisCont;
  v7 = this;
  if ( !thisCont || thisCont->GetType(thisCont) != MouseUp )
    return 0;
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s((unsigned int *)&thisCont, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v8 = (Scaleform::RefCountNTSImpl **)(&v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + v6->AvmObjOffset);
  resultVal.T.Type = 0;
  v9 = (Scaleform::GFx::InteractiveObject *)((int (__thiscall *)(Scaleform::RefCountNTSImpl **))(*v8)[15].RefCount)(v8);
  v10 = numArgs - 1;
  thisCont = v9;
  if ( (int)(numArgs - 1) >= 0 )
  {
    p_RefCount = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&v9->RefCount;
    v12 = &pargs[v10];
    do
    {
      asval.T.Type = 0;
      Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, v12, &asval);
      if ( ++p_RefCount->pCurrent >= p_RefCount->pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_RefCount);
      if ( p_RefCount->pCurrent )
        Scaleform::GFx::AS2::Value::Value(p_RefCount->pCurrent, &asval);
      if ( asval.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&asval);
      --v10;
      --v12;
    }
    while ( v10 >= 0 );
    v7 = this;
  }
  v13 = pmethodName;
  if ( v7->pInvokeAliases && (v14 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(v7, pmethodName)) != 0 )
  {
    v15 = Scaleform::GFx::AS2::MovieRoot::InvokeAlias(v7, v13, v14, &resultVal, numArgs);
  }
  else
  {
    v16 = v8[4];
    if ( v16 )
      ++v16->RefCount;
    v15 = Scaleform::GFx::AS2::GAS_Invoke(
            v13,
            &resultVal,
            (Scaleform::GFx::AS2::ObjectInterface *)(v8 + 1),
            (Scaleform::GFx::AS2::Environment *)(v8 + 7),
            numArgs,
            (((char *)v8[8] - (char *)v8[9]) >> 4) + 32 * (_DWORD)v8[13] - 32);
    if ( v16 )
      Scaleform::RefCountNTSImpl::Release(v16);
  }
  v17 = (Scaleform::GFx::AS2::Environment *)thisCont;
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
    (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&thisCont->RefCount,
    numArgs);
  if ( v15 && presult )
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v17, &resultVal, presult);
  if ( resultVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&resultVal);
  _controlfp_s(&numArgs, dpg.fpc, 0x30000u);
  return v15;
}
