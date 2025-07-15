void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::lineGradientStyle(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::Render::ComplexFill *LineComplexFill; // eax

  LineComplexFill = (Scaleform::Render::ComplexFill *)Scaleform::GFx::DrawingContext::CreateLineComplexFill(this->pDrawing.pObject);
  Scaleform::GFx::AS3::Instances::fl_display::Graphics::CreateGradientHelper(this, argc, argv, LineComplexFill);
}
