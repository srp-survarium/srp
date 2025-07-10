Scaleform::GFx::TimelineSnapshot::SnapshotElement *__cdecl Scaleform::GFx::AS2::RemoveObjectEH::CheckEventHandlers(
        Scaleform::GFx::TimelineSnapshot::SnapshotElement *pse,
        Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *pevts)
{
  unsigned int Size; // edx
  int v3; // eax
  Scaleform::GFx::SwfEvent **i; // ecx

  Size = pevts->Data.Size;
  v3 = 0;
  if ( !Size )
    return pse;
  for ( i = pevts->Data.Data; ((*i)->Event.Id & 4) == 0; ++i )
  {
    if ( ++v3 >= Size )
      return pse;
  }
  pse->Flags |= 2u;
  return 0;
}
