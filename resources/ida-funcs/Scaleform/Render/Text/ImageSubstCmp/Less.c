BOOL __cdecl Scaleform::Render::Text::ImageSubstCmp::Less(
        const Scaleform::Render::Text::DocView::ImageSubstitutor::Element *a1,
        const Scaleform::Render::Text::ImageSubstCmp::Comparable *a2)
{
  return (-Scaleform::Render::Text::ImageSubstCmp::StrCompare(a2->Str, a2->MaxSize, a1->SubString, a1->SubStringLen, 0)
        & 0x80000000) != 0;
}
