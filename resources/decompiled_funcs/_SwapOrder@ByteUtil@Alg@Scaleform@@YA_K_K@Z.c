unsigned __int64 __cdecl Scaleform::Alg::ByteUtil::SwapOrder(unsigned __int64 v)
{
  unsigned __int64 v1; // rt0
  int v2; // eax
  unsigned int v3; // ebx

  LODWORD(v1) = v >> 16;
  HIDWORD(v1) = HIWORD(HIDWORD(v)) | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & HIDWORD(v);
  LODWORD(v1) = v1 >> 16;
  HIDWORD(v1) = WORD2(v) & 0xFF00 | HIWORD(HIDWORD(v1));
  v2 = v1 >> 16;
  HIDWORD(v1) = v >> 16;
  LODWORD(v1) = ((_DWORD)v << 16) | v & 0xFF00;
  HIDWORD(v1) = v1 >> 16;
  LODWORD(v1) = (unsigned int)&vostok::memory::s_CRT_arena[5508664] & v | ((_DWORD)v1 << 16);
  HIDWORD(v1) = v1 >> 16;
  LODWORD(v1) = v & 0xFF000000
              | (((unsigned int)&vostok::memory::s_CRT_arena[5508664] & (unsigned int)v
                | ((((_DWORD)v << 16) | v & 0xFF00) << 16)) << 16);
  v3 = v1 >> 24;
  LODWORD(v1) = v2;
  HIDWORD(v1) = BYTE4(v)
              | ((WORD2(v) & 0xFF00
                | ((HIWORD(HIDWORD(v)) | (unsigned int)&vostok::memory::s_CRT_arena[5508664] & HIDWORD(v)) >> 16)) >> 16);
  return __PAIR64__(
           v3,
           (v & 0xFF000000
          | (((unsigned int)&vostok::memory::s_CRT_arena[5508664] & (unsigned int)v
            | ((((_DWORD)v << 16) | v & 0xFF00) << 16)) << 16)) << 8)
       | (v1 >> 8);
}
