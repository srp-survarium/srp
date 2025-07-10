void __thiscall Scaleform::GFx::DisplayObjectBase::SetProjectionMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        const Scaleform::Render::Matrix4x4<float> *m)
{
  Scaleform::Render::TreeNode *pObject; // eax
  bool v4; // bl
  Scaleform::GFx::InteractiveObject *pParent; // esi
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi

  pObject = this->pRenNode.pObject;
  v4 = pObject
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x1000) != 0;
  pParent = this->pParent;
  if ( !pParent || !Scaleform::GFx::DisplayObjectBase::Has3D(this->pParent) || pParent->pPerspectiveData || v4 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetProjectionMatrix3D(RenderNode, m);
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( pMovieImpl )
    {
      if ( pMovieImpl->MovieLevels.Data.Data->pSprite.pObject == this )
      {
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(pMovieImpl->pRenderRoot.pObject, m);
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(pMovieImpl->pTopMostRoot.pObject, m);
      }
    }
  }
}
