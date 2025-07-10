Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *__thiscall Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>::operator=(
        Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *this,
        const Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *__that)
{
  Scaleform::Render::Text::TextFormat *pObject; // eax
  Scaleform::Render::Text::TextFormat *v4; // edi

  this->Index = __that->Index;
  this->Length = __that->Length;
  pObject = __that->Data.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v4 = this->Data.pObject;
  if ( v4 )
  {
    if ( v4->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v4);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  this->Data.pObject = __that->Data.pObject;
  return this;
}
