void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx::setIMECandidateListStyle(
        Scaleform::GFx::AS3::Classes::fl_gfx::IMEEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle *style)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::MovieImpl *v4; // ecx
  unsigned int textColor; // edx
  unsigned int selectedTextColor; // edx
  unsigned int fontSize; // edx
  unsigned int backgroundColor; // edx
  unsigned int selectedBackgroundColor; // edx
  unsigned int indexBackgroundColor; // edx
  unsigned int selectedIndexBackgroundColor; // edx
  unsigned int readingWindowTextColor; // edx
  unsigned int readingWindowBackgroundColor; // edx
  unsigned int readingWindowFontSize; // eax
  Scaleform::GFx::IMECandidateListStyle st; // [esp+0h] [ebp-2Ch] BYREF

  pObject = this->pTraits.pObject;
  st.Flags = 0;
  v4 = (Scaleform::GFx::MovieImpl *)pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  if ( v4 )
  {
    textColor = style->textColor;
    if ( textColor != -1 )
    {
      st.Flags = 1;
      st.TextColor = textColor;
    }
    selectedTextColor = style->selectedTextColor;
    if ( selectedTextColor != -1 )
    {
      st.Flags |= 8u;
      st.SelectedTextColor = selectedTextColor;
    }
    fontSize = style->fontSize;
    if ( fontSize != -1 )
    {
      st.Flags |= 0x40u;
      st.FontSize = fontSize;
    }
    backgroundColor = style->backgroundColor;
    if ( backgroundColor != -1 )
    {
      st.Flags |= 2u;
      st.BackgroundColor = backgroundColor;
    }
    selectedBackgroundColor = style->selectedBackgroundColor;
    if ( selectedBackgroundColor != -1 )
    {
      st.Flags |= 0x10u;
      st.SelectedBackgroundColor = selectedBackgroundColor;
    }
    indexBackgroundColor = style->indexBackgroundColor;
    if ( indexBackgroundColor != -1 )
    {
      st.Flags |= 4u;
      st.IndexBackgroundColor = indexBackgroundColor;
    }
    selectedIndexBackgroundColor = style->selectedIndexBackgroundColor;
    if ( selectedIndexBackgroundColor != -1 )
    {
      st.Flags |= 0x20u;
      st.SelectedIndexBackgroundColor = selectedIndexBackgroundColor;
    }
    readingWindowTextColor = style->readingWindowTextColor;
    if ( readingWindowTextColor != -1 )
    {
      st.Flags |= 0x80u;
      st.ReadingWindowTextColor = readingWindowTextColor;
    }
    readingWindowBackgroundColor = style->readingWindowBackgroundColor;
    if ( readingWindowBackgroundColor != -1 )
    {
      st.Flags |= 0x100u;
      st.ReadingWindowBackgroundColor = readingWindowBackgroundColor;
    }
    readingWindowFontSize = style->readingWindowFontSize;
    if ( readingWindowFontSize != -1 )
    {
      st.Flags |= 0x200u;
      st.ReadingWindowFontSize = readingWindowFontSize;
    }
    Scaleform::GFx::MovieImpl::SetIMECandidateListStyle(v4, &st);
  }
}
