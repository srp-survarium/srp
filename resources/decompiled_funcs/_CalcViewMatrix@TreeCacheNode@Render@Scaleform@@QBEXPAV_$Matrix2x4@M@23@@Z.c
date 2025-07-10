void __thiscall Scaleform::Render::TreeCacheNode::CalcViewMatrix(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Matrix2x4<float> *pviewMatrix)
{
  int v2; // edi
  int v3; // edx
  Scaleform::Render::TreeCacheNode *pParent; // ecx
  Scaleform::Render::TreeCacheNode *v5; // edi

  v2 = (int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000);
  v3 = *(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14);
  pParent = this->pParent;
  *pviewMatrix = *(Scaleform::Render::Matrix2x4<float> *)((*(_DWORD *)(v3 + 4 * (v2 / 28) + 20) & 0xFFFFFFFE) + 16);
  if ( pParent )
  {
    v5 = pParent;
    do
    {
      Scaleform::Render::Matrix2x4<float>::Append(
        pviewMatrix,
        (const Scaleform::Render::Matrix2x4<float> *)((*(_DWORD *)(*(_DWORD *)(((int)v5->pNode & 0xFFFFF000) + 0x14)
                                                                 + 4
                                                                 * ((int)((int)&v5->pNode[-1]
                                                                        - ((int)v5->pNode & 0xFFFFF000))
                                                                  / 28)
                                                                 + 20)
                                                     & 0xFFFFFFFE)
                                                    + 16));
      v5 = v5->pParent;
    }
    while ( v5 );
  }
}
