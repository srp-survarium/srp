void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::objectEncodingGet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int *result)
{
  *result = (int)(*((_DWORD *)this + 12) << 29) >> 29;
}
