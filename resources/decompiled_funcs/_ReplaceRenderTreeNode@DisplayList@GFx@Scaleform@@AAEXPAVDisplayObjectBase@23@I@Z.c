void __thiscall Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int index)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v3; // esi
  Scaleform::Render::TreeContainer *v4; // ebp
  Scaleform::GFx::MovieDefImpl *v5; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::MovieDefImpl *v7; // eax
  Scaleform::Render::TreeContainer *v8; // ebx
  unsigned int MaskTreeIndex; // eax
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v11; // eax
  Scaleform::Render::TreeNode *v12; // eax

  v3 = &this->DisplayObjectArray.Data.Data[index];
  if ( (v3->pCharacter->Flags & 0x8000u) == 0 )
  {
    v4 = owner->GetRenderContainer(owner);
    v5 = v3->pCharacter->GetResourceMovieDef(v3->pCharacter);
    if ( v5 != owner->GetResourceMovieDef(owner) )
    {
      pMovieImpl = v3->pCharacter->pASRoot->pMovieImpl;
      v7 = v3->pCharacter->GetResourceMovieDef(v3->pCharacter);
      Scaleform::GFx::MovieImpl::AddMovieDefToKillList(pMovieImpl, v7);
    }
    v8 = (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(v4, v3->TreeIndex);
    MaskTreeIndex = v3->MaskTreeIndex;
    if ( MaskTreeIndex == -1 )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v8 & 0xFFFFF000) + 0x10)
                                 + 4 * ((int)((int)&v8[-1] - ((unsigned int)v8 & 0xFFFFF000)) / 28)
                                 + 20)
                     + 6)
          & 0x10) != 0 )
      {
        RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3->pCharacter);
        Scaleform::Render::TreeNode::SetMaskNode(v8, RenderNode);
      }
      else
      {
        Scaleform::Render::TreeContainer::Remove(v4, v3->TreeIndex, 1u);
        v11 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3->pCharacter);
        Scaleform::Render::TreeContainer::Insert(v4, v3->TreeIndex, v11);
      }
    }
    else
    {
      Scaleform::Render::TreeContainer::Remove(v8, MaskTreeIndex, 1u);
      v12 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3->pCharacter);
      Scaleform::Render::TreeContainer::Insert(v8, v3->MaskTreeIndex, v12);
    }
  }
  else
  {
    Scaleform::GFx::MovieImpl::UpdateTransformParent(owner->pASRoot->pMovieImpl, v3->pCharacter, owner);
  }
}
