Scaleform::GFx::MovieImpl::IndirectTransPair *__thiscall Scaleform::GFx::MovieImpl::RemoveIndirectTransformPair(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieImpl::IndirectTransPair *result,
        Scaleform::GFx::DisplayObjectBase *obj)
{
  unsigned int Size; // esi
  unsigned int v4; // edx
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // edi
  Scaleform::ArrayLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2,Scaleform::ArrayDefaultPolicy> *p_IndirectTransformPairs; // ecx
  Scaleform::GFx::DisplayObjectBase **p_pObject; // eax
  Scaleform::GFx::MovieImpl::IndirectTransPair *v8; // eax
  Scaleform::Render::TreeNode *pObject; // esi
  Scaleform::GFx::MovieImpl::IndirectTransPair *v10; // eax
  Scaleform::GFx::DisplayObjectBase *v11; // esi
  Scaleform::Render::TreeNode *v12; // edi
  Scaleform::GFx::DisplayObjContainer *v13; // esi
  Scaleform::GFx::DisplayObjectBase *v14; // ebp
  Scaleform::GFx::DisplayObjContainer *v15; // esi
  int OrigParentDepth; // [esp+1Ch] [ebp-4h]

  Size = this->IndirectTransformPairs.Data.Size;
  v4 = 0;
  if ( Size )
  {
    Data = this->IndirectTransformPairs.Data.Data;
    p_IndirectTransformPairs = &this->IndirectTransformPairs;
    p_pObject = &Data->Obj.pObject;
    while ( *p_pObject != obj )
    {
      ++v4;
      p_pObject += 4;
      if ( v4 >= Size )
        goto LABEL_5;
    }
    pObject = Data[v4].TransformParent.pObject;
    v10 = &Data[v4];
    if ( pObject )
      ++pObject->RefCount;
    v11 = v10->Obj.pObject;
    v12 = v10->TransformParent.pObject;
    if ( v11 )
      ++v11->RefCount;
    v13 = v10->OriginalParent.pObject;
    v14 = v10->Obj.pObject;
    if ( v13 )
      ++v13->RefCount;
    v15 = v10->OriginalParent.pObject;
    OrigParentDepth = v10->OrigParentDepth;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      p_IndirectTransformPairs,
      v4);
    if ( v12 )
      ++v12->RefCount;
    result->TransformParent.pObject = v12;
    if ( v14 )
      ++v14->RefCount;
    result->Obj.pObject = v14;
    if ( v15 )
      ++v15->RefCount;
    result->OriginalParent.pObject = v15;
    result->OrigParentDepth = OrigParentDepth;
    if ( v15 )
      Scaleform::RefCountNTSImpl::Release(v15);
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release(v14);
    if ( v12 )
    {
      if ( v12->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
    }
    return result;
  }
  else
  {
LABEL_5:
    v8 = result;
    result->TransformParent.pObject = 0;
    result->Obj.pObject = 0;
    result->OriginalParent.pObject = 0;
    result->OrigParentDepth = -1;
  }
  return v8;
}
