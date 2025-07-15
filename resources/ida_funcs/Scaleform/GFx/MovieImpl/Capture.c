void __thiscall Scaleform::GFx::MovieImpl::Capture(Scaleform::GFx::MovieImpl *this, bool onChangeOnly)
{
  Scaleform::GFx::MovieImpl *v2; // edi
  Scaleform::GFx::MovieImpl::IndirectTransPair *v3; // ebx
  Scaleform::Render::TreeNode *RenderNode; // edx
  Scaleform::Render::ContextImpl::Entry *pPrev; // eax
  Scaleform::Render::TreeRoot *pObject; // eax
  int v7; // esi
  unsigned __int8 *pIndXFormData; // esi
  Scaleform::Render::TreeRoot *v9; // ebx
  int v10; // edi
  Scaleform::Render::TreeRoot *pParent; // eax
  Scaleform::Render::TreeRoot *v12; // ebx
  int v13; // edi
  unsigned __int8 *Inverse; // eax
  bool HasChanges; // al
  bool v16; // [esp+75Fh] [ebp-191h]
  char j; // [esp+75Fh] [ebp-191h]
  Scaleform::Render::TreeNode *v19; // [esp+764h] [ebp-18Ch]
  int v20; // [esp+768h] [ebp-188h]
  unsigned int i; // [esp+76Ch] [ebp-184h]
  Scaleform::Render::Matrix3x4<float> src; // [esp+770h] [ebp-180h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+7A0h] [ebp-150h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+7D0h] [ebp-120h] BYREF
  Scaleform::Render::Matrix3x4<float> v25; // [esp+800h] [ebp-F0h] BYREF
  Scaleform::Render::Matrix3x4<float> v26; // [esp+830h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix3x4<float> v27; // [esp+860h] [ebp-90h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+890h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [esp+8C0h] [ebp-30h] BYREF

  v2 = this;
  if ( onChangeOnly
    && !Scaleform::Render::ContextImpl::Context::HasChanges(&this->RenderContext)
    && !v2->MovieDefKillList.Data.Size )
  {
    if ( v2->PreviouslyCaptured > 0 )
    {
      v2->pASMovieRoot.pObject->SuspendGC(v2->pASMovieRoot.pObject, 1);
      Scaleform::Render::ContextImpl::Context::Capture(&v2->RenderContext);
      v2->pASMovieRoot.pObject->SuspendGC(v2->pASMovieRoot.pObject, 0);
      --v2->PreviouslyCaptured;
    }
    return;
  }
  if ( v2->IndirectTransformPairs.Data.Size )
  {
    v20 = 0;
    for ( i = v2->IndirectTransformPairs.Data.Size; i; --i )
    {
      v3 = &v2->IndirectTransformPairs.Data.Data[v20];
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3->Obj.pObject);
      pPrev = RenderNode->pPrev;
      v19 = RenderNode;
      if ( RenderNode->pPrev )
      {
        v16 = (pPrev->RefCount & 0x80040181) != 0;
        if ( (pPrev->RefCount & 0x80040181) != 0 )
          goto LABEL_20;
      }
      else
      {
        v16 = 0;
      }
      pObject = (Scaleform::Render::TreeRoot *)v3->TransformParent.pObject;
      v7 = 0;
      if ( v3->TransformParent.pObject )
      {
        while ( pObject != v2->pRenderRoot.pObject )
        {
          if ( pObject->pPrev && (pObject->pPrev->RefCount & 0x80040181) != 0 )
          {
            v16 = 1;
            break;
          }
          pObject = (Scaleform::Render::TreeRoot *)pObject->pParent;
          ++v7;
          if ( !pObject )
            break;
        }
      }
      if ( v7 == v3->OrigParentDepth )
      {
        if ( !v16 )
        {
          pParent = (Scaleform::Render::TreeRoot *)RenderNode->pParent;
          if ( pParent )
          {
            while ( pParent != v2->pRenderRoot.pObject )
            {
              if ( pParent->pPrev && (pParent->pPrev->RefCount & 0x80040181) != 0 )
                goto LABEL_20;
              pParent = (Scaleform::Render::TreeRoot *)pParent->pParent;
              if ( !pParent )
                goto LABEL_42;
            }
          }
          goto LABEL_42;
        }
      }
      else
      {
        v3->OrigParentDepth = v7;
      }
LABEL_20:
      pIndXFormData = (unsigned __int8 *)v3->Obj.pObject->pIndXFormData;
      memcpy((unsigned __int8 *)&dst, pIndXFormData, sizeof(dst));
      v9 = (Scaleform::Render::TreeRoot *)v3->TransformParent.pObject;
      for ( j = pIndXFormData[48]; v9; v2 = this )
      {
        if ( v9 == v2->pRenderRoot.pObject )
          break;
        v10 = (int)((int)&v9[-1] - ((unsigned int)v9 & 0xFFFFF000)) / 28;
        if ( (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v9 & 0xFFFFF000) + 0x10) + 4 * v10 + 20) + 6) & 0x200) != 0 )
        {
          memcpy((unsigned __int8 *)&m2, (unsigned __int8 *)&dst, sizeof(m2));
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            &dst,
            (const Scaleform::Render::Matrix3x4<float> *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v9 & 0xFFFFF000) + 0x10)
                                                                    + 4 * v10
                                                                    + 20)
                                                        + 16),
            &m2);
          j = 1;
        }
        else
        {
          memcpy((unsigned __int8 *)&v25, (unsigned __int8 *)&dst, sizeof(v25));
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            &dst,
            (const Scaleform::Render::Matrix2x4<float> *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v9 & 0xFFFFF000) + 0x10)
                                                                    + 4 * v10
                                                                    + 20)
                                                        + 16),
            &v25);
        }
        v9 = (Scaleform::Render::TreeRoot *)v9->pParent;
      }
      memset((int)&src, 0, sizeof(src));
      src.M[0][0] = 1.0;
      v12 = (Scaleform::Render::TreeRoot *)v19->pParent;
      src.M[1][1] = 1.0;
      for ( src.M[2][2] = 1.0; v12; v2 = this )
      {
        if ( v12 == v2->pRenderRoot.pObject )
          break;
        v13 = (int)((int)&v12[-1] - ((unsigned int)v12 & 0xFFFFF000)) / 28;
        if ( (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v12 & 0xFFFFF000) + 0x10) + 4 * v13 + 20) + 6) & 0x200) != 0 )
        {
          memcpy((unsigned __int8 *)&v26, (unsigned __int8 *)&src, sizeof(v26));
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            &src,
            (const Scaleform::Render::Matrix3x4<float> *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v12 & 0xFFFFF000) + 0x10)
                                                                    + 4 * v13
                                                                    + 20)
                                                        + 16),
            &v26);
          j = 1;
        }
        else
        {
          memcpy((unsigned __int8 *)&v27, (unsigned __int8 *)&src, sizeof(v27));
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            &src,
            (const Scaleform::Render::Matrix2x4<float> *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v12 & 0xFFFFF000) + 0x10)
                                                                    + 4 * v13
                                                                    + 20)
                                                        + 16),
            &v27);
        }
        v12 = (Scaleform::Render::TreeRoot *)v12->pParent;
      }
      if ( j )
      {
        Inverse = (unsigned __int8 *)Scaleform::Render::Matrix3x4<float>::GetInverse(&src, &result);
        memcpy((unsigned __int8 *)&src, Inverse, sizeof(src));
        memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)&src, sizeof(m1));
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&src, &m1, &dst);
        Scaleform::Render::TreeNode::SetMatrix3D(v19, &src);
      }
      else
      {
        result.M[0][0] = src.M[0][0];
        result.M[0][1] = src.M[0][1];
        result.M[0][2] = src.M[0][2];
        result.M[0][3] = src.M[0][3];
        result.M[1][0] = src.M[1][0];
        result.M[1][1] = src.M[1][1];
        result.M[1][2] = src.M[1][2];
        result.M[1][3] = src.M[1][3];
        Scaleform::Render::Matrix2x4<float>::SetInverse(
          (Scaleform::Render::Matrix2x4<float> *)&src,
          (const Scaleform::Render::Matrix2x4<float> *)&result);
        Scaleform::Render::Matrix2x4<float>::Prepend(
          (Scaleform::Render::Matrix2x4<float> *)&src,
          (const Scaleform::Render::Matrix2x4<float> *)&dst);
        Scaleform::Render::TreeNode::SetMatrix(v19, (const Scaleform::Render::Matrix2x4<float> *)&src);
      }
LABEL_42:
      ++v20;
    }
  }
  if ( (v2->Flags & 0x400) != 0
    || (HasChanges = Scaleform::Render::ContextImpl::Context::HasChanges(&v2->RenderContext)) )
  {
    HasChanges = 1;
  }
  if ( HasChanges )
    v2->Flags |= 0x400u;
  else
    v2->Flags &= ~0x400u;
  v2->pASMovieRoot.pObject->SuspendGC(v2->pASMovieRoot.pObject, 1);
  Scaleform::Render::ContextImpl::Context::Capture(&v2->RenderContext);
  v2->pASMovieRoot.pObject->SuspendGC(v2->pASMovieRoot.pObject, 0);
  v2->PreviouslyCaptured = 1;
}
