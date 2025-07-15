void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::isNaN(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        bool *result,
        long double n)
{
  *result = (HIDWORD(n) & 0x7FF00000) == 0x7FF00000 && HIDWORD(n) & 0xFFFFF | LODWORD(n);
}
