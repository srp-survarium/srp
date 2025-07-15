Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle> *__cdecl Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle *t)
{
  Scaleform::GFx::AS3::Instances::fl::Catch *v2; // eax
  Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle> *v4; // eax

  v2 = (Scaleform::GFx::AS3::Instances::fl::Catch *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v3 = (Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle *)v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v2, t);
    v3->textColor = -1;
    v3->selectedTextColor = -1;
    v3->fontSize = -1;
    v3->backgroundColor = -1;
    v3->selectedBackgroundColor = -1;
    v3->indexBackgroundColor = -1;
    v3->selectedIndexBackgroundColor = -1;
    v3->readingWindowTextColor = -1;
    v3->readingWindowBackgroundColor = -1;
    v3->readingWindowFontSize = -1;
    v4 = result;
    v3->__vftable = (Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle_vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle::`vftable';
    result->pV = v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
