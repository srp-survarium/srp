char __thiscall Scaleform::GFx::AS2::MovieRoot::InvokeAlias(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        const Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *alias,
        Scaleform::GFx::AS2::Value *presult,
        unsigned int numArgs)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v7; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  Scaleform::GFx::AS2::Object *v13; // edi
  Scaleform::GFx::InteractiveObject *v14; // ebp
  Scaleform::GFx::InteractiveObject *v15; // eax
  Scaleform::GFx::AS2::ObjectInterface *v16; // edi
  int v17; // eax
  Scaleform::GFx::MovieImpl *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v21; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v22; // ecx
  Scaleform::GFx::InteractiveObject *v23; // eax
  int v24; // ecx
  Scaleform::GFx::AS2::Environment *v25; // esi
  char v26; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value method; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::Object *pobj; // [esp+20h] [ebp+8h]

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
  if ( alias->ThisObject.pObject )
    alias->ThisObject.pObject->RefCount = (alias->ThisObject.pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = alias->ThisChar.pObject;
  v13 = alias->ThisObject.pObject;
  v14 = 0;
  pobj = alias->ThisObject.pObject;
  if ( pObject )
  {
    v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pObject, this->pMovieImpl);
    if ( v15 )
      ++v15->RefCount;
    v14 = v15;
  }
  if ( v13 )
  {
    v16 = &v13->Scaleform::GFx::AS2::ObjectInterface;
  }
  else if ( v14
         && (v17 = (*(int (__thiscall **)(int))(*((_DWORD *)&v14->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + v14->AvmObjOffset)
                                              + 4))((int)v14 + 4 * v14->AvmObjOffset)) != 0 )
  {
    v16 = (Scaleform::GFx::AS2::ObjectInterface *)(v17 + 4);
  }
  else
  {
    v16 = 0;
  }
  v18 = this->pMovieImpl;
  v19 = v18->MovieLevels.Data.Size;
  v20 = 0;
  if ( v19 )
  {
    v21 = v18->MovieLevels.Data.Data;
    v22 = v21;
    while ( v22->Level )
    {
      ++v20;
      ++v22;
      if ( v20 >= v19 )
        goto LABEL_23;
    }
    v23 = v21[v20].pSprite.pObject;
  }
  else
  {
LABEL_23:
    v23 = 0;
  }
  v24 = (int)v23 + 4 * v23->AvmObjOffset;
  v25 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v24 + 124))(v24);
  Scaleform::GFx::AS2::Value::Value(&method, &alias->Function);
  v26 = Scaleform::GFx::AS2::GAS_Invoke(
          &method,
          presult,
          v16,
          v25,
          numArgs,
          v25->Stack.pCurrent - v25->Stack.pPageStart + 32 * v25->Stack.Pages.Data.Size - 32,
          pmethodName);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  if ( pobj )
  {
    RefCount = pobj->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pobj->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pobj);
    }
  }
  return v26;
}
