void __thiscall Scaleform::Render::Color::GetRGBAFloat(
        Scaleform::Render::Color *this,
        float *pr,
        float *pg,
        float *pb,
        float *pa)
{
  Scaleform::Render::Color::GetRGBFloat(this, pr, pg, pb);
  Scaleform::Render::Color::GetAlphaFloat(this, pa);
}


void __thiscall Scaleform::Render::Color::GetRGBAFloat(Scaleform::Render::Color *this, float *prgba)
{
  Scaleform::Render::Color::GetRGBAFloat(this, prgba, prgba + 1, prgba + 2, prgba + 3);
}
