void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::objectEncodingSet(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned __int8 value)
{
  *((_DWORD *)this + 12) ^= (value ^ (unsigned __int8)*((_DWORD *)this + 12)) & 7;
}
