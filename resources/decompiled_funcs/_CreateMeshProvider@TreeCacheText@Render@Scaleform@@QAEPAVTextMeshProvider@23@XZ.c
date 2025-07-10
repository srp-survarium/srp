Scaleform::Render::TextMeshProvider *__thiscall Scaleform::Render::TreeCacheText::CreateMeshProvider(
        Scaleform::Render::TreeCacheText *this)
{
  const Scaleform::Render::TextLayout *v2; // esi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // ecx
  unsigned __int16 Flags; // cx
  unsigned int v5; // eax
  Scaleform::Render::Viewport v7; // [esp+230h] [ebp-ACh] BYREF
  Scaleform::Render::Matrix4x4<float> dst; // [esp+25Ch] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> result; // [esp+29Ch] [ebp-40h] BYREF

  v2 = *(const Scaleform::Render::TextLayout **)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                                                            + 4
                                                            * ((int)((int)&this->pNode[-1]
                                                                   - ((int)this->pNode & 0xFFFFF000))
                                                             / 28)
                                                            + 20)
                                                & 0xFFFFFFFE)
                                               + 148);
  if ( v2 && this->pRoot )
  {
    memset((int)&dst, 0, sizeof(dst));
    pHandle = this->M.pHandle;
    dst.M[0][0] = 1.0;
    dst.M[1][1] = 1.0;
    dst.M[2][2] = 1.0;
    memset(&v7, 0, 16);
    dst.M[3][3] = 1.0;
    v7.Height = 1;
    v7.Width = 1;
    memset(&v7.ScissorLeft, 0, 20);
    if ( (pHandle->pHeader->Format & 0x10) != 0 )
    {
      Scaleform::Render::TreeCacheNode::GetViewProj(this, &result);
      Scaleform::Render::TreeCacheText::getMatrix4F(this, &dst, &result);
      qmemcpy(&v7, &Scaleform::Render::TreeCacheNode::GetNodeData(this->pRoot)[1].M34, sizeof(v7));
    }
    Flags = this->Flags;
    if ( (Flags & 0x40) != 0 )
      v5 = 2;
    else
      v5 = (Flags & 0xC) == 4;
    if ( (Flags & 0x80u) != 0 )
      v5 |= 8u;
    Scaleform::Render::TextMeshProvider::CreateMeshData(
      &this->TMProvider,
      v2,
      this->pRenderer2D,
      &this->M,
      &dst,
      &v7,
      v5);
  }
  if ( (this->TMProvider.Flags & 0x20) != 0 )
    this->UpdateDistanceFieldUniforms(this);
  if ( (this->TMProvider.Flags & 0x20) != 0 )
    return &this->TMProvider;
  else
    return 0;
}
