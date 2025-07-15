void __thiscall Scaleform::GFx::DisplayObjectBase::Clear3D(Scaleform::GFx::DisplayObjectBase *this, bool bInherit)
{
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  Scaleform::Render::TreeNode *pObject; // ecx
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [esp+10h] [ebp-60h] BYREF

  if ( bInherit )
  {
    pParent = this->pParent;
    if ( pParent )
      Scaleform::GFx::DisplayObjectBase::Clear3D(pParent, bInherit);
  }
  gd.OrigMatrix.M[0][0] = 1.0;
  gd.OrigMatrix.M[0][1] = 0.0;
  gd.Y = 0;
  gd.OrigMatrix.M[0][2] = 0.0;
  gd.X = 0;
  gd.OrigMatrix.M[0][3] = 0.0;
  gd.OrigMatrix.M[1][0] = 0.0;
  gd.OrigMatrix.M[1][2] = 0.0;
  gd.OrigMatrix.M[1][3] = 0.0;
  gd.OrigMatrix.M[1][1] = 1.0;
  gd.Rotation = 0.0;
  gd.YScale = 100.0;
  gd.XScale = 100.0;
  gd.ZScale = 100.0;
  gd.YRotation = 0.0;
  gd.XRotation = 0.0;
  gd.Z = 0.0;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(this, &gd);
  pObject = this->pRenNode.pObject;
  if ( pObject )
    Scaleform::Render::TreeNode::Clear3D(pObject);
}
