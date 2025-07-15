char __userpurge Scaleform::GFx::AS2::MovieRoot::InvokeArgs@<al>(
        Scaleform::GFx::AS2::MovieRoot *this@<ecx>,
        char a2@<bl>,
        Scaleform::GFx::ASStringNode *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        char *args)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v9; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
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
  unsigned int _CurrentState; // [esp+8h] [ebp-18h] BYREF
  unsigned int v34; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+10h] [ebp-10h] BYREF

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v9 = 0;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v9 >= Size )
      return 0;
  }
  if ( !Data[v9].pSprite.pObject )
    return 0;
  _controlfp_s(a2, &_CurrentState, 0, 0);
  _controlfp_s(a2, &v34, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  v13 = this->pInvokeAliases == 0;
  value.T.Type = 0;
  if ( v13
    || (v14 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(
                                                            this,
                                                            (__m128i *)pmethodName)) == 0 )
  {
    v16 = this->pMovieImpl;
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
          goto LABEL_14;
      }
      pObject = v19[v18].pSprite.pObject;
    }
    else
    {
LABEL_14:
      pObject = 0;
    }
    AvmObjOffset = pObject->AvmObjOffset;
    v23 = (Scaleform::RefCountNTSImpl *)*((_DWORD *)&pObject->pASRoot + AvmObjOffset);
    v24 = (int)pObject + 4 * AvmObjOffset;
    if ( v23 )
      ++v23->RefCount;
    v15 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            pmethodName,
            &value,
            (Scaleform::GFx::AS2::ObjectInterface *)(v24 + 4),
            (Scaleform::GFx::AS2::Environment *)(v24 + 28),
            pargFmt,
            args);
    if ( v23 )
      Scaleform::RefCountNTSImpl::Release(v23);
  }
  else
  {
    v15 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(this, (const char *)pmethodName, v14, &value, pargFmt, args);
  }
  if ( v15 && presult )
  {
    v25 = this->pMovieImpl;
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
          goto LABEL_25;
      }
      v30 = v28[v27].pSprite.pObject;
    }
    else
    {
LABEL_25:
      v30 = 0;
    }
    v31 = (int)v30 + 4 * v30->AvmObjOffset;
    v32 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v31 + 124))(v31);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v32, &value, presult);
  }
  if ( value.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&value);
  _controlfp_s(v15, (unsigned int *)&args, _CurrentState, (unsigned int)&loc_30000);
  return v15;
}
