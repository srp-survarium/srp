void __thiscall Scaleform::GFx::FontGlyphPacker::~FontGlyphPacker(Scaleform::GFx::FontGlyphPacker *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx

  this->__vftable = (Scaleform::GFx::FontGlyphPacker_vtbl *)&Scaleform::GFx::FontGlyphPacker::`vftable';
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>,Scaleform::HashNode<Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey,unsigned int,Scaleform::GFx::FontGlyphPacker::GlyphGeometryKey>::NodeHashF>>::Clear(&this->GlyphGeometryHash.mHash);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Ras.LHeap);
  this->Ras.__vftable = (Scaleform::Render::Rasterizer_vtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->Packer.Failed);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->Packer.PackTree);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->Packer.Packs);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->Packer.PackedRects);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->Packer.SrcRects);
  pObject = (Scaleform::RefCountVImpl *)this->pLog.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->pImageCreator.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
