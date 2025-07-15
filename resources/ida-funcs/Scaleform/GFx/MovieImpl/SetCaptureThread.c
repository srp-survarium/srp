void __thiscall Scaleform::GFx::MovieImpl::SetCaptureThread(Scaleform::GFx::MovieImpl *this, BOOL captureThreadId)
{
  stlp_std::basic_streambuf<wchar_t,stlp_std::char_traits<wchar_t>>::imbue(
    (Scaleform::GFx::AS3::Object *)&this->RenderContext,
    captureThreadId);
}
