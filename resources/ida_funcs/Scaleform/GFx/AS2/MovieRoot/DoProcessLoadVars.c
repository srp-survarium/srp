void __thiscall Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::String *data,
        unsigned int fileLen,
        bool __formal)
{
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  unsigned int Size; // ecx
  Scaleform::GFx::AS2::LoadVarsObject *v10; // ebx
  unsigned int v11; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v13; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::ASStringNode *v15; // edi
  const Scaleform::String *StringNode; // eax
  long double v17; // st7
  Scaleform::GFx::ASStringNode *v18; // esi
  Scaleform::GFx::InteractiveObject *v20; // eax
  Scaleform::GFx::Sprite *EmptySprite; // edi
  int v22; // eax
  Scaleform::GFx::AS2::ObjectInterface *v23; // ebx
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::GFx::MovieImpl *v25; // esi
  unsigned int v26; // edx
  unsigned int v27; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v28; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v29; // ecx
  Scaleform::GFx::InteractiveObject *v30; // eax
  int v31; // ecx
  Scaleform::GFx::AS2::Environment *v32; // eax
  Scaleform::String *v33; // [esp-4h] [ebp-10h]

  if ( Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[1].QuietOpen, 0) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[1].QuietOpen, 0);
    pMovieImpl = this->pMovieImpl;
    Size = pMovieImpl->MovieLevels.Data.Size;
    v10 = (Scaleform::GFx::AS2::LoadVarsObject *)v7;
    v11 = 0;
    if ( Size )
    {
      v12 = pMovieImpl->MovieLevels.Data.Data;
      v13 = v12;
      while ( v13->Level )
      {
        ++v11;
        ++v13;
        if ( v11 >= Size )
          goto LABEL_6;
      }
      pObject = v12[v11].pSprite.pObject;
    }
    else
    {
LABEL_6:
      pObject = 0;
    }
    v15 = (Scaleform::GFx::ASStringNode *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                       + pObject->AvmObjOffset)
                                                                     + 124))((int)pObject + 4 * pObject->AvmObjOffset);
    StringNode = (const Scaleform::String *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                              *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(v15[4].Size + 20)
                                                                                              + 12)
                                                                                  + 788),
                                              (char *)((data->HeapTypeBits & 0xFFFFFFFC) + 8),
                                              *(_DWORD *)(data->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    v17 = (double)fileLen;
    v18 = (Scaleform::GFx::ASStringNode *)StringNode;
    ++StringNode[3].HeapTypeBits;
    data = (Scaleform::String *)StringNode;
    if ( v10->BytesLoadedTotal < 0.0 )
      v10->BytesLoadedTotal = 0.0;
    v10->BytesLoadedCurrent = v17;
    v10->BytesLoadedTotal = v17 + v10->BytesLoadedTotal;
    Scaleform::GFx::AS2::LoadVarsObject::NotifyOnData(v10, v15, (Scaleform::GFx::ASString *)&data);
    if ( v18->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    return;
  }
  if ( p_entry[1].__vftable == (Scaleform::GFx::LoadQueueEntry_vtbl *)-1 )
  {
    v20 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
            (Scaleform::GFx::CharacterHandle *)p_entry[1].pNext,
            this->pMovieImpl);
    if ( v20 )
      ++v20->RefCount;
    EmptySprite = (Scaleform::GFx::Sprite *)v20;
    if ( !v20 )
      goto LABEL_23;
  }
  else
  {
    LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(this, (int)p_entry[1].__vftable);
    if ( LevelMovie )
      ++LevelMovie->RefCount;
    EmptySprite = LevelMovie;
    if ( !LevelMovie )
    {
      EmptySprite = Scaleform::GFx::AS2::MovieRoot::CreateEmptySprite(this, pls, (int)p_entry[1].__vftable);
      if ( !EmptySprite )
        return;
    }
  }
  v22 = (*(int (__thiscall **)(int))(*((_DWORD *)&EmptySprite->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + EmptySprite->AvmObjOffset)
                                   + 4))((int)EmptySprite + 4 * EmptySprite->AvmObjOffset);
  if ( !v22 )
  {
LABEL_23:
    v23 = 0;
    goto LABEL_24;
  }
  v23 = (Scaleform::GFx::AS2::ObjectInterface *)(v22 + 4);
LABEL_24:
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
        goto LABEL_28;
    }
    v30 = v28[v27].pSprite.pObject;
  }
  else
  {
LABEL_28:
    v30 = 0;
  }
  v31 = (int)v30 + 4 * v30->AvmObjOffset;
  v33 = data;
  v32 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v31 + 124))(v31);
  Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(v32, v23, v33);
  if ( EmptySprite )
    Scaleform::RefCountNTSImpl::Release(EmptySprite);
}
