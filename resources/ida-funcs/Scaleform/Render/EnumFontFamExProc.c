int __stdcall Scaleform::Render::EnumFontFamExProc(
        const tagLOGFONTW *a1,
        const tagTEXTMETRICW *a2,
        unsigned int a3,
        _BYTE *a4)
{
  *a4 = 1;
  return 0;
}
