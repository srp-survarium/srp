char __userpurge Scaleform::GFx::AS2::MovieRoot::SetVariable@<al>(
        Scaleform::GFx::AS2::MovieRoot *this@<ecx>,
        const Scaleform::GFx::ASString *a2@<ebp>,
        Scaleform::GFx::ASStringNode ppathToVar)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  unsigned int Size; // edx
  int v6; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  __m128i *pData; // ebx
  Scaleform::Log *pObject; // esi
  Scaleform::Log *v11; // esi
  Scaleform::GFx::MovieImpl *v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v16; // edx
  Scaleform::GFx::InteractiveObject *v17; // eax
  int v18; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::MovieImpl *v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v24; // edx
  Scaleform::GFx::MovieImpl::LevelInfo *v25; // esi
  Scaleform::GFx::InteractiveObject *v26; // eax
  Scaleform::GFx::ASStringNode *pLower; // esi
  int v28; // ecx
  Scaleform::GFx::AS2::Environment *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  bool v31; // [esp-4h] [ebp-28h]
  unsigned int _CurrentState; // [esp+Ch] [ebp-18h] BYREF
  unsigned int v33; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value pdestVal; // [esp+14h] [ebp-10h] BYREF

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v6 = 0;
  if ( !Size )
    return 0;
  for ( i = pMovieImpl->MovieLevels.Data.Data; i->Level; ++i )
  {
    if ( ++v6 >= Size )
      return 0;
  }
  if ( !pMovieImpl->MovieLevels.Data.Data[v6].pSprite.pObject )
    return 0;
  pData = (__m128i *)ppathToVar.pData;
  if ( !ppathToVar.pData )
  {
    pObject = Scaleform::GFx::StateBag::GetLog(
                &pMovieImpl->Scaleform::GFx::StateBag,
                (Scaleform::Ptr<Scaleform::Log> *)&ppathToVar.pManager)->pObject;
    if ( ppathToVar.pManager )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ppathToVar.pManager);
    if ( pObject )
    {
      v11 = Scaleform::GFx::StateBag::GetLog(
              &this->pMovieImpl->Scaleform::GFx::StateBag,
              (Scaleform::Ptr<Scaleform::Log> *)&ppathToVar.pManager)->pObject;
      if ( ppathToVar.pManager )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ppathToVar.pManager);
      Scaleform::Log::LogError(v11, "NULL pathToVar passed to SetVariable/SetDouble()");
    }
    return 0;
  }
  _controlfp_s((int)ppathToVar.pData, &_CurrentState, 0, 0);
  _controlfp_s((int)pData, &v33, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  v12 = this->pMovieImpl;
  v13 = v12->MovieLevels.Data.Size;
  v14 = 0;
  if ( v13 )
  {
    Data = v12->MovieLevels.Data.Data;
    v16 = Data;
    while ( v16->Level )
    {
      ++v14;
      ++v16;
      if ( v14 >= v13 )
        goto LABEL_19;
    }
    v17 = Data[v14].pSprite.pObject;
  }
  else
  {
LABEL_19:
    v17 = 0;
  }
  v18 = (*(int (__thiscall **)(int))(*((_DWORD *)&v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + v17->AvmObjOffset)
                                   + 124))((int)v17 + 4 * v17->AvmObjOffset);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v18 + 116) + 20) + 12) + 788),
                 pData);
  pManager = ppathToVar.pManager;
  ppathToVar.pData = (const char *)StringNode;
  ++StringNode->RefCount;
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, (const Scaleform::GFx::Value *)pManager, &pdestVal);
  v21 = this->pMovieImpl;
  v22 = v21->MovieLevels.Data.Size;
  v23 = 0;
  if ( v22 )
  {
    v24 = v21->MovieLevels.Data.Data;
    v25 = v24;
    while ( v25->Level )
    {
      ++v23;
      ++v25;
      if ( v23 >= v22 )
        goto LABEL_24;
    }
    v26 = v24[v23].pSprite.pObject;
  }
  else
  {
LABEL_24:
    v26 = 0;
  }
  pLower = ppathToVar.pLower;
  v28 = (int)v26 + 4 * v26->AvmObjOffset;
  v31 = ppathToVar.pLower == 0;
  v29 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v28 + 124))(v28);
  LOBYTE(pData) = Scaleform::GFx::AS2::Environment::SetVariable(v29, a2, &ppathToVar, &pdestVal, 0, v31);
  if ( !(_BYTE)pData && pLower || pLower == (Scaleform::GFx::ASStringNode *)2 )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(
      this,
      &ppathToVar,
      &pdestVal,
      (Scaleform::GFx::Movie::SetVarType)pLower);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  v30 = (Scaleform::GFx::ASStringNode *)ppathToVar.pData;
  --*((_DWORD *)ppathToVar.pData + 3);
  if ( !v30->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  _controlfp_s((int)pData, (unsigned int *)&ppathToVar.pManager, _CurrentState, (unsigned int)&loc_30000);
  return (char)pData;
}
