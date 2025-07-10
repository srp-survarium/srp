unsigned int __thiscall Scaleform::GFx::Text::EditorKit::TextPos2GlyphOffset(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int textPos)
{
  if ( this->HasCompositionString(this) && textPos > this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) )
    return textPos + this->pComposStr.pObject->GetLength(this->pComposStr.pObject);
  else
    return textPos;
}
