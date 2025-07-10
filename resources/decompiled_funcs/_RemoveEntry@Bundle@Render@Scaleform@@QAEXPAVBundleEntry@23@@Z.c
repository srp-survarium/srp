void __thiscall Scaleform::Render::Bundle::RemoveEntry(
        Scaleform::Render::Bundle *this,
        Scaleform::Render::BundleEntry *entry)
{
  if ( Scaleform::Render::Bundle::findEntryIndex(this, (unsigned int *)&entry, entry) )
    this->RemoveEntries(this, (unsigned int)entry, 1u);
}
