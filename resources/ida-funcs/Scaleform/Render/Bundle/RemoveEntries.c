void __thiscall Scaleform::Render::Bundle::RemoveEntries(
        Scaleform::Render::Bundle *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::Render::Bundle *v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // ebp
  Scaleform::Render::BundleEntry *v6; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Entries; // esi
  unsigned int Size; // eax

  v3 = this;
  if ( count )
  {
    v4 = index;
    v5 = count;
    do
    {
      v6 = v3->Entries.Data.Data[v4];
      pObject = v6->pBundle.pObject;
      if ( pObject )
      {
        Scaleform::RefCountNTSImpl::Release(pObject);
        v3 = this;
      }
      ++v4;
      --v5;
      v6->pBundle.pObject = 0;
      v6->IndexHint = 0;
    }
    while ( v5 );
  }
  p_Entries = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Entries;
  Size = v3->Entries.Data.Size;
  if ( Size != count )
  {
    memmove((int)&p_Entries->Data[index], (const __m128i *)&p_Entries->Data[index + count], 4 * (Size - index - count));
    p_Entries->Size -= count;
    return;
  }
  if ( !Size )
  {
    if ( !p_Entries->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Entries,
        p_Entries,
        0);
    goto LABEL_14;
  }
  if ( (p_Entries->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_14:
    p_Entries->Size = 0;
    return;
  }
  if ( p_Entries->Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Entries->Data);
    p_Entries->Data = 0;
  }
  p_Entries->Policy.Capacity = 0;
  p_Entries->Size = 0;
}
