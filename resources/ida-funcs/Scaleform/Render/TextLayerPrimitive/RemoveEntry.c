bool __thiscall Scaleform::Render::TextLayerPrimitive::RemoveEntry(
        Scaleform::Render::TextLayerPrimitive *this,
        Scaleform::Render::BundleEntry *e)
{
  unsigned int i; // edi
  unsigned int Size; // eax

  for ( i = 0; i < this->Entries.Data.Size; ++i )
  {
    if ( this->Entries.Data.Data[i] == e )
    {
      Size = this->Entries.Data.Size;
      if ( Size == 1 )
      {
        if ( (this->Entries.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
        {
          if ( this->Entries.Data.Data )
          {
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
            this->Entries.Data.Data = 0;
          }
          this->Entries.Data.Policy.Capacity = 0;
        }
        this->Entries.Data.Size = 0;
      }
      else
      {
        memmove((int)&this->Entries.Data.Data[i], (const __m128i *)&this->Entries.Data.Data[i + 1], 4 * (Size - i) - 4);
        --this->Entries.Data.Size;
      }
      Scaleform::Render::Primitive::Remove(this, i--, 1u);
    }
  }
  return 0;
}
