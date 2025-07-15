void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Set(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned __int8 *data,
        unsigned int sz)
{
  this->Position = 0;
  if ( sz < this->Data.Data.Size )
  {
    if ( sz >= this->Length )
      this->Length = sz;
  }
  else
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, sz);
  }
  memcpy(&this->Data.Data.Data[this->Position], data, sz);
  this->Position = 0;
}
