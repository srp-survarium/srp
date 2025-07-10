void __userpurge Scaleform::GFx::AS3::Instances::fl_text::TextField::typeSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::RefCountVImpl *value)
{
  Scaleform::GFx::TextField *pObject; // edi
  Scaleform::Render::Text::EditorKitBase *v5; // eax
  Scaleform::RefCountVImpl *v6; // esi

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  if ( !strcmp((const char *)value->~Scaleform::RefCountVImpl, "dynamic") )
  {
    v5 = pObject->pDocument.pObject->pEditorKit.pObject;
    if ( v5 )
    {
      LOWORD(v5[16].__vftable) |= 1u;
      pObject->pDocument.pObject->RTFlags |= 1u;
      return;
    }
  }
  else if ( !strcmp((const char *)value->~Scaleform::RefCountVImpl, "input")
         && !Scaleform::GFx::TextField::HasStyleSheet(pObject) )
  {
    v6 = *Scaleform::GFx::TextField::CreateEditorKit(pObject, a2, (int)&value);
    if ( value )
      Scaleform::RefCountImpl::Release(value);
    LOWORD(v6[16].__vftable) &= ~1u;
  }
  pObject->pDocument.pObject->RTFlags |= 1u;
}
