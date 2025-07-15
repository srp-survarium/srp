void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3lastIndexOf(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        int *result,
        const Scaleform::GFx::ASString *value,
        int from)
{
  Scaleform::GFx::ASString *pNode; // esi

  pNode = (Scaleform::GFx::ASString *)value->pNode;
  if ( value->pNode )
    ++pNode[3].pNode;
  value = pNode;
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::LastIndexOf(
    (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&this->V,
    result,
    (const unsigned int *)&value,
    from);
  if ( pNode )
  {
    if ( pNode[3].pNode-- == (Scaleform::GFx::ASStringNode *)1 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pNode);
  }
}
