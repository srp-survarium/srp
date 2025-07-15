Scaleform::Render::TextMeshProvider *__thiscall Scaleform::Render::TreeCacheText::CreateMeshProvider(
        Scaleform::Render::TreeCacheText *this)
{
  Scaleform::Render::TextLayout *v2; // esi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // ecx
  unsigned __int16 Flags; // cx
  unsigned int v5; // eax
  __int64 v7; // [esp-14h] [ebp-D4h]
  Scaleform::Render::Viewport vp; // [esp+14h] [ebp-ACh] BYREF
  Scaleform::Render::Matrix4x4<float> m4; // [esp+40h] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> result; // [esp+80h] [ebp-40h] BYREF

  v2 = *(Scaleform::Render::TextLayout **)((*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                                                      + 4
                                                      * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000))
                                                       / 28)
                                                      + 20)
                                          & 0xFFFFFFFE)
                                         + 148);
  if ( v2 && this->pRoot )
  {
    memset((int)&m4, 0, sizeof(m4));
    pHandle = this->M.pHandle;
    m4.M[0][0] = 1.0;
    m4.M[1][1] = 1.0;
    m4.M[2][2] = 1.0;
    memset(&vp, 0, 16);
    m4.M[3][3] = 1.0;
    vp.Height = 1;
    vp.Width = 1;
    memset(&vp.ScissorLeft, 0, 20);
    if ( (pHandle->pHeader->Format & 0x10) != 0 )
    {
      Scaleform::Render::TreeCacheNode::GetViewProj(this, &result);
      Scaleform::Render::TreeCacheText::getMatrix4F(this, &m4, &result);
      qmemcpy(&vp, &Scaleform::Render::TreeCacheNode::GetNodeData(this->pRoot)[1].M34, sizeof(vp));
    }
    Flags = this->Flags;
    if ( (Flags & 0x40) != 0 )
      v5 = 2;
    else
      v5 = (Flags & 0xC) == 4;
    if ( (Flags & 0x80u) != 0 )
      v5 |= 8u;
    HIDWORD(v7) = &this->M;
    LODWORD(v7) = this->pRenderer2D;
    Scaleform::Render::TextMeshProvider::CreateMeshData(&this->TMProvider, v2, v7, &m4, &vp, v5);
  }
  if ( (this->TMProvider.Flags & 0x20) != 0 )
    this->UpdateDistanceFieldUniforms(this);
  if ( (this->TMProvider.Flags & 0x20) != 0 )
    return &this->TMProvider;
  else
    return 0;
}
