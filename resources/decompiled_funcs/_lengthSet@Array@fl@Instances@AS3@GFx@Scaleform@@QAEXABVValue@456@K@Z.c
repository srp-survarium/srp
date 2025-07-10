void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::lengthSet(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int newLength)
{
  Scaleform::GFx::AS3::Impl::SparseArray::Resize(&this->SA, newLength);
}
