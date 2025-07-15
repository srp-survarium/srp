void __thiscall Scaleform::GFx::MovieImpl::AddIndirectTransformPair(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::DisplayObjContainer *origParent,
        Scaleform::Render::TreeNode *transformParent,
        Scaleform::GFx::DisplayObjectBase *obj)
{
  Scaleform::Render::TreeNode *pObject; // ecx
  Scaleform::GFx::MovieImpl::IndirectTransPair val; // [esp+0h] [ebp-10h] BYREF

  val.OrigParentDepth = -1;
  if ( transformParent )
    ++transformParent->RefCount;
  val.TransformParent.pObject = transformParent;
  if ( obj )
    ++obj->RefCount;
  val.Obj.pObject = obj;
  if ( origParent )
    ++origParent->RefCount;
  val.OriginalParent.pObject = origParent;
  Scaleform::ArrayData<Scaleform::GFx::MovieImpl::IndirectTransPair,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::IndirectTransPair,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->IndirectTransformPairs.Data,
    &val);
  if ( val.OriginalParent.pObject )
    Scaleform::RefCountNTSImpl::Release(val.OriginalParent.pObject);
  if ( val.Obj.pObject )
    Scaleform::RefCountNTSImpl::Release(val.Obj.pObject);
  pObject = val.TransformParent.pObject;
  if ( val.TransformParent.pObject )
  {
    if ( val.TransformParent.pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
}
