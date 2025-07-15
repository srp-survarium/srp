Scaleform::Render::Text::ParagraphFormat *__thiscall Scaleform::Render::Text::Allocator::AllocateParagraphFormat(
        Scaleform::Render::Text::Allocator *this,
        const Scaleform::Render::Text::ParagraphFormat *srcfmt)
{
  const Scaleform::Render::Text::ParagraphFormat *v2; // ebx
  Scaleform::HashSetLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,78,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor> > *p_ParagraphFormatStorage; // edi
  signed int v5; // eax
  int v6; // eax
  Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor> >::TableType *pTable; // eax
  Scaleform::Render::Text::ParagraphFormat *v9; // eax
  const Scaleform::Render::Text::ParagraphFormat *v10; // eax
  const Scaleform::Render::Text::ParagraphFormat *v11; // esi

  v2 = srcfmt;
  p_ParagraphFormatStorage = &this->ParagraphFormatStorage;
  v5 = Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor>>::findIndex<Scaleform::Render::Text::ParagraphFormat const *>(
         &this->ParagraphFormatStorage,
         &srcfmt);
  if ( v5 >= 0 && (v6 = (int)&p_ParagraphFormatStorage->pTable[2] + 12 * v5) != 0 )
  {
    ++**(_DWORD **)v6;
    return *(Scaleform::Render::Text::ParagraphFormat **)v6;
  }
  else
  {
    pTable = p_ParagraphFormatStorage->pTable;
    if ( p_ParagraphFormatStorage->pTable )
      pTable = (Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor> >::TableType *)pTable->EntryCount;
    if ( (unsigned int)pTable >= this->ParagraphFormatStorageCap )
      Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(this, 0);
    v9 = (Scaleform::Render::Text::ParagraphFormat *)this->pHeap->Alloc(this->pHeap, 20, 0);
    if ( v9 )
    {
      Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(v9, v2);
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    srcfmt = v11;
    Scaleform::HashSetBase<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,78>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>,Scaleform::Render::Text::TextFormatPtrWrapper<Scaleform::Render::Text::ParagraphFormat>::HashFunctor>>::Set<Scaleform::Render::Text::ParagraphFormat *>(
      p_ParagraphFormatStorage,
      p_ParagraphFormatStorage,
      (Scaleform::Render::Text::ParagraphFormat **)&srcfmt);
    return (Scaleform::Render::Text::ParagraphFormat *)v11;
  }
}
