bool __thiscall Scaleform::GFx::AS3::MovieRoot::UnloadMovie_::_46_::TextFormatVisitor::Visit(
        Scaleform::GFx::AS3::MovieRoot::UnloadMovie::__l46::TextFormatVisitor *this,
        Scaleform::RefCountVImpl *tf)
{
  char v3; // al
  Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *p_tf; // edx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::Render::Text::FontHandle *pObject; // esi

  v3 = 0;
  if ( (tf[4].RefCount & 0x8000000) != 0 )
  {
    p_tf = (Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *)&tf[3];
    v5 = tf;
  }
  else
  {
    v5 = 0;
    v3 = 1;
    tf = 0;
    p_tf = (Scaleform::Ptr<Scaleform::Render::Text::FontHandle> *)&tf;
  }
  pObject = p_tf->pObject;
  if ( (v3 & 1) != 0 && v5 )
    Scaleform::RefCountImpl::Release(v5);
  return !pObject || pObject[1].__vftable != (Scaleform::Render::Text::FontHandle_vtbl *)this->pDefImpl;
}
