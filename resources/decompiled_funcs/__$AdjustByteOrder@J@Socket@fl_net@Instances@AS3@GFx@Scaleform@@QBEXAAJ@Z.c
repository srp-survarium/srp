void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::AdjustByteOrder<long>(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int *v)
{
  if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
    *v = (((*v << 16) | *v & 0xFF00) << 8)
       | ((HIWORD(*v) | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & *v) >> 8);
}
