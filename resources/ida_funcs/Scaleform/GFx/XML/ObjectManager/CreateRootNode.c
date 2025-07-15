Scaleform::GFx::XML::RootNode *__thiscall Scaleform::GFx::XML::ObjectManager::CreateRootNode(
        Scaleform::GFx::XML::ObjectManager *this,
        Scaleform::GFx::XML::Node *pdom)
{
  Scaleform::GFx::XML::RootNode *result; // eax

  result = (Scaleform::GFx::XML::RootNode *)this->pHeap->Alloc(this->pHeap, 12, 0);
  if ( !result )
    return 0;
  result->RefCount = 1;
  result->__vftable = (Scaleform::GFx::XML::RootNode_vtbl *)&Scaleform::GFx::XML::RootNode::`vftable';
  if ( pdom )
    ++pdom->RefCount;
  result->pDOMTree.pObject = pdom;
  return result;
}
