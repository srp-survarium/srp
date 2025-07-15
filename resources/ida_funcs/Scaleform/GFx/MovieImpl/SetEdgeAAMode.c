void __thiscall Scaleform::GFx::MovieImpl::SetEdgeAAMode(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::EdgeAAMode edgeAA)
{
  Scaleform::Render::TreeNode::SetEdgeAAMode(this->pRenderRoot.pObject, edgeAA);
}
