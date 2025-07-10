BOOL __cdecl Scaleform::GFx::DisplayList::DepthLess1(
        const Scaleform::GFx::DisplayList::DepthToIndexMapElem *de,
        int depth)
{
  return de->Depth < depth;
}
