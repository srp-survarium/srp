Scaleform::Render::Color *__userpurge Scaleform::Render::ProfileViews::GetColor@<eax>(
        Scaleform::Render::ProfileViews *this@<ecx>,
        int a2@<eax>,
        Scaleform::Render::Color *a3@<esi>,
        Scaleform::Render::Color *result,
        Scaleform::Render::Color color)
{
  Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::Render::Cxform v7; // [esp+0h] [ebp-20h] BYREF

  if ( *(_BYTE *)(a2 + 5) || *(_DWORD *)(a2 + 8) )
  {
    Cxform = Scaleform::Render::ProfileViews::GetCxform(
               (Scaleform::Render::ProfileViews *)&v7,
               (Scaleform::Render::Cxform *)a2,
               &v7,
               (float *)&Scaleform::Render::Cxform::Identity);
    Scaleform::Render::Cxform::Transform(Cxform, a3, (const Scaleform::Render::Color)result);
  }
  else
  {
    a3->Raw = (unsigned int)result;
  }
  return a3;
}
