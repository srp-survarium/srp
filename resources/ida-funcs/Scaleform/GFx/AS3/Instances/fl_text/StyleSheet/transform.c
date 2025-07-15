void __userpurge Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::transform(
        Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::ASString a3@<esi>,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result,
        const Scaleform::GFx::AS3::Value *formatObject)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *VInt; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *v8; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> textFormat; // [esp+0h] [ebp-4h] BYREF

  textFormat.pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)this;
  if ( (formatObject->Flags & 0x1F) - 12 <= 3 )
  {
    VInt = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)formatObject->value.VS._1.VInt;
    if ( VInt )
    {
      pObject = this->pTraits.pObject;
      textFormat.pObject = 0;
      Scaleform::GFx::AS3::VM::constructBuiltinObject(
        pObject->pVM,
        (Scaleform::GFx::AS3::CheckResult *)&formatObject,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&textFormat,
        "flash.text.TextFormat",
        0,
        0);
      Scaleform::GFx::AS3::CSSTextFormatLoader::Process(a2, textFormat.pObject, VInt, a3);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(result, &textFormat);
      if ( textFormat.pObject )
      {
        if ( ((int)textFormat.pObject & 1) == 0 )
        {
          RefCount = textFormat.pObject->RefCount;
          v8 = textFormat.pObject;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            textFormat.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
          }
        }
      }
    }
  }
}
