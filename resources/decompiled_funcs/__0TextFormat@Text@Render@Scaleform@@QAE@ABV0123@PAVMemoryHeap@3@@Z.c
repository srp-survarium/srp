void __thiscall Scaleform::Render::Text::TextFormat::TextFormat(
        Scaleform::Render::Text::TextFormat *this,
        const Scaleform::Render::Text::TextFormat *srcfmt,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v3; // ebx
  Scaleform::MemoryHeap *v5; // eax
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // eax
  Scaleform::GFx::Resource *v7; // ecx

  v3 = pheap;
  this->RefCount = 1;
  v5 = pheap;
  if ( !pheap )
    v5 = srcfmt->FontList.pHeap;
  Scaleform::StringDH::CopyConstructHelper(&this->FontList, &srcfmt->FontList, v5);
  if ( !pheap )
    v3 = srcfmt->FontList.pHeap;
  Scaleform::StringDH::CopyConstructHelper(&this->Url, &srcfmt->Url, v3);
  pObject = srcfmt->pImageDesc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->pImageDesc.pObject = srcfmt->pImageDesc.pObject;
  v7 = (Scaleform::GFx::Resource *)srcfmt->pFontHandle.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::AddRef(v7);
  this->pFontHandle.pObject = srcfmt->pFontHandle.pObject;
  this->ColorV = srcfmt->ColorV;
  this->LetterSpacing = srcfmt->LetterSpacing;
  this->FontSize = srcfmt->FontSize;
  this->FormatFlags = srcfmt->FormatFlags;
  this->PresentMask = srcfmt->PresentMask;
}
