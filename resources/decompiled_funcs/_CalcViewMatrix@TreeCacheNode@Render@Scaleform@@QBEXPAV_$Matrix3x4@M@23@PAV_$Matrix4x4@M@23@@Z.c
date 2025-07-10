void __thiscall Scaleform::Render::TreeCacheNode::CalcViewMatrix(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Matrix3x4<float> *pviewMatrix,
        Scaleform::Render::Matrix4x4<float> *pviewProj)
{
  Scaleform::Render::TreeNode *pNode; // eax
  unsigned int v5; // esi
  Scaleform::Render::TreeCacheNode **i; // ebx
  Scaleform::Render::TreeCacheNode *v7; // ebx
  unsigned int v8; // esi
  int v9; // edi
  unsigned int State; // [esp+184h] [ebp-B8h]
  unsigned int v11; // [esp+188h] [ebp-B4h]
  Scaleform::Render::Matrix3x4<float> dst; // [esp+18Ch] [ebp-B0h] BYREF
  Scaleform::Render::Matrix4x4<float> m1; // [esp+1BCh] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> v14; // [esp+1FCh] [ebp-40h] BYREF

  pNode = this->pNode;
  if ( !pNode )
  {
    v5 = 0;
LABEL_6:
    State = 0;
    goto LABEL_7;
  }
  v5 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                 + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28)
                 + 20)
     & 0xFFFFFFFE;
  if ( !v5 || (*(_WORD *)(v5 + 6) & 0x800) == 0 )
    goto LABEL_6;
  State = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v5 + 64), State_FSCommandHandler);
LABEL_7:
  if ( v5 && (*(_WORD *)(v5 + 6) & 0x1000) != 0 )
    v11 = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v5 + 64), State_ExternalInterface);
  else
    v11 = 0;
  memcpy((unsigned __int8 *)pviewMatrix, (unsigned __int8 *)(v5 + 16), sizeof(Scaleform::Render::Matrix3x4<float>));
  for ( i = &this->pParent; *i; i = &v7->pParent )
  {
    v7 = *i;
    v8 = (int)v7->pNode & 0xFFFFF000;
    v9 = (int)((int)&v7->pNode[-1] - v8) / 28;
    memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)pviewMatrix, sizeof(dst));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
      pviewMatrix,
      (const Scaleform::Render::Matrix3x4<float> *)((*(_DWORD *)(*(_DWORD *)(v8 + 20) + 4 * v9 + 20) & 0xFFFFFFFE) + 16),
      &dst);
    if ( !State
      && (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v7->pNode & 0xFFFFF000) + 0x14)
                                + 4 * ((int)((int)&v7->pNode[-1] - ((int)v7->pNode & 0xFFFFF000)) / 28)
                                + 20)
                    & 0xFFFFFFFE)
                   + 6)
        & 0x800) != 0 )
    {
      State = Scaleform::Render::StateBag::GetState(
                (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((int)v7->pNode & 0xFFFFF000) + 0x14)
                                                           + 4
                                                           * ((int)((int)&v7->pNode[-1] - ((int)v7->pNode & 0xFFFFF000))
                                                            / 28)
                                                           + 20)
                                               & 0xFFFFFFFE)
                                              + 64),
                State_FSCommandHandler);
    }
    if ( !v11
      && (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v7->pNode & 0xFFFFF000) + 0x14)
                                + 4 * ((int)((int)&v7->pNode[-1] - ((int)v7->pNode & 0xFFFFF000)) / 28)
                                + 20)
                    & 0xFFFFFFFE)
                   + 6)
        & 0x1000) != 0 )
    {
      v11 = Scaleform::Render::StateBag::GetState(
              (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((int)v7->pNode & 0xFFFFF000) + 0x14)
                                                         + 4
                                                         * ((int)((int)&v7->pNode[-1] - ((int)v7->pNode & 0xFFFFF000))
                                                          / 28)
                                                         + 20)
                                             & 0xFFFFFFFE)
                                            + 64),
              State_ExternalInterface);
    }
  }
  if ( State && v11 )
  {
    memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)(*(_DWORD *)(State + 4) + 16), sizeof(dst));
    memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)(*(_DWORD *)(v11 + 4) + 16), sizeof(m1));
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v14, &m1, &dst);
    memcpy((unsigned __int8 *)pviewProj, (unsigned __int8 *)&v14, sizeof(Scaleform::Render::Matrix4x4<float>));
  }
  else
  {
    memcpy(
      (unsigned __int8 *)pviewProj,
      (unsigned __int8 *)&Scaleform::Render::Matrix4x4<float>::Identity,
      sizeof(Scaleform::Render::Matrix4x4<float>));
  }
}
