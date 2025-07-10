void __thiscall Scaleform::Render::PrimitiveFill::~PrimitiveFill(Scaleform::Render::PrimitiveFill *this)
{
  Scaleform::Render::PrimitiveFillManager *pManager; // eax
  const Scaleform::Render::VertexFormat **p_pFormat; // esi
  int i; // ebx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::Render::PrimitiveFill *key; // [esp+Ch] [ebp-4h] BYREF

  pManager = this->pManager;
  this->__vftable = (Scaleform::Render::PrimitiveFill_vtbl *)&Scaleform::Render::PrimitiveFill::`vftable';
  if ( pManager )
  {
    key = this;
    Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::PrimitiveFill *>(
      &pManager->FillSet,
      &key);
  }
  p_pFormat = &this->Data.pFormat;
  for ( i = 1; i >= 0; --i )
  {
    v5 = (Scaleform::RefCountVImpl *)*--p_pFormat;
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}
