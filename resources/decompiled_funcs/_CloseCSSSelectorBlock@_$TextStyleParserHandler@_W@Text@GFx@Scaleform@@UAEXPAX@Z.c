void __thiscall Scaleform::GFx::Text::TextStyleParserHandler<wchar_t>::CloseCSSSelectorBlock(
        Scaleform::GFx::Text::TextStyleParserHandler<wchar_t> *this,
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *pdata)
{
  if ( !pdata->Size )
  {
    if ( !pdata->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        pdata,
        pdata,
        0);
    goto LABEL_8;
  }
  if ( (pdata->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_8:
    pdata->Size = 0;
    return;
  }
  if ( pdata->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pdata->Data);
    pdata->Data = 0;
  }
  pdata->Policy.Capacity = 0;
  pdata->Size = 0;
}
