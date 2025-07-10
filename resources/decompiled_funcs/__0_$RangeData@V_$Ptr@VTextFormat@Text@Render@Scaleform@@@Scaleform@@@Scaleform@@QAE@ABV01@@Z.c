void __thiscall Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>(
        Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *this,
        const Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *__that)
{
  unsigned int Length; // edx
  Scaleform::Render::Text::TextFormat *pObject; // edx

  Length = __that->Length;
  this->Index = __that->Index;
  this->Length = Length;
  pObject = __that->Data.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->Data.pObject = __that->Data.pObject;
}
