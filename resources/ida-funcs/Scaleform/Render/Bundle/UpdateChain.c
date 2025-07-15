void __thiscall Scaleform::Render::Bundle::UpdateChain(
        Scaleform::Render::Bundle *this,
        Scaleform::Render::BundleEntry *newTop)
{
  unsigned int v3; // edi
  Scaleform::Render::BundleEntry *i; // ebx
  unsigned int Size; // ecx
  unsigned int v6; // eax
  Scaleform::Render::BundleEntry **v7; // ecx
  unsigned int v8; // eax

  v3 = 0;
  this->NeedUpdate = 0;
  for ( i = newTop; i; ++v3 )
  {
    Size = this->Entries.Data.Size;
    if ( v3 >= Size || i != this->Entries.Data.Data[v3] )
    {
      if ( i->pBundle.pObject != this )
        goto LABEL_13;
      v6 = v3;
      if ( v3 < Size )
      {
        v7 = &this->Entries.Data.Data[v3];
        do
        {
          if ( *v7 == i )
            break;
          ++v6;
          ++v7;
        }
        while ( v6 < this->Entries.Data.Size );
        if ( v6 > v3 )
          this->RemoveEntries(this, v3, v6 - v3);
      }
      if ( v3 >= this->Entries.Data.Size || i != this->Entries.Data.Data[v3] )
      {
LABEL_13:
        Scaleform::Render::BundleEntry::SetBundle(i, this, v3);
        this->InsertEntry(this, v3, i);
      }
    }
    i = i->pChain;
  }
  v8 = this->Entries.Data.Size;
  if ( v3 < v8 )
    this->RemoveEntries(this, v3, v8 - v3);
  this->pTop = newTop;
}
