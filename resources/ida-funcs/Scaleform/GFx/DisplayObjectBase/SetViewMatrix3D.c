void __thiscall Scaleform::GFx::DisplayObjectBase::SetViewMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::TreeNode *pObject; // eax
  bool v4; // bl
  Scaleform::GFx::InteractiveObject *pParent; // esi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v6; // eax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  double Width; // st7
  double Height; // st6
  Scaleform::Render::TreeNode *RenderNode; // eax
  int v12; // [esp+9Ch] [ebp-C4h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [esp+A0h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+D0h] [ebp-90h] BYREF
  Scaleform::Render::Matrix3x4<float> mat3D; // [esp+100h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+130h] [ebp-30h] BYREF

  pObject = this->pRenNode.pObject;
  v4 = pObject
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x800) != 0;
  pParent = this->pParent;
  if ( !pParent || !Scaleform::GFx::DisplayObjectBase::Has3D(this->pParent) || pParent->pPerspectiveData || v4 )
  {
    if ( !this->pPerspectiveData )
    {
      v12 = 322;
      v6 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       this,
                                                                       80,
                                                                       &v12);
      if ( v6 )
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v6);
      else
        v7 = 0;
      this->pPerspectiveData = v7;
    }
    memcpy(
      (unsigned __int8 *)&this->pPerspectiveData->ViewMatrix3D,
      (unsigned __int8 *)m,
      sizeof(this->pPerspectiveData->ViewMatrix3D));
    pMovieImpl = this->pASRoot->pMovieImpl;
    memset((int)&dst, 0, sizeof(dst));
    Width = (double)pMovieImpl->mViewport.Width;
    *(float *)&v12 = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
    dst.M[0][0] = 1.0 / (Width / *(float *)&v12);
    Height = (double)pMovieImpl->mViewport.Height;
    *(float *)&v12 = pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1;
    dst.M[1][1] = 1.0 / (Height / *(float *)&v12);
    dst.M[2][2] = 1.0;
    memset((int)&m1, 0, sizeof(m1));
    m1.M[0][0] = 1.0;
    m1.M[1][1] = 1.0;
    m1.M[2][2] = 1.0;
    m1.M[0][3] = pMovieImpl->VisibleFrameRect.x1;
    m1.M[1][3] = pMovieImpl->VisibleFrameRect.y1;
    m1.M[2][3] = 0.0;
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&m2, &m1, &dst);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&mat3D, m, &m2);
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetViewMatrix3D(RenderNode, &mat3D);
    if ( pMovieImpl->MovieLevels.Data.Data->pSprite.pObject == this )
    {
      Scaleform::Render::TreeNode::SetViewMatrix3D(pMovieImpl->pRenderRoot.pObject, &mat3D);
      Scaleform::Render::TreeNode::SetViewMatrix3D(pMovieImpl->pTopMostRoot.pObject, &mat3D);
    }
  }
}
