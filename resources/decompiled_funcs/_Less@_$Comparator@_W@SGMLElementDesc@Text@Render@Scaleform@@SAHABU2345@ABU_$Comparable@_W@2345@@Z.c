BOOL __cdecl Scaleform::Render::Text::SGMLElementDesc::Comparator<wchar_t>::Less(
        const Scaleform::Render::Text::SGMLElementDesc *p1,
        const Scaleform::Render::Text::SGMLElementDesc::Comparable<wchar_t> *p2)
{
  return (-Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(p2->Str, p1->ElemName, (const char *)p2->Size)
        & 0x80000000) != 0;
}
