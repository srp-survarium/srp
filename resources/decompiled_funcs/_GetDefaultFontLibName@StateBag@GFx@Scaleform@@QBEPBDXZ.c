const char *__thiscall Scaleform::GFx::StateBag::GetDefaultFontLibName(Scaleform::GFx::StateBag *this)
{
  Scaleform::RefCountVImpl *v1; // eax
  unsigned int v2; // esi

  v1 = (Scaleform::RefCountVImpl *)this->GetStateAddRef(this, 18);
  if ( !v1 )
    return 0;
  v2 = (v1[1].RefCount & 0xFFFFFFFC) + 8;
  Scaleform::RefCountImpl::Release(v1);
  return (const char *)v2;
}
