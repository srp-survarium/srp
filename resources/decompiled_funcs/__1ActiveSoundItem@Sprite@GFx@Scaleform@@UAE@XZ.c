void __thiscall Scaleform::GFx::Sprite::ActiveSoundItem::~ActiveSoundItem(
        Scaleform::GFx::Sprite::ActiveSoundItem *this)
{
  Scaleform::Sound::SoundChannel *pObject; // ecx
  Scaleform::GFx::SoundResource *pResource; // eax
  Scaleform::GFx::SoundResource *v4; // eax
  Scaleform::RefCountVImpl *v5; // ecx

  pObject = this->pChannel.pObject;
  this->__vftable = (Scaleform::GFx::Sprite::ActiveSoundItem_vtbl *)&Scaleform::GFx::Sprite::ActiveSoundItem::`vftable';
  if ( pObject )
    pObject->Stop(pObject);
  pResource = this->pResource;
  if ( pResource )
  {
    --pResource->PlayingCount;
    v4 = this->pResource;
    if ( v4->PlayingCount <= 0 )
      v4->pSoundInfo.pObject->ReleaseResource(v4->pSoundInfo.pObject);
    Scaleform::GFx::Resource::Release(this->pResource);
  }
  v5 = (Scaleform::RefCountVImpl *)this->pChannel.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
