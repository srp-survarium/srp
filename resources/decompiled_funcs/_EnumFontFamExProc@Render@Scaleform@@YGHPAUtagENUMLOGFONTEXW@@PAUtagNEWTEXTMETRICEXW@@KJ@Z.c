int __stdcall Scaleform::Render::EnumFontFamExProc(
        tagENUMLOGFONTEXW *lpelfe,
        tagNEWTEXTMETRICEXW *lpntme,
        unsigned int FontType,
        _BYTE *lParam)
{
  *lParam = 1;
  return 0;
}
