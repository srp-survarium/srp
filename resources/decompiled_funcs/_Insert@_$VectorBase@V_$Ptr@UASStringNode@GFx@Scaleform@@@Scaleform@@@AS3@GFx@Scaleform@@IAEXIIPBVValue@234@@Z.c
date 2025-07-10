void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Insert(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        unsigned int pos,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v4; // edi
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebp
  Scaleform::GFx::AS3::Value::VU *p_value; // ebx
  Scaleform::GFx::AS3::Value *VInt; // esi

  v4 = 0;
  if ( argc )
  {
    p_ValueA = &this->ValueA;
    p_value = &argv->value;
    do
    {
      VInt = (Scaleform::GFx::AS3::Value *)p_value->VS._1.VInt;
      if ( p_value->VS._1.VInt )
        ++VInt->value.VS._2.VObj;
      argv = VInt;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        p_ValueA,
        v4 + pos,
        (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&argv);
      if ( VInt )
      {
        if ( VInt->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)VInt);
      }
      ++v4;
      p_value += 2;
    }
    while ( v4 < argc );
  }
}
