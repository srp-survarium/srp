Scaleform::String *__thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::GetAS3ObjectName(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::String *result)
{
  Scaleform::String::String(result, (const __m128i *)this->Uri.pNode->pData);
  return result;
}
