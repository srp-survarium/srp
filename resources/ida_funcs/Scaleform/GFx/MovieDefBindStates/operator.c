BOOL __thiscall Scaleform::GFx::MovieDefBindStates::operator==(
        Scaleform::GFx::MovieDefBindStates *this,
        Scaleform::GFx::MovieDefBindStates *other)
{
  return this->pFileOpener.pObject == other->pFileOpener.pObject
      && this->pURLBulider.pObject == other->pURLBulider.pObject
      && this->pImageCreator.pObject == other->pImageCreator.pObject
      && this->pImportVisitor.pObject == other->pImportVisitor.pObject
      && this->pFontPackParams.pObject == other->pFontPackParams.pObject
      && this->pFontCompactorParams.pObject == other->pFontCompactorParams.pObject
      && this->pImagePackParams.pObject == other->pImagePackParams.pObject;
}
