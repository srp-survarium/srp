void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::beginGradientFill(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::Render::ComplexFill *NewComplexFill; // eax

  NewComplexFill = (Scaleform::Render::ComplexFill *)Scaleform::GFx::DrawingContext::CreateNewComplexFill(this->pDrawing.pObject);
  Scaleform::GFx::AS3::Instances::fl_display::Graphics::CreateGradientHelper(this, argc, argv, NewComplexFill);
  Scaleform::GFx::DrawingContext::BeginFill(this->pDrawing.pObject);
}
