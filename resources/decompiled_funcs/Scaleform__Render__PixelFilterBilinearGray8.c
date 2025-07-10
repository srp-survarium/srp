void __cdecl Scaleform::Render::PixelFilterBilinearGray8(
        unsigned __int8 *pDst,
        const unsigned __int8 *pSrc1,
        const unsigned __int8 *pSrc2,
        const unsigned __int8 *pSrc3,
        const unsigned __int8 *pSrc4,
        int xFract,
        int yFract)
{
  *pDst = ((256 - xFract) * (256 - yFract) * *pSrc1
         + yFract * (256 - xFract) * *pSrc3
         + xFract * (256 - yFract) * *pSrc2
         + yFract * xFract * (unsigned int)*pSrc4
         + 0x8000) >> 16;
}
