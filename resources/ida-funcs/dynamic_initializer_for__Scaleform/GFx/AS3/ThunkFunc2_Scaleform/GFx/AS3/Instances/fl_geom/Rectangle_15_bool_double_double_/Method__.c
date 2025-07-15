void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl_geom::Rectangle_15_bool_double_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this, bool *result, long double x, long double y)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *, bool *, long double, long double); // eax

  result = Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::contains;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle,15,bool,double,double>::Method) = Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::contains;
  dword_AAC774 = 0;
  return result;
}
