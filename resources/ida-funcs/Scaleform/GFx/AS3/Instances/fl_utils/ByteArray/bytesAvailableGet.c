void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::bytesAvailableGet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int *result)
{
  *result = this->Data.Data.Size - this->Position;
}
