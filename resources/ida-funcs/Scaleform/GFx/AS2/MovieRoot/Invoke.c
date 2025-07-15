char __usercall Scaleform::GFx::AS2::MovieRoot::Invoke@<al>(
        char a1@<bl>,
        Scaleform::GFx::AS2::MovieRoot *this,
        __m128i *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        ...)
{
  Scaleform::GFx::AS2::MovieRoot *v5; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v8; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::ASStringNode *v12; // edi
  bool v13; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // eax
  char v15; // bl
  Scaleform::GFx::MovieImpl *v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v19; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v20; // ecx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int AvmObjOffset; // ecx
  Scaleform::RefCountNTSImpl *v23; // esi
  int v24; // eax
  Scaleform::GFx::MovieImpl *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v28; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v29; // ecx
  Scaleform::GFx::InteractiveObject *v30; // eax
  int v31; // ecx
  Scaleform::GFx::AS2::Environment *v32; // eax
  Scaleform::GFx::Value *v33; // [esp-Ch] [ebp-28h]
  unsigned int v34; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+Ch] [ebp-10h] BYREF
  va_list va; // [esp+30h] [ebp+14h] BYREF

  va_start(va, pargFmt);
  v5 = this;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v8 = 0;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v8 >= Size )
      return 0;
  }
  if ( !Data[v8].pSprite.pObject )
    return 0;
  _controlfp_s(a1, (unsigned int *)&this, 0, 0);
  _controlfp_s(a1, &v34, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  v12 = (Scaleform::GFx::ASStringNode *)pmethodName;
  v13 = v5->pInvokeAliases == 0;
  value.T.Type = 0;
  if ( v13
    || (v14 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(
                                                            v5,
                                                            pmethodName)) == 0 )
  {
    v16 = v5->pMovieImpl;
    v17 = v16->MovieLevels.Data.Size;
    v18 = 0;
    if ( v17 )
    {
      v19 = v16->MovieLevels.Data.Data;
      v20 = v19;
      while ( v20->Level )
      {
        ++v18;
        ++v20;
        if ( v18 >= v17 )
          goto LABEL_15;
      }
      pObject = v19[v18].pSprite.pObject;
    }
    else
    {
LABEL_15:
      pObject = 0;
    }
    AvmObjOffset = pObject->AvmObjOffset;
    v23 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)&pObject->pASRoot + AvmObjOffset);
    v24 = (int)pObject + 4 * AvmObjOffset;
    if ( v23 )
      ++v23->RefCount;
    v15 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            v12,
            &value,
            (Scaleform::GFx::AS2::ObjectInterface *)(v24 + 4),
            (Scaleform::GFx::AS2::Environment *)(v24 + 28),
            pargFmt,
            va);
    if ( v23 )
      Scaleform::RefCountNTSImpl::Release(v23);
  }
  else
  {
    v15 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(v5, (const char *)v12, v14, &value, pargFmt, va);
  }
  if ( v15 && presult )
  {
    v25 = v5->pMovieImpl;
    v26 = v25->MovieLevels.Data.Size;
    v27 = 0;
    if ( v26 )
    {
      v28 = v25->MovieLevels.Data.Data;
      v29 = v28;
      while ( v29->Level )
      {
        ++v27;
        ++v29;
        if ( v27 >= v26 )
          goto LABEL_26;
      }
      v30 = v28[v27].pSprite.pObject;
    }
    else
    {
LABEL_26:
      v30 = 0;
    }
    v31 = (int)v30 + 4 * v30->AvmObjOffset;
    v33 = presult;
    v32 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v31 + 124))(v31);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v5, v32, &value, v33);
  }
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  _controlfp_s(v15, &v34, (unsigned int)this, (unsigned int)&loc_30000);
  return v15;
}


char __thiscall Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *thisCont,
        __m128i *pmethodName,
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
  __m128i *v13; // ebp
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // eax
  Scaleform::RefCountNTSImpl *v15; // esi
  Scaleform::GFx::AS2::Environment *v16; // esi
  unsigned int _CurrentState; // [esp+Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value pdestVal; // [esp+20h] [ebp-10h] BYREF

  v6 = thisCont;
  v7 = this;
  if ( !thisCont || thisCont->GetType(thisCont) != MouseUp )
    return 0;
  _controlfp_s((int)v7, &_CurrentState, 0, 0);
  _controlfp_s((int)v7, (unsigned int *)&thisCont, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  v8 = (Scaleform::RefCountNTSImpl **)(&v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + v6->AvmObjOffset);
  value.T.Type = 0;
  v9 = (Scaleform::GFx::InteractiveObject *)((int (__thiscall *)(Scaleform::RefCountNTSImpl **))(*v8)[15].RefCount)(v8);
  v10 = numArgs - 1;
  thisCont = v9;
  if ( (int)(numArgs - 1) >= 0 )
  {
    p_RefCount = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&v9->RefCount;
    v12 = &pargs[v10];
    do
    {
      pdestVal.T.Type = 0;
      Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, v12, &pdestVal);
      if ( ++p_RefCount->pCurrent >= p_RefCount->pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_RefCount);
      if ( p_RefCount->pCurrent )
        Scaleform::GFx::AS2::Value::Value(p_RefCount->pCurrent, &pdestVal);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      --v10;
      --v12;
    }
    while ( v10 >= 0 );
    v7 = this;
  }
  v13 = pmethodName;
  if ( v7->pInvokeAliases
    && (v14 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(
                                                            v7,
                                                            pmethodName)) != 0 )
  {
    LOBYTE(v7) = Scaleform::GFx::AS2::MovieRoot::InvokeAlias(v7, v13->m128i_i8, v14, &value, numArgs);
  }
  else
  {
    v15 = v8[4];
    if ( v15 )
      ++v15->RefCount;
    LOBYTE(v7) = Scaleform::GFx::AS2::GAS_Invoke(
                   (Scaleform::GFx::ASStringNode *)v13,
                   &value,
                   (Scaleform::GFx::AS2::ObjectInterface *)(v8 + 1),
                   (Scaleform::GFx::AS2::Environment *)(v8 + 7),
                   numArgs,
                   (((char *)v8[8] - (char *)v8[9]) >> 4) + 32 * (_DWORD)v8[13] - 32);
    if ( v15 )
      Scaleform::RefCountNTSImpl::Release(v15);
  }
  v16 = (Scaleform::GFx::AS2::Environment *)thisCont;
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
    (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&thisCont->RefCount,
    numArgs);
  if ( (_BYTE)v7 && presult )
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v16, &value, presult);
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  _controlfp_s((int)v7, &numArgs, _CurrentState, (unsigned int)&loc_30000);
  return (char)v7;
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
