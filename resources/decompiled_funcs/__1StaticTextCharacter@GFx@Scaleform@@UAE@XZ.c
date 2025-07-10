void __thiscall Scaleform::GFx::StaticTextCharacter::~StaticTextCharacter(Scaleform::GFx::StaticTextCharacter *this)
{
  Scaleform::GFx::StaticTextCharacter::HighlightDesc *pHighlight; // edi
  Scaleform::GFx::StaticTextDef *pObject; // ecx

  pHighlight = this->pHighlight;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::StaticTextCharacter_vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pHighlight )
  {
    Scaleform::Memory::pGlobalHeap->Free(
      Scaleform::Memory::pGlobalHeap,
      pHighlight->HighlightManager.Highlighters.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pHighlight);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&this->Filter);
  Scaleform::Render::Text::LineBuffer::~LineBuffer(&this->TextGlyphRecords);
  pObject = this->pDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
}
