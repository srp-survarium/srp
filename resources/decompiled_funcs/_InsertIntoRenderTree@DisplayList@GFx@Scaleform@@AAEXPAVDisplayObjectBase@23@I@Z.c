void __thiscall Scaleform::GFx::DisplayList::InsertIntoRenderTree(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int index)
{
  Scaleform::GFx::DisplayList *v3; // ebp
  Scaleform::GFx::DisplayList::DisplayEntry *v4; // ebx
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v6; // edx
  int v7; // eax
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // edi
  unsigned int *p_TreeIndex; // ecx
  Scaleform::GFx::DisplayList::DisplayEntry *v10; // edx
  unsigned int v11; // esi
  unsigned int *v12; // ecx
  int Depth; // ecx
  unsigned int *v14; // edi
  Scaleform::Render::TreeContainer *v15; // eax
  Scaleform::Render::TreeContainer *v16; // ebp
  Scaleform::Render::ContextImpl::Context *RenderContext; // eax
  Scaleform::Render::TreeContainer *v18; // esi
  bool v19; // zf
  unsigned int v20; // ebp
  unsigned int v21; // esi
  int v22; // ecx
  Scaleform::GFx::DisplayList::DisplayEntry *v23; // eax
  unsigned int v24; // esi
  Scaleform::Render::ContextImpl::Context *v25; // eax
  Scaleform::Render::TreeContainer *v26; // edi
  unsigned int Size; // edx
  unsigned int TreeIndex; // ebx
  unsigned int *v29; // ecx
  unsigned int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // ebp
  int v33; // edi
  int v34; // edx
  _DWORD *v35; // edi
  int v36; // eax
  Scaleform::Render::TreeNode *v37; // eax
  Scaleform::Render::TreeNode *v38; // esi
  int v39; // edx
  unsigned int v40; // ecx
  bool masked; // [esp+Fh] [ebp-21h]
  Scaleform::Render::TreeNode *pnode; // [esp+14h] [ebp-1Ch]
  Scaleform::GFx::DisplayList::DisplayEntry *v44; // [esp+18h] [ebp-18h]
  Scaleform::GFx::DisplayObjectBase *pCharacter; // [esp+1Ch] [ebp-14h]
  Scaleform::Render::TreeContainer *pcontainerNode; // [esp+20h] [ebp-10h]
  int treeIndexDelta; // [esp+24h] [ebp-Ch]
  unsigned int updateFromIndex; // [esp+28h] [ebp-8h]
  unsigned int v49; // [esp+2Ch] [ebp-4h]
  int v50; // [esp+2Ch] [ebp-4h]
  Scaleform::Render::TreeContainer *maskNode; // [esp+34h] [ebp+4h]
  unsigned int i; // [esp+38h] [ebp+8h]

  v3 = this;
  v4 = &this->DisplayObjectArray.Data.Data[index];
  v49 = index;
  v44 = v4;
  if ( (v4->pCharacter->Flags & 0x8000u) == 0 )
  {
    pcontainerNode = owner->GetRenderContainer(owner);
    pCharacter = v4->pCharacter;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v4->pCharacter);
    v6 = RenderNode;
    pnode = RenderNode;
    if ( RenderNode )
      ++RenderNode->RefCount;
    masked = 0;
    if ( index )
    {
      v7 = v3->DisplayObjectArray.Data.Size - 1;
      if ( index - 1 < v7 )
        v7 = index - 1;
      if ( v7 < 0 )
      {
        v4->TreeIndex = 0;
      }
      else
      {
        Data = v3->DisplayObjectArray.Data.Data;
        p_TreeIndex = &v3->DisplayObjectArray.Data.Data[v7].TreeIndex;
        while ( *p_TreeIndex == -1 )
        {
          --v7;
          p_TreeIndex -= 3;
          if ( v7 < 0 )
          {
            v4->TreeIndex = 0;
            goto LABEL_45;
          }
        }
        v10 = &Data[v7];
        if ( !v10->pCharacter->ClipDepth && v10->MaskTreeIndex == -1 )
          goto LABEL_41;
        v11 = 0;
        if ( v7 )
        {
          v12 = &v10->TreeIndex;
          do
          {
            if ( v12[1] == -1 )
            {
              if ( *v12 != -1 )
                break;
            }
            else if ( *v12 != -1 )
            {
              ++v11;
            }
            --v7;
            v12 -= 3;
          }
          while ( v7 );
        }
        Depth = pCharacter->Depth;
        v14 = (unsigned int *)&Data[v7];
        if ( Depth > *(unsigned __int16 *)(*v14 + 60) || Depth <= *(_DWORD *)(*v14 + 24) )
        {
LABEL_41:
          v4->TreeIndex = v10->TreeIndex + 1;
        }
        else
        {
          v4->TreeIndex = v14[1];
          v4->MaskTreeIndex = v11;
          masked = 1;
          v15 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(pcontainerNode, v14[1]);
          v16 = v15;
          if ( pCharacter->ClipDepth )
          {
            RenderContext = Scaleform::GFx::DisplayObjectBase::GetRenderContext(owner);
            v18 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(RenderContext);
            Scaleform::Render::TreeNode::SetMaskNode(v18, pnode);
            Scaleform::Render::TreeContainer::Insert(v16, v4->MaskTreeIndex, v18);
            if ( v18 )
            {
              v19 = v18->RefCount-- == 1;
              if ( v19 )
                Scaleform::Render::ContextImpl::Entry::destroyHelper(v18);
            }
          }
          else
          {
            Scaleform::Render::TreeContainer::Insert(v15, v11, pnode);
          }
          v20 = index + 1;
          if ( index + 1 >= this->DisplayObjectArray.Data.Size )
          {
            v3 = this;
          }
          else
          {
            v21 = v20;
            while ( 1 )
            {
              v22 = this->DisplayObjectArray.Data.Data[v21].pCharacter->Depth;
              v23 = &this->DisplayObjectArray.Data.Data[v21];
              if ( v22 > *(unsigned __int16 *)(*v14 + 60) || v22 <= *(_DWORD *)(*v14 + 24) )
                break;
              if ( v23->TreeIndex != -1 )
                ++v23->MaskTreeIndex;
              ++v20;
              ++v21;
              if ( v20 >= this->DisplayObjectArray.Data.Size )
              {
                v3 = this;
                goto LABEL_44;
              }
            }
            v3 = this;
          }
        }
LABEL_44:
        v6 = pnode;
      }
    }
    else
    {
      v4->TreeIndex = 0;
    }
LABEL_45:
    treeIndexDelta = 1;
    if ( !masked )
    {
      v24 = index + 1;
      if ( pCharacter->ClipDepth )
      {
        v25 = Scaleform::GFx::DisplayObjectBase::GetRenderContext(owner);
        v26 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(v25);
        maskNode = v26;
        Scaleform::Render::TreeNode::SetMaskNode(v26, pnode);
        Size = v3->DisplayObjectArray.Data.Size;
        if ( v24 < Size )
        {
          TreeIndex = v3->DisplayObjectArray.Data.Data[v49 + 1].TreeIndex;
          v29 = &v3->DisplayObjectArray.Data.Data[v49 + 1].TreeIndex;
          if ( TreeIndex != -1 )
            goto LABEL_53;
          v30 = index + 1;
          do
          {
            ++index;
            ++v30;
            ++v24;
            v29 += 3;
            if ( v30 >= Size )
              break;
            TreeIndex = *v29;
          }
          while ( *v29 == -1 );
          v3 = this;
          if ( TreeIndex != -1 )
          {
LABEL_53:
            v31 = index + 1;
            v32 = 0;
            i = v31;
            if ( v31 < Size )
            {
              v33 = 12 * v31;
              v50 = 12 * v31;
              do
              {
                v34 = *(int *)((char *)&this->DisplayObjectArray.Data.Data->pCharacter + v33);
                v35 = (Scaleform::GFx::DisplayObjectBase **)((char *)&this->DisplayObjectArray.Data.Data->pCharacter
                                                           + v33);
                v36 = *(_DWORD *)(v34 + 24);
                if ( v36 > pCharacter->ClipDepth || v36 <= pCharacter->Depth )
                  break;
                updateFromIndex = ++v24;
                if ( v35[1] != -1 )
                {
                  if ( *(_WORD *)(*v35 + 60) )
                    break;
                  v37 = Scaleform::Render::TreeContainer::GetAt(pcontainerNode, TreeIndex);
                  v38 = v37;
                  if ( v37 )
                    ++v37->RefCount;
                  Scaleform::Render::TreeContainer::Remove(pcontainerNode, TreeIndex, 1u);
                  v35[1] = v44->TreeIndex;
                  v35[2] = v32;
                  Scaleform::Render::TreeContainer::Insert(maskNode, v32, v38);
                  --treeIndexDelta;
                  ++v32;
                  if ( v38 )
                  {
                    v19 = v38->RefCount-- == 1;
                    if ( v19 )
                      Scaleform::Render::ContextImpl::Entry::destroyHelper(v38);
                  }
                  v24 = updateFromIndex;
                  v31 = i;
                }
                ++v31;
                v33 = v50 + 12;
                i = v31;
                v50 += 12;
              }
              while ( v31 < this->DisplayObjectArray.Data.Size );
              v26 = maskNode;
            }
            v3 = this;
          }
          v4 = v44;
        }
        Scaleform::Render::TreeContainer::Insert(pcontainerNode, v4->TreeIndex, v26);
        if ( v26 )
        {
          v19 = v26->RefCount-- == 1;
          if ( v19 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(v26);
        }
      }
      else
      {
        Scaleform::Render::TreeContainer::Insert(pcontainerNode, v4->TreeIndex, v6);
      }
      if ( v24 < v3->DisplayObjectArray.Data.Size )
      {
        v39 = v24;
        do
        {
          v40 = v3->DisplayObjectArray.Data.Data[v39].TreeIndex;
          if ( v40 != -1 )
            v3->DisplayObjectArray.Data.Data[v39].TreeIndex = treeIndexDelta + v40;
          ++v24;
          ++v39;
        }
        while ( v24 < v3->DisplayObjectArray.Data.Size );
      }
      v6 = pnode;
    }
    if ( v6 )
    {
      v19 = v6->RefCount-- == 1;
      if ( v19 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
    }
  }
  else
  {
    Scaleform::GFx::MovieImpl::UpdateTransformParent(owner->pASRoot->pMovieImpl, v4->pCharacter, owner);
  }
}
