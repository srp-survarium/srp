BOOL __thiscall Scaleform::GFx::Text::EditorKit::HasCompositionString(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::CompositionString *pObject; // ecx

  pObject = this->pComposStr.pObject;
  return pObject && pObject->GetLength(pObject);
}
