void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::appendText(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *newText)
{
  Scaleform::GFx::TextField *pObject; // esi

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  if ( !Scaleform::GFx::TextField::HasStyleSheet(pObject) )
  {
    Scaleform::Render::Text::DocView::AppendText(pObject->pDocument.pObject, newText->pNode->pData, 0xFFFFFFFF);
    pObject->Flags |= (unsigned int)&_sbh_sizeHeaderList;
    Scaleform::GFx::TextField::SetDirtyFlag(pObject);
  }
}
