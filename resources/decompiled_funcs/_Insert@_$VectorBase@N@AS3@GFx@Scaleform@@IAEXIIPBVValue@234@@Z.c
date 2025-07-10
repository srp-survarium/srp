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
