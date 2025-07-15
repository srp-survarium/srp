void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Scene_2_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_display::Scene *this, int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_display::Scene *, int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_display::Scene::numFramesGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Scene,2,long>::Method) = Scaleform::GFx::AS3::Instances::fl_display::Scene::numFramesGet;
  dword_8F2964 = 0;
  return result;
}
