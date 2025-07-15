void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::defaultTextFormatSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *value)
{
  Scaleform::GFx::TextField *pObject; // esi
  void (__thiscall *v5)(Scaleform::GFx::AS3::VM *); // ecx
  Scaleform::MemoryHeap *v6; // eax
  Scaleform::Render::Text::DocView::DocumentText *v7; // eax
  Scaleform::Render::Text::ParagraphFormat *v8; // edi
  Scaleform::Render::Text::TextFormat *v9; // eax
  const Scaleform::Render::Text::ParagraphFormat *v10; // eax
  Scaleform::Render::Text::ParagraphFormat paraFmt; // [esp+8h] [ebp-64h] BYREF
  Scaleform::Render::Text::TextFormat v12; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [esp+44h] [ebp-28h] BYREF

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  if ( !Scaleform::GFx::TextField::HasStyleSheet(pObject) )
  {
    v5 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
    v6 = (Scaleform::MemoryHeap *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)v5 + 188))(v5);
    Scaleform::Render::Text::TextFormat::TextFormat(&fmt, v6);
    paraFmt.RefCount = 1;
    memset(&paraFmt.pTabStops, 0, 16);
    Scaleform::GFx::AS3::Instances::fl_text::TextFormat::GetTextFormat(value, (signed int)&paraFmt, &fmt);
    v7 = pObject->pDocument.pObject->pDocument.pObject;
    v8 = v7->pDefaultParagraphFormat.pObject;
    v9 = Scaleform::Render::Text::TextFormat::Merge(v7->pDefaultTextFormat.pObject, &v12, &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(pObject->pDocument.pObject->pDocument.pObject, v9);
    pObject->Flags |= (unsigned int)&_sbh_sizeHeaderList;
    Scaleform::Render::Text::TextFormat::~TextFormat(&v12);
    v10 = Scaleform::Render::Text::ParagraphFormat::Merge(
            v8,
            (Scaleform::Render::Text::ParagraphFormat *)&v12,
            &paraFmt);
    Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(pObject->pDocument.pObject->pDocument.pObject, v10);
    pObject->Flags |= (unsigned int)&_sbh_sizeHeaderList;
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&v12);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&paraFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
}
