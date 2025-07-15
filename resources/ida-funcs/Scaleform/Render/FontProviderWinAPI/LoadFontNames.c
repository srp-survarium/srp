void __thiscall Scaleform::Render::FontProviderWinAPI::LoadFontNames(
        Scaleform::Render::FontProviderWinAPI *this,
        Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  HDC__ *WinHDC; // ecx
  tagLOGFONTW Logfont; // [esp+0h] [ebp-5Ch] BYREF

  WinHDC = this->SysData.WinHDC;
  Logfont.lfFaceName[0] = 0;
  Logfont.lfPitchAndFamily = 0;
  Logfont.lfCharSet = 1;
  EnumFontFamiliesExW(WinHDC, &Logfont, (FONTENUMPROCW)Scaleform::Render::LoadFontNamesProc, (LPARAM)fontnames, 0);
}
