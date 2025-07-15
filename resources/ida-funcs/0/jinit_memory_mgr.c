const char *__cdecl jinit_memory_mgr(int a1)
{
  Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent *v1; // ecx
  _DWORD *v2; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v3; // ecx
  _DWORD *small; // esi
  const char *result; // eax
  Scaleform::GFx::AS3::Object *StrokeStyleCount; // [esp+Ch] [ebp-4h] BYREF

  v2 = (_DWORD *)a1;
  *(_DWORD *)(a1 + 4) = 0;
  StrokeStyleCount = Scaleform::GFx::ConstShapeNoStyles::GetStrokeStyleCount(v1);
  small = (_DWORD *)jpeg_get_small((int)v2, 0x54u);
  if ( !small )
  {
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v3);
    *(_DWORD *)(*v2 + 20) = 56;
    *(_DWORD *)(*v2 + 24) = 0;
    (*(void (__cdecl **)(_DWORD *, _DWORD *))*v2)(v2, v2);
  }
  *small = sub_481300;
  small[1] = sub_481430;
  small[2] = sub_4814D0;
  small[3] = sub_481580;
  small[4] = sub_481630;
  small[5] = sub_4816A0;
  small[6] = sub_481710;
  small[7] = sub_4819F0;
  small[8] = sub_481B30;
  small[9] = sub_481C80;
  small[10] = sub_481D90;
  small[12] = 1000000000;
  small[11] = StrokeStyleCount;
  small[14] = 0;
  small[16] = 0;
  small[13] = 0;
  small[15] = 0;
  small[17] = 0;
  small[18] = 0;
  small[19] = 84;
  v2[1] = small;
  result = getenv(0, (int)v2, "JPEGMEM");
  if ( result )
  {
    LOBYTE(a1) = 120;
    result = (const char *)sscanf(0, result, "%ld%c", &StrokeStyleCount, &a1);
    if ( (int)result > 0 )
    {
      if ( (_BYTE)a1 == 109 || (_BYTE)a1 == 77 )
      {
        result = (const char *)(1000000 * (_DWORD)StrokeStyleCount);
        small[11] = 1000000 * (_DWORD)StrokeStyleCount;
      }
      else
      {
        result = (const char *)(1000 * (_DWORD)StrokeStyleCount);
        small[11] = 1000 * (_DWORD)StrokeStyleCount;
      }
    }
  }
  return result;
}
