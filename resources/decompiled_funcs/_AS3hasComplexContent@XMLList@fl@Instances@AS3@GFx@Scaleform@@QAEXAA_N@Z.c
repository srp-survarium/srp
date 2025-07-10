void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3hasComplexContent(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        bool *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList::AS3hasSimpleContent(this, result);
  *result = !*result;
}
