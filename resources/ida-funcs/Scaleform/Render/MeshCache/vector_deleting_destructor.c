Scaleform::Render::MeshCache *__thiscall Scaleform::Render::MeshCache::`vector deleting destructor'(
        Scaleform::Render::MeshCache *this,
        char a2)
{
  this->Scaleform::Render::CacheBase::__vftable = (Scaleform::Render::MeshCache_vtbl *)&Scaleform::Render::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  this->Scaleform::Render::MeshCacheConfig::__vftable = (Scaleform::Render::MeshCacheConfig_vtbl *)&Scaleform::Render::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)&this->BatchCacheItemHash);
  Scaleform::Render::MeshStagingBuffer::Reset(&this->StagingBuffer);
  this->Scaleform::Render::MeshCacheConfig::__vftable = (Scaleform::Render::MeshCacheConfig_vtbl *)&Scaleform::GFx::AMP::ConnStatusInterface::`vftable';
  this->Scaleform::Render::CacheBase::__vftable = (Scaleform::Render::MeshCache_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


Scaleform::Render::MeshCache *__thiscall Scaleform::Render::MeshCache::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::Render::MeshCache::`vector deleting destructor'((Scaleform::Render::MeshCache *)(this - 4), a2);
}
