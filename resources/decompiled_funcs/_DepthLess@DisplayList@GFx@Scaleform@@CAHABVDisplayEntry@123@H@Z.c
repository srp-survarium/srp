BOOL __cdecl Scaleform::GFx::DisplayList::DepthLess(const Scaleform::GFx::DisplayList::DisplayEntry *de, int depth)
{
  return de->pCharacter->Depth < depth;
}
