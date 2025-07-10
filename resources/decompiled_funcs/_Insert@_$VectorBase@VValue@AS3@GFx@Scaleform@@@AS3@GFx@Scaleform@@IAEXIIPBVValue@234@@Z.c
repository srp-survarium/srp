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
