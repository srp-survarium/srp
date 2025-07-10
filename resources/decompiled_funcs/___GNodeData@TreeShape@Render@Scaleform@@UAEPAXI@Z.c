Scaleform::Render::TreeShape::NodeData *__thiscall Scaleform::Render::TreeShape::NodeData::`scalar deleting destructor'(
        Scaleform::Render::TreeShape::NodeData *this,
        char a2)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax

  this->__vftable = (Scaleform::Render::TreeShape::NodeData_vtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable';
  pObject = this->pMeshProvider.pObject;
  if ( pObject )
    pObject->Release(&pObject->Scaleform::Render::MeshProvider);
  if ( this->States.ArraySize )
    Scaleform::Render::StateData::destroyBag_NotEmpty(&this->States);
  Scaleform::Render::ContextImpl::EntryData::~EntryData(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
