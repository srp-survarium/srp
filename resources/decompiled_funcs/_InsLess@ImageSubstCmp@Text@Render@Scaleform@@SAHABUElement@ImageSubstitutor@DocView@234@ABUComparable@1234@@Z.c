BOOL __cdecl Scaleform::Render::Text::ImageSubstCmp::InsLess(
        const Scaleform::Render::Text::DocView::ImageSubstitutor::Element *p1,
        const Scaleform::Render::Text::ImageSubstCmp::Comparable *p2)
{
  return (-Scaleform::Render::Text::ImageSubstCmp::StrCompare(p2->Str, p2->MaxSize, p1->SubString, p1->SubStringLen, 1)
        & 0x80000000) != 0;
}
