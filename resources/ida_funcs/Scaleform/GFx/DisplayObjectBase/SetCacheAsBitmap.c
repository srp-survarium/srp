void __userpurge Scaleform::GFx::DisplayObjectBase::SetCacheAsBitmap(
        Scaleform::GFx::DisplayObjectBase *this@<ecx>,
        int a2@<esi>,
        bool enable)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  const Scaleform::Render::State *State; // eax
  Scaleform::Render::FilterSet *pData; // ecx
  Scaleform::Render::FilterSet *v7; // eax
  Scaleform::Render::FilterSet *v8; // eax
  Scaleform::Render::FilterSet *v9; // esi

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    State = Scaleform::Render::TreeNode::GetState(RenderNode, State_ActionControl);
    if ( State && (pData = (Scaleform::Render::FilterSet *)State->pData) != 0 )
    {
      if ( enable != pData->CacheAsBitmap )
      {
        v9 = Scaleform::Render::FilterSet::Clone(pData, 0, 0);
        Scaleform::Render::FilterSet::SetCacheAsBitmap(v9, enable);
        this->SetFilters(this, v9);
        if ( v9 )
LABEL_12:
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
      }
    }
    else if ( enable )
    {
      v7 = (Scaleform::Render::FilterSet *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))Scaleform::Memory::pGlobalHeap->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             24,
                                             0,
                                             a2);
      if ( v7 )
      {
        Scaleform::Render::FilterSet::FilterSet(v7, 0);
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      Scaleform::Render::FilterSet::SetCacheAsBitmap(v9, 1);
      ((void (__thiscall *)(Scaleform::GFx::DisplayObjectBase *))this->SetFilters)(this);
      if ( v9 )
        goto LABEL_12;
    }
  }
}
