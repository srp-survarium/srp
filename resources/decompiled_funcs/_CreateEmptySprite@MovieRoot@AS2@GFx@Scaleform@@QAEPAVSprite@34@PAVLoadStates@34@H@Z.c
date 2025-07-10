Scaleform::GFx::Sprite *__thiscall Scaleform::GFx::AS2::MovieRoot::CreateEmptySprite(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadStates *pls,
        int level)
{
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::MemoryHeap *v5; // ecx
  Scaleform::GFx::MovieDataDef *v6; // eax
  Scaleform::GFx::MovieDataDef *v7; // eax
  Scaleform::GFx::MovieDataDef *v8; // esi
  Scaleform::GFx::MovieDefImpl *v9; // eax
  Scaleform::GFx::MovieDefImpl *v10; // eax
  Scaleform::GFx::Resource *v11; // edi
  Scaleform::GFx::Sprite *Sprite; // ebp
  Scaleform::GFx::ResourceKey createKey; // [esp+10h] [ebp-8h] BYREF

  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&createKey, (char *)&buf, 0, 0, 0);
  pHeap = this->pMovieImpl->pHeap;
  v5 = pHeap;
  if ( !pHeap )
    v5 = Scaleform::Memory::pGlobalHeap;
  v6 = (Scaleform::GFx::MovieDataDef *)v5->Alloc(v5, 36u, 0);
  if ( !v6 )
    goto LABEL_8;
  Scaleform::GFx::MovieDataDef::MovieDataDef(v6, &createKey, MT_Empty, (char *)&buf, pHeap, 0, 0);
  v8 = v7;
  if ( !v7 )
    goto LABEL_8;
  Scaleform::GFx::MovieDataDef::LoadTaskData::InitEmptyMovieDef(v7->pData.pObject);
  Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, v8);
  v9 = (Scaleform::GFx::MovieDefImpl *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 32, 0);
  if ( !v9
    || (Scaleform::GFx::MovieDefImpl::MovieDefImpl(
          v9,
          v8,
          (Scaleform::GFx::Resource *)pls->pBindStates.pObject,
          (Scaleform::GFx::Resource *)pls->pLoaderImpl.pObject,
          0,
          (Scaleform::GFx::Resource *)this->pMovieImpl->pStateBag.pObject->pDelegate.pObject,
          this->pMovieImpl->pHeap,
          1,
          0),
        (v11 = v10) == 0) )
  {
    Scaleform::GFx::Resource::Release(v8);
LABEL_8:
    if ( createKey.pKeyInterface )
      createKey.pKeyInterface->Release(createKey.pKeyInterface, createKey.hKeyData);
    return 0;
  }
  Sprite = Scaleform::GFx::AS2::MovieRoot::CreateSprite(
             this,
             (int)this,
             (int)v10,
             v8,
             v10,
             0,
             (Scaleform::GFx::ResourceId)0x40000,
             1);
  Scaleform::GFx::AS2::AvmSprite::SetLevel(
    (Scaleform::GFx::AS2::AvmSprite *)(&Sprite->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + Sprite->AvmObjOffset),
    level);
  Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, level, Sprite);
  Scaleform::GFx::Resource::Release(v11);
  Scaleform::GFx::Resource::Release(v8);
  if ( createKey.pKeyInterface )
    createKey.pKeyInterface->Release(createKey.pKeyInterface, createKey.hKeyData);
  return Sprite;
}
