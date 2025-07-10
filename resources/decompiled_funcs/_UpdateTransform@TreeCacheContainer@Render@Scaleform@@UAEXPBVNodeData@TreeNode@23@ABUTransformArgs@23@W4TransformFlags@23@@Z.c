void __thiscall Scaleform::Render::TreeCacheContainer::UpdateTransform(
        Scaleform::Render::TreeCacheContainer *this,
        const Scaleform::Render::TreeNode::NodeData *pbaseData,
        const Scaleform::Render::TransformArgs *t,
        Scaleform::Render::TransformFlags flags)
{
  Scaleform::Render::TransformFlags updated; // eax
  Scaleform::Render::TreeCacheNode *pNext; // edi
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_Children; // esi
  int v8; // eax
  char v9; // cl
  char UpdateFlags; // si
  const Scaleform::Render::TreeNode::NodeData *v11; // ebx
  int v12; // esi
  int v13; // esi
  unsigned int State; // eax
  Scaleform::Render::FilterSet *v15; // eax
  char v16; // al
  float y1; // [esp+662h] [ebp-11Ch]
  Scaleform::Render::TreeCacheNode *v18; // [esp+662h] [ebp-11Ch]
  float x2; // [esp+666h] [ebp-118h]
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *v20; // [esp+666h] [ebp-118h]
  float y2; // [esp+66Ah] [ebp-114h]
  Scaleform::Render::Matrix3x4<float> m; // [esp+66Eh] [ebp-110h] BYREF
  Scaleform::Render::TransformArgs v23; // [esp+69Eh] [ebp-E0h] BYREF
  Scaleform::Render::TransformFlags flagsa; // [esp+78Eh] [ebp+10h]

  Scaleform::Render::TransformArgs::TransformArgs(&v23, t);
  updated = Scaleform::Render::TreeCacheNode::updateCulling(this, pbaseData, t, &v23.CullRect, flags);
  y1 = pbaseData->AproxParentBounds.y1;
  flagsa = updated;
  x2 = pbaseData->AproxParentBounds.x2;
  y2 = pbaseData->AproxParentBounds.y2;
  this->SortParentBounds.x1 = pbaseData->AproxParentBounds.x1;
  this->SortParentBounds.y1 = y1;
  this->SortParentBounds.x2 = x2;
  this->SortParentBounds.y2 = y2;
  pNext = this->Children.Root.pNext;
  this->Flags &= ~0x400u;
  p_Children = &this->Children;
  v18 = pNext;
  v20 = p_Children;
  while ( 1 )
  {
    v8 = p_Children ? (int)&p_Children[-2] : 0;
    if ( pNext == (Scaleform::Render::TreeCacheNode *)v8 )
      break;
    v9 = flagsa;
    UpdateFlags = pNext->UpdateFlags;
    v11 = (const Scaleform::Render::TreeNode::NodeData *)(*(_DWORD *)(*(_DWORD *)(((int)pNext->pNode & 0xFFFFF000) + 0x14)
                                                                    + 4
                                                                    * ((int)((int)&pNext->pNode[-1]
                                                                           - ((int)pNext->pNode & 0xFFFFF000))
                                                                     / 28)
                                                                    + 20)
                                                        & 0xFFFFFFFE);
    pNext->UpdateFlags &= 0xFFFFFFFC;
    v12 = flagsa | UpdateFlags & 3;
    if ( (v11->Flags & 0x200) != 0 )
    {
      if ( (flagsa & 0x40) != 0 )
      {
        Scaleform::Render::TransformArgs::GetMatrix3D(t, flagsa, &m);
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v23.Mat3D, &m, &v11->M34);
        v12 &= ~0x40u;
      }
      else if ( (flagsa & 0x80u) != 0 )
      {
        Scaleform::Render::TransformArgs::GetMatrix3D(t, flagsa, &m);
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v23.Mat3D, &m, &v11->M34);
      }
      v13 = v12 | 0x80;
    }
    else
    {
      if ( (flagsa & 0x40) != 0 )
      {
        Scaleform::Render::Matrix2x4<float>::SetToAppend(
          &v23.Mat,
          (const Scaleform::Render::Matrix2x4<float> *)&v11->M34,
          &t->Mat);
        v9 = flagsa;
      }
      else
      {
        v23.Mat.M[0][0] = v11->M34.M[0][0];
        v23.Mat.M[0][1] = v11->M34.M[0][1];
        v23.Mat.M[0][2] = v11->M34.M[0][2];
        v23.Mat.M[0][3] = v11->M34.M[0][3];
        v23.Mat.M[1][0] = v11->M34.M[1][0];
        v23.Mat.M[1][1] = v11->M34.M[1][1];
        v23.Mat.M[1][2] = v11->M34.M[1][2];
        v23.Mat.M[1][3] = v11->M34.M[1][3];
      }
      v13 = v12 | 0x40;
      if ( v9 < 0 )
        memcpy((unsigned __int8 *)&v23.Mat3D, (unsigned __int8 *)&t->Mat3D, sizeof(v23.Mat3D));
    }
    Scaleform::Render::TransformArgs::SetViewProj(&v23, v11, t);
    if ( (pbaseData->Flags & 0x400) != 0
      && ((State = Scaleform::Render::StateBag::GetState(&pbaseData->States, State_ActionControl)) == 0
       || (v15 = *(Scaleform::Render::FilterSet **)(State + 4)) == 0
       || !Scaleform::Render::FilterSet::IsContributing(v15)
        ? (v16 = 1)
        : (v16 = 0),
          v13 |= 0x100u,
          !v16) )
    {
      qmemcpy(&v23.Cx, &v11->Cx, sizeof(v23.Cx));
      pNext = v18;
    }
    else
    {
      Scaleform::Render::Cxform::SetToAppend(&v23.Cx, &v11->Cx, &t->Cx);
    }
    pNext->UpdateTransform(pNext, v11, &v23, (Scaleform::Render::TransformFlags)v13);
    p_Children = v20;
    v18 = pNext->pNext;
    pNext = v18;
  }
}
