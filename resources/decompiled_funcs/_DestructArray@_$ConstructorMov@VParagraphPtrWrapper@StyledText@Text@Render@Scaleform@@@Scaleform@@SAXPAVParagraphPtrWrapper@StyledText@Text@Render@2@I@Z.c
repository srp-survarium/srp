void __usercall Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper>::DestructArray(
        Scaleform::Render::Text::Paragraph *a1@<edi>,
        Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *p,
        unsigned int count)
{
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v3; // ebx
  unsigned int v4; // ebp
  Scaleform::Render::Text::Paragraph *pPara; // esi
  Scaleform::Render::Text::ParagraphFormat *pObject; // edi

  v3 = &p[count - 1];
  if ( count )
  {
    v4 = count;
    do
    {
      pPara = v3->pPara;
      if ( v3->pPara )
      {
        Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
          pPara->FormatInfo.Ranges.Data.Data,
          pPara->FormatInfo.Ranges.Data.Size);
        ((void (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *, Scaleform::Render::Text::Paragraph *))Scaleform::Memory::pGlobalHeap->Free)(
          Scaleform::Memory::pGlobalHeap,
          pPara->FormatInfo.Ranges.Data.Data,
          a1);
        pObject = pPara->pFormat.pObject;
        if ( pObject )
        {
          if ( pObject->RefCount-- == 1 )
          {
            Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
          }
        }
        Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pPara);
        a1 = pPara;
        ((void (__thiscall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->Free)(Scaleform::Memory::pGlobalHeap);
      }
      --v3;
      --v4;
    }
    while ( v4 );
  }
}
