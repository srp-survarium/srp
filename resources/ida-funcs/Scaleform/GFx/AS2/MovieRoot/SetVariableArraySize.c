char __thiscall Scaleform::GFx::AS2::MovieRoot::SetVariableArraySize(
        Scaleform::GFx::AS2::MovieRoot *this,
        char *ppathToVar,
        unsigned int count,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  int v7; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // edx
  unsigned int v11; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::AS2::Environment *v14; // esi
  Scaleform::GFx::AS2::Object *v15; // eax
  Scaleform::GFx::AS2::ArrayObject *v16; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::ArrayObject *v19; // edi
  Scaleform::GFx::MovieImpl *v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v23; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v24; // ecx
  Scaleform::GFx::InteractiveObject *v25; // eax
  Scaleform::GFx::AS2::Environment *v26; // eax
  Scaleform::GFx::AS2::ArrayObject *v27; // eax
  Scaleform::GFx::AS2::ArrayObject *v28; // edi
  Scaleform::GFx::MovieImpl *v29; // edx
  unsigned int v30; // ecx
  unsigned int v31; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v32; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v33; // edx
  Scaleform::GFx::InteractiveObject *v34; // eax
  int v35; // ecx
  Scaleform::GFx::AS2::Environment *v36; // eax
  char v37; // bl
  unsigned int v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::ASString path; // [esp+8h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value retVal; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+1Ch] [ebp-10h] BYREF

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
  v11 = 0;
  v12 = Data;
  while ( v12->Level )
  {
    ++v11;
    ++v12;
    if ( v11 >= Size )
    {
      pObject = 0;
      goto LABEL_13;
    }
  }
  pObject = Data[v11].pSprite.pObject;
LABEL_13:
  v14 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                         + pObject->AvmObjOffset)
                                                                       + 124))((int)pObject + 4 * pObject->AvmObjOffset);
  path.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 ppathToVar);
  ++path.pNode->RefCount;
  retVal.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v14, &path, &retVal, 0, 0, 0, 0)
    && retVal.T.Type == 6
    && (v15 = Scaleform::GFx::AS2::Value::ToObject(&retVal, v14), (v16 = (Scaleform::GFx::AS2::ArrayObject *)v15) != 0)
    && v15->GetObjectType(&v15->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
  {
    v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
    if ( count != v16->Elements.Data.Size )
      Scaleform::GFx::AS2::ArrayObject::Resize(v16, count);
    if ( retVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&retVal);
    RefCount = v16->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v16->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
    }
    pNode = path.pNode;
    --path.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 1;
  }
  else
  {
    v19 = (Scaleform::GFx::AS2::ArrayObject *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 80, 0);
    if ( v19 )
    {
      v20 = this->pMovieImpl;
      v21 = v20->MovieLevels.Data.Size;
      v22 = 0;
      if ( v21 )
      {
        v23 = v20->MovieLevels.Data.Data;
        v24 = v23;
        while ( v24->Level )
        {
          ++v22;
          ++v24;
          if ( v22 >= v21 )
            goto LABEL_32;
        }
        v25 = v23[v22].pSprite.pObject;
      }
      else
      {
LABEL_32:
        v25 = 0;
      }
      v26 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&v25->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                             + v25->AvmObjOffset)
                                                                           + 124))((int)v25 + 4 * v25->AvmObjOffset);
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v19, v26);
      v28 = v27;
    }
    else
    {
      v28 = 0;
    }
    Scaleform::GFx::AS2::ArrayObject::Resize(v28, count);
    val.T.Type = 0;
    Scaleform::GFx::AS2::Value::SetAsObject(&val, v28);
    v29 = this->pMovieImpl;
    v30 = v29->MovieLevels.Data.Size;
    v31 = 0;
    if ( v30 )
    {
      v32 = v29->MovieLevels.Data.Data;
      v33 = v32;
      while ( v33->Level )
      {
        ++v31;
        ++v33;
        if ( v31 >= v30 )
          goto LABEL_40;
      }
      v34 = v32[v31].pSprite.pObject;
    }
    else
    {
LABEL_40:
      v34 = 0;
    }
    v35 = (int)v34 + 4 * v34->AvmObjOffset;
    v36 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v35 + 124))(v35);
    v37 = Scaleform::GFx::AS2::Environment::SetVariable(v36, (int)this, &path, &val, 0, setType == SV_Normal);
    if ( !v37 && setType || setType == SV_Permanent )
      Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(this, &path, &val, setType);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    if ( retVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&retVal);
    if ( v28 )
    {
      v38 = v28->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v38) != 0 )
      {
        v28->RefCount = v38 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
      }
    }
    v39 = path.pNode;
    --path.pNode->RefCount;
    if ( !v39->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    return v37;
  }
}
