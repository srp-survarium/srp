// attributes: thunk
void __thiscall Scaleform::GFx::AS3::AvmSprite::CopyPhysicalProperties(
        Scaleform::GFx::AS3::AvmSprite *this,
        const Scaleform::GFx::InteractiveObject *poldChar)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::imbue(
    (Scaleform::GFx::AS3::Object *)this,
    (bool)poldChar);
}


void __thiscall Scaleform::GFx::AS3::AvmSprite::CopyPhysicalProperties(
        char *this,
        const Scaleform::GFx::InteractiveObject *a2)
{
  Scaleform::GFx::AS3::AvmSprite::CopyPhysicalProperties((Scaleform::GFx::AS3::AvmSprite *)(this - 8), a2);
}


void __thiscall Scaleform::GFx::AS3::AvmSprite::CopyPhysicalProperties(
        char *this,
        const Scaleform::GFx::InteractiveObject *a2)
{
  Scaleform::GFx::AS3::AvmSprite::CopyPhysicalProperties((Scaleform::GFx::AS3::AvmSprite *)(this - 12), a2);
}
