void __thiscall Scaleform::GFx::StaticTextCharacter::SetFilters(
        Scaleform::GFx::StaticTextCharacter *this,
        const Scaleform::Render::FilterSet *filters)
{
  unsigned int i; // esi
  Scaleform::Render::Text::TextFilter v4; // [esp+8h] [ebp-48h] BYREF

  if ( filters )
  {
    Scaleform::Render::Text::TextFilter::TextFilter(&v4);
    for ( i = 0; i < filters->Filters.Data.Size; ++i )
      Scaleform::Render::Text::TextFilter::LoadFilterDesc(&v4, filters->Filters.Data.Data[i].pObject);
    this->SetTextFilters(this, &v4);
    Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&v4);
  }
}
