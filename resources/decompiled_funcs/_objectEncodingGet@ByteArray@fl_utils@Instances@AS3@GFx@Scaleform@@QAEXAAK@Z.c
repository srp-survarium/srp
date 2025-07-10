void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::objectEncodingGet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int *result)
{
  *result = (int)(*((_DWORD *)this + 8) << 29) >> 29;
}
