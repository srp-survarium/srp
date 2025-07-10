void __thiscall Scaleform::GFx::MovieImpl::AddIndirectTransformPair(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::DisplayObjContainer *origParent,
        Scaleform::Render::TreeNode *transformParent,
        Scaleform::GFx::DisplayObjectBase *obj)
{
  Scaleform::Render::TreeNode *pObject; // ecx
  Scaleform::GFx::MovieImpl::IndirectTransPair p; // [esp+0h] [ebp-10h] BYREF

  p.OrigParentDepth = -1;
  if ( transformParent )
    ++transformParent->RefCount;
  p.TransformParent.pObject = transformParent;
  if ( obj )
    ++obj->RefCount;
  p.Obj.pObject = obj;
  if ( origParent )
    ++origParent->RefCount;
  p.OriginalParent.pObject = origParent;
  Scaleform::ArrayData<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->IndirectTransformPairs.Data,
    &p);
  if ( p.OriginalParent.pObject )
    Scaleform::RefCountNTSImpl::Release(p.OriginalParent.pObject);
  if ( p.Obj.pObject )
    Scaleform::RefCountNTSImpl::Release(p.Obj.pObject);
  pObject = p.TransformParent.pObject;
  if ( p.TransformParent.pObject )
  {
    if ( p.TransformParent.pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
}
