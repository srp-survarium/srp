void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::defaultTextFormatGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::Render::ContextImpl::EntryData *pNative; // eax
  int v3; // esi
  Scaleform::Render::Text::ParagraphFormat *v4; // edi

  pNative = this->pDispObj.pObject[1].pRenNode.pObject->pNative;
  v3 = *(_DWORD *)&pNative[3].Type;
  v4 = (Scaleform::Render::Text::ParagraphFormat *)pNative[3].__vftable;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
    result,
    (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.pHeap,
    0,
    0);
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat::SetTextFormat(
    (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)result->pObject,
    v4,
    v3);
}
