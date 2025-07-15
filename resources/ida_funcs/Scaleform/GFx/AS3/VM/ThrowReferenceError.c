void __thiscall Scaleform::GFx::AS3::VM::ThrowReferenceError(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    e,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
}
