void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // eax

  VStr = v->value.VS._1.VStr;
  if ( VStr )
    ++VStr->RefCount;
  p_ValueA = &this->ValueA;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ValueA.Data,
    this->ValueA.Data.pHeap,
    this->ValueA.Data.Size + 1);
  v4 = &p_ValueA->Data.Data[p_ValueA->Data.Size - 1];
  if ( &p_ValueA->Data.Data[p_ValueA->Data.Size] != (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)4 )
  {
    if ( VStr )
      ++VStr->RefCount;
    v4->pObject = VStr;
  }
  if ( VStr )
  {
    if ( VStr->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
}
