void __thiscall Scaleform::GFx::TextField::ClearImageSubstitutor(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::DocView *pObject; // edi
  Scaleform::Render::Text::DocView::ImageSubstitutor *pImageSubstitutor; // esi

  pObject = this->pDocument.pObject;
  pImageSubstitutor = pObject->pImageSubstitutor;
  if ( pImageSubstitutor )
  {
    Scaleform::ConstructorMov<Scaleform::Render::Text::DocView::ImageSubstitutor::Element>::DestructArray(
      pImageSubstitutor->Elements.Data.Data,
      pImageSubstitutor->Elements.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImageSubstitutor->Elements.Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pImageSubstitutor);
  }
  pObject->pImageSubstitutor = 0;
}
