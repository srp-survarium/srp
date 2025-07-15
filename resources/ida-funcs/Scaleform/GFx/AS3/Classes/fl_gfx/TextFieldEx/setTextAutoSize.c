void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setTextAutoSize(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *autoSz)
{
  Scaleform::GFx::TextField *pObject; // edi
  Scaleform::Render::Text::DocView *v5; // eax
  Scaleform::Render::Text::DocView *v6; // eax
  Scaleform::Render::Text::DocView *v7; // eax

  if ( LOBYTE(this->pTraits.pObject->pVM[1].ExceptionObj.Bonus.pWeakProxy) )
  {
    pObject = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
    if ( !strcmp(autoSz->pNode->pData, "none") )
    {
      v5 = pObject->pDocument.pObject;
      v5->AlignProps &= 0xCFu;
      v5->RTFlags |= 1u;
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
    else if ( !strcmp(autoSz->pNode->pData, "shrink") )
    {
      v6 = pObject->pDocument.pObject;
      v6->AlignProps = v6->AlignProps & 0xCF | 0x10;
      v6->RTFlags |= 1u;
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
    else
    {
      if ( Scaleform::GFx::ASString::operator==(autoSz, "fit") )
      {
        v7 = pObject->pDocument.pObject;
        v7->AlignProps = v7->AlignProps & 0xCF | 0x20;
        v7->RTFlags |= 1u;
      }
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
  }
}
