void __thiscall Scaleform::GFx::Sprite::ActiveSounds::~ActiveSounds(Scaleform::GFx::Sprite::ActiveSounds *this)
{
  Scaleform::Sound::SoundChannel *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  unsigned int i; // edi
  Scaleform::GFx::ASSoundIntf *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  unsigned int Size; // eax
  Scaleform::Ptr<Scaleform::GFx::Sprite::ActiveSoundItem> *v8; // edi
  unsigned int v9; // ebx

  pObject = this->pStreamSound.pObject;
  if ( pObject )
  {
    pObject->Stop(pObject);
    v3 = (Scaleform::RefCountVImpl *)this->pStreamSound.pObject;
    if ( v3 )
      Scaleform::RefCountImpl::Release(v3);
    this->pStreamSound.pObject = 0;
  }
  for ( i = 0; i < this->ASSounds.Data.Size; ++i )
  {
    v5 = this->ASSounds.Data.Data[i];
    v5->ReleaseTarget(v5);
  }
  v6 = (Scaleform::RefCountVImpl *)this->pStreamSound.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ASSounds.Data.Data);
  Size = this->Sounds.Data.Size;
  v8 = &this->Sounds.Data.Data[Size - 1];
  if ( Size )
  {
    v9 = this->Sounds.Data.Size;
    do
    {
      if ( v8->pObject )
        Scaleform::RefCountNTSImpl::Release(v8->pObject);
      --v8;
      --v9;
    }
    while ( v9 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Sounds.Data.Data);
}
