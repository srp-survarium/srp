BOOL __cdecl Scaleform::GFx::TimelineSnapshot::DepthLess(
        int depth,
        const Scaleform::GFx::TimelineSnapshot::SnapshotElement *pse)
{
  return depth < pse->Depth;
}
