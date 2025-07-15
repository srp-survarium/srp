Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::Allocator::AllocateTextFormat(
        Scaleform::Render::Text::Allocator *this,
        const Scaleform::Render::Text::TextFormat *srcfmt)
{
  const Scaleform::Render::Text::TextFormat *v2; // ebx
  Scaleform::HashSetLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,78,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> > *p_TextFormatStorage; // esi
  signed int v5; // eax
  int v6; // eax
  Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> >::TableType *pTable; // esi
  Scaleform::Render::Text::TextFormat *v9; // eax
  const Scaleform::Render::Text::TextFormat *v10; // eax
  const Scaleform::Render::Text::TextFormat *v11; // esi
  bool v12; // zf
  Scaleform::RefCountVImpl *pObject; // ecx

  v2 = srcfmt;
  if ( (srcfmt->PresentMask & 0x200) == 0 )
  {
    p_TextFormatStorage = &this->TextFormatStorage;
    v5 = Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor>>::findIndex<Scaleform::Render::Text::TextFormat const *>(
           &this->TextFormatStorage,
           (Scaleform::Render::Text::TextFormat **)&srcfmt);
    if ( v5 >= 0 )
    {
      v6 = (int)&p_TextFormatStorage->pTable[2] + 12 * v5;
      if ( v6 )
      {
        ++**(_DWORD **)v6;
        return *(Scaleform::Render::Text::TextFormat **)v6;
      }
    }
    pTable = p_TextFormatStorage->pTable;
    if ( pTable )
      pTable = (Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor> >::TableType *)pTable->EntryCount;
    if ( (unsigned int)pTable >= this->TextFormatStorageCap )
      Scaleform::Render::Text::Allocator::FlushTextFormatCache(this, 0);
  }
  v9 = (Scaleform::Render::Text::TextFormat *)this->pHeap->Alloc(this->pHeap, 40, 0);
  if ( v9 )
  {
    Scaleform::Render::Text::TextFormat::TextFormat(v9, v2, this->pHeap);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  v12 = (this->Flags & 1) == 0;
  srcfmt = v11;
  if ( !v12 && (v11->PresentMask & 0x800) != 0 )
  {
    pObject = (Scaleform::RefCountVImpl *)v11->pFontHandle.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    v11->pFontHandle.pObject = 0;
    v11->PresentMask &= ~0x800u;
  }
  if ( (v2->PresentMask & 0x200) == 0 )
    Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::TextFormat>::HashFunctor>>::Set<Scaleform::Render::Text::TextFormat *>(
      &this->TextFormatStorage,
      &this->TextFormatStorage,
      (Scaleform::Render::Text::TextFormat **)&srcfmt);
  return (Scaleform::Render::Text::TextFormat *)v11;
}
