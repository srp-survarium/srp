char __thiscall Scaleform::GFx::AS2::MovieRoot::SetVariableArray(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        __m128i *ppathToVar,
        int index,
        Scaleform::GFx::Value *pdata,
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
  int v32; // ebx
  unsigned int j; // esi
  int v34; // edx
  unsigned int m; // esi
  unsigned int k; // esi
  unsigned int v37; // esi
  const Scaleform::GFx::Value *v38; // ebp
  unsigned int n; // ebp
  Scaleform::GFx::ASStringNode *v40; // esi
  bool v41; // zf
  unsigned int ii; // ebp
  Scaleform::GFx::ASStringNode *v43; // esi
  Scaleform::GFx::MovieImpl *v44; // edx
  unsigned int v45; // ecx
  unsigned int v46; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v47; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v48; // edx
  Scaleform::GFx::InteractiveObject *v49; // eax
  Scaleform::GFx::Movie::SetVarType v50; // esi
  int v51; // ecx
  Scaleform::GFx::AS2::Environment *v52; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v54; // eax
  __int64 v55; // [esp-1Ch] [ebp-64h]
  bool v56; // [esp-Ch] [ebp-54h]
  Scaleform::GFx::AS2::MovieRoot *v57; // [esp+8h] [ebp-40h]
  Scaleform::GFx::ASStringNode *StringNode; // [esp+Ch] [ebp-3Ch] BYREF
  unsigned int _CurrentState; // [esp+10h] [ebp-38h] BYREF
  unsigned int v60; // [esp+14h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::Value v61; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v62; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+38h] [ebp-10h] BYREF

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v10 = 0;
  v57 = this;
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
  _controlfp_s((int)this, &_CurrentState, 0, 0);
  _controlfp_s((int)this, &v60, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
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
  HIDWORD(v55) = &v62;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v21->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 ppathToVar);
  ++StringNode->RefCount;
  LODWORD(v55) = &StringNode;
  v62.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v21, v55, 0, 0, 0)
    && v62.T.Type == 6
    && (v22 = Scaleform::GFx::AS2::Value::ToObject(&v62, v21), (v23 = (Scaleform::GFx::AS2::ArrayObject *)v22) != 0)
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
  v32 = index;
  if ( index + count > v23->Elements.Data.Size )
    Scaleform::GFx::AS2::ArrayObject::Resize(v23, index + count);
  switch ( type )
  {
    case SA_Int:
      for ( j = 0; j < count; ++j )
      {
        v34 = *((_DWORD *)&pdata->pObjectInterface + j);
        val.T.Type = 4;
        val.NV.Int32Value = v34;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, j + index, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      break;
    case SA_Double:
      for ( k = 0; k < count; ++k )
      {
        val.NV.NumberValue = *(double *)&(&pdata->pObjectInterface)[2 * k];
        val.T.Type = 3;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, k + index, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      break;
    case SA_Float:
      for ( m = 0; m < count; ++m )
      {
        val.NV.NumberValue = *((float *)&pdata->pObjectInterface + m);
        val.T.Type = 3;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, m + index, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      break;
    case SA_String:
      for ( n = 0; n < count; ++n )
      {
        v40 = Scaleform::GFx::ASStringManager::CreateStringNode(
                v57->BuiltinsMgr.pStringManager,
                *((__m128i **)&pdata->pObjectInterface + n));
        ++v40->RefCount;
        ++v40->RefCount;
        val.T.Type = 5;
        val.NV.Int32Value = (int)v40;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, index + n, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v41 = v40->RefCount-- == 1;
        if ( v41 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v40);
      }
      break;
    case SA_StringW:
      for ( ii = 0; ii < count; ++ii )
      {
        v43 = Scaleform::GFx::ASStringManager::CreateStringNode(
                v57->BuiltinsMgr.pStringManager,
                *((wchar_t **)&pdata->pObjectInterface + ii),
                -1);
        ++v43->RefCount;
        ++v43->RefCount;
        val.T.Type = 5;
        val.NV.Int32Value = (int)v43;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v23, index + ii, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v41 = v43->RefCount-- == 1;
        if ( v41 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      }
      break;
    case SA_Value:
      v37 = 0;
      if ( count )
      {
        v38 = pdata;
        do
        {
          val.T.Type = 0;
          Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v57, v38, &val);
          Scaleform::GFx::AS2::ArrayObject::SetElement(v23, v37 + index, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v37;
          ++v38;
        }
        while ( v37 < count );
      }
      break;
    default:
      break;
  }
  v61.T.Type = 0;
  Scaleform::GFx::AS2::Value::SetAsObject(&v61, v23);
  v44 = v57->pMovieImpl;
  v45 = v44->MovieLevels.Data.Size;
  v46 = 0;
  if ( v45 )
  {
    v47 = v44->MovieLevels.Data.Data;
    v48 = v47;
    while ( v48->Level )
    {
      ++v46;
      ++v48;
      if ( v46 >= v45 )
        goto LABEL_69;
    }
    v49 = v47[v46].pSprite.pObject;
  }
  else
  {
LABEL_69:
    v49 = 0;
  }
  v50 = setType;
  v51 = (int)v49 + 4 * v49->AvmObjOffset;
  v56 = setType == SV_Normal;
  v52 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v51 + 124))(v51);
  LOBYTE(v32) = Scaleform::GFx::AS2::Environment::SetVariable(
                  v52,
                  (const Scaleform::GFx::ASString *)v57,
                  (Scaleform::GFx::ASStringNode *)&StringNode,
                  &v61,
                  0,
                  v56);
  if ( !(_BYTE)v32 && v50 || v50 == SV_Permanent )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(v57, (Scaleform::GFx::ASStringNode *)&StringNode, &v61, v50);
  if ( v61.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v61);
  if ( v62.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v62);
  RefCount = v23->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    v23->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
  }
  v54 = StringNode;
  --StringNode->RefCount;
  if ( !v54->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
  _controlfp_s(v32, &count, _CurrentState, (unsigned int)&loc_30000);
  return v32;
}
