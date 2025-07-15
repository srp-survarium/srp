void __thiscall Scaleform::GFx::DrawTextImpl::SetDepth(Scaleform::GFx::DrawTextImpl *this, unsigned int newDepth)
{
  unsigned int v3; // ebp
  Scaleform::Render::TreeRoot *pObject; // edi
  unsigned int Size; // ebx

  v3 = this->GetDepth(this);
  pObject = this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject;
  Size = newDepth;
  if ( newDepth > Scaleform::Render::TreeContainer::GetSize(pObject) )
    Size = Scaleform::Render::TreeContainer::GetSize(pObject);
  Scaleform::Render::TreeContainer::Remove(pObject, v3, 1u);
  Scaleform::Render::TreeContainer::Insert(
    this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject,
    Size,
    (Scaleform::Render::TreeNodeArray *)this->pTextNode.pObject);
}
