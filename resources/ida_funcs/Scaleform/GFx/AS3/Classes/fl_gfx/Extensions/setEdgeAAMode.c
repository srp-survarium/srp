void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::setEdgeAAMode(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *dispObj,
        unsigned int mode)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::Render::EdgeAAMode v6; // esi
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v8; // eax
  Scaleform::Render::TreeNode *v9; // eax

  pObject = dispObj->pDispObj.pObject;
  v6 = EdgeAA_Inherit;
  if ( mode == this->EDGEAA_DISABLE )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pObject);
    Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, EdgeAA_Disable);
  }
  else if ( mode == this->EDGEAA_ON )
  {
    v8 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pObject);
    Scaleform::Render::TreeNode::SetEdgeAAMode(v8, EdgeAA_On);
  }
  else
  {
    if ( mode == this->EDGEAA_OFF )
      v6 = EdgeAA_Off;
    v9 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pObject);
    Scaleform::Render::TreeNode::SetEdgeAAMode(v9, v6);
  }
}
