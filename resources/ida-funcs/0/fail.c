Scaleform::Render::Text::CompositionStringBase *(__thiscall *__thiscall Scaleform::GFx::TextField::GetBeginIndex(
        Scaleform::GFx::TextField *this))(Scaleform::Render::Text::EditorKitBase *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax
  Scaleform::Render::Text::EditorKitBase_vtbl *v2; // eax
  unsigned int v3; // ecx
  Scaleform::Render::Text::CompositionStringBase *(__thiscall *result)(Scaleform::Render::Text::EditorKitBase *); // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( !pObject )
    return 0;
  v2 = pObject[1].__vftable;
  v3 = (unsigned int)v2[1].~Scaleform::Render::Text::EditorKitBase;
  result = v2->GetCompositionString;
  if ( (unsigned int)result >= v3 )
    return (Scaleform::Render::Text::CompositionStringBase *(__thiscall *)(Scaleform::Render::Text::EditorKitBase *))v3;
  return result;
}


Scaleform::Render::Text::CompositionStringBase *(__thiscall *__thiscall Scaleform::GFx::TextField::GetEndIndex(
        Scaleform::GFx::TextField *this))(Scaleform::Render::Text::EditorKitBase *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax
  Scaleform::Render::Text::EditorKitBase_vtbl *v2; // eax
  unsigned int v3; // ecx
  Scaleform::Render::Text::CompositionStringBase *(__thiscall *result)(Scaleform::Render::Text::EditorKitBase *); // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( !pObject )
    return 0;
  v2 = pObject[1].__vftable;
  v3 = (unsigned int)v2[1].~Scaleform::Render::Text::EditorKitBase;
  result = v2->GetCompositionString;
  if ( v3 >= (unsigned int)result )
    return (Scaleform::Render::Text::CompositionStringBase *(__thiscall *)(Scaleform::Render::Text::EditorKitBase *))v3;
  return result;
}
