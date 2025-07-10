void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::isFinite(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        bool *result,
        long double n)
{
  *result = (HIDWORD(n) & 0x7FF00000) != 0x7FF00000;
}
