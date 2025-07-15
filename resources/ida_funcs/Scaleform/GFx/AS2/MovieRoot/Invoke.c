char Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        ...)
{
  Scaleform::GFx::AS2::MovieRoot *v4; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v7; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  char *v11; // edi
  bool v12; // zf
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v13; // eax
  char v14; // bl
  Scaleform::GFx::MovieImpl *v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v18; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v19; // ecx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int AvmObjOffset; // ecx
  Scaleform::RefCountNTSImpl *v22; // esi
  int v23; // eax
  Scaleform::GFx::MovieImpl *v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v27; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v28; // ecx
  Scaleform::GFx::InteractiveObject *v29; // eax
  int v30; // ecx
  Scaleform::GFx::AS2::Environment *v31; // eax
  Scaleform::GFx::Value *v32; // [esp-Ch] [ebp-28h]
  unsigned int _CurrentState; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value resultVal; // [esp+Ch] [ebp-10h] BYREF
  va_list args; // [esp+30h] [ebp+14h] BYREF

  va_start(args, pargFmt);
  v4 = this;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v7 = 0;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v7 >= Size )
      return 0;
  }
  if ( !Data[v7].pSprite.pObject )
    return 0;
  _controlfp_s((unsigned int *)&this, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v11 = pmethodName;
  v12 = v4->pInvokeAliases == 0;
  resultVal.T.Type = 0;
  if ( v12 || (v13 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(v4, pmethodName)) == 0 )
  {
    v15 = v4->pMovieImpl;
    v16 = v15->MovieLevels.Data.Size;
    v17 = 0;
    if ( v16 )
    {
      v18 = v15->MovieLevels.Data.Data;
      v19 = v18;
      while ( v19->Level )
      {
        ++v17;
        ++v19;
        if ( v17 >= v16 )
          goto LABEL_15;
      }
      pObject = v18[v17].pSprite.pObject;
    }
    else
    {
LABEL_15:
      pObject = 0;
    }
    AvmObjOffset = pObject->AvmObjOffset;
    v22 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)&pObject->pASRoot + AvmObjOffset);
    v23 = (int)pObject + 4 * AvmObjOffset;
    if ( v22 )
      ++v22->RefCount;
    v14 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            v11,
            &resultVal,
            (Scaleform::GFx::AS2::ObjectInterface *)(v23 + 4),
            (Scaleform::GFx::AS2::Environment *)(v23 + 28),
            pargFmt,
            args);
    if ( v22 )
      Scaleform::RefCountNTSImpl::Release(v22);
  }
  else
  {
    v14 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(v4, v11, v13, &resultVal, pargFmt, args);
  }
  if ( v14 && presult )
  {
    v24 = v4->pMovieImpl;
    v25 = v24->MovieLevels.Data.Size;
    v26 = 0;
    if ( v25 )
    {
      v27 = v24->MovieLevels.Data.Data;
      v28 = v27;
      while ( v28->Level )
      {
        ++v26;
        ++v28;
        if ( v26 >= v25 )
          goto LABEL_26;
      }
      v29 = v27[v26].pSprite.pObject;
    }
    else
    {
LABEL_26:
      v29 = 0;
    }
    v30 = (int)v29 + 4 * v29->AvmObjOffset;
    v32 = presult;
    v31 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v30 + 124))(v30);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v4, v31, &resultVal, v32);
  }
  if ( resultVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&resultVal);
  _controlfp_s(&_CurrentState, (unsigned int)this, 0x30000u);
  return v14;
}


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


int __thiscall Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // esi
  unsigned int v7; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *v9; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v7 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v9 = Data;
    while ( v9->Level )
    {
      ++v7;
      ++v9;
      if ( v7 >= Size )
        goto LABEL_5;
    }
    pObject = Data[v7].pSprite.pObject;
  }
  else
  {
LABEL_5:
    pObject = 0;
  }
  return ((int (__thiscall *)(Scaleform::GFx::AS2::MovieRoot *, Scaleform::GFx::InteractiveObject *, const char *, Scaleform::GFx::Value *, const Scaleform::GFx::Value *, unsigned int))this->Invoke)(
           this,
           pObject,
           pmethodName,
           presult,
           pargs,
           numArgs);
}
