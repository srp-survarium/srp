void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::Finalize_GC(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment> *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // eax

  pInterfaces = this->pInterfaces;
  if ( pInterfaces )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pInterfaces);
  }
  Scaleform::Render::Text::TextFormat::~TextFormat(&this->mTextFormat);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&this->mParagraphFormat);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
