Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::AppendChild(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Value *child)
{
  ((void (__stdcall *)(Scaleform::GFx::AS3::CheckResult *, unsigned int, const Scaleform::GFx::AS3::Value *))this->InsertChildAt)(
    result,
    this->Children.Data.Size,
    child);
  return result;
}
