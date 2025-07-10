void __thiscall Scaleform::GFx::AS2::RemoveObjectEH::CheckEventHandlers(
        Scaleform::GFx::AS2::RemoveObjectEH *this,
        void **pse,
        Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *pevts)
{
  *pse = Scaleform::GFx::AS2::RemoveObjectEH::CheckEventHandlers(
           (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)*pse,
           pevts);
}
