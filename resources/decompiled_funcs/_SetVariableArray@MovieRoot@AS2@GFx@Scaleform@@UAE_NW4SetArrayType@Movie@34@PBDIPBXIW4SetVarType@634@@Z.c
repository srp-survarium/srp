char __thiscall Scaleform::GFx::AS2::MovieRoot::SetVariableArray(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        char *ppathToVar,
        unsigned int index,
        const Scaleform::GFx::Value *pdata,
        unsigned int count,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v10; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::MovieImpl *v14; // edx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v17; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v18; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v20; // ecx
  Scaleform::GFx::AS2::Environment *v21; // esi
  Scaleform::GFx::AS2::Object *v22; // eax
  Scaleform::GFx::AS2::ArrayObject *v23; // edi
  Scaleform::GFx::AS2::ArrayObject *v24; // edi
  unsigned int v25; // eax
  Scaleform::GFx::MovieImpl *v26; // ecx
  unsigned int v27; // edx
  Scaleform::GFx::MovieImpl::LevelInfo *v28; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v29; // ecx
  Scaleform::GFx::InteractiveObject *v30; // eax
  Scaleform::GFx::AS2::Environment *v31; // eax
  unsigned int j; // esi
  int v33; // edx
  unsigned int m; // esi
  unsigned int k; // esi
  unsigned int v36; // esi
  const Scaleform::GFx::Value *v37; // ebp
  unsigned int n; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // esi
  bool v40; // zf
  unsigned int ii; // ebp
  Scaleform::GFx::ASStringNode *v42; // esi
  Scaleform::GFx::MovieImpl *v43; // edx
  unsigned int v44; // ecx
  unsigned int v45; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v46; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v47; // edx
  Scaleform::GFx::InteractiveObject *v48; // eax
  Scaleform::GFx::Movie::SetVarType v49; // esi
  int v50; // ecx
  Scaleform::GFx::AS2::Environment *v51; // eax
  char v52; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v55; // [esp-Ch] [ebp-54h]
  Scaleform::GFx::AS2::MovieRoot *v56; // [esp+8h] [ebp-40h]
  Scaleform::GFx::ASString path; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+10h] [ebp-38h] BYREF
  unsigned int _CurrentState; // [esp+14h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value retVal; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value asVal; // [esp+38h] [ebp-10h] BYREF

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v10 = 0;
  v56 = this;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v10 >= Size )
      return 0;
  }
  if ( !Data[v10].pSprite.pObject )
    return 0;
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v14 = this->pMovieImpl;
  v15 = v14->MovieLevels.Data.Size;
  v16 = 0;
  if ( v15 )
  {
    v17 = v14->MovieLevels.Data.Data;
    v18 = v17;
    while ( v18->Level )
    {
      ++v16;
      ++v18;
      if ( v16 >= v15 )
        goto LABEL_12;
    }
    pObject = v17[v16].pSprite.pObject;
  }
  else
  {
LABEL_12:
    pObject = 0;
  }
  v20 = (int)pObject + 4 * pObject->AvmObjOffset;
  v21 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 124))(v20);
  path.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v21->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 ppathToVar);
  ++path.pNode->RefCount;
  retVal.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v21, &path, &retVal, 0, 0, 0, 0)
    && retVal.T.Type == 6
    && (v22 = Scaleform::GFx::AS2::Value::ToObject(&retVal, v21), (v23 = (Scaleform::GFx::AS2::ArrayObject *)v22) != 0)
    && v22->GetObjectType(&v22->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
  {
    v23->RefCount = (v23->RefCount + 1) & 0x8FFFFFFF;
  }
  else
  {
    v24 = (Scaleform::GFx::AS2::ArrayObject *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 80, 0);
    v25 = 0;
    if ( v24 )
    {
      v26 = this->pMovieImpl;
      v27 = v26->MovieLevels.Data.Size;
      if ( v27 )
      {
        v28 = v26->MovieLevels.Data.Data;
        v29 = v28;
        while ( v29->Level )
        {
          ++v25;
          ++v29;
          if ( v25 >= v27 )
            goto LABEL_24;
        }
        v30 = v28[v25].pSprite.pObject;
      }
      else
      {
LABEL_24:
        v30 = 0;
      }
      v31 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&v30->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                             + v30->AvmObjOffset)
                                                                           + 124))((int)v30 + 4 * v30->AvmObjOffset);
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v24, v31);
    }
    v23 = (Scaleform::GFx::AS2::ArrayObject *)v25;
  }
  if ( index + count > v23->Elements.Data.Size )
    Scaleform::GFx::AS2::ArrayObject::Resize(v23, index + count);
  switch ( type )
  {
    case SA_Int:
      for ( j = 0; j < count; ++j )
      {
        v33 = *((_DWORD *)&pdata->pObjectInterface + j);
        asVal.T.Type = 4;
        asVal.NV.Int32Value = v33;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, j + index, &asVal);
        if ( asVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&asVal);
      }
      break;
    case SA_Double:
      for ( k = 0; k < count; ++k )
      {
        asVal.NV.NumberValue = *(double *)&(&pdata->pObjectInterface)[2 * k];
        asVal.T.Type = 3;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, k + index, &asVal);
        if ( asVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&asVal);
      }
      break;
    case SA_Float:
      for ( m = 0; m < count; ++m )
      {
        asVal.NV.NumberValue = *((float *)&pdata->pObjectInterface + m);
        asVal.T.Type = 3;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, m + index, &asVal);
        if ( asVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&asVal);
      }
      break;
    case SA_String:
      for ( n = 0; n < count; ++n )
      {
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       this->BuiltinsMgr.pStringManager,
                       *((char **)&pdata->pObjectInterface + n));
        ++StringNode->RefCount;
        ++StringNode->RefCount;
        asVal.T.Type = 5;
        asVal.NV.Int32Value = (int)StringNode;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, index + n, &asVal);
        if ( asVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&asVal);
        v40 = StringNode->RefCount-- == 1;
        if ( v40 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      }
      break;
    case SA_StringW:
      for ( ii = 0; ii < count; ++ii )
      {
        v42 = Scaleform::GFx::ASStringManager::CreateStringNode(
                this->BuiltinsMgr.pStringManager,
                *((const wchar_t **)&pdata->pObjectInterface + ii),
                -1);
        ++v42->RefCount;
        ++v42->RefCount;
        asVal.T.Type = 5;
        asVal.NV.Int32Value = (int)v42;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, index + ii, &asVal);
        if ( asVal.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&asVal);
        v40 = v42->RefCount-- == 1;
        if ( v40 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v42);
      }
      break;
    case SA_Value:
      v36 = 0;
      if ( count )
      {
        v37 = pdata;
        do
        {
          asVal.T.Type = 0;
          Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, v37, &asVal);
          Scaleform::GFx::AS2::ArrayObject::SetElement(v23, v36 + index, &asVal);
          if ( asVal.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&asVal);
          ++v36;
          ++v37;
        }
        while ( v36 < count );
      }
      break;
    default:
      break;
  }
  val.T.Type = 0;
  Scaleform::GFx::AS2::Value::SetAsObject(&val, v23);
  v43 = this->pMovieImpl;
  v44 = v43->MovieLevels.Data.Size;
  v45 = 0;
  if ( v44 )
  {
    v46 = v43->MovieLevels.Data.Data;
    v47 = v46;
    while ( v47->Level )
    {
      ++v45;
      ++v47;
      if ( v45 >= v44 )
        goto LABEL_69;
    }
    v48 = v46[v45].pSprite.pObject;
  }
  else
  {
LABEL_69:
    v48 = 0;
  }
  v49 = setType;
  v50 = (int)v48 + 4 * v48->AvmObjOffset;
  v55 = setType == SV_Normal;
  v51 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v50 + 124))(v50);
  v52 = Scaleform::GFx::AS2::Environment::SetVariable(v51, (int)this, &path, &val, 0, v55);
  if ( !v52 && v49 || v49 == SV_Permanent )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(v56, &path, &val, v49);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  if ( retVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&retVal);
  RefCount = v23->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    v23->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
  }
  pNode = path.pNode;
  --path.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  _controlfp_s(&count, dpg.fpc, 0x30000u);
  return v52;
}
