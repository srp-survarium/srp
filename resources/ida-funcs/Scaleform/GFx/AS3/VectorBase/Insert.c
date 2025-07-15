void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Insert(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int pos,
        Scaleform::GFx::AS3::Value::V1U argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  unsigned int VInt; // ebp
  unsigned int v5; // esi
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::AS3::Value::VU *p_value; // edi

  VInt = argc.VInt;
  v5 = 0;
  if ( argc.VInt )
  {
    p_ValueA = &this->ValueA;
    p_value = &argv->value;
    do
    {
      argc = p_value->VS._1;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        p_ValueA,
        v5 + pos,
        (unsigned int *)&argc);
      ++v5;
      p_value += 2;
    }
    while ( v5 < VInt );
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Insert(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int pos,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v4; // esi
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::AS3::Value::VU *p_value; // edi
  double val; // [esp+10h] [ebp-8h] BYREF

  v4 = 0;
  if ( argc )
  {
    p_ValueA = &this->ValueA;
    p_value = &argv->value;
    do
    {
      val = p_value->VNumber;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        p_ValueA,
        v4 + pos,
        &val);
      ++v4;
      p_value += 2;
    }
    while ( v4 < argc );
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Insert(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int pos,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v4; // edi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::Extra v8; // ecx
  Scaleform::GFx::AS3::Value::V2U v9; // ecx
  Scaleform::GFx::AS3::Value val; // [esp+4h] [ebp-10h] BYREF

  v4 = 0;
  if ( argc )
  {
    p_ValueA = &this->ValueA;
    do
    {
      Flags = argv->Flags;
      v8.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)argv->Bonus;
      val.value.VS._1.VInt = argv->value.VS._1.VInt;
      val.Bonus = v8;
      v9.VObj = (Scaleform::GFx::AS3::Object *)argv->value.VS._2;
      val.Flags = Flags;
      val.value.VS._2 = v9;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(argv);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(argv);
      }
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        p_ValueA,
        v4 + pos,
        &val);
      if ( (val.Flags & 0x1F) > 9 )
      {
        if ( (val.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
      ++v4;
      ++argv;
    }
    while ( v4 < argc );
  }
}


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
