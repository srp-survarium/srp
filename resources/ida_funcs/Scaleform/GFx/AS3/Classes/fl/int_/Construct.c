void __thiscall Scaleform::GFx::AS3::Classes::fl::int_::Construct(
        Scaleform::GFx::AS3::Classes::fl::int_ *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  unsigned int v5; // edx
  Scaleform::GFx::AS3::Value::V2U v6; // [esp+4h] [ebp-4h]

  if ( argc )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, (int *)&argv)->Result )
      Scaleform::GFx::AS3::Value::SetSInt32(result, (int)argv);
  }
  else
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    v5 = result->Flags & 0xFFFFFFE0 | 2;
    result->value.VS._1.VInt = 0;
    result->Flags = v5;
    result->value.VS._2 = v6;
  }
}
