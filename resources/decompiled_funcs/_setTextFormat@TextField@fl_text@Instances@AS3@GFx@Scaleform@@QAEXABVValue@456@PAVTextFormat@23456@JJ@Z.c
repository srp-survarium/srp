void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::setTextFormat(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *format,
        int beginIndex,
        int endIndex)
{
  signed int v5; // ebx
  signed int v6; // edi
  Scaleform::GFx::TextField *pObject; // esi
  void (__thiscall *v8)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::MemoryHeap *v9; // eax
  Scaleform::Render::Text::ParagraphFormat paraFmt; // [esp+4h] [ebp-3Ch] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [esp+18h] [ebp-28h] BYREF

  if ( format )
  {
    v5 = beginIndex;
    if ( beginIndex == -1 )
      v5 = 0;
    v6 = endIndex;
    if ( endIndex == -1 )
      v6 = 0x7FFFFFFF;
    if ( v5 <= v6 )
    {
      pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
      v8 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
      v9 = (Scaleform::MemoryHeap *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)v8 + 188))(v8);
      Scaleform::Render::Text::TextFormat::TextFormat(&fmt, v9);
      paraFmt.RefCount = 1;
      memset(&paraFmt.pTabStops, 0, 16);
      Scaleform::GFx::AS3::Instances::fl_text::TextFormat::GetTextFormat(format, (signed int)&paraFmt, &fmt);
      Scaleform::Render::Text::DocView::SetTextFormat(pObject->pDocument.pObject, &fmt, v5, v6);
      Scaleform::Render::Text::DocView::SetParagraphFormat(pObject->pDocument.pObject, &paraFmt, v5, v6);
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&paraFmt);
      Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
    }
  }
}
