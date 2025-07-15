void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::ASStringNode *v2; // edi
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *p_V; // esi
  unsigned int Size; // ecx
  const Scaleform::MemoryHeap *pHeap; // edx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // esi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v7; // eax

  v2 = v;
  if ( v )
    ++v->RefCount;
  p_V = &this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&this->V, (Scaleform::GFx::AS3::CheckResult *)&v)->Result )
  {
    Size = p_V->ValueA.Data.Size;
    pHeap = p_V->ValueA.Data.pHeap;
    p_Data = &p_V->ValueA.Data;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      p_Data,
      pHeap,
      Size + 1);
    v7 = &p_Data->Data[p_Data->Size - 1];
    if ( &p_Data->Data[p_Data->Size] != (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)4 )
    {
      if ( v2 )
        ++v2->RefCount;
      v7->pObject = v2;
    }
  }
  if ( v2 )
  {
    if ( v2->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  }
}
