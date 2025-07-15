void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setVerticalAlign(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_text::TextField *textField,
        Scaleform::GFx::ASString *valign)
{
  Scaleform::GFx::TextField *pObject; // edi
  Scaleform::Render::Text::DocView *v5; // eax
  Scaleform::Render::Text::DocView *v6; // eax
  unsigned __int8 AlignProps; // cl
  Scaleform::Render::Text::DocView *v8; // eax
  unsigned __int8 v9; // dl

  if ( *(&this->pTraits.pObject->pVM[1].HandleException + 4) )
  {
    pObject = (Scaleform::GFx::TextField *)textField->pDispObj.pObject;
    if ( !strcmp(valign->pNode->pData, "none") )
    {
      v5 = pObject->pDocument.pObject;
      v5->AlignProps &= 0xF3u;
      v5->RTFlags |= 1u;
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
    else if ( !strcmp(valign->pNode->pData, "top") )
    {
      v6 = pObject->pDocument.pObject;
      AlignProps = v6->AlignProps;
      v6->RTFlags |= 1u;
      v6->AlignProps = AlignProps & 0xF3 | 4;
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
    else if ( Scaleform::GFx::ASString::operator==(valign, "bottom") )
    {
      v8 = pObject->pDocument.pObject;
      v9 = v8->AlignProps;
      v8->RTFlags |= 1u;
      v8->AlignProps = v9 & 0xF3 | 8;
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
    else
    {
      if ( Scaleform::GFx::ASString::operator==(valign, "center") )
        Scaleform::GFx::TextField::SetVAlignment(pObject, VAlign_Bottom|VAlign_Center);
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
    }
  }
}
