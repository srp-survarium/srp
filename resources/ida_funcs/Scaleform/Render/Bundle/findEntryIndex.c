char __thiscall Scaleform::Render::Bundle::findEntryIndex(
        Scaleform::Render::Bundle *this,
        unsigned int *pindex,
        Scaleform::Render::BundleEntry *entry)
{
  unsigned int Size; // edx
  unsigned int IndexHint; // eax
  unsigned int v6; // eax
  Scaleform::Render::BundleEntry **i; // ecx

  Size = this->Entries.Data.Size;
  IndexHint = entry->IndexHint;
  if ( IndexHint < Size && this->Entries.Data.Data[IndexHint] == entry )
  {
    *pindex = IndexHint;
    return 1;
  }
  else
  {
    v6 = 0;
    if ( Size )
    {
      for ( i = this->Entries.Data.Data; *i != entry; ++i )
      {
        if ( ++v6 >= Size )
          return 0;
      }
      entry->IndexHint = v6;
      *pindex = v6;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
