BOOL __cdecl Scaleform::Render::Text::SGMLElementDesc::Comparator<wchar_t>::Less(
        const Scaleform::Render::Text::SGMLElementDesc *a1,
        const Scaleform::Render::Text::SGMLElementDesc::Comparable<wchar_t> *a2)
{
  return (-Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(a2->Str, a1->ElemName, a2->Size) & 0x80000000) != 0;
}
