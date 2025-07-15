void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::describeType(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASString *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode *v5; // ecx
  Scaleform::GFx::ASStringNode *v7; // eax

  v3 = Scaleform::GFx::AS3::VM::describeTypeEx(this->pTraits.pObject->pVM, (Scaleform::GFx::ASString *)&v, v);
  pNode = v3->pNode;
  ++v3->pNode->RefCount;
  v5 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v7 = (Scaleform::GFx::ASStringNode *)v;
  result->pNode = pNode;
  if ( !--v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}
