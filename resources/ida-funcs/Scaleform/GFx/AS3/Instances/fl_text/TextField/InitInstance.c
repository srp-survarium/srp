void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::InitInstance(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        bool extCall)
{
  Scaleform::GFx::TextField *pObject; // esi

  if ( !extCall )
  {
    Scaleform::GFx::AS3::Instances::fl_text::TextField::CreateStageObject(this);
    pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
    ((void (__thiscall *)(Scaleform::GFx::TextField *, _DWORD, _DWORD))pObject->SetWidth)(
      pObject,
      COERCE_UNSIGNED_INT64(100.0),
      HIDWORD(COERCE_UNSIGNED_INT64(100.0)));
    ((void (__thiscall *)(Scaleform::GFx::TextField *, _DWORD, _DWORD))pObject->SetHeight)(
      pObject,
      COERCE_UNSIGNED_INT64(100.0),
      HIDWORD(COERCE_UNSIGNED_INT64(100.0)));
    Scaleform::GFx::TextField::SetTextValue(pObject, (const __m128i *)uri, 1, 1);
  }
}
