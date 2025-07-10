void __thiscall Scaleform::Render::Renderer2DImpl::~Renderer2DImpl(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  this->Scaleform::Render::ContextImpl::RenderNotify::__vftable = (Scaleform::Render::Renderer2DImpl_vtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::ContextImpl::RenderNotify'};
  this->Scaleform::Render::HALNotify::__vftable = (Scaleform::Render::HALNotify_vtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::HALNotify'};
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(this);
  Scaleform::Render::MeshKeyManager::DestroyAllKeys(this->pMeshKeyManager.pObject);
  this->pPrev->pNext = this->pNext;
  this->pNext->pPrev = this->pPrev;
  pObject = (Scaleform::RefCountVImpl *)this->pGlyphCache.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->pMeshKeyManager.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::~MatrixPool(&this->MPool);
  this->FillManager.__vftable = (Scaleform::Render::PrimitiveFillManager_vtbl *)&Scaleform::Render::PrimitiveFillManager::`vftable';
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)&this->FillManager.Gradients);
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)&this->FillManager.FillSet);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->FillManager);
  this->StrokeGen.mPath.__vftable = (Scaleform::Render::VertexPath_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->StrokeGen.mStrokeSorter.__vftable = (Scaleform::Render::StrokeSorter_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->StrokeGen.mStroker.__vftable = (Scaleform::Render::Stroker_vtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->StrokeGen.Heap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->StrokeGen.Heap1);
  this->MeshGen.mStrokerAA.__vftable = (Scaleform::Render::StrokerAA_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->MeshGen.mHairliner.__vftable = (Scaleform::Render::Hairliner_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->MeshGen.mStrokeSorter.__vftable = (Scaleform::Render::StrokeSorter_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->MeshGen.mStroker.__vftable = (Scaleform::Render::Stroker_vtbl *)&Scaleform::Render::TessBase::`vftable';
  this->MeshGen.mTess.__vftable = (Scaleform::Render::Tessellator_vtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->MeshGen.Heap4);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->MeshGen.Heap3);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->MeshGen.Heap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->MeshGen.Heap1);
  v4 = (Scaleform::RefCountVImpl *)this->pHal.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->Scaleform::Render::HALNotify::__vftable = (Scaleform::Render::HALNotify_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::Render::ContextImpl::RenderNotify::~RenderNotify(this);
}
