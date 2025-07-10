void __thiscall Scaleform::Render::TreeShape::NodeData::NodeData(
        Scaleform::Render::TreeShape::NodeData *this,
        const Scaleform::Render::TreeShape::NodeData *__that)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax

  Scaleform::Render::TreeNode::NodeData::NodeData(this, __that);
  this->__vftable = (Scaleform::Render::TreeShape::NodeData_vtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable';
  pObject = __that->pMeshProvider.pObject;
  if ( pObject )
    pObject->AddRef(&pObject->Scaleform::Render::MeshProvider);
  this->pMeshProvider.pObject = __that->pMeshProvider.pObject;
  this->MorphRatio = __that->MorphRatio;
}
