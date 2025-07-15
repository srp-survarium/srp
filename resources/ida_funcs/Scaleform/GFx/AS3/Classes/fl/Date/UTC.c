void __thiscall Scaleform::GFx::AS3::Classes::fl::Date::UTC(
        Scaleform::GFx::AS3::Classes::fl::Date *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  double time; // [esp+Ch] [ebp-8h]

  time = Scaleform::GFx::AS3::Instances::fl::Date::decodeUTCArgs(argc, argv, 0.0);
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  result->Flags = result->Flags & 0xFFFFFFE0 | 4;
  result->value.VNumber = time;
}
