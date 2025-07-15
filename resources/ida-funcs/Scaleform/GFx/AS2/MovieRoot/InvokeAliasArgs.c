char __thiscall Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *alias,
        Scaleform::GFx::AS2::Value *presult,
        const char *methodArgFmt,
        char *args)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int Size; // edx
  int v9; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // ecx
  Scaleform::GFx::CharacterHandle *pRCC; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v15; // esi
  Scaleform::GFx::InteractiveObject *v16; // edi
  Scaleform::GFx::InteractiveObject *v17; // eax
  Scaleform::GFx::AS2::ObjectInterface *p_Finalize_GC; // ebx
  int v19; // eax
  Scaleform::GFx::MovieImpl *v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v23; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *v24; // ecx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v26; // ecx
  Scaleform::GFx::AS2::Environment *v27; // esi
  char v28; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::MovieRoot *v30; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS2::Value v31; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v32; // [esp+24h] [ebp+8h]

  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v9 = 0;
  v30 = this;
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
  if ( alias->__vftable )
    alias->__vftable[1].ExecuteForEachChild_GC = (void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC))(((int)alias->__vftable[1].ExecuteForEachChild_GC + 1) & 0x8FFFFFFF);
  pRCC = (Scaleform::GFx::CharacterHandle *)alias->pRCC;
  v15 = alias->__vftable;
  v16 = 0;
  v32 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)alias->__vftable;
  if ( pRCC )
  {
    v17 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pRCC, this->pMovieImpl);
    if ( v17 )
      ++v17->RefCount;
    v16 = v17;
  }
  if ( v15 )
  {
    p_Finalize_GC = (Scaleform::GFx::AS2::ObjectInterface *)&v15[1].Finalize_GC;
  }
  else if ( v16
         && (v19 = (*(int (__thiscall **)(int))(*((_DWORD *)&v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + v16->AvmObjOffset)
                                              + 4))((int)v16 + 4 * v16->AvmObjOffset)) != 0 )
  {
    p_Finalize_GC = (Scaleform::GFx::AS2::ObjectInterface *)(v19 + 4);
  }
  else
  {
    p_Finalize_GC = 0;
  }
  v20 = v30->pMovieImpl;
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
        goto LABEL_23;
    }
    pObject = v23[v22].pSprite.pObject;
  }
  else
  {
LABEL_23:
    pObject = 0;
  }
  v26 = (int)pObject + 4 * pObject->AvmObjOffset;
  v27 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v26 + 124))(v26);
  Scaleform::GFx::AS2::Value::Value(&v31, (const Scaleform::GFx::AS2::FunctionRef *)&alias->8);
  v28 = Scaleform::GFx::AS2::GAS_InvokeParsed(&v31, presult, p_Finalize_GC, v27, methodArgFmt, args, pmethodName);
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
  if ( v16 )
    Scaleform::RefCountNTSImpl::Release(v16);
  if ( v32 )
  {
    RefCount = v32->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v32->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
    }
  }
  return v28;
}
