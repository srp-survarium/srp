Scaleform::Render::TreeCacheNode *__thiscall Scaleform::Render::TreeCacheNode::`scalar deleting destructor'(
        Scaleform::Render::TreeCacheNode *this,
        char a2)
{
  Scaleform::Render::TreeCacheNode::~TreeCacheNode(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
