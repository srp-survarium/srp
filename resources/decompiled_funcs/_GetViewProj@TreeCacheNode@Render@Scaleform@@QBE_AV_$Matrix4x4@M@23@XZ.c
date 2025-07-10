Scaleform::Render::Matrix4x4<float> *__thiscall Scaleform::Render::TreeCacheNode::GetViewProj(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Matrix4x4<float> *result)
{
  Scaleform::Render::TreeNode *pNode; // eax
  unsigned int v4; // esi
  Scaleform::Render::TreeCacheNode **p_pParent; // ebx
  unsigned int v6; // eax
  unsigned int v7; // esi
  Scaleform::Render::TreeCacheNode *v8; // ebx
  unsigned int v10; // [esp+104h] [ebp-78h]
  unsigned int State; // [esp+108h] [ebp-74h]
  Scaleform::Render::Matrix3x4<float> dst; // [esp+10Ch] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> m1; // [esp+13Ch] [ebp-40h] BYREF

  pNode = this->pNode;
  if ( !pNode )
  {
    v4 = 0;
LABEL_6:
    State = 0;
    goto LABEL_7;
  }
  v4 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                 + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28)
                 + 20)
     & 0xFFFFFFFE;
  if ( !v4 || (*(_WORD *)(v4 + 6) & 0x800) == 0 )
    goto LABEL_6;
  State = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v4 + 64), State_FSCommandHandler);
LABEL_7:
  if ( v4 && (*(_WORD *)(v4 + 6) & 0x1000) != 0 )
    v10 = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v4 + 64), State_ExternalInterface);
  else
    v10 = 0;
  p_pParent = &this->pParent;
  if ( this->pParent )
  {
    while ( 1 )
    {
      v6 = State;
      if ( State )
      {
        v7 = v10;
        if ( v10 )
          break;
      }
      v8 = *p_pParent;
      if ( !State
        && (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v8->pNode & 0xFFFFF000) + 0x14)
                                  + 4 * ((int)((int)&v8->pNode[-1] - ((int)v8->pNode & 0xFFFFF000)) / 28)
                                  + 20)
                      & 0xFFFFFFFE)
                     + 6)
          & 0x800) != 0 )
      {
        State = Scaleform::Render::StateBag::GetState(
                  (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((int)v8->pNode & 0xFFFFF000) + 0x14)
                                                             + 4
                                                             * ((int)((int)&v8->pNode[-1] - ((int)v8->pNode & 0xFFFFF000))
                                                              / 28)
                                                             + 20)
                                                 & 0xFFFFFFFE)
                                                + 64),
                  State_FSCommandHandler);
      }
      if ( !v10
        && (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v8->pNode & 0xFFFFF000) + 0x14)
                                  + 4 * ((int)((int)&v8->pNode[-1] - ((int)v8->pNode & 0xFFFFF000)) / 28)
                                  + 20)
                      & 0xFFFFFFFE)
                     + 6)
          & 0x1000) != 0 )
      {
        v10 = Scaleform::Render::StateBag::GetState(
                (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((int)v8->pNode & 0xFFFFF000) + 0x14)
                                                           + 4
                                                           * ((int)((int)&v8->pNode[-1] - ((int)v8->pNode & 0xFFFFF000))
                                                            / 28)
                                                           + 20)
                                               & 0xFFFFFFFE)
                                              + 64),
                State_ExternalInterface);
      }
      p_pParent = &v8->pParent;
      if ( !*p_pParent )
        goto LABEL_21;
    }
  }
  else
  {
LABEL_21:
    v7 = v10;
    v6 = State;
  }
  if ( v6 && v7 )
  {
    memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)(*(_DWORD *)(v6 + 4) + 16), sizeof(dst));
    memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)(*(_DWORD *)(v7 + 4) + 16), sizeof(m1));
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(result, &m1, &dst);
    return result;
  }
  else
  {
    memcpy(
      (unsigned __int8 *)result,
      (unsigned __int8 *)&Scaleform::Render::Matrix4x4<float>::Identity,
      sizeof(Scaleform::Render::Matrix4x4<float>));
    return result;
  }
}
