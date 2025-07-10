void __thiscall Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>::~RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>(
        Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *this)
{
  Scaleform::Render::Text::TextFormat *pObject; // esi

  pObject = this->Data.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
}
