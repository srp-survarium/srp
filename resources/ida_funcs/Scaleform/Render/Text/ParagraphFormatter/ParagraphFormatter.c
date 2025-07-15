void __thiscall Scaleform::Render::Text::ParagraphFormatter::ParagraphFormatter(
        Scaleform::Render::Text::ParagraphFormatter *this,
        Scaleform::Render::Text::DocView *pdoc,
        Scaleform::Log *plog)
{
  Scaleform::Render::Text::Allocator *pObject; // ecx
  Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::RefCountVImpl *v6; // ecx

  this->pDocView = pdoc;
  this->pParagraph = 0;
  this->pParaFormat = 0;
  this->pTempLine = 0;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->LineCursor);
  pObject = pdoc->pDocument.pObject->pTextAllocator.pObject;
  if ( pObject )
    pHeap = pObject->pHeap;
  else
    pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, pdoc->pDocument.pObject);
  this->FontCache.mHash.pTable = 0;
  this->FontCache.mHash.pHeap = pHeap;
  this->FindFontInfo.pFontCache = &this->FontCache;
  this->FindFontInfo.pCurrentFont.pObject = 0;
  this->FindFontInfo.pPrevFormat = 0;
  this->FindFontInfo.pCurrentFormat = 0;
  v6 = (Scaleform::RefCountVImpl *)this->FindFontInfo.pCurrentFont.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->FindFontInfo.pCurrentFont.pObject = 0;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->StartPoint);
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->HalfPoint);
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&this->WordWrapPoint);
  this->pFontHandle.pObject = 0;
  this->pDynLine = 0;
  this->ParaYOffset = 0;
  this->NextOffsetY = 0;
  this->NeedRecenterLines = 0;
  this->ForceVerticalCenterAutoSize = 0;
  this->pLog = plog;
}
