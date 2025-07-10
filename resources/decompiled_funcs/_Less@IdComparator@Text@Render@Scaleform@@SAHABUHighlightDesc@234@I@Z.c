BOOL __cdecl Scaleform::Render::Text::IdComparator::Less(
        const Scaleform::Render::Text::HighlightDesc *p1,
        unsigned int id)
{
  return (int)(p1->Id - id) < 0;
}
