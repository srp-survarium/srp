char __userpurge Scaleform::GFx::AS2::MovieRoot::SetVariable@<al>(
        Scaleform::GFx::AS2::MovieRoot *this@<ecx>,
        int a2@<ebp>,
        char *ppathToVar,
        Scaleform::RefCountVImpl *value,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  unsigned int Size; // edx
  int v8; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  char *v11; // ebx
  Scaleform::Log *pObject; // esi
  Scaleform::Log *v13; // esi
  Scaleform::GFx::MovieImpl *v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v18; // edx
  Scaleform::GFx::InteractiveObject *v19; // eax
  int v20; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  const Scaleform::GFx::Value *v22; // edx
  Scaleform::GFx::MovieImpl *v23; // edx
  unsigned int v24; // ecx
  unsigned int v25; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v26; // edx
  Scaleform::GFx::MovieImpl::LevelInfo *v27; // esi
  Scaleform::GFx::InteractiveObject *v28; // eax
  Scaleform::GFx::Movie::SetVarType v29; // esi
  int v30; // ecx
  Scaleform::GFx::AS2::Environment *v31; // eax
  char v32; // bl
  Scaleform::GFx::ASStringNode *v33; // eax
  bool v34; // [esp-4h] [ebp-28h]
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+Ch] [ebp-18h] BYREF
  unsigned int _CurrentState; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+14h] [ebp-10h] BYREF

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v8 = 0;
  if ( !Size )
    return 0;
  for ( i = pMovieImpl->MovieLevels.Data.Data; i->Level; ++i )
  {
    if ( ++v8 >= Size )
      return 0;
  }
  if ( !pMovieImpl->MovieLevels.Data.Data[v8].pSprite.pObject )
    return 0;
  v11 = ppathToVar;
  if ( !ppathToVar )
  {
    pObject = Scaleform::GFx::StateBag::GetLog(
                &pMovieImpl->Scaleform::GFx::StateBag,
                (Scaleform::Ptr<Scaleform::Log> *)&value)->pObject;
    if ( value )
      Scaleform::RefCountImpl::Release(value);
    if ( pObject )
    {
      v13 = Scaleform::GFx::StateBag::GetLog(
              &this->pMovieImpl->Scaleform::GFx::StateBag,
              (Scaleform::Ptr<Scaleform::Log> *)&value)->pObject;
      if ( value )
        Scaleform::RefCountImpl::Release(value);
      Scaleform::Log::LogError(v13, "NULL pathToVar passed to SetVariable/SetDouble()");
    }
    return 0;
  }
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v14 = this->pMovieImpl;
  v15 = v14->MovieLevels.Data.Size;
  v16 = 0;
  if ( v15 )
  {
    Data = v14->MovieLevels.Data.Data;
    v18 = Data;
    while ( v18->Level )
    {
      ++v16;
      ++v18;
      if ( v16 >= v15 )
        goto LABEL_19;
    }
    v19 = Data[v16].pSprite.pObject;
  }
  else
  {
LABEL_19:
    v19 = 0;
  }
  v20 = (*(int (__thiscall **)(int))(*((_DWORD *)&v19->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + v19->AvmObjOffset)
                                   + 124))((int)v19 + 4 * v19->AvmObjOffset);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v20 + 116) + 20) + 12) + 788),
                 v11);
  v22 = (const Scaleform::GFx::Value *)value;
  ppathToVar = (char *)StringNode;
  ++StringNode->RefCount;
  val.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, v22, &val);
  v23 = this->pMovieImpl;
  v24 = v23->MovieLevels.Data.Size;
  v25 = 0;
  if ( v24 )
  {
    v26 = v23->MovieLevels.Data.Data;
    v27 = v26;
    while ( v27->Level )
    {
      ++v25;
      ++v27;
      if ( v25 >= v24 )
        goto LABEL_24;
    }
    v28 = v26[v25].pSprite.pObject;
  }
  else
  {
LABEL_24:
    v28 = 0;
  }
  v29 = setType;
  v30 = (int)v28 + 4 * v28->AvmObjOffset;
  v34 = setType == SV_Normal;
  v31 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v30 + 124))(v30);
  v32 = Scaleform::GFx::AS2::Environment::SetVariable(v31, a2, (Scaleform::GFx::ASString *)&ppathToVar, &val, 0, v34);
  if ( !v32 && v29 || v29 == SV_Permanent )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(this, (Scaleform::GFx::ASString *)&ppathToVar, &val, v29);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v33 = (Scaleform::GFx::ASStringNode *)ppathToVar;
  --*((_DWORD *)ppathToVar + 3);
  if ( !v33->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  _controlfp_s((unsigned int *)&value, dpg.fpc, 0x30000u);
  return v32;
}
