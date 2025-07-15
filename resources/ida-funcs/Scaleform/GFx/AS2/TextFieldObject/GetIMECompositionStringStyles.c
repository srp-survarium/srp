Scaleform::GFx::Text::IMEStyle *__thiscall Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(
        Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::GFx::AS2::TextFieldObject *pObject; // esi

  if ( this->pIMECompositionStringStyles )
    return this->pIMECompositionStringStyles;
  while ( 1 )
  {
    pObject = (Scaleform::GFx::AS2::TextFieldObject *)this->pProto.pObject;
    if ( !pObject || pObject->GetObjectType(&pObject->Scaleform::GFx::AS2::ObjectInterface) != Object_TextFieldASObject )
      break;
    this = pObject;
    if ( pObject->pIMECompositionStringStyles )
      return this->pIMECompositionStringStyles;
  }
  return 0;
}
