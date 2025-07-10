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
