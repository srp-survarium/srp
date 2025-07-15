void __cdecl Scaleform::Render::PixelFilterBilinearRGB24(
        unsigned __int8 *pDst,
        const unsigned __int8 *pSrc1,
        const unsigned __int8 *pSrc2,
        const unsigned __int8 *pSrc3,
        const unsigned __int8 *pSrc4,
        int xFract,
        int yFract)
{
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  int v10; // ecx
  int v11; // edx

  v7 = xFract * (256 - yFract);
  v8 = (256 - xFract) * (256 - yFract);
  v9 = yFract * (256 - xFract);
  v10 = (yFract * xFract * pSrc4[1] + v9 * pSrc3[1] + v7 * pSrc2[1] + v8 * pSrc1[1] + 0x8000) >> 16;
  v11 = (yFract * xFract * pSrc4[2] + v9 * pSrc3[2] + v7 * pSrc2[2] + v8 * pSrc1[2] + 0x8000) >> 16;
  *pDst = (yFract * xFract * *pSrc4 + v9 * *pSrc3 + v7 * *pSrc2 + v8 * (unsigned int)*pSrc1 + 0x8000) >> 16;
  pDst[1] = v10;
  pDst[2] = v11;
}
