Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::MakeInstance(
        Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> *result)
{
  Scaleform::GFx::AS3::Instance *v3; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v4; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> *v5; // eax

  v3 = (Scaleform::GFx::AS3::Instance *)Scaleform::GFx::AS3::Traits::Alloc(this);
  v4 = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v3;
  if ( v3 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v3, this);
    v5 = result;
    v4->__vftable = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript_vtbl *)&Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::`vftable';
    v4->Initialized = 0;
    result->pV = v4;
  }
  else
  {
    v5 = result;
    result->pV = 0;
  }
  return v5;
}
