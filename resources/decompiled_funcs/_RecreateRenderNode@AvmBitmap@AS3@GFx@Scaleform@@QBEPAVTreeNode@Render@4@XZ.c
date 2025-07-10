Scaleform::Render::TreeNode *__thiscall Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(
        Scaleform::GFx::AS3::AvmBitmap *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v3; // ecx
  Scaleform::Render::TreeNode *pObject; // edi
  unsigned int v5; // ebx
  Scaleform::Render::TreeContainer *pParent; // ebp
  unsigned int Size; // ebp
  Scaleform::GFx::ImageResource *ImageResource; // eax
  Scaleform::GFx::ImageResource *v9; // edi
  Scaleform::GFx::ImageResource *v10; // ecx
  Scaleform::Render::TreeNode *result; // eax
  Scaleform::Render::TreeNode *v12; // ebp
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v13; // edi
  Scaleform::Render::TreeNode *v14; // ecx
  bool v15; // zf
  Scaleform::Render::ContextImpl::Entry *v16; // eax
  Scaleform::Render::TreeNode *v17; // ecx
  bool renNodeExisted; // [esp+13h] [ebp-9h]
  Scaleform::Render::TreeContainer *parent; // [esp+14h] [ebp-8h]
  Scaleform::GFx::AS3::Instances::fl_display::Bitmap *v20; // [esp+18h] [ebp-4h] BYREF

  pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)this->pAS3CollectiblePtr.pObject;
  v3 = pAS3RawPtr;
  v20 = pAS3RawPtr;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
  {
    v3 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)((char *)pAS3RawPtr - 1);
    v20 = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)((char *)pAS3RawPtr - 1);
  }
  pObject = this->pRenNode.pObject;
  v5 = -1;
  renNodeExisted = pObject != 0;
  parent = 0;
  if ( v3 )
  {
    if ( pObject )
    {
      pParent = (Scaleform::Render::TreeContainer *)pObject->pParent;
      if ( pParent )
      {
        if ( !(unsigned __int8)Scaleform::Render::TreeNode::IsMaskNode(pObject) )
          parent = pParent;
        v5 = 0;
        Size = Scaleform::Render::TreeContainer::GetSize(parent);
        if ( Size )
        {
          do
          {
            if ( Scaleform::Render::TreeContainer::GetAt(parent, v5) == pObject )
              break;
            ++v5;
          }
          while ( v5 < Size );
        }
        Scaleform::Render::TreeContainer::Remove(parent, v5, 1u);
        v3 = v20;
      }
    }
    ImageResource = Scaleform::GFx::AS3::Instances::fl_display::Bitmap::GetImageResource(v3);
    v9 = ImageResource;
    if ( ImageResource )
    {
      Scaleform::RefCountImpl::AddRef(ImageResource);
      v10 = this->pImage.pObject;
      if ( v10 )
        Scaleform::GFx::Resource::Release(v10);
      this->pImage.pObject = v9;
    }
  }
  result = this->pRenNode.pObject;
  if ( renNodeExisted )
  {
    if ( result )
      ++result->RefCount;
    v12 = this->pRenNode.pObject;
    v13 = this->CreateRenderNode(this, &v20, &this->pASRoot->pMovieImpl->RenderContext);
    if ( v13->pObject )
      ++v13->pObject->RefCount;
    v14 = this->pRenNode.pObject;
    if ( v14 )
    {
      v15 = v14->RefCount-- == 1;
      if ( v15 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v14);
    }
    this->pRenNode = (Scaleform::Ptr<Scaleform::Render::TreeNode>)v13->pObject;
    v16 = (Scaleform::Render::ContextImpl::Entry *)v20;
    if ( v20 )
    {
      --v20->pRCCRaw;
      if ( !v16->RefCount )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v16);
    }
    v17 = this->pRenNode.pObject;
    if ( v17 )
    {
      if ( v12 )
        Scaleform::Render::TreeNode::CopyGeomData(v17, v12);
      else
        Scaleform::Render::TreeNode::SetVisible(
          v17,
          (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x4000) != 0);
      if ( parent )
        Scaleform::Render::TreeContainer::Insert(parent, v5, this->pRenNode.pObject);
    }
    if ( v12 )
    {
      v15 = v12->RefCount-- == 1;
      if ( v15 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
    }
    return this->pRenNode.pObject;
  }
  return result;
}
