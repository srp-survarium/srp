unsigned __int8 *__usercall Wm4::System::Memcpy@<eax>(
        unsigned __int8 *pvDst@<esi>,
        unsigned __int8 *pvSrc@<ecx>,
        unsigned int uiSrcSize@<eax>,
        unsigned int a4@<ebx>,
        unsigned int uiDstSize)
{
  return memcpy_s(a4, pvDst, uiDstSize, pvSrc, uiSrcSize) == 0 ? pvDst : 0;
}
