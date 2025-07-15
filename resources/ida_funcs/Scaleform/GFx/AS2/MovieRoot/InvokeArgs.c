char __thiscall Scaleform::GFx::AS2::MovieRoot::InvokeArgs(
        Scaleform::GFx::AS2::MovieRoot *this,
        char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        char *args)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v8; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
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
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+8h] [ebp-18h] BYREF
  unsigned int _CurrentState; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value resultVal; // [esp+10h] [ebp-10h] BYREF

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
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v12 = this->pInvokeAliases == 0;
  resultVal.T.Type = 0;
  if ( v12 || (v13 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(this, pmethodName)) == 0 )
  {
    v15 = this->pMovieImpl;
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
          goto LABEL_14;
      }
      pObject = v18[v17].pSprite.pObject;
    }
    else
    {
LABEL_14:
      pObject = 0;
    }
    AvmObjOffset = pObject->AvmObjOffset;
    v22 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)&pObject->pASRoot + AvmObjOffset);
    v23 = (int)pObject + 4 * AvmObjOffset;
    if ( v22 )
      ++v22->RefCount;
    v14 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            pmethodName,
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
    v14 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(this, pmethodName, v13, &resultVal, pargFmt, args);
  }
  if ( v14 && presult )
  {
    v24 = this->pMovieImpl;
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
          goto LABEL_25;
      }
      v29 = v27[v26].pSprite.pObject;
    }
    else
    {
LABEL_25:
      v29 = 0;
    }
    v30 = (int)v29 + 4 * v29->AvmObjOffset;
    v31 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v30 + 124))(v30);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v31, &resultVal, presult);
  }
  if ( resultVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&resultVal);
  _controlfp_s((unsigned int *)&args, dpg.fpc, 0x30000u);
  return v14;
}
