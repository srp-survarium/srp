unsigned int __thiscall Scaleform::GFx::GFxMovieDefImplKeyInterface::GetHashCode(
        Scaleform::GFx::GFxMovieDefImplKeyInterface *this,
        _DWORD *hdata)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)hdata[3];
  return hdata[2]
       ^ v2[2]
       ^ v2[3]
       ^ v2[4]
       ^ v2[6]
       ^ v2[7]
       ^ v2[8]
       ^ v2[9]
       ^ ((hdata[2] ^ v2[2] ^ v2[3] ^ v2[4] ^ v2[6] ^ v2[7] ^ (unsigned int)(v2[8] ^ v2[9])) >> 7);
}
