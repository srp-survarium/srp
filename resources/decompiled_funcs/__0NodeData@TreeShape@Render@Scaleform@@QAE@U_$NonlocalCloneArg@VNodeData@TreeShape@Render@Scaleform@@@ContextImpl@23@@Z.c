void __thiscall Scaleform::Render::TreeShape::NodeData::NodeData(
        Scaleform::Render::TreeShape::NodeData *this,
        Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeShape::NodeData> src)
{
  Scaleform::Render::TreeNode::NodeData::NodeData(
    this,
    (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)src.pC);
  this->__vftable = (Scaleform::Render::TreeShape::NodeData_vtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable';
  if ( src.pC->pMeshProvider.pObject )
    src.pC->pMeshProvider.pObject->AddRef(&src.pC->pMeshProvider.pObject->Scaleform::Render::MeshProvider);
  this->pMeshProvider.pObject = src.pC->pMeshProvider.pObject;
  this->MorphRatio = src.pC->MorphRatio;
}
