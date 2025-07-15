void __thiscall Scaleform::Render::FontProviderWinAPI::LoadFontNames(
        Scaleform::Render::FontProviderWinAPI *this,
        Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  HDC__ *WinHDC; // ecx
  tagLOGFONTW lf; // [esp+0h] [ebp-5Ch] BYREF

  WinHDC = this->SysData.WinHDC;
  lf.lfFaceName[0] = 0;
  lf.lfPitchAndFamily = 0;
  lf.lfCharSet = 1;
  EnumFontFamiliesExW(WinHDC, &lf, (FONTENUMPROCW)Scaleform::Render::LoadFontNamesProc, (LPARAM)fontnames, 0);
}
