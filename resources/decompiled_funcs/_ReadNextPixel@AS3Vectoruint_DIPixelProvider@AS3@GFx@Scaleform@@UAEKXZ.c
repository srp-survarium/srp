Scaleform::GFx::AS3::Value::V1U __thiscall Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider::ReadNextPixel(
        Scaleform::GFx::AS3::AS3Vectoruint_DIPixelProvider *this)
{
  unsigned int Location; // eax
  Scaleform::GFx::AS3::Value::V1U v2; // esi
  Scaleform::GFx::AS3::Value v; // [esp+4h] [ebp-10h] BYREF

  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  Location = this->Location;
  this->Location = Location + 1;
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Get(&this->PixelVector->V, Location, &v);
  v2 = v.value.VS._1;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      return v2;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  return v2;
}
