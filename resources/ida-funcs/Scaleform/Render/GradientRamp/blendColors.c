void __cdecl Scaleform::Render::GradientRamp::blendColors(
        unsigned __int8 *c,
        const Scaleform::Render::GradientRamp::ColorType *c1,
        const Scaleform::Render::GradientRamp::ColorType *c2,
        int ratio,
        int maxRatio,
        float gamma)
{
  *c = Scaleform::Render::GradientRamp::applyGammaInv(c1->r + ratio * (c2->r - c1->r) / maxRatio, gamma);
  c[1] = Scaleform::Render::GradientRamp::applyGammaInv(c1->g + ratio * (c2->g - c1->g) / maxRatio, gamma);
  c[2] = Scaleform::Render::GradientRamp::applyGammaInv(c1->b + ratio * (c2->b - c1->b) / maxRatio, gamma);
  c[3] = LOBYTE(c1->a) + ratio * (c2->a - c1->a) / (maxRatio | (maxRatio << 8));
}
