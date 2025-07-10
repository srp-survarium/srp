void __thiscall Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(
        Scaleform::GFx::AS2::TextFieldObject *this,
        Scaleform::GFx::Text::IMEStyle *imeStyles)
{
  Scaleform::GFx::Text::IMEStyle *pIMECompositionStringStyles; // ecx
  char *v4; // eax
  Scaleform::GFx::Text::IMEStyle *v5; // esi
  int v6; // [esp+4h] [ebp-4h] BYREF

  pIMECompositionStringStyles = this->pIMECompositionStringStyles;
  if ( pIMECompositionStringStyles )
  {
    Scaleform::GFx::Text::IMEStyle::operator=(pIMECompositionStringStyles, imeStyles);
  }
  else
  {
    v6 = 325;
    v4 = (char *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 84, &v6);
    v5 = (Scaleform::GFx::Text::IMEStyle *)v4;
    if ( v4 )
    {
      `vector copy constructor iterator'(
        v4,
        (char *)imeStyles,
        0x10u,
        5,
        (void *(__thiscall *)(void *, void *))Scaleform::Render::Text::HighlightInfo::HighlightInfo);
      v5->PresenceMask = imeStyles->PresenceMask;
      this->pIMECompositionStringStyles = v5;
    }
    else
    {
      this->pIMECompositionStringStyles = 0;
    }
  }
}
