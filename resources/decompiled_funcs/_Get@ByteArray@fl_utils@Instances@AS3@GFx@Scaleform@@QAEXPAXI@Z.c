void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned __int8 *dest,
        unsigned int destSz)
{
  this->Position = 0;
  if ( destSz <= this->Data.Data.Size )
  {
    memcpy(dest, this->Data.Data.Data, destSz);
    this->Position += destSz;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ThrowEOFError(this);
  }
  this->Position = 0;
}
