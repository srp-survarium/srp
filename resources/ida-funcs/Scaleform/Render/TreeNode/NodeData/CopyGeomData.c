void __thiscall Scaleform::Render::TreeNode::NodeData::CopyGeomData(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::TreeNode *destNode,
        Scaleform::Render::TreeNode *srcNode)
{
  Scaleform::Render::ContextImpl::Entry *pParent; // ecx
  int v5; // eax
  unsigned int State; // eax
  void *v7; // esi
  Scaleform::Render::StateBag *v8; // ecx
  int v9; // [esp+Ch] [ebp-54h]
  Scaleform::Render::Rect<float> result; // [esp+10h] [ebp-50h] BYREF
  Scaleform::Render::Matrix4x4<float> mat3D; // [esp+20h] [ebp-40h] BYREF

  if ( destNode != srcNode )
  {
    v9 = *(_DWORD *)(*(_DWORD *)(((unsigned int)srcNode & 0xFFFFF000) + 0x10)
                   + 4 * ((int)((int)&srcNode[-1] - ((unsigned int)srcNode & 0xFFFFF000)) / 28)
                   + 20);
    if ( ((LOBYTE(this->Flags) ^ *(_BYTE *)(v9 + 6)) & 1) != 0 )
    {
      Scaleform::Render::TreeNode::SetVisible(
        destNode,
        *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)srcNode & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&srcNode[-1] - ((unsigned int)srcNode & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 1);
      pParent = destNode->pParent;
      if ( pParent )
      {
        if ( !pParent->PNode.pPrev )
          Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(pParent);
      }
    }
    v5 = v9;
    if ( (*(_WORD *)(v9 + 6) & 0x200) != 0 )
    {
      memcpy((int)&this->M34, (const __m128i *)(v9 + 16), sizeof(this->M34));
      this->Flags |= 0x200u;
      memset((int)&mat3D, 0, sizeof(mat3D));
      mat3D.M[0][0] = 1.0;
      mat3D.M[1][1] = 1.0;
      mat3D.M[2][2] = 1.0;
      mat3D.M[3][3] = 1.0;
      if ( Scaleform::Render::TreeNode::GetProjectionMatrix3D(srcNode, &mat3D) )
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(destNode, &mat3D);
      memset((int)&mat3D, 0, 48);
      mat3D.M[0][0] = 1.0;
      mat3D.M[1][1] = 1.0;
      mat3D.M[2][2] = 1.0;
      if ( Scaleform::Render::TreeNode::GetViewMatrix3D(srcNode, (Scaleform::Render::Matrix3x4<float> *)&mat3D) )
        Scaleform::Render::TreeNode::SetViewMatrix3D(destNode, (const Scaleform::Render::Matrix3x4<float> *)&mat3D);
      v5 = v9;
    }
    else
    {
      this->M34.M[0][0] = *(float *)(v9 + 16);
      this->M34.M[0][1] = *(float *)(v9 + 20);
      this->M34.M[0][2] = *(float *)(v9 + 24);
      this->M34.M[0][3] = *(float *)(v9 + 28);
      this->M34.M[1][0] = *(float *)(v9 + 32);
      this->M34.M[1][1] = *(float *)(v9 + 36);
      this->M34.M[1][2] = *(float *)(v9 + 40);
      this->M34.M[1][3] = *(float *)(v9 + 44);
    }
    qmemcpy(&this->Cx, (const void *)(v5 + 80), sizeof(this->Cx));
    State = Scaleform::Render::StateBag::GetState(
              (Scaleform::Render::StateBag *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)srcNode & 0xFFFFF000) + 0x10)
                                                        + 4
                                                        * ((int)((int)&srcNode[-1] - ((unsigned int)srcNode & 0xFFFFF000))
                                                         / 28)
                                                        + 20)
                                            + 64),
              State_Translator);
    if ( State )
      v7 = *(void **)(State + 4);
    else
      v7 = 0;
    v8 = (Scaleform::Render::StateBag *)&Scaleform::Render::ContextImpl::Entry::getWritableData(
                                           destNode,
                                           (unsigned int)&loc_20000)[8];
    if ( v7 )
      Scaleform::Render::StateBag::SetStateVoid(v8, &Scaleform::Render::BlendState::InterfaceImpl, v7);
    else
      Scaleform::Render::StateBag::RemoveState(v8, State_Translator);
    Scaleform::Render::TreeNode::GetScale9Grid(srcNode, &result);
    if ( result.x2 > (double)result.x1 && result.y2 > (double)result.y1 )
      Scaleform::Render::TreeNode::SetScale9Grid(destNode, &result);
  }
}
