const Scaleform::Render::Text::SGMLElementDesc *__cdecl Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
        const wchar_t *lookForElemName,
        unsigned int nameSize,
        const Scaleform::Render::Text::SGMLElementDesc *ptable,
        unsigned int tableSize)
{
  unsigned int v4; // esi
  unsigned int v5; // eax
  const Scaleform::Render::Text::SGMLElementDesc *v6; // esi
  Scaleform::Render::Text::SGMLElementDesc::Comparable<wchar_t> val; // [esp+4h] [ebp-8h] BYREF

  v4 = tableSize;
  val.Str = lookForElemName;
  val.Size = nameSize;
  v5 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::Text::SGMLElementDesc const *,Scaleform::Render::Text::SGMLElementDesc::Comparable<wchar_t>,int (__cdecl *)(Scaleform::Render::Text::SGMLElementDesc const &,Scaleform::Render::Text::SGMLElementDesc::Comparable<wchar_t> const &)>(
         &ptable,
         0,
         tableSize,
         &val,
         Scaleform::Render::Text::SGMLElementDesc::Comparator<wchar_t>::Less);
  if ( v5 >= v4 )
    return 0;
  v6 = &ptable[v5];
  if ( Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(val.Str, v6->ElemName, val.Size) )
    return 0;
  else
    return v6;
}
