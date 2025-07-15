void __cdecl Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Rectangle_NaNParams__()
{
  Scaleform::GFx::AS2::Value *v0; // esi
  int i; // edi

  v0 = (Scaleform::GFx::AS2::Value *)&Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray,32,Scaleform::GFx::AS3::Value const,double>::Method;
  for ( i = 3; i >= 0; --i )
  {
    --v0;
    if ( v0->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v0);
  }
}
