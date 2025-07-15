Scaleform::Render::TreeShape::NodeData *__thiscall Scaleform::Render::TreeShape::NodeData::operator=(
        Scaleform::Render::TreeShape::NodeData *this,
        const Scaleform::Render::TreeShape::NodeData *__that)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax
  Scaleform::Render::ShapeMeshProvider *v4; // eax

  Scaleform::Render::TreeNode::NodeData::operator=(this, __that);
  pObject = __that->pMeshProvider.pObject;
  if ( pObject )
    pObject->AddRef(&pObject->Scaleform::Render::MeshProvider);
  v4 = this->pMeshProvider.pObject;
  if ( v4 )
    v4->Release(&v4->Scaleform::Render::MeshProvider);
  this->pMeshProvider.pObject = __that->pMeshProvider.pObject;
  this->MorphRatio = __that->MorphRatio;
  return this;
}
