void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::AdjustByteOrder<long>(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        unsigned int *v)
{
  if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
    *v = (((*v << 16) | *v & 0xFF00) << 8) | ((HIWORD(*v) | *v & 0xFF0000) >> 8);
}


void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::AdjustByteOrder<float>(
        Scaleform::GFx::AS3::Instances::fl_net::Socket *this,
        float *v)
{
  float va; // [esp+4h] [ebp+4h]

  if ( (*((_DWORD *)this + 12) & 0x18) != 8 )
  {
    va = *v;
    *(_DWORD *)v = (((LODWORD(va) << 16) | LOWORD(va) & 0xFF00) << 8)
                 | ((HIWORD(LODWORD(va)) | LODWORD(va) & 0xFF0000u) >> 8);
  }
}
