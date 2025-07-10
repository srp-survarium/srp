void __thiscall Scaleform::GFx::Button::ClearRenderTreeForState(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::Button::ButtonState state)
{
  Scaleform::GFx::Button::StateCharacters *v3; // esi
  Scaleform::Render::TreeContainer *pObject; // ebx
  unsigned int Size; // eax
  Scaleform::Render::TreeContainer *v6; // eax

  v3 = &this->States[state];
  if ( v3->pRenNode.pObject )
  {
    pObject = v3->pRenNode.pObject;
    Size = Scaleform::Render::TreeContainer::GetSize(v3->pRenNode.pObject);
    Scaleform::Render::TreeContainer::Remove(pObject, 0, Size);
    if ( v3->pRenNode.pObject->pParent )
    {
      v6 = this->GetRenderContainer(this);
      Scaleform::Render::TreeContainer::Remove(v6, 0, 1u);
    }
  }
}
