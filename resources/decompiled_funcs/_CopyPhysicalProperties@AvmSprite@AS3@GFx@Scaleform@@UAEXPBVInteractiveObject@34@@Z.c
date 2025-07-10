// attributes: thunk
void __thiscall Scaleform::GFx::AS3::AvmSprite::CopyPhysicalProperties(
        Scaleform::GFx::AS3::AvmSprite *this,
        const Scaleform::GFx::InteractiveObject *poldChar)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::imbue(
    (Scaleform::GFx::AS3::Object *)this,
    (bool)poldChar);
}
