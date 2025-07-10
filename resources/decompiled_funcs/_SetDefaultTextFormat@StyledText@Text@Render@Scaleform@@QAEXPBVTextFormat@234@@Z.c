void __thiscall Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *pdefaultTextFmt)
{
  Scaleform::Render::Text::TextFormat *v2; // edi
  char v4; // al
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *p_pImageDesc; // edx
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // esi
  Scaleform::Render::Text::TextFormat *v8; // esi

  v2 = pdefaultTextFmt;
  v4 = 0;
  if ( (pdefaultTextFmt->PresentMask & 0x200) != 0 )
  {
    v5 = (Scaleform::RefCountNTSImpl *)pdefaultTextFmt;
    p_pImageDesc = &pdefaultTextFmt->pImageDesc;
  }
  else
  {
    v5 = 0;
    v4 = 1;
    pdefaultTextFmt = 0;
    p_pImageDesc = (Scaleform::Ptr<Scaleform::Render::Text::HTMLImageTagDesc> *)&pdefaultTextFmt;
  }
  pObject = p_pImageDesc->pObject;
  if ( (v4 & 1) != 0 && v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  if ( pObject )
  {
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this, v2);
  }
  else
  {
    ++v2->RefCount;
    v8 = this->pDefaultTextFormat.pObject;
    if ( v8 )
    {
      if ( v8->RefCount-- == 1 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v8);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
    }
    this->pDefaultTextFormat.pObject = v2;
  }
}
