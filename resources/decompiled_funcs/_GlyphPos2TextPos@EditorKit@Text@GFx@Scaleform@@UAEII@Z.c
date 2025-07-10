int __thiscall Scaleform::GFx::Text::EditorKit::GlyphPos2TextPos(
        Scaleform::GFx::Text::EditorKit *this,
        unsigned int glyphPos)
{
  unsigned int v3; // esi
  Scaleform::GFx::Text::CompositionString *pObject; // edi
  int v5; // ebp
  unsigned int v6; // ebp
  Scaleform::GFx::Text::CompositionString_vtbl *v7; // eax

  if ( !this->HasCompositionString(this) )
    return glyphPos;
  v3 = glyphPos;
  if ( glyphPos <= this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) )
    return v3;
  pObject = this->pComposStr.pObject;
  v5 = pObject->GetPosition(pObject);
  v6 = pObject->GetLength(pObject) + v5;
  v7 = this->pComposStr.pObject->__vftable;
  if ( glyphPos >= v6 )
    return glyphPos - ((int (*)(void))v7->GetLength)();
  return ((int (*)(void))v7->GetPosition)();
}
