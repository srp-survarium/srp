Scaleform::Render::TreeContainer *__thiscall Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::TreeContainer *pParent; // edi
  Scaleform::Render::ContextImpl::Context *p_RenderContext; // esi
  Scaleform::Render::TreeNode::NodeData *v6; // eax
  Scaleform::Render::TreeNode *EntryHelper; // esi
  int v8; // eax
  char v9; // cl
  _DWORD *v10; // eax
  char v11; // cl
  unsigned int v12; // ecx
  unsigned int v13; // esi
  Scaleform::Render::TreeNode *pObject; // eax
  const __m128i *v15; // eax
  Scaleform::GFx::DisplayObjectBase_vtbl *v16; // edx
  bool (__thiscall *GetProjectionMatrix3D)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix4x4<float> *, bool); // edx
  Scaleform::GFx::DisplayObjectBase_vtbl *v18; // edx
  bool (__thiscall *GetViewMatrix3D)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix3x4<float> *, bool); // edx
  const Scaleform::Render::Matrix2x4<float> *v20; // eax
  Scaleform::Render::TreeNode *v21; // eax
  Scaleform::Render::Cxform *v22; // esi
  bool v23; // al
  const Scaleform::Render::State *State; // eax
  Scaleform::Render::BlendMode pData; // eax
  Scaleform::Render::TreeNode *v26; // ecx
  int v27; // eax
  unsigned int v28; // ecx
  int v29; // eax
  Scaleform::Render::TreeNode *v30; // ecx
  bool v31; // zf
  Scaleform::Render::TreeNode::NodeData *index; // [esp+10h] [ebp-A0h]
  unsigned int indexa; // [esp+10h] [ebp-A0h]
  char i; // [esp+17h] [ebp-99h]
  Scaleform::Render::TreeContainer *node; // [esp+18h] [ebp-98h]
  unsigned int Size; // [esp+1Ch] [ebp-94h]
  Scaleform::Render::Rect<float> result; // [esp+20h] [ebp-90h] BYREF
  Scaleform::Render::Rect<float> v39; // [esp+30h] [ebp-80h] BYREF
  Scaleform::Render::Matrix3x4<float> v40; // [esp+40h] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> mat3D; // [esp+70h] [ebp-40h] BYREF

  if ( !this->pRenNode.pObject )
    Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  pMovieImpl = this->pASRoot->pMovieImpl;
  pHeap = pMovieImpl->RenderContext.pHeap;
  pParent = (Scaleform::Render::TreeContainer *)this->pRenNode.pObject->pParent;
  p_RenderContext = &pMovieImpl->RenderContext;
  v6 = (Scaleform::Render::TreeNode::NodeData *)pHeap->Alloc(pHeap, 160u, 0);
  index = v6;
  if ( v6 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v6, ET_Container);
    v6 = index;
    index->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&index[1].Type = 0;
    index[1].__vftable = 0;
  }
  EntryHelper = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                                 p_RenderContext,
                                                 &v6->Scaleform::Render::ContextImpl::EntryData);
  node = (Scaleform::Render::TreeContainer *)EntryHelper;
  if ( pParent )
  {
    if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(((int)this->pRenNode.pObject & 0xFFFFF000) + 0x10)
                               + 4
                               * ((int)((int)&this->pRenNode.pObject[-1] - ((int)this->pRenNode.pObject & 0xFFFFF000))
                                / 28)
                               + 20)
                   + 6)
        & 0x20) != 0 )
    {
      Scaleform::Render::TreeNode::SetMaskNode(pParent, 0);
      Scaleform::Render::TreeNode::SetMaskNode(pParent, EntryHelper);
    }
    else
    {
      indexa = 0;
      Size = Scaleform::Render::TreeContainer::GetSize(pParent);
      if ( Size )
      {
        v8 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pParent & 0xFFFFF000) + 0x10)
                       + 4 * ((int)((int)&pParent[-1] - ((unsigned int)pParent & 0xFFFFF000)) / 28)
                       + 20);
        v9 = *(_BYTE *)(v8 + 144);
        v10 = (_DWORD *)(v8 + 144);
        v11 = v9 & 1;
        for ( i = v11; ; v11 = i )
        {
          v12 = v11 ? (*v10 & 0xFFFFFFFE) + 8 : (unsigned int)v10;
          v13 = indexa;
          if ( *(Scaleform::Render::TreeNode **)(v12 + 4 * indexa) == this->pRenNode.pObject )
            break;
          ++indexa;
          if ( v13 + 1 >= Size )
            break;
        }
      }
      Scaleform::Render::TreeContainer::Remove(pParent, indexa, 1u);
      Scaleform::Render::TreeContainer::Insert(pParent, indexa, node);
    }
    EntryHelper = node;
  }
  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pObject & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&pObject[-1] - ((unsigned int)pObject & 0xFFFFF000)) / 28)
                             + 20)
                 + 6)
      & 0x200) != 0 )
  {
    v15 = (const __m128i *)this->GetMatrix3D(this);
    Scaleform::Render::TreeNode::SetMatrix3D(EntryHelper, v15);
    memset((int)&mat3D, 0, sizeof(mat3D));
    v16 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    mat3D.M[0][0] = 1.0;
    GetProjectionMatrix3D = v16->GetProjectionMatrix3D;
    mat3D.M[1][1] = 1.0;
    mat3D.M[2][2] = 1.0;
    mat3D.M[3][3] = 1.0;
    if ( GetProjectionMatrix3D(this, &mat3D, 0) )
      Scaleform::Render::TreeNode::SetProjectionMatrix3D(EntryHelper, &mat3D);
    memset((int)&v40, 0, sizeof(v40));
    v18 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v40.M[0][0] = 1.0;
    GetViewMatrix3D = v18->GetViewMatrix3D;
    v40.M[1][1] = 1.0;
    v40.M[2][2] = 1.0;
    if ( GetViewMatrix3D(this, &v40, 0) )
      Scaleform::Render::TreeNode::SetViewMatrix3D(EntryHelper, &v40);
  }
  else
  {
    v20 = this->GetMatrix(this);
    Scaleform::Render::TreeNode::SetMatrix(EntryHelper, v20);
  }
  Scaleform::Render::TreeNode::SetMatrix(this->pRenNode.pObject, &Scaleform::Render::Matrix2x4<float>::Identity);
  v21 = this->pRenNode.pObject;
  if ( v21 )
    v22 = (Scaleform::Render::Cxform *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v21 & 0xFFFFF000) + 0x10)
                                                  + 4 * ((int)((int)&v21[-1] - ((unsigned int)v21 & 0xFFFFF000)) / 28)
                                                  + 20)
                                      + 80);
  else
    v22 = &Scaleform::Render::Cxform::Identity;
  qmemcpy(&Scaleform::Render::ContextImpl::Entry::getWritableData(node, 2u)[10], v22, 0x20u);
  qmemcpy(
    &Scaleform::Render::ContextImpl::Entry::getWritableData(this->pRenNode.pObject, 2u)[10],
    &Scaleform::Render::Cxform::Identity,
    0x20u);
  v23 = this->GetVisible(this);
  Scaleform::Render::TreeNode::SetVisible(node, v23);
  Scaleform::Render::TreeNode::SetVisible(this->pRenNode.pObject, 1);
  State = Scaleform::Render::TreeNode::GetState(this->pRenNode.pObject, State_Translator);
  if ( State )
    pData = (Scaleform::Render::BlendMode)State->pData;
  else
    pData = Blend_None;
  Scaleform::Render::TreeNode::SetBlendMode(node, pData);
  Scaleform::Render::TreeNode::SetBlendMode(this->pRenNode.pObject, Blend_None);
  Scaleform::Render::TreeNode::GetScale9Grid(this->pRenNode.pObject, &result);
  if ( result.x2 > (double)result.x1 && result.y2 > (double)result.y1 )
  {
    Scaleform::Render::TreeNode::SetScale9Grid(node, &result);
    v39.x1 = 0.0;
    v39.y1 = 0.0;
    v26 = this->pRenNode.pObject;
    v39.x2 = 0.0;
    v39.y2 = 0.0;
    Scaleform::Render::TreeNode::SetScale9Grid(v26, &v39);
  }
  v27 = *(_DWORD *)(*(_DWORD *)(((unsigned int)node & 0xFFFFF000) + 0x10)
                  + 4 * ((int)((int)&node[-1] - ((unsigned int)node & 0xFFFFF000)) / 28)
                  + 20);
  v28 = *(_DWORD *)(v27 + 144);
  v29 = v27 + 144;
  if ( v28 )
  {
    if ( (v28 & 1) != 0 )
      v28 = *(_DWORD *)((v28 & 0xFFFFFFFE) + 4);
    else
      v28 = (*(_DWORD *)(v29 + 4) != 0) + 1;
  }
  Scaleform::Render::TreeContainer::Insert(node, v28, this->pRenNode.pObject);
  if ( node )
    ++node->RefCount;
  v30 = this->pRenNode.pObject;
  if ( v30 )
  {
    v31 = v30->RefCount-- == 1;
    if ( v31 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v30);
  }
  this->pRenNode.pObject = node;
  if ( node )
  {
    v31 = node->RefCount-- == 1;
    if ( v31 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(node);
  }
  return node;
}
