void __cdecl Scaleform::Render::PixelFilterBilinearRGBA32(
        unsigned __int8 *pDst,
        const unsigned __int8 *pSrc1,
        const unsigned __int8 *pSrc2,
        const unsigned __int8 *pSrc3,
        const unsigned __int8 *pSrc4,
        int xFract,
        int yFract)
{
  int v7; // ebp
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // edx
  int v13; // ecx
  int v14; // ebp
  int v15; // esi

  v7 = xFract * (256 - yFract);
  v8 = (256 - xFract) * (256 - yFract);
  v9 = yFract * (256 - xFract);
  v10 = v9 * *pSrc3 + v7 * *pSrc2 + v8 * *pSrc1 + 0x8000;
  v11 = v9 * pSrc3[3] + v7 * pSrc2[3] + v8 * pSrc1[3] + 0x8000;
  v12 = v9 * pSrc3[2] + v7 * pSrc2[2] + v8 * pSrc1[2] + 0x8000;
  v13 = yFract * xFract * pSrc4[1] + v9 * pSrc3[1] + v7 * pSrc2[1] + v8 * pSrc1[1] + 0x8000;
  v14 = yFract * xFract * pSrc4[2];
  v15 = yFract * xFract * pSrc4[3] + v11;
  *pDst = (yFract * xFract * (unsigned int)*pSrc4 + v10) >> 16;
  pDst[1] = BYTE2(v13);
  pDst[2] = (unsigned int)(v14 + v12) >> 16;
  pDst[3] = BYTE2(v15);
}
