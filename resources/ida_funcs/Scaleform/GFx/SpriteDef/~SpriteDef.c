void __thiscall Scaleform::GFx::SpriteDef::~SpriteDef(Scaleform::GFx::SpriteDef *this)
{
  unsigned int v2; // edi
  Scaleform::GFx::SoundStreamDef *pObject; // ecx

  v2 = 0;
  for ( this->__vftable = (Scaleform::GFx::SpriteDef_vtbl *)&Scaleform::GFx::SpriteDef::`vftable';
        v2 < this->Playlist.Data.Size;
        ++v2 )
  {
    Scaleform::GFx::TimelineDef::Frame::DestroyTags(&this->Playlist.Data.Data[v2]);
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pScale9Grid);
  pObject = this->pSoundStream.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Playlist.Data.Data);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->NamedFrames);
  this->__vftable = (Scaleform::GFx::SpriteDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
}
