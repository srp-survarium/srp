Scaleform::Render::Text::DocView::ImageSubstitutor *__thiscall Scaleform::GFx::TextField::CreateImageSubstitutor(
        Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::DocView *pObject; // esi
  Scaleform::Render::Text::DocView::ImageSubstitutor *result; // eax

  pObject = this->pDocument.pObject;
  if ( !pObject->pImageSubstitutor )
  {
    result = (Scaleform::Render::Text::DocView::ImageSubstitutor *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                     Scaleform::Memory::pGlobalHeap,
                                                                     12,
                                                                     0);
    if ( result )
    {
      result->Elements.Data.Data = 0;
      result->Elements.Data.Size = 0;
      result->Elements.Data.Policy.Capacity = 0;
      pObject->pImageSubstitutor = result;
      return result;
    }
    pObject->pImageSubstitutor = 0;
  }
  return pObject->pImageSubstitutor;
}
