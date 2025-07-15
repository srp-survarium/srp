char __thiscall Scaleform::GFx::AS2::MovieRoot::InvokeAlias(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *alias,
        Scaleform::GFx::AS2::Value *presult,
        int numArgs)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v7; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::CharacterHandle *pRCC; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v13; // edi
  Scaleform::GFx::InteractiveObject *v14; // ebp
  Scaleform::GFx::InteractiveObject *v15; // eax
  Scaleform::GFx::AS2::ObjectInterface *p_Finalize_GC; // edi
  int v17; // eax
  Scaleform::GFx::MovieImpl *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v21; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v22; // ecx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v24; // ecx
  Scaleform::GFx::AS2::Environment *v25; // esi
  char v26; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v29; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // [esp+20h] [ebp+8h]

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
  if ( alias->__vftable )
    alias->__vftable[1].ExecuteForEachChild_GC = (void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC))(((int)alias->__vftable[1].ExecuteForEachChild_GC + 1) & 0x8FFFFFFF);
  pRCC = (Scaleform::GFx::CharacterHandle *)alias->pRCC;
  v13 = alias->__vftable;
  v14 = 0;
  v30 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)alias->__vftable;
  if ( pRCC )
  {
    v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pRCC, this->pMovieImpl);
    if ( v15 )
      ++v15->RefCount;
    v14 = v15;
  }
  if ( v13 )
  {
    p_Finalize_GC = (Scaleform::GFx::AS2::ObjectInterface *)&v13[1].Finalize_GC;
  }
  else if ( v14
         && (v17 = (*(int (__thiscall **)(int))(*((_DWORD *)&v14->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + v14->AvmObjOffset)
                                              + 4))((int)v14 + 4 * v14->AvmObjOffset)) != 0 )
  {
    p_Finalize_GC = (Scaleform::GFx::AS2::ObjectInterface *)(v17 + 4);
  }
  else
  {
    p_Finalize_GC = 0;
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
    pObject = v21[v20].pSprite.pObject;
  }
  else
  {
LABEL_23:
    pObject = 0;
  }
  v24 = (int)pObject + 4 * pObject->AvmObjOffset;
  v25 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v24 + 124))(v24);
  Scaleform::GFx::AS2::Value::Value(&v29, (const Scaleform::GFx::AS2::FunctionRef *)&alias->8);
  v26 = Scaleform::GFx::AS2::GAS_Invoke(
          &v29,
          presult,
          p_Finalize_GC,
          v25,
          numArgs,
          v25->Stack.pCurrent - v25->Stack.pPageStart + 32 * v25->Stack.Pages.Data.Size - 32,
          pmethodName);
  if ( v29.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v29);
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  if ( v30 )
  {
    RefCount = v30->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v30->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
    }
  }
  return v26;
}
