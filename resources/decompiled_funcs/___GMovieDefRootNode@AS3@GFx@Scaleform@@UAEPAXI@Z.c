Scaleform::GFx::AS3::MovieDefRootNode *__thiscall Scaleform::GFx::AS3::MovieDefRootNode::`scalar deleting destructor'(
        Scaleform::GFx::AS3::MovieDefRootNode *this,
        char a2)
{
  Scaleform::GFx::AS3::MovieDefRootNode::~MovieDefRootNode(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
