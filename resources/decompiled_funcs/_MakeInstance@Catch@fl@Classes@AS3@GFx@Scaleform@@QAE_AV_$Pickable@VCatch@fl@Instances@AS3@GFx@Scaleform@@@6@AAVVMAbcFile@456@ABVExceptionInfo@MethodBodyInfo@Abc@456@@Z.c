Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *__thiscall Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstance(
        Scaleform::GFx::AS3::Classes::fl::Catch *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  unsigned int to; // ecx
  unsigned int exc_type_ind; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // esi
  Scaleform::GFx::AS3::Instances::fl::Catch *v7; // eax
  Scaleform::GFx::AS3::Instances::fl::Catch *v8; // eax
  unsigned int var_name_ind; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // ecx

  Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstanceTraits(
    this,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *)&e,
    file,
    e);
  to = e[3].to;
  exc_type_ind = e[2].exc_type_ind;
  file = (Scaleform::GFx::AS3::VMAbcFile *)337;
  v6 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)e;
  v7 = (Scaleform::GFx::AS3::Instances::fl::Catch *)(*(int (__thiscall **)(_DWORD, unsigned int, Scaleform::GFx::AS3::VMAbcFile **))(**(_DWORD **)(to + 32) + 40))(
                                                      *(_DWORD *)(to + 32),
                                                      exc_type_ind,
                                                      &file);
  if ( v7 )
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v7, v6);
  else
    v8 = 0;
  result->pV = v8;
  if ( e )
  {
    if ( ((unsigned __int8)e & 1) == 0 )
    {
      var_name_ind = e->var_name_ind;
      v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)e;
      if ( ((unsigned int)&byte_3FFFFF & var_name_ind) != 0 )
      {
        e->var_name_ind = var_name_ind - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
  }
  return result;
}
