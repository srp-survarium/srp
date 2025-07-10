void __thiscall Scaleform::GFx::Text::EditorKit::ClearRestrict(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // ecx

  pObject = this->pRestrict.pObject;
  if ( pObject )
  {
    if ( this->pRestrict.Owner )
    {
      this->pRestrict.Owner = 0;
      Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor'(pObject, 1);
    }
    this->pRestrict.pObject = 0;
  }
  this->pRestrict.Owner = 0;
}
