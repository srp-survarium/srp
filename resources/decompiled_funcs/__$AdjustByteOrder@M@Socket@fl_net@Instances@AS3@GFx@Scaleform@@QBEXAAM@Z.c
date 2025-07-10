void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::AdjustByteOrder<float>(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        float *v)
{
  float va; // [esp+4h] [ebp+4h]

  if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
  {
    va = *v;
    *(_DWORD *)v = (((LODWORD(va) << 16) | LOWORD(va) & 0xFF00) << 8)
                 | ((HIWORD(LODWORD(va)) | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & LODWORD(va)) >> 8);
  }
}
